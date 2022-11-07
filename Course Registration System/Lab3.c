/*
 *Title: Lab Assignment #3 - Student Registration System
 *Course: CST8234 C Language
 *@Author:<<< Boyu Li >>>
 *Lab Section: 303
 *Professor: Prof. Frank Emanuel
 *Due date: 10/18/2022
 *Submission date: 10/17/2022
 *
 */

/*
 *
 *Status:
 *Requirement #1: {complete}
 *Requirement #2: {complete}
 *Requirement #3: {complete}
 *Requirement #4: {complete}
 *Requirement #5: {complete}
 *Requirement #6: {complete}
 *Requirement #7: {complete}
 *Requirement #8: {complete}
 *Requirement #9: {complete}
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Header.h"
int studentNum;
int courseNum;
char *studentsArray[1000];
char *coursesArray[1000];
int **registrationTable;
/************************************************************************************************************
 * Function Name: printInForm
 * Purpose: The function will read and print each element in the target array
 * Function in parameters: array[] - The target array needs to read and print each element
 * numbers - the length of the target array
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */


/************************************************************************************************************
 * Function Name: mains
 * Purpose: The drive class of the program
 * Function in parameters: void
 * Function out parameters: int - the number indicates the running state
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
int main()
{   
    int option, i;
    printf("Welcome to Student Registration System.\n\n");
    /*Make user input the student numbers*/
    printf("Enter the number students to register: ");
    scanf("%d", &studentNum);
    /*Invoke the method to initialize the memory */
    iniStuIDs(studentNum);
    /*Invoke the method to Register student IDs*/
    studentReg(studentNum);
    printf("\n");
    /*Make user input the course numbers*/
    printf("Enter the number of courses avaliable: ");
    scanf("%d", &courseNum);
    /*Invoke the method to intialize the memory*/
    iniCourIDs(courseNum);
    /*Invoke the method the register course IDs*/
    courseReg(courseNum);
    printf("\n");
    /*Initialize the registration table*/
    iniRegTable();
    /*Create a length for traversal*/
    const int length = courseNum * studentNum;
    /*Create a state array to hold the course state*/
    int state[1000][2];
    int n = 0;
    /*Change all the state of course to 0*/
    for (i = 0; i < length; i++)
    {
        state[i][1] = 0;
    }
    do
    {
        /*Do while to keep program loop*/
        displayMenu();
        /*Make the user input the option*/
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("List of Student Ids\n");
            printInform(studentsArray, studentNum);
            char checkedID[100];
            for (i = 1; i < 2; i++)
            {   /*Make the user enter the target student ID*/
                printf("Enter the Student's Id to register a course: ");
                char checkID[100];
                /*Invoke the method to check the entered id and make user input the id untill the correct method received*/
                scanf("%s", checkID);
                if (checkNum(checkID) == 0)
                {
                    printf("Student Id must be 5 digits\n");
                    i--;
                }
                else
                /*If it is legal, save the id*/
                {
                    strcpy(checkedID, checkID);
                }
            }
            /*Make the user enter the course Id*/
            printf("List of Available Couese Id\n");
            int target;
            printInform(coursesArray, courseNum);
            char checkedCID[100];
            for (i = 1; i < 2; i++)
            {   
                /*Invoke the method to check the entered id and make user input the id untill the correct method received*/
                printf("Enter the Student's Id to register a course: ");
                char checkCID[100];
                scanf("%s", checkCID);
                if (checkCourse(checkCID) == -1)
                {
                    printf("Incorrect Course Id length [7-character Id]\n");
                    i--;
                }
                else if (checkCourse(checkCID) == 0)
                {
                    printf("Enter the course index[%d] course id [3-Alphas][4-digits]: \n", i);
                    i--;
                }
                else if (checkCourse(checkCID) == 1)
                {   
                    /*If it is legal, save the id*/
                    strcpy(checkedCID, checkCID);
                }
            }
            /*Using a for loop to find the target's index and store it*/
            for (i = 0; i < length; i++)
            {   
                if (strcmp(studentsArray[registrationTable[i][1]], checkedID) == 0)
                {
                    if (strcmp(coursesArray[registrationTable[i][2]], checkedCID) == 0)
                    {
                        target = i;
                        break;
                    }
                }
            }
             /*Check the state of course registration in the registration table, if it has already already been dropped*/
             /*The drop will be refused*/   
            if ((registrationTable[target][3] != 1) && (state[target][1] == 1))
            {
                printf("Student id %s have dropped out from course %s.\n", studentsArray[registrationTable[target][1]], coursesArray[registrationTable[target][2]]);
                printf("Student id %s cannot regsiter to course %s.\n", studentsArray[registrationTable[target][1]], coursesArray[registrationTable[target][2]]);
                printf("Regestration Unsuccessful\n");
            }

            /*Check the state of course registration in the registration table, if it has already already on the record/
             /*The drop will be refused*/   
            else if (registrationTable[target][3] == 1)
            {
                printf("Already on record.\n");
                printf("Student id %s cannot regsiter to course %s.\n", studentsArray[registrationTable[target][1]], coursesArray[registrationTable[target][2]]);
                printf("Regestration Unsuccessful\n");
                break;
            }

            /*Check the state of course registration in the registration table, if it didn't been register then the course will be suceesfully register*/
             /*The drop will be refused*/   
            else if (registrationTable[target][3] != 1)
            {   
                /*Change the registration state in the registration table*/
                registrationTable[target][3] = 1;
                /*Change the registration state*/
                state[target][1] = 1;
                state[target][2] = n;
                n++;
                printf("Registration Successful\n");
                break;
            }
            break;
        case 2:
            /*Invoke the method to implement the course drop*/
            printRegTable(state, length, 1);
            break;
        case 3:
            /*Invoke the method to implement the table print*/
            printRegTable(state, length, 0);
            break;
        case 4:
            break;
        }
    } while (option != 4);
    /*Invoke the method to free the memeory*/
    freeMemory(length);
    printf("Exiting...\n");
    return 0;
}
