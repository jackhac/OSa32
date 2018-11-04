//Andrew Buchanan
//Scott Martin

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

//global variables
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
	//if not right number of argumenets quit and show usage
	if (argc!=8)
	{
		printf("usage stats num1 num2 num3 num4 num5 num6 num7\n");
		return 1;
	}
	//take commandline variables to global variable
	for (int i=1; i<argc; i++)
	{
		inputNums[i-1]=atoi(argv[i]);
		
	}
	
<<<<<<< HEAD
 	//thread1
=======
 	
>>>>>>> 8802683a40a6307f0a874fa3941c1c01bbb55849
    pthread_create(&thread1_id, NULL, thread1, NULL); 
    pthread_join(thread1_id, NULL); 
	//thread2
    pthread_create(&thread2_id, NULL, thread2, NULL); 
    pthread_join(thread2_id, NULL); 
	//thread3
    pthread_create(&thread3_id, NULL, thread3, NULL); 
    pthread_join(thread3_id, NULL); 
	
	//print aggregate stats
	printf("The averate value is %d\n",avgNum);
	printf("The minimum value is %d\n",minNum);
	printf("The maximum value is %d\n",maxNum);
	
    exit(0); 
	
	return 0;

}

void *thread1(void *vargp) 
{ 
	//cycle through numbers adding as it goes
	for (int i=0; i<7; i++)
	{
		avgNum+=inputNums[i];
	}
	//divide that number by count of numbers in array
	avgNum=avgNum/7;
	
    pthread_exit(0);
} 

void *thread2(void *vargp) 
{
	//cycle through finding largest number
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
	//set first number in array to the minimum
	minNum=inputNums[0];
	
	//cycle through the rest finding smallest number
   for (int i=1; i<7; i++)
	{
		if (inputNums[i]<minNum)
		{
			minNum=inputNums[i];
		}
	}
	
    pthread_exit(0);
} 
