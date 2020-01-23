#include<stdio.h>
#include<stdlib.h>



void heapify(int array[], int i, int n)
{
	int max=i;
	int left=2*i;
	int right=2*i+1;
//	printf("i : %d\n",i);
//	printf("LEFT : %d\n",left);
//	printf("RIGHT : %d\n",right);
	if((left<n) && (array[left]>array[max]))
	{
		max=left;
//		printf("LEFT\n");
	}
	if((right<n) && (array[right]>array[max]))
	{
		max=right;
//		printf("RIGHT\n");	
	}
	if(max!=i)
	{
		int temp = array[i];
		array[i]=array[max];
		array[max]=temp;
		heapify(array,max,n);
	}
//	printf("End of a iteration!\n");
}


void buildHeap(int array[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
//		printf("i : %d\n",i);
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

int main()
{
	int array[] = {-1,5,2,8,1,3,7};
	int n = sizeof(array)/sizeof(array[0]);
	buildHeap(array,n);
	printf("Max heap : ");
	int i;
	for (i=1; i<n; ++i)
    	printf("%d ",array[i]);
    printf("\nHeap Sorted Array : ");
    heapsort(array,n);
    for (i=1; i<n; ++i)
    	printf("%d ",array[i]);
    
}

