pgm1: main.o ReadGrades.o CalculateLetterGrade.o PrintGrades.o
	gcc -o pgm1 -Wall  main.o ReadGrades.o CalculateLetterGrade.o PrintGrades.o

main.o: main.c student.h
	gcc -c -Wall main.c

ReadGrades.o: ReadGrades.c student.h
	gcc -c -Wall ReadGrades.c

CalculateLetterGrade.o: CalculateLetterGrade.c student.h
	gcc -c -Wall CalculateLetterGrade.c

PrintGrades.o: PrintGrades.c student.h
	gcc -c -Wall PrintGrades.c
