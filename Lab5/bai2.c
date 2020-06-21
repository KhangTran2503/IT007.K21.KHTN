#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
sem_t sem1, sem2;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int n, size;
int *a;

int rand_range(int low,int high){
	return (rand() % (high - low + 1)) + low; 
}

void *pop()
{
	while (1)
	{
		sem_wait(&sem1);
		pthread_mutex_lock(&mutex);
		size--;
		printf("Pop : %6d\t\t Size of array: %3d\n", a[size],size);
		sem_post(&sem2);
		pthread_mutex_unlock(&mutex);
	}
}

void *push()
{
	while (1)
	{
		sem_wait(&sem2);
		pthread_mutex_lock(&mutex);
		
		a[size]= rand_range(1,1000);
		size++;
		printf("Push: %6d\t\t Size of array: %3d\n", a[size-1],size);
		sem_post(&sem1);
		pthread_mutex_unlock(&mutex);
	}
}
int main()
{

	pthread_mutex_init(&mutex,NULL);

	printf("Enter size of array n: ");
	scanf("%d", &n);
	a = (int*) malloc(n*sizeof(int));
	sem_init(&sem1,0,0);
	sem_init(&sem2,0,n);

	pthread_t t1, t2;

	pthread_create(&t1, NULL, push, NULL);
	pthread_create(&t2, NULL, pop, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}

	
	

