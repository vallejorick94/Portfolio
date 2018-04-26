
#include <stdio.h>

struct HealthProfile{
    char fName[30];
    char lName[30];
    char gender;
    int day, month, yearOfBirth;
};

    void getInput(struct HealthProfile *ptr);
    int calcAge(int birthYear);
    void print(struct HealthProfile *ptr);

    int main(){
        struct HealthProfile health1;
        struct HealthProfile *ptr = &health1;
        getInput(ptr);
        print(ptr);
        return 0;
    }

    void getInput(struct HealthProfile *ptr){
        //First Name
        printf("Enter the following -\n");
        printf("\t First Name: ");
        scanf("%s", ptr->fName);
        //Last Name
        printf("\t Last Name: ");
        scanf("%s", ptr->lName);
        //Gender
        getchar(); 
        printf("\t Gender(M/F): ");
        scanf("%c", &ptr->gender);
        //DOB
        printf("\t Date of Birth(MM DD YYYY): ");
        scanf("%d %d %d", &ptr->month, &ptr->day, &ptr->yearOfBirth);
    }

    int calcAge(int birthYear){
        return 2018 - birthYear;//did not figure out how to have correct age if their birthday is after today
    }

    void print(struct HealthProfile *ptr){
        int age = calcAge(ptr->yearOfBirth);
  
        printf("The person's info is this - \n");
        printf("Name: %s %s\n", ptr->fName, ptr->lName);
        printf("Gender: %c\n", ptr->gender);
        printf("Date of Birth: %d/%d/%d\n", ptr->month, ptr->day, ptr->yearOfBirth );
        printf("Age: %d\n",age);
    }


