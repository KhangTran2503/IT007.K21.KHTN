/*#######################################
# University of Information Technology
# IT007 Operating System
# Tran Dinh Khang, 18520072
# File: example_thread_creation.c 
########################################*/

#include <pthread.h>
#include <stdio.h>

void *thread_print(void *messenge){
	while (1){
		printf("Hello, How are you?\n");
	}
}

int main(){
	pthread_t idthread;
	pthread_create(&idthread,NULL,&thread_print,NULL);

	while (1){
		printf("I'm fine, and you?\n");
	}

	return 0;
}
