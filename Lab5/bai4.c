#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int x;
void *processA()
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		x++;
		if(x==20)
			x=0;
		printf("A: %d\n",x);
		pthread_mutex_unlock(&mutex);
	}
}

void *processB()
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		x++;
		if(x==20)
			x=0;
		printf("B: %d\n",x);
		pthread_mutex_unlock(&mutex);
	}		
}
int main()
{
	pthread_mutex_init(&mutex,NULL);
	x=0;
	pthread_t t1,t2;
	pthread_create(&t1, NULL, processA, NULL);
	pthread_create(&t2, NULL, processB, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	exit(0);
}
