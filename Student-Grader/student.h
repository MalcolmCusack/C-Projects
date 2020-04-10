typedef struct {
	
	char last[20];	//last name

	char first[20];	//first name

	double grade;	//number grade

	char letter[5];	//letter grade

	char curved;	//if the grade was curved
} Student_t;

int ReadGrades(FILE *inp, Student_t class[]);

void CalculateLetterGrade(Student_t class[], int size);

void PrintGrades(Student_t class[], int size);
