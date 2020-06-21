#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int x;
void *processA()
{
	while (1)
	{
		x++;
		if(x==20)
			x=0;
		printf("process A: %d\n",x);
	}
}

void *processB()
{
	while (1)
	{
		x++;
		if(x==20)
			x=0;
		printf("process B: %d\n",x);
	}	
}
int main()
{
	x=0;
	pthread_t t1,t2;
	pthread_create(&t1, NULL, processA, NULL);
	pthread_create(&t2, NULL, processB, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	exit(0);
}
