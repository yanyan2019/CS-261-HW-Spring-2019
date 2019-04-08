/* CS261 - HW1 - Program4.c 
 * Name: YanYan Lee
 * Date: 04/08/2019
 * solution description: sort and print a struct student array 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};


/* allocate dynamic memory */
struct student* allocate(int n){
	struct student* students = NULL;
	students = (struct student*) malloc(sizeof(struct student[n]));
	return students;
}

/* generate random initials and scores for student array */
void generate(struct student* students, int n){
	/* declare variables */
	int i, j, num, num2;

	for(i = 0; i < n; i++){
		for(j = 0; j < 2; j++){
			num = rand()%25+65;
			students[i].initials[j] = (char)num;
		}
		num2 = rand()%100;
		students[i].score = num2;
	}
	
}

/* print the array */
void print(struct student* stud, int n){
	int i;	

	printf("\n\n");
	for(i = 0; i < n; i++){
		printf("%d. %s %d\n", i+1, stud[i].initials, stud[i].score);
	}
}

/* swap function */
void swap(struct student* stud, int n, int n2){
	struct student temp;
	temp.initials[0] = stud[n].initials[0];
        temp.initials[1] = stud[n].initials[1];
	temp.score = stud[n].score;
	
	stud[n].initials[0] = stud[n+1].initials[0];
	stud[n].initials[1] = stud[n+1].initials[1];
	stud[n].score = stud[n+1].score;

	stud[n+1].initials[0] = temp.initials[0];
        stud[n+1].initials[1] = temp.initials[1];
        stud[n+1].score = temp.score;
}

/* sort students initials */
void sort(struct student* students, int n){
	/* declare variblaes */
	int i, j;
	
	/* sort the array */
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if((int)students[j].initials[0] > (int)students[j+1].initials[0]){ /* check if swap is needed */
				swap(students, j, j+1);
			}else if((int)students[j].initials[0] == (int)students[j+1].initials[0] && (int)students[j].initials[1] > (int)students[j+1].initials[1]){ /* swap by checking the second initials if the first initials are the same */
				swap(students, j, j+1);
			}
		}
	}
}

/* deallocate memory */
void deallocate(struct student* stud){
	if(stud != NULL){
		free(stud);
	}
}

int main(){
	/* declare variables */
	int n;
	struct student* students = NULL;

	srand(time(NULL));
	
	/* prompt and validate user input */
	printf("Enter number of students: ");
	scanf("%d",&n);
	if(n <= 0){
		printf("Invalid input, program exit.\n");
		return 1;
	}
	
	/* allocate student array */
	students = allocate(n);
	
	/* fill data into array */
	generate(students, n);
	
	/* print unsorted array */
	print(students, n);

	/* sort array by initials */
	sort(students, n);

	/* print the sorted array */
	print(students, n);

	/* deallocate dynamic memory */
	deallocate(students);

	return 0;
}
