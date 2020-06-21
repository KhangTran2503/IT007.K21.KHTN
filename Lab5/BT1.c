#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t mutex[7];
int x1, x2, x3, x4, x5, x6;
int w, v ,y ,z ,result;

void *func_a()
{
	w = x1 * x2;
	printf("Process a: w = x1 * x2 = %d \n", w);
	pthread_mutex_unlock(&mutex[1]);
}

void *func_b()
{
	v = x3 * x4;
	printf("Process b: v = x3 * x4 = %d \n", v);
	pthread_mutex_unlock(&mutex[2]);
}

void *func_c()
{
	pthread_mutex_lock(&mutex[2]);
	pthread_mutex_unlock(&mutex[2]);

	y = v * x5;

	printf("Process c: y = v * x5 = %d \n", y);
	pthread_mutex_unlock(&mutex[3]);
}

void *func_d()
{	
	pthread_mutex_lock(&mutex[2]);
	pthread_mutex_unlock(&mutex[2]);
	z = v * x6;
	printf("Process d: z = v * x6 = %d \n", z);

	pthread_mutex_unlock(&mutex[4]);

}

void *func_e()
{
	pthread_mutex_lock(&mutex[1]);	
	pthread_mutex_lock(&mutex[3]);
	pthread_mutex_unlock(&mutex[1]);

	y = w * y;
	printf("Process e: y = w * y = %d \n", y);

	pthread_mutex_unlock(&mutex[5]);

}

void *func_f()
{

	pthread_mutex_lock(&mutex[1]);	
	pthread_mutex_lock(&mutex[4]);
	pthread_mutex_unlock(&mutex[1]);
	z = w * z;
	printf("Process f: z = w * z = %d \n", z);	

	pthread_mutex_unlock(&mutex[6]);
}
void *func_g()
{
	pthread_mutex_lock(&mutex[6]);	
	pthread_mutex_lock(&mutex[5]);

	result = y + z;
	printf("Process g: result = y + z = %d \n", result);


}
int main()
{
	for (int i = 1; i<=6 ;i++)
	{
		pthread_mutex_init(&mutex[i],NULL);
		pthread_mutex_lock(&mutex[i]);
	}

	printf("Enter x1, x2, x3, x4, x5, x6: ");
	scanf("%d %d %d %d %d %d",&x1,&x2,&x3,&x4,&x5,&x6);
	w = v = y = z =0;

	pthread_t a, b, c, d, e, f, g;

	pthread_create(&f, NULL, func_a, NULL);
	pthread_create(&g, NULL, func_b, NULL);
	pthread_create(&e, NULL, func_c, NULL);
	pthread_create(&a, NULL, func_d, NULL);
	pthread_create(&b, NULL, func_e, NULL);
	pthread_create(&c, NULL, func_f, NULL);
	pthread_create(&d, NULL, func_g, NULL);

	pthread_join(a, NULL);
	pthread_join(b, NULL);
	pthread_join(c, NULL);
	pthread_join(d, NULL);
	pthread_join(e, NULL);
	pthread_join(f, NULL);
	pthread_join(g, NULL);
	
	return 0;
}

	
	

