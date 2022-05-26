#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

//Ramazan Arslan - 250201023
//I could not finish that homework for various reasons, still thank you for your interest.

#define BILLION 1E9
// maximum number of threads 
#define MAX_THREAD 10

int countLines(FILE *f){ // for count the number of lines of the file
   int count = 0;
   char ch;
   while ((ch = fgetc(f)) != EOF){
       if (ch == '\n')
           count++;
   }
   return count;
}

int countWord(int lineCount, char stopwords[851][30],FILE *f){ 
//finds the number of 'stop words' in the file
   for (int  j = 0;j < 851; j++ ){
              char currentline[200];
               int count = 0;
               char *stopword = stopwords[j];
            while (fgets(currentline, sizeof(currentline), f) != NULL) {
                if(strstr(currentline, stopword) != NULL) {
                    count+=1;
                }
            }
            fclose(f);
    }  
   return 0;
}

int fileOperations(char stopwords[851][30]){ //calls countLines and countWord function
   int lineCount=1;
   int numberOfWord;
   FILE *rFile = fopen("book1.txt", "r");
   lineCount += countLines(rFile);
   numberOfWord = countWord(lineCount,stopwords,rFile);
   fclose(rFile);
   return 0;

}


void *mythread() { // main operation function

   FILE *stopwordfile = fopen("englishstopwords.txt", "r"); // file operations for stopword
    char lines[30];
    char stopwords[851][30]; // create array for storing stopwords 
    int i = 0;

    while (fgets(lines, sizeof(lines), stopwordfile) != NULL) {
        for(int j = 0 ; j<30 ; j++){
            stopwords[i][j] = lines[j];
        }
        i++;
    }
    fclose(stopwordfile);
    fileOperations(stopwords);
    pthread_exit(NULL);

}

int main() 
{ 
	
	pthread_t threads[MAX_THREAD]; 
	struct timespec requestStart, requestEnd; // for calculating time
	clock_gettime(CLOCK_REALTIME, &requestStart);

	for (int i = 0; i < MAX_THREAD; i++) { 
		int* p = malloc(sizeof(int));
		*p=i; 
		pthread_create(&threads[i], NULL, mythread, p); 
	} 

	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL);	 

	clock_gettime(CLOCK_REALTIME, &requestEnd);

	double accum = ( requestEnd.tv_sec - requestStart.tv_sec ) + ( requestEnd.tv_nsec - requestStart.tv_nsec ) / BILLION;
	printf("Total time spent %lf, for %d threads\n", accum, MAX_THREAD);

	return 0; 
} 
