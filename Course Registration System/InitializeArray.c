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
 * Function Name: iniStuIDs
 * Purpose: The function will initialize the student IDs
 * Function in parameters: stuNum - the number of students need to be initialized
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
void iniStuIDs(int stuNum)
{ 
    int i;
    for (i = 0; i < stuNum; i++)
    /*Intialize each char array in the studentArray by malloc*/
    {
        studentsArray[i] = (char *)malloc(sizeof(char) * 4);
    }
}

/************************************************************************************************************
 * Function Name: iniCourIDs
 * Purpose: The function will initialize the course IDs
 * Function in parameters: stuNum - the number of courses need to be initialized
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
void iniCourIDs(int coursNum)
{
    int i;
    for (i = 0; i < coursNum; i++)
    /*Intialize each char array in the courseArray by malloc*/
    {
        coursesArray[i] = (char *)malloc(sizeof(char) * 9);
    }
}

/************************************************************************************************************
 * Function Name: iniRegTable
 * Purpose: The function will initialize the student registration table
 * Function in parameters: void
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
void iniRegTable()
{
    int i;
    int j;
    /*First to define the number of the index*/
    int index = studentNum * courseNum;
    registrationTable = (int **)malloc(sizeof(int *) * index);
    /*intialize each value in the registrationTable by malloc*/
    for (i = 0; i < index; i++)
    {
        registrationTable[i] = (int *)malloc(sizeof(int) * 3);
    }
    index = 0;
    /*Fill the registrationTable with the default value*/
    for (i = 0; i < studentNum; i++)
    {
        for (j = 0; j < courseNum; j++)
        {
            registrationTable[index][1] = i;
            registrationTable[index][2] = j;
            registrationTable[index][3] = 0;
            index++;
        }
    }
}

/************************************************************************************************************
 * Function Name: freeMemory
 * Purpose: The function will free all the memory that author assigned
 * Function in parameters: void
 * Function out parameters: length - the length of the student registration table
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
void freeMemory(int length)
{
    /*Free each char array in the studentArray*/
    int i;
    for (i = 0; i < studentNum; i++)
    {
        free(studentsArray[i]);
    }
    /*Free each char array in the courseArray*/
    for (i = 0; i < courseNum; i++)
    {
        free(coursesArray[i]);
    }
    /*Free each element in the registrationTable*/
    for (i = 0; i < length; i++)
    {
        free(registrationTable[i]);
    }
    free(registrationTable);
}