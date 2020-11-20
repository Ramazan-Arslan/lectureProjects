#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Ramazan Arslan 2020
// Sources:
// https://www.programiz.com/c-programming/c-file-input-output
// https://www.youtube.com/watch?v=j9egu_VB1j4
// https://www.geeksforgeeks.org/binary-tree-array-implementation/

char charArray[500000];
int Nums[1000];
int tree[10000000];

void add(int key,int parentIndex){ //adds the numbers to the tree.
   if(key > tree[parentIndex]){
      if(tree[(parentIndex*2) +2] != 0){
         add(key,((parentIndex*2)+2));
      }
      else{
         tree[(parentIndex*2)+2] = key;
      }

   }
   else if( key < tree[parentIndex]){
      if(tree[parentIndex*2 +1] != 0){
         add(key,((parentIndex*2)+1));
      }
      else{
          tree[(parentIndex*2)+1] = key;
      }
   }
}


void writeFile(int parentIndex){ // Writes ordered numbers in the tree.
   FILE *fptr;
   fptr = fopen("C_Ordered_BST.txt","a");//If you run and control this code you need to delete C_Ordered_BST.txt file from the directory.
   fprintf(fptr,"%d ",tree[parentIndex]); //If you don't delete file , The program overwrites to file .
   fclose(fptr);
}


int inorder(int parentIndex){ // in order traversal 
   if(tree[parentIndex]== NULL){
      return 0;
   }
   inorder((parentIndex*2)+1);
   //printf("BST In Order Traversal Elements : %i \n" ,tree[parentIndex]); //prints ordered tree
   writeFile(parentIndex);
   inorder((parentIndex*2)+2);     
}


int main() {
  
   FILE *fptr; // file read operations
   fptr = fopen("randomNumbers1000.txt","r");//you can change the text name for trying the other files.
   fscanf(fptr, "%[^\n]", charArray);
   fclose(fptr); // close file

     clock_t begin = clock(); // beginning of the operation time
   int j = 0;
   int count =0;
   char tempStr[4];
    for(int i = 0; i<strlen(charArray);i++){ //Split operations  & Adds numbers to the 'int' array from 'char' array.
        if(charArray[i] == ' '||charArray[i] =='\0'){
         tempStr[j] =NULL;
         j=0;
         int x = atoi(tempStr); //str to int
         Nums[count] = x;
         count++;
        }
        else{
           tempStr[j] = charArray[i];
           j++;
        }
    }
   tree[0] = Nums[0]; //Root of tree. ##First number in the text is root of tree.

   for (int k = 1 ; k <count ; k++){ // adds to the tree readed numbers from text.
      add(Nums[k],0);
   }
   clock_t end = clock(); //ending of the operation time
   inorder(0); // call inorder function for in-order traversal
   
   printf("Total execute time : %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC); // prints executed time.

  
   return 0;
}