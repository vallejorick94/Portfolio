#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main() { 
    FILE *filePtr; // filePtr = input.txt file pointer
    double sum = 0. , mean = 0, tmp = 0;
    int i = 0;
    
   // fopen opens file; exits program if file cannot be opened 
   if ((filePtr = fopen("input.txt", "r")) == NULL) {
      puts("File could not be opened");
   } 
   else { // file opened successfully
	  int number;   // store the integer read from the input.txt

        while(fscanf(filePtr, "%lf", &tmp) != EOF) {
            sum += tmp;
            ++ i;
        }
        
        mean = sum / i;
    // make two process which run same
    // program after this instruction
    // while not end of file
        while (!feof(filePtr)) { 
            fscanf(filePtr, "%d", &number);
		    //printf("%d ", number);
        } 
        printf("\n");
   } 
    pid_t returnValue = fork();
    if (returnValue == 0){
        pid_t returnVal2 = fork();
        if(returnVal2 == 0){
            printf("\nchild process 1 pid is %d and parent process is 4\n", getpid());
            //srand(time(NULL));
            int j = 0;
            while(j < 20){
                int random = rand() % (100) + 100;
                printf ("%d ", random);
                j++;
            }
        }
        else{
            wait(NULL);
            printf("child process 2 pid is %d and parent process is 4\n", getpid());
            int arr[13] = {23, 4, 51, 56, 47, 87, 25, 84, 94, 32, 12, 80, 67};
            int total, loop;
            float avg;
            total = avg = 0;
            for(loop = 0; loop < 13; loop++){
                total = total + arr[loop];
            }
            avg = (float)total / loop;
            printf("Average is %.2f", avg);
        }
        
    }
    else{
	    wait(NULL);
        pid_t returnVal2 = fork();
        if(returnVal2 == 0){
            printf("child process 3 pid is %d \n", getpid());
            int random2 = rand() % (100) + 400;
            printf("%d \n", random2);
            int mult = 19;
            while(mult < random2){
                printf("%d ", mult);
                mult += 19;
            }
        }
        else{
            wait(NULL);
            printf("\nparent pid is %d  \n", getpid());
            printf("Average is %d ", mean);
            
        }
    }
    fclose(filePtr); // fclose closes the file   
	return 0;
}