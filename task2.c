#include<stdio.h>
#include<stdlib.h>

int i=0;
int size=10;
int count=0;

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
	buildHeap(array,count);
	heapify(array,1,i);
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
	printf("Highest value in the Queue : %d \n",array[1]);
}



int main()
{
	int array[10];
	int ch,val;
	while(1)
	{
		printf("\nEnter the operataion\n");
		printf("1.Insert to queue\n2.Delete the highest\n3.Get the highest value\n4.Print Queue\nAny other to exit\n");
		printf("Operataion : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value : ");
				scanf("%d",&val);
				count++;
				enque(val,array,count);
				break;
			case 2:
				count--;
				dequeue(array,count);
				printf("Queue after deletion : ");
				for (i=1; i<=count; ++i)
    				printf("%d ",array[i]);
    			printf("\n");
				break;
			case 3:
				getTheHighest(array,count);
				break;
			case 4:
				printf("Queue : ");
				int i;
				for (i=1; i<=count; ++i)
			    	printf("%d ",array[i]);
			    printf("\n");
			    break;
			default:
				return 1;
		}
	}   
}

