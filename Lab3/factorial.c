/*#######################################
# University of Information Technology	#
# IT007 Operating System                #
# Tran Dinh Khang, 18520072		#
# File: factorial.c			#
#########################################*/


#include <stdio.h>


int main(){
	int i, num, j = 1;
	printf("Enter the number: ");
	scanf("%d",&num);

	for (i = 1; i <= num; i++) j = j*i;

	printf("The factorical of %d is %d\n",num,j);
	return 0;
      
}	
