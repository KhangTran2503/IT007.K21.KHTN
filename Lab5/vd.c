#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
sem_t sem1;
int sells,products;

void *processA()
{
	int stop = 120;
	while (1)
	{
		sem_wait(&sem1);
		sells++;
		printf("sells.    sells = %d, products = %d, %d \n",sells, products, products-sells);
	}
}

void *processB()
{
	int stop = 150;
	while (1)
	{
		products++;
		sem_post(&sem1);
		printf("products. sells = %d, products = %d, %d \n",sells, products, products-sells);
	}
}
int main()
{
	sem_init(&sem1,0,0);
	sells =  0;
	products = 0;

	pthread_t t1, t2;

	pthread_create(&t1, NULL, processA, NULL);
	pthread_create(&t2, NULL, processB, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}

	
	

