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
extern int studentNum;
extern int courseNum;
extern char *studentsArray[1000];
extern char *coursesArray[1000];
extern int **registrationTable;
void printInform(char *array[], int length);
void cutZero(char array[]);
int checkNum(char id[]);
void studentReg(int studentNums);
int checkCourse(char coursID[]);
void courseReg(int courseNums);
void iniStuIDs(int stuNum);
void iniCourIDs(int coursNum);
void displayMenu();
void iniRegTable();
void printRegTable(int state[][2], int length, int purpose);
void freeMemory(int length);