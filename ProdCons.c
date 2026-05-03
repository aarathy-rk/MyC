/* C pgm to demonstrate Producer Consumer problem solution using Semaphores and mutex
Goal: Limit buffer access to 1 thread at a time (mutual exclusion)
      Ensure producer waits if buffer full
	  Ensure consumer waits if buffer empty */
	  
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in=0,out=0;

sem_t empty;  //counts empty slots
sem_t full;   //counts filled slots

pthread_mutex_t mutex;

void *producer(void *arg)
{
	for(int i=0;i<10;i++)
	{
		int item = i+1;
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = item;
		printf("Producer produced: %d\n",item);
		in = (in+1)%BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
		sleep(1); //simulate time to produce
	}
	return NULL;
}

void *consumer(void *arg)
{
	for(int i=0;i<10;i++)
	{
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[out];
		printf("Consumer consumed: %d\n",item);
		out = (out+1)%BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		sleep(2); //simulate time to consume
	}
	return NULL;
}
	
int main()
{
	pthread_t prod,cons;
	
	sem_init(&empty,0,BUFFER_SIZE);
	sem_init(&full,0,0);
	
	pthread_mutex_init(&mutex,NULL);
	
	pthread_create(&prod,NULL,producer,NULL);
	pthread_create(&cons,NULL,consumer,NULL);
	
	pthread_join(prod,NULL);
	pthread_join(cons,NULL);
	
	sem_destroy(&empty);
	sem_destroy(&full);
	
	pthread_mutex_destroy(&mutex);
	
	return 0;
}
	