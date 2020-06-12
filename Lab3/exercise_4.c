/*######################################
# University of Information Technology
# IT007 Operating System
# Khang Tran, 18520072
# File: exercise_4.c
########################################*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int loop_forever = 1;
void on_sigint(){
	printf("\nYou are pressed CTR+C! Goodbye!\n");
	loop_forever = 0;
}

int main(){
        
	printf("Welcome to IT007, I am 18520072\n");
	
	sleep(1);
	
	system("gvim abcd.txt");
	
	loop_forever = 1;
	
	signal(SIGINT,on_sigint);
	while (loop_forever){};
	return 0;
}
