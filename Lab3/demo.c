#define _OPEN_THREADS 
#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <errno.h> 

int main(void){ 
	int rc; 
	pthread_attr_t attr; 
	rc = pthread_attr_init(&attr); 
	
	if (rc == -1){ 
		perror("error in pthread_attr_init"); 
		exit(1); 
	} 
	
	printf("Set guardsize to value of Pagesize.\n"); 
	rc = pthread_attr_setguardsize(&attr,EMSGSIZE); 
	
	if (rc != 0){ 
		printf("pthread_attr_setguardsize returned: %d\n",rc);
	       	printf("Error: %d, Error_Jr: %08x\n",errno,errno); 
		exit(2); 
	} else printf("Set guardsize is %d\n",EMSGSIZE); 
	
	rc = pthread_attr_destroy(&attr); 
	
	if (rc != 0){ 
		perror("error in pthread_attr_destroy");
		exit(3);
	}
	exit(0);
}	

	
	
