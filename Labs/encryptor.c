#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The encrypt function that will output encrpyed chars from one file to another file.
// Passing in a key string, current line string and the output file. 
void encrypt(char key[], char *line, FILE *outp);

int main(void) {
	//variables, files being opened
	FILE *inp = fopen("/public/examples/lab6/tinyTale.txt", "r");
	FILE *outp = fopen("encryption.txt", "w");
	char key[27] = "efghijklmnopqrstuvwxyzabcd";
	char data[200];
	
	// Makes sure that the file I want to read strings from exsists.
	if ((inp = fopen("/public/examples/lab6/tinyTale.txt", "r")) == NULL) {
        printf("Error");
        exit(-1);
    	}
	
	// Loops through the file. After every line the line is printed to the out file.
	// The line is passed to the encrypt function too.
    	while(fgets(data, 100, inp)) {

		fprintf(outp, "%s", data);
		encrypt(key, data, outp);
	}
	
	// Closing the files
   	fclose(inp);
    	fclose(outp);

    	return(0);
}

void encrypt(char key[], char *line, FILE *outp) {
	
	// This loop looks at each char in the string line. 
	// if the char is a - z (97 - 122), I print that encrypted char to the out file.
	// else I just print what char is in the line to the out file.
	// To encrypt you take the key string char index which is the char line is at subtracted by 'a'. 
	for (int i = 0; i < strlen(line); i++) {
		if (line[i] >= 97 && line[i] <= 122) {
			fprintf(outp, "%c", key[line[i] - 97]);
		} else {
			fprintf(outp, "%c", line[i]);
		}
	}
}
