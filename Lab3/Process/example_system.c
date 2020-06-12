/*########################################
# University of Information Technology
# IT007 Operating System
# Tran Dinh Khang, 18520072
# File: example_system.c
#########################################*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	
	printf("Hello IT007! I will open vim editor now ^_^\n");
	system("vi abc.txt");
	return 0;
}
