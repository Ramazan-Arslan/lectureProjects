// Ramazan Arslan - 250201023
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <syslog.h>
#include <netinet/in.h>

void* thread_proc(void *arg);

// deamonizing function
void deamonize()
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

    if (pid > 0)
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
    openlog ("second", LOG_PID, LOG_DAEMON);
}

 main(int argc, char *argv[]) // main function
{
    deamonize();

    while (1)
    {
        struct sockaddr_in sAddr;
        int listensock;
        int result;
        int nchildren = 1;
        pthread_t thread_id;
        int x;
        int val;

        if (argc > 1) {
            nchildren = atoi(argv[1]);
        }

        listensock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        val = 1;
        result = setsockopt(listensock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        
        if (result < 0) {
            perror("The second server");
            return 0;
        }

        sAddr.sin_family = AF_INET;
        sAddr.sin_port = htons(1972);
        sAddr.sin_addr.s_addr = INADDR_ANY;

        result = bind(listensock, (struct sockaddr *) &sAddr, sizeof(sAddr));
        
        if (result < 0) {
            perror("The second server");
            return 0;
        }

        result = listen(listensock, 5);
        
        if (result < 0) {
            perror("The second server");
            return 0;
        }

        for (x = 0; x < nchildren; x++) {
            result = pthread_create(&thread_id, NULL, thread_proc,
            (void *)(intptr_t)listensock);
            if (result != 0) {
                printf("Could not create thread.\n");
            }
            sched_yield();
        }
        pthread_join (thread_id, NULL);

        syslog (LOG_NOTICE, "The  second server daemonizing started.");
        sleep (20);
        break;
    }

    syslog (LOG_NOTICE, "The second server daemonizing terminated.");
    closelog();

    return EXIT_SUCCESS;
}

void* thread_proc(void *arg)
{
    int listensock, sock;
    char buffer[25];
    int nread;
    listensock = (intptr_t) arg;
    
    while (1) {
        sock = accept(listensock, NULL, NULL);
        printf("Client connected to child thread %lu with pid %i.\n",
        pthread_self(), getpid());
        nread = recv(sock, buffer, 25, 0);
        buffer[nread] = '\0';
        printf("%s\n", buffer);
        send(sock, buffer, nread, 0);
        close(sock);
        printf("Client disconnected from child thread %lu with pid %i.\n",
        pthread_self(), getpid());
    }
}
