#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h> 
#include <stdlib.h>

typedef struct{
    char name[50];
    int age;
    float gpa;
}Student;//Student 

typedef enum{
    OPTION1 = 1, OPTION2, OPTION3, OPTION4
}Choice;//Organize the choices

Choice readOption(void);
int stringToInt(const char *input, int *out);
int stringToFloat(const char *input, float *out);
int checkInputInt(int *value);
int checkInputFloat(float *value);
void addStudentAge(int *age);
void addStudentGPA(float *gpa);
void addStudentName(char name[]);
void addAll(Student *student);
void showData(Student student);

//Student Management System 
int main() {
    int currentOption = 0;
    Student student1 = {0};

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
            currentOption = readOption();//Gets user input and filters it trough the function
            if(currentOption < OPTION1 || currentOption > OPTION4){
                printf("\nInvalid input!\n");
            }
        }while(currentOption < 1 || currentOption > 4);
        switch(currentOption){
            case OPTION1://Add Student
                if(student1.age == 0){
                    addAll(&student1);
                }else{
                    printf("\nYou can only add one student.\n");//If he tries to add another student shuts it down
                }
                break;
            case OPTION2://Show student data
                if(student1.age != 0){
                    showData(student1);
                }else{
                    printf("\nThere is no student data.\n");
                }
                break;
            case OPTION3://Update student data
                if(student1.age != 0){
                    do{//Sees if the option is valid
                        printf("\n1. Name\n");
                        printf("2. Age\n");
                        printf("3. GPA\n");
                        printf("4. All\n");
                        printf("What would you like to update:");
                        currentOption = readOption();
                        if(currentOption < OPTION1 || currentOption > OPTION4){//if its not repeats the loop
                            printf("\nInvalid input!\n");
                            continue;
                        }
                        }while(currentOption < OPTION1 || currentOption > OPTION4);
                        switch(currentOption){   
                            case OPTION1://Change name
                                addStudentName(student1.name);
                                break;
                            case OPTION2://Change age
                                addStudentAge(&student1.age);
                                break;
                            case OPTION3://Change gpa
                                addStudentGPA(&student1.gpa);
                                break;
                            case OPTION4://Change all
                                student1.age = 0;
                                student1.gpa = 0;
                                addAll(&student1);
                                currentOption = 0;
                                break;
                        }  
                }else{
                     printf("\nThere is no data do update.\n");
                }
                break;
        }

    }while(currentOption != OPTION4);
    return 0;
}

Choice readOption(void){
    int temp;
    checkInputInt(&temp);
    if (temp >= OPTION1 && temp <= OPTION4){
        return (Choice)temp;
    }else{
        return 0;
    }
}

int stringToFloat(const char *input, float *out){
    char *end;
    errno = 0;
    float value = strtof(input, &end);

    if(end == input){//Checks if the string starts with a number
        return 0;
    }
    if(*end != '\0'){//checks if there is nothing after the numbers
        return 0;
    }
    if(errno == ERANGE){//Checks overflow
        return 0;
    }
    if(value < 0.0f || value > 5.0f){//Checks if its in the allowed range
        return 0;
    }
    *out = (float)value;
    return 1;
}

int stringToInt(const char *input, int *out){
    char *end;
    errno = 0;
    long value = strtol(input, &end, 10);

    if(end == input){//Checks if the string starts with a number
        return 0;
    }
    if(*end != '\0'){//checks if there is nothing after the numbers
        return 0;
    }
    if(errno == ERANGE){//Checks overflow
        return 0;
    }
    if(value < INT_MIN || value > INT_MAX){//Checks if the conversion to int is possible
        return 0;
    }
    *out = (int)value;//converts it to an int 
    return 1;
}

void addAll(Student *student){
    addStudentName(student->name);
    addStudentAge(&student->age);
    addStudentGPA(&student->gpa);
}

void addStudentName(char name[]){
    bool hasDigit = true;

    while(hasDigit == true){
        printf("\nEnter the student's name: ");//Prompts for the name              
        //Read input as a string
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = '\0';
        for(int i = 0; name[i]; i++){//iterates trough the string and sees if it has any integers
            if(isdigit((unsigned char)name[i])){
                printf("\nInvalid input!\n");
                break;
            }else{
                if(i == strlen(name) - 1){//if it doesnt it breaks out of the loops
                    hasDigit = false;
                    break;
                }
            }
        }
        }
    }

void showData(Student student){
    printf("\nStudent's name: %s\n", student.name);//Prints name
    printf("Student's age: %d\n", student.age);//Prints age
    printf("Student's GPA: %.2f\n", student.gpa);//Prints age
}

void addStudentGPA(float *gpa){
    *gpa = 0;
    //Gets the gpa and checks if the input is valid
    do{
        printf("\nEnter the student's gpa: ");
        checkInputFloat(gpa);
        if(*gpa < 1){
            printf("\nInvalid input!\n");
            continue;
        }
    }while(*gpa < 0.1f || *gpa > 5.0f);  
}

void addStudentAge(int *age){
    *age = 0;
    //Gets the age and checks if the input is valid
    do{
        printf("\nEnter the student's age: ");
        checkInputInt(age);
        if(*age < 1 ){
            printf("\nInvalid input!\n");
        }
    }while(*age < 1);    
}

int checkInputFloat(float *value){
    char input[50];

    //Read input as a string
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
    if(stringToFloat(input, value)){
        return 1;
    }
    return 0;
}

int checkInputInt(int *value){
    char input[50];

    //Read input as a string
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
    if(stringToInt(input, value) != 1){
        return 0;
    }  
    
}