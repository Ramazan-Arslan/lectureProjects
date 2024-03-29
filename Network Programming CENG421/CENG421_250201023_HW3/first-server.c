// Ramazan Arslan - 250201023
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <syslog.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdlib.h>

// server1.c from textbook:
void* thread_proc(void *arg);

// deamonizing function
void daemonize()
{
    pid_t pid;
    pid = fork();

    if (pid < 0)
        exit(EXIT_FAILURE);

    else if (pid > 0)
        exit(EXIT_SUCCESS);
 
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    pid = fork();
 
    if (pid < 0)
        exit(EXIT_FAILURE);
    
    else if (pid > 0)
        exit(EXIT_SUCCESS);

    umask(0);

    chdir("/");

    /* Closes all open file descriptors */
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
    {
        close (x);
    }

    /* opens the log file */
    openlog ("first", LOG_PID, LOG_DAEMON);
}

int main(int argc, char *argv[])
{ 	
	daemonize();

	while (1)
    {
    struct sockaddr_in sAddr;
	int listensock;
	int newsock;
	int result;
	pthread_t thread_id;
	int val; 

	listensock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	val = 1;
	result = setsockopt(listensock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	
	if (result < 0) {
		perror("The first server");
		return 0;
	}

	sAddr.sin_family = AF_INET;
	sAddr.sin_port = htons(1972);
	sAddr.sin_addr.s_addr = INADDR_ANY;
	
	result = bind(listensock, (struct sockaddr *) &sAddr, sizeof(sAddr));
	
	if (result < 0) {
		perror("The first server");
		return 0;
	}

	result = listen(listensock, 5);
	
	if (result < 0) {
		perror("The first server");
		return 0;
	}

	while (1) {
		newsock = accept(listensock, NULL,NULL);
		result = pthread_create(&thread_id, NULL, thread_proc, (void *) (intptr_t) newsock);
		if (result != 0) {
			printf("Could not create thread.\n");
		}

		pthread_detach(thread_id);
		sched_yield();
	}
	
        syslog (LOG_NOTICE, "The First server daemonizing started.");
        sleep (20);
        break;
    }

    syslog (LOG_NOTICE, "The first server daemonizing terminated.");
    closelog();

    return EXIT_SUCCESS;
}

void* thread_proc(void *arg)
{
	int sock;
	char buffer[25];
	int nread;
	printf("Child thread %lu with pid %i created.\n", pthread_self(), getpid());
	sock = (intptr_t) arg;
	nread = recv(sock, buffer, 25, 0);
	buffer[nread] = '\0';
	printf("%s\n", buffer);
	send(sock, buffer, nread, 0);
	close(sock);
	printf("Child thread %lu with pid %i finished.\n", pthread_self(), getpid());
}

