#include<stdio.h>
#include<stdlib.h>

int i=0;

void heapify(int array[], int i, int n)
{
	int max=i;
	int left=2*i;
	int right=2*i+1;
	if((left<n) && (array[left]>array[max]))
	{
		max=left;
	}
	if((right<n) && (array[right]>array[max]))
	{
		max=right;	
	}
	if(max!=i)
	{
		int temp = array[i];
		array[i]=array[max];
		array[max]=temp;
		heapify(array,max,n);
	}
}


void buildHeap(int array[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		heapify(array,i,n);
	}
}

void heapsort(int array[],int n)
{
	int i;
	for(i=n-1;i>=1;i--)
	{
		int temp = array[1];
		array[1]=array[i];
		array[i]=temp;
		n--;
		heapify(array,1,i);
	}
}

void enque(int value, int array[], int size)
{
	i++;
	array[i]=value;
	buildHeap(array,size);
}

void dequeue(int array[], int size)
{
	int temp = array[1];
	array[1]=array[i];
	array[i]=temp;
	heapify(array,1,i);
}

void getTheHighest(int array[], int size)
{
	printf("\nHighest value in the Queue : %d ",array[1]);
}

int size=10;

int main()
{
	int array[10];
	int count=0;
	count++;
	enque(5,array,count);
	count++;
	enque(2,array,count);
	count++;
	enque(8,array,count);
	count++;
	enque(1,array,count);
	count++;
	enque(3,array,count);
	count++;
	enque(7,array,count);
	printf("Queue : ");
	int i;
	for (i=1; i<=count; ++i)
    	printf("%d ",array[i]);
    count--;
    dequeue(array,count);
    printf("\nQueue after deletion : ");
	for (i=1; i<=count; ++i)
    	printf("%d ",array[i]);
    getTheHighest(array,count);
    
}

