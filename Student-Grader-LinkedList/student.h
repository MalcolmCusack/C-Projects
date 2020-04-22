typedef struct {
	
	char last[20];	//last name

	char first[20];	//first name

	double grade;	//number grade

	char letter[5];	//letter grade

	char curved;	//if the grade was curved
} Student_t;

typedef struct {
	
    	char letter[3];	//letter grade

    	double lower_limit; //lower limit of numerical grade
} Grade_t;

typedef struct node_t {

	Student_t* stu; // the student thats contained in a node

	struct node_t *next; //linker of the list
} Node_t;
	

void ReadGrades(FILE *inp, Node_t**);

void ListInsert( Node_t**, Student_t*);

void CalculateLetterGrade(Node_t**);

void PrintGrades(Node_t**);

void SortGrades(Node_t**);
