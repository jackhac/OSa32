#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

void *thread1(void *vargp);
void *thread2(void *vargp);
void *thread3(void *vargp);
int inputNums[7];
int avgNum=0;
int maxNum=0;
int minNum=0;

int main(int argc, char *argv[])
{
	// This is where the threads are declared
	pthread_t thread1_id, thread2_id, thread3_id; 
	
	if (argc!=8)
	{
		printf("usage stats num1 num2 num3 num4 num5 num6 num7\n");
		return 1;
	}
	
	for (int i=1; i<argc; i++)
	{
		inputNums[i-1]=atoi(argv[i]);
		
	}
	
 	
    pthread_create(&thread1_id, NULL, thread1, NULL); 
    pthread_join(thread1_id, NULL); 

    pthread_create(&thread2_id, NULL, thread2, NULL); 
    pthread_join(thread2_id, NULL); 
	
    pthread_create(&thread3_id, NULL, thread3, NULL); 
    pthread_join(thread3_id, NULL); 
	
	printf("The averate value is %d\n",avgNum);
	printf("The minimum value is %d\n",minNum);
	printf("The maximum value is %d\n",maxNum);
	
    exit(0); 
	
	return 0;

}

void *thread1(void *vargp) 
{ 
	
	for (int i=0; i<7; i++)
	{
		avgNum+=inputNums[i];
	}
	avgNum=avgNum/7;
	
    pthread_exit(0);
} 

void *thread2(void *vargp) 
{
    for (int i=0; i<7; i++)
	{
		if (inputNums[i]>maxNum)
		{
			maxNum=inputNums[i];
		}
	}
	
    pthread_exit(0);
} 

void *thread3(void *vargp) 
{ 
	minNum=inputNums[0];
	
   for (int i=1; i<7; i++)
	{
		if (inputNums[i]<minNum)
		{
			minNum=inputNums[i];
		}
	}
	
    pthread_exit(0);
} 
