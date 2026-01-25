#include <stdio.h>
#include <string.h>

int checkInput();
void addStudentAge(int *age);
void showData(char name[], int age);
void addStudentName(char name[]);
void addBoth(char name[], int *age);

//Student Management System
int main() {
    int currentOption = 0;
    int studentAge = 0;
    char studentName[50];

    printf("*** Student Management System ***\n");

    //Loops if its the user didnt select exit
    do{
        //Loops if is not a 1 - 4 number
        do{
            printf("\n1. Add student\n");
            printf("2. Show student data\n");
            printf("3. Update student data\n");
            printf("4. Exit\n");
            printf("Choose an option: ");
            currentOption = checkInput();//Gets user input and filters it trough the function
            if(currentOption < 1 || currentOption > 4){
                printf("\nInvalid input!\n");
            }
        }while(currentOption < 1 || currentOption > 4);
        switch(currentOption){
            case 1://Add Student
                if(studentAge == 0){
                    addBoth(studentName, &studentAge);
                }else{
                    printf("\nYou can only add one student.\n");//If he tries to add another student shuts it down
                }
                break;
            case 2://Show student data
                if(studentAge != 0){
                    showData(studentName, studentAge);
                }else{
                    printf("\nThere is no student data.\n");
                }
                break;
            case 3://Update student data
                if(studentAge != 0){
                    currentOption = 0;
                    while(currentOption < 1 || currentOption > 3){//Sees if the option is valid
                        printf("\nWould you like to update the:\n");
                        printf("1. Name\n");
                        printf("2. Age\n");
                        printf("3. Both\n");
                            currentOption = checkInput();
                        if(currentOption < 1 || currentOption > 3){//if its not repeats the loop
                            printf("\nInvalid input!\n");
                            continue;
                        }
                        switch(currentOption){
                            case 1://Change name
                                addStudentName(studentName);
                                break;
                            case 2://Change age
                                addStudentAge(&studentAge);
                                break;
                            case 3://Change both
                                addBoth(studentName, &studentAge);
                                break;
                        }
                    }   
                }else{
                     printf("\nThere is no data do update.\n");
                }
                break;
        }

    }while(currentOption != 4);
    return 0;
}

void addBoth(char name[], int *age){
    addStudentName(name);
    addStudentAge(age);
}

void addStudentName(char name[]){
    printf("\nEnter the student's name: ");//Prompts for the name
    fgets(name, 50, stdin);//Gets name
    if(name[strlen(name) - 1] == '\n'){
        name[strlen(name) - 1] = '\0';//Gets rid of \n at the end
    }                
}

void showData(char name[], int age){
    printf("\nStudent's name: %s\n", name);//Prints name
    printf("Student's age: %d\n", age);//Prints age
}

void addStudentAge(int *age){
    //Gets the age and checks if the input is valid
    do{
        printf("\nEnter the student's age: ");
        *age = checkInput();
        if(*age < 1){
            printf("\nInvalid input!\n");
        }
    }while(*age < 1);    
}

int checkInput(){
    int number = 0;//Variable to store the user's number
    int inNumber;//Stores the number that are inside de input
    char input[100] = "";//Buffer to hold user input as a string
    char extra;//Variable to check extra letters 

    //Read input as a string
    fgets(input, sizeof(input), stdin);
    //Check inside of input to see if there is a integer
    if(sscanf(input, "%d %c", &inNumber, &extra) == 1){
        number = inNumber;//Changes the number for the value on the string  
        return number;//Returns number      
    }else{
        return 0;
    }
    
}