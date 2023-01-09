#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct Student{
    char *fstName;
    char *lstName;
    int age; 
    float height; 
} Student ;



void printStudent(Student *s);
void deleteStudent(Student **s);
void sortStudentsBy(Student **s,char *field);
void check_argv(int argc, char *argv[], int *numStudents, char *printOrder, char *order);

int  addStudent(Student **newStudent, char *fstName, char *lstName, int age, float height);
int compareFstName(const void *s1, const void *s2);
int compareLstName(const void *s1, const void *s2);
int compareHeight(const void *s1, const void *s2);
int compareAge(const void *s1, const void *s2);


