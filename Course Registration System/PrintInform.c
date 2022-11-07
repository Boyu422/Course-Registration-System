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
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Header.h"
/************************************************************************************************************
 * Function Name: printInForm
 * Purpose: The function will cut the head and end zero of a string variable
 * Function in parameters: array[] - The target array needs to be cut zero at head and end
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
void printInform(char *array[], int length)
{   
    int i;
    for (i = 0; i < length; i++)
    {
        printf("index %d        %s\n", i, array[i]);
    }
}

/************************************************************************************************************
 * Function Name: displayMenu
 * Purpose: The function will print the user menu to the screen
 * Function in parameters: void
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */

void displayMenu()
{
    printf("Main Menu\n");
    printf(" [1] Register a student into a course.\n");
    printf(" [2] Drop a student from a course.\n");
    printf(" [3] Display Registration table.\n");
    printf(" [4] Exit.\n");
    printf(" Enter an option from the menu: ");
}



/************************************************************************************************************
 * Function Name: printRegTable
 * Purpose: The function will free all the memory that author assigned
 * Function in parameters: state[] - the array that hold the course registration state
 * length - the length of the registration table
 * purpose - the "boolean" indicates the purpose of the method, 0 indicates it only prints the table
 * 1 indicates it will make the user drop the course after printing the table
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
void printRegTable(int state[][2], int length, int purpose)
{   
    int i;
    int j;
    int index = 0;
    int drop = 0;
    char dropState = 'D';
    char regState = 'R';
    /*Print the table head at first*/
    printf("\n");
    printf("                            Registration Table\n");
    printf("Registration index          Student ID      CouseID     Registration Status\n");
    /*Use a nested for loop to read each value in the registrationTable*/
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        /*if the student registered in course also the index follow the correct order, then and print out the information*/
        {
            if (registrationTable[j][3] == 1 && state[j][2] == index)
            {
                printf("       %d                    %s           %s      %c\n", index, studentsArray[registrationTable[j][1]], coursesArray[registrationTable[j][2]], regState);
                index++;
            }
            /*if the student registered in course and dropped also the index follow the correct order, then and print out the information*/
            else if (registrationTable[j][3] == 0 && state[j][2] == index && state[j][1] == 1)
            {
                printf("       %d                    %s           %s      %c\n", index, studentsArray[registrationTable[j][1]], coursesArray[registrationTable[j][2]], dropState);
                index++;
            }
        }
    }
    /*If the user wants to drop a course, then go to the below steps */
    if (purpose == 1)
    {
        /*Initialize the index for user choice*/
        index = 0;
        /*Make the user input the index*/
        printf("Please select Index number to drop student registration:  ");
        scanf("%d", &drop);
        /*Use the for loop to find the correct element and then change the state*/
            for (i = 0; i < length; i++){
            for (j = 0; j < length; j++)
            {
                /*if the student registered in course also the index follow the correct order,then increment index*/
                if ((registrationTable[j][3] == 1 && state[j][2] == index) || (registrationTable[j][3] == 0 && state[j][2] == 1))
                {
                    index++;
                }
                /*If the drop index found, then change the state to*/
                if (drop == index - 1)
                {
                    registrationTable[j][3] = 0;
                    break;
                }
            }
            }
            /*Prompt the user and print the table again*/
        printf("Drop course successful.\n");
        printRegTable(state, length, 0);
    }
}
