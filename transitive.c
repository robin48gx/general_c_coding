#include <stdio.h>
#include <stdarg.h>

int transitive_lt(int num, int arg1, ...) {

   va_list ap;
   int last,true=0;
   int i,j,k;

   printf("\nstarting transitive_lt(int num, int arg1, ...) num==%d\n",num);
   if ( num <= 1 )
	   return 0; // FALSE only one argument for the transitive function


   last = arg1;
   va_start(ap, arg1);
   num--;
   for (i = 0; i < num; i++) {
	j = va_arg(ap,int);
	printf(" comparing last %d < next %d\n",last,j);
	if ( last < j ) true++;
	last = j;	
   }

   va_end(ap);

   printf("exiting transitive_lt num==%d true==%d\n",num, true);
   return num == true;
}


int
transitive_three (int a, int b, int c)
{
	// this evaluates a < b as  == 1 
	// then compares c to 1 which passes
	// which is unintended!
	//
	//if ( a < b < c ) {
	//
	if ( a < b && b < c ) {
		return 1; // true
	}
	else {
		return 0;
	}
}


int main () {

	printf (" transitive_three (1,2,3) = %d\n",  transitive_three (1,2,3));
	printf (" transitive_three (1,4,3) = %d\n",  transitive_three (1,4,3));
	printf (" transitive_three (1,2,0) = %d\n",  transitive_three (1,2,0));
	printf (" transitive_three (-1,2,3) = %d\n",  transitive_three (-1,2,3));


	printf (" transitive_lt(3, -1,2,3) = %d\n",  transitive_lt(3, -1,2,3));
	printf (" transitive_lt(4, -1,2,3,4) = %d\n",  transitive_lt(4, -1,2,3,4));
	printf (" transitive_lt(5, -1,2,3,4,10) = %d\n",  transitive_lt(5, -1,2,3,4,10));
	printf (" transitive_lt(5, -1,33,3,4,10) = %d\n",  transitive_lt(5, -1,2,3,4,10));
	printf (" transitive_lt(6, -1,33,99,3,4,10) = %d\n",  transitive_lt(6, -1,33,99,3,4,10));
	printf (" transitive_lt(2, -1,2) = %d\n",  transitive_lt(3, -1,2));
	printf (" transitive_lt(1, -1) = %d\n",  transitive_lt(3, -1));


	return 0;
}

