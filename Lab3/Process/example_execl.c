/*########################################
# University of Information Technology
# IT007 Operating System
# Tran Dinh Khang, 18520072
# File: example_execl.c
#########################################*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	execl("/usr/bin/gedit","gedit","foo.c",NULL);
	printf("ERROR!!! execl() is failed\n");	
	exit(1);
}
