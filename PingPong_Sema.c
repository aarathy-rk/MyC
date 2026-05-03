// C pgm to create 2 threads to print Ping and Pong alternately starting with Ping, Use semaphores for thread synchronization

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t sem_ping;
sem_t sem_pong;

void *ping(void *arg)
{
	for(int i=0;i<5;i++)
	{
		sem_wait(&sem_ping);
		printf("Ping\n");
		sleep(1);
		sem_post(&sem_pong);
	}
	
	return NULL;
}

void *pong(void *arg)
{
	for(int i=0;i<5;i++)
	{
		sem_wait(&sem_pong);
		printf("Pong\n");
		sleep(1);
		sem_post(&sem_ping);
	}
	
	return NULL;
}

int main()
{
	pthread_t t1,t2;

	sem_init(&sem_ping,0,1);
	sem_init(&sem_pong,0,0);
	
	pthread_create(&t1,NULL,ping,NULL);
	pthread_create(&t2,NULL,pong,NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	sem_destroy(&sem_ping);
	sem_destroy(&sem_pong);

	return 0;
}

