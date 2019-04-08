/* CS261 - HW1 - Program2.c */
/* Name: YanYan Lee
 * Date: 04/08/2019
 * Solution description: create a struct dynamic array for 10 students and print their initials and scores.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
	/* Allocate memory for ten students */
	struct student* s_ptr = NULL;
	s_ptr = (struct student*) malloc(sizeof(struct student[10]));

	/* return the pointer */
	return s_ptr;
} 

void generate(struct student* students){
	/* Generate random initials and scores for ten students.
	 * The two initial letter smust be capital and must be between A and Z.
	 * The score must between 0 and 100. */
	
	srand(time(NULL));

	/* declare variables */
	int num, num2, i, j;
	
	/* for loop to input initials and scores into to students. */			
	for(i = 0; i < 10; i++){

		/* for loop for inserting the initials */
		for(j = 0; j < 2; j++){

			/* generate random number form 65(A) to 90(Z) according to ASCII table */
			num = rand()%25+65;
			students[i].initials[j] = (char)num;
		}

		/* generate random scores */
		num2  = rand()%100;
		students[i].score = num2;
	}
}

void output(struct student* students){
	/* output information about the ten students in the format: */
	
	/* declare variables */
	int i;	
	
	/* for loop to print out 10 students */
	for(i = 0; i < 10; i++){
		printf("%d. %s %d\n", i+1, students[i].initials, students[i].score);
	}
}

void summary(struct student* students){
	int i, min = 0, max = 0; /*min and max are the index of the array */
	double total = 0, average = 0;

	for(i = 0; i < 10; i++){
		if(students[min].score > students[i].score){ /* find the index of the minimum score */
			min = i;
		}
		if(students[max].score < students[i].score){ /* find the index of the maximum score */
			max = i;
		}
		total += students[i].score;
	}
	average = total/10;
	printf("Student with minimum score: %s %d, student with maximum score: %s %d\n", students[min].initials, students[min].score, students[max].initials, students[max].score);
	printf("Average score: %g\n", average);
} 

void deallocate(struct student* stud){
	if(stud != NULL){
		free(stud);
	}
}

int main(){
	/* declare variables */
	struct student* stud;

	/* call functions*/
	stud = allocate();
	generate(stud);
	output(stud);
	summary(stud);
	deallocate(stud);
	return 0;
}
