/*########################################
# University of Information Technology
# IT007 Operating System
# Tran Dinh Khang, 18520072
# File: example_fork_wait.c
#########################################*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	pid = fork();
	if (pid == 0) printf("Child Process, pid = %d\n",pid);
	else {
		wait(NULL);
		printf("Parent process, pid = %d <-- This is PID of child process \n", pid);
	}
	exit(0);
}
