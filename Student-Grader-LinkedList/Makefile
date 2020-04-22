pgm1: main.o ReadGrades.o CalculateLetterGrade.o PrintGrades.o SortGrades.o ListInsert.o
	gcc -o pgm1 -Wall  main.o ReadGrades.o CalculateLetterGrade.o PrintGrades.o SortGrades.o ListInsert.o

main.o: main.c student.h
	gcc -c -Wall main.c

ReadGrades.o: ReadGrades.c student.h
	gcc -c -Wall ReadGrades.c

CalculateLetterGrade.o: CalculateLetterGrade.c student.h
	gcc -c -Wall CalculateLetterGrade.c

PrintGrades.o: PrintGrades.c student.h
	gcc -c -Wall PrintGrades.c

SortGrades.o: SortGrades.c student.h
	gcc -c -Wall SortGrades.c

ListInsert.o: ListInsert.c student.h
	gcc -c -Wall ListInsert.c
