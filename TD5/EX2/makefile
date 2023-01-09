all: student_file.o main.o
	gcc -o student_file.o main.o -o stu -Wall

student_file.o: student_file.c student_file.h
	gcc -c student_file.c

main.o: main.c student_file.h
	gcc -c main.c
