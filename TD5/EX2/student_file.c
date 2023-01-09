#include "student_file.h"

void printStudent(Student *s)
{
    printf("Student-\n FirstName: %s\nLastname: %s\nAge: %d\nHeight: %.2f\n", s->fstName, s->lstName, s->age,s->height);
}


int addStudent(Student **newStudent, char *fstName, char *lstName, int age, float height){
    *newStudent = (Student*)malloc(sizeof(Student));
    if(*newStudent == NULL){
        return -1;
    }
    (*newStudent)->fstName = (char*)malloc(sizeof(char)*(strlen(fstName)+1));
    (*newStudent)->fstName = (char*)malloc(sizeof(char)*strlen(fstName));
    (*newStudent)->lstName = (char*)malloc(sizeof(char)*strlen(lstName));
    strcpy((*newStudent)->fstName, fstName);
    strcpy((*newStudent)->lstName, lstName);
    (*newStudent)->age = age;
    (*newStudent)->height = height;

    return 0;
    
}
void deleteStudent(Student **s){
    if(*s != NULL){
        free((*s)->fstName);
        free((*s)->lstName);
        free(*s);
        *s = NULL;
    }
}
void check_argv(int argc, char *argv[], int *numStudents, char *printOrder, char *order){
    if (argc <2){
        printf("Usage: %s <numStudents> <printOrder (D- Desc  A- Asc)> <by H- Height A-age F- FirstName L- LastName >\n", argv[0]);
        exit(1);
    }

    if (argc == 2){
        *numStudents = atoi(argv[1]);
        strcpy(printOrder, "A");
        strcpy(order, "F");
    }
    else if (argc == 3){
        *numStudents = atoi(argv[1]);
        strcpy(printOrder, argv[2]);
        strcpy(order, "F");
    }
    else if (argc == 4){
        *numStudents = atoi(argv[1]);
        strcpy(printOrder, argv[2]);
        strcpy(order, argv[3]);
    }
    else{
        
        exit(1);
    }
}
int compareFstName(const void *s1, const void *s2){

    Student *student1 = (Student*)s1;
    Student *student2 = (Student*)s2;

    return strcmp(student1->fstName, student2->fstName);

}
int compareLstName(const void *s1, const void *s2){
    
        Student *student1 = (Student*)s1;
        Student *student2 = (Student*)s2;
    
        return strcmp(student1->lstName, student2->lstName);
    
}
int compareAge(const void *s1, const void *s2){
        
    Student *student1 = (Student*)s1;
    Student *student2 = (Student*)s2;
        
    return student1->age - student2->age;
        
}
int compareHeight(const void *s1, const void *s2){
        
    Student *student1 = (Student*)s1;
    Student *student2 = (Student*)s2;

    if (student1->height < student2->height)
        return -1;
    return(student1->height > student2->height);
        
}


void sortStudentsBy(Student **s,char *field){
    if(strcmp(field,"F") == 0){
        qsort(*s, sizeof(Student), sizeof(Student), compareFstName);
    }
    else if(strcmp(field,"L") == 0){
        qsort(*s, sizeof(Student), sizeof(Student), compareLstName);
    }
    else if(strcmp(field,"A") == 0){
        qsort(*s, sizeof(Student), sizeof(Student), compareAge);
    }
    else if(strcmp(field,"H") == 0){
        qsort(*s, sizeof(Student), sizeof(Student), compareHeight);
    }
}



    