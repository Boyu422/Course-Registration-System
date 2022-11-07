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
 * Function Name: cutZero
 * Purpose: The function will cut the head and end zero of a string variable
 * Function in parameters: array[] - The target array needs to be cut zero at head and end
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
void cutZero(char array[])
{   
    /* Get the length of the target array to control the loop times*/
    int length = strlen(array);
    /* Create a temp array to make the actual array not involve in calculation*/
    char tempArray[100];
    int i;
    /* For loop to read each element in the target array and cut the head zero*/
    /*It will read at the start of the target array*/
    for (i = 0; i < length; i++)
    {
        if (array[i] != '0')
        {
             /*Once the not zero value found, use the strncpy method to cut the head 0*/
            strncpy(tempArray, array + i, length - i);
             /*Copy the cutted array to the actual array*/
            strcpy(array, tempArray);
            /*Change the array end with termination symbol*/
            array[length - i] = '\0';
            /*Change the length of the array*/
            length = length - i;
            break;
        }
    }

    /* For loop to read each element in the target array and cut the end zero*/
    /* This time the for will start to read at end of the target array*/
    for (i = length - 1; i >= 0; i--)
    {
        /*Once the not zero value found, use the strncpy method to cut the end 0*/
        if (tempArray[i] != '0')
        {
            /*Once the not zero value found, use the strncpy method to cut the end 0*/
            strncpy(tempArray, array, i + 1);
            /*Copy the cutted array to the actual array*/
            strcpy(array, tempArray);
            /*Change the array end with termination symbol*/
            array[i + 1] = '\0';
            /*Change the length of the array*/
            length = i + 1;
            break;
        }
    }
}

/************************************************************************************************************
 * Function Name: checkNum
 * Purpose: The function will check if the student id is legal
 * Function in parameters: id[] - The target student id needs to be checked
 * Function out parameters: The number indicates if the course id is legal
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
int checkNum(char id[])
{   
    int i;
    /*Get the length of the target studentId*/
    int length = strlen(id);
    /*If the length is not 5, then return error code and end the program*/
    if (length != 5)
        return 0;
    for (i = 0; i < length; i++)
    {
    /*If the character found, then return error code and end the program*/
        if (!isdigit(id[i]))
            return 0;
    }
    /*If no problem, the program will return success code*/
    return 1;
}

/************************************************************************************************************
 * Function Name: studentReg
 * Purpose: The function will make the user register the student ID
 * Function in parameters: studentNums - the number of student that needs to be registered
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
void studentReg(int studentNums)
{   
    int i;
    /*Make the user input the student ID based on the spcified student number*/
    for (i = 0; i < studentNums; i++)
    {
        printf("Enter the student index[%d] student id [5-digits]: ", i);
        /*Intialize a new student ID and make user input it*/
        char newStudentID[20];
        scanf("%s", newStudentID);
        /*Invoke the method to cut the zero*/
        cutZero(newStudentID);
        /*Validate the studentID*/
        if (checkNum(newStudentID) == 0)
        {   
            /*If it is illegal, than output the error message and make the user input again*/
            printf("Student ID must be 5 digits\n");
            i--;
        }
        else
        {   
            /*If it is legal, take the string into array*/
            strncpy(studentsArray[i], newStudentID, 5);
        }
    }
}

/************************************************************************************************************
 * Function Name: checkCourse
 * Purpose: The function will check the courseID
 * Function in parameters: studentNums - the number of student that needs to be registered
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
int checkCourse(char coursID[])
{   
    int i;
    /*First check the length of the course ID*/
    if (strlen(coursID) != 7)
    /*If it is wrong, then return the error code -1*/
        return -1;
    /*Then check the first three character*/
    for (i = 0; i < 3; i++)
    {
     /*If the no character stuff found, then return the error code 0*/   
        if (!isalpha(coursID[i]))
            return 0;
    }
    for (i = 3; i < 7; i++)
    {
        /*If the no digits stuff found,then return error code 0*/
        if (!isdigit(coursID[i]))
            return 0;
    }
    /*If it is legal, reutrn success code 0*/
    return 1;
}

/************************************************************************************************************
 * Function Name: courseReg
 * Purpose: The function will make the user to register the course(s)
 * Function in parameters: courseNums - the number of courses need to be checked
 * Function out parameters: void
 * Version:1
 * Author: Boyu Li
 ************************************************************************************************************
 */
void courseReg(int courseNums)
{
    int i;
    /*Make the user input the course code based on the specific course numbers*/
    for (i = 0; i < courseNums; i++)
    {   
        printf("Enter the course index[%d] course id [3-Alphas][4-digits]: ", i);
        /*Create a courseID and make the user input*/
        char newCourseID[20];
        scanf("%s", newCourseID);
        /*If the error code -1 found, then prompt the user and make the user input again*/
        if (checkCourse(newCourseID) == -1)
        {
            printf("Incorrect Course Id length [7-character Id]\n");
            i--;
        }
        /*If the error code 0 found, then prompt the user and make the user input again*/
        else if (checkCourse(newCourseID) == 0)
        {
            printf("Inccorect Course Id input [3-Alphas][4-digits]\n");
            i--;
        }
        /*If the input is legal, then put it into the course array*/
        else
        {
            strncpy(coursesArray[i], newCourseID, 7);
        }
    }
}