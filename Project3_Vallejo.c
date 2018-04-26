#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/* This is our thread function.  It is like main(), but for a thread */
void *threadFunc(void *arg)
{
    int flag = 0;
	// Store the value argument passed to this thread
    int *myid = (int *)arg;
    // Print the argument
    printf("Thread with ID = %d in critical section and placed the prime number:\n", *myid);
    
    if(*myid == 0){
        srand(time(NULL));   // should only be called once
        int r = rand() % 500;
        //printf("%d\n", r);
        
            for (int j = 2; j <= r / 2; j++){
                if ((r % j) == 0){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                printf("%d is a prime number \n", r);
            }
            else{
                printf("%d is not a prime number \n", r);
                r++;
                if ((r % 2) == 1){
                    printf("%d is prime\n", r);
                }
            }
    }
    if(*myid == 1){
        srand(time(NULL));   // should only be called once
        int r2 = (rand() % (2000 + 1 - 1000) + 1000);
        //printf("%d\n", r2);
        
            for (int j = 2; j <= r2 / 2; j++){
                if ((r2 % j) == 0){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                printf("%d is a prime number \n", r2);
            }
            else{
                printf("%d is not a prime number \n", r2);
                //r2++;
                //if ((r2 % 2) == 1){
                 //   printf("%d is prime\n", r2);
                }
    }
    if(*myid == 2){
        srand(time(NULL));   // should only be called once
        int r3 = rand() % (20000 + 1 - 10000) + 10000;
        //printf("%d\n", r3);
        
            for (int j = 2; j <= r3 / 2; j++){
                if ((r3 % j) == 0){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                printf("%d is a prime number \n", r3);
            }
            else{
                printf("%d is not a prime number \n", r3);
                r3++;
                //if ((r3 % 2) == 1){
                 //  printf("%d is prime\n", r3);
            }
    }
    if(*myid == 3){
        srand(time(NULL));   // should only be called once
        int r4 = rand() % (60000 + 1 - 50000) + 50000;
        //printf("%d\n", r4);
        
            for (int j = 2; j <= r4 / 2; j++){
                if ((r4 % j) == 0){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                printf("%d is a prime number \n", r4);
            }
            else{
                printf("%d is not a prime number \n", r4);
                r4++;
                //if ((r4 % 2) == 1){
                //printf("%d is prime\n", r4);
            //}
            }
    }
}

int main(void)
{
	pthread_t tid;	//thread identifier
	int i;

	/* Create 4 threads */
	for (i = 0; i < 4; i++){
	    pthread_create(&tid, NULL, threadFunc, (void *)&i);
        sleep(1);
	}
    pthread_exit(NULL);
	return 0;
}