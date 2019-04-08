/* CS261- HW1 - Program1.c */
/* Name: YanYan Lee
 * Date: 03/04/2019
 * Solution description: Build Program1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int *a, int *b, int c){
	/* Increment a*/
	(*a)++;

	/* Decrement b*/
	(*b)--;

	/* Assign a-b to c */
	c = (*b)-(*a);

	/* return c */
	return c;
} 

int main(){
	/* declare variables */
	int x, y, z, foo_value;
	
	/* assign random value to the variables from 0 to 10 */
	srand(time(NULL));
	x = rand()%10;
	y = rand()%10;
	z = rand()%10;

	/* print values of x, y and z */
	printf("x = %d, y = %d, z = %d\n", x, y, z);

	/* call foo function */
	foo_value = foo(&x, &y, z);	

	/* print values x, y ,z and value from foo() */
	printf("foo_value = %d, x = %d, y = %d, z = %d\n\n", foo_value, x, y, z);

	printf("By comparing z and the return value of foo() function, foo() value is not the same as the value in z.\nThe reason is that z was passed by value to the foo() function, after exiting the foo() function, z remains as it is.\nBut for x and y, they were passed by reference (poiner) , so the change is perminant.\n");	

	return 0;
}
