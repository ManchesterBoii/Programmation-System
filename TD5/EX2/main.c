//#include "student_file.h"
#include "student_file.c"


int main(int argc, char *argv[])
{
    int numStudents;
    char printOrder;
    char order;

    int age;
    float height;
    char * lastname;
    char * firstname;

    
    check_argv(argc, argv, &numStudents, &printOrder, &order);

    Student *students = (Student*)malloc(numStudents * sizeof(Student));


    for(int i = 0; i < numStudents; i++)
    {
        printf("Enter student %d information:\n", i+1);
        printf("Firstname: ");
        scanf("%s", firstname);
        printf("Lastname: ");
        scanf("%s", lastname);
        printf("Age: ");
        scanf("%d%*c", &age);
        printf("Height: ");
        scanf("%f%*c", &height);

        addStudent(&students[i], firstname, lastname, age, height);
    }


    sortStudentsBy(&students,&order);

    if(strcmp(printOrder, 'A')){

        for(int i = 0; i < numStudents; i++)
        {
            printStudent(&students[i]);
        }
    }
    else if(strcmp(printOrder, 'D' ))
    {
        for(int i = numStudents - 1; i >= 0; i--)
        {
            printStudent(&students[i]);
        }
    }
    else
    {
        printf("Invalid print order.\n");
    }

    for (int i = 0; i < numStudents; i++)
    {
        deleteStudent(&students[i]);
    }
    free(students);

    return 0;
}
    


