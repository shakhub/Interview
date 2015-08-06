#include<iostream>
#include<time.h>
#include"sorting.hpp"

#define __SORT
#define SIZE 40000
template <class T>
inline void swapSort(T *a,T *b)
{
	/*
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	*/
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
template <class T>
T binarySearch(T *a,const int size, const T data)
{
	/*
	The input array must be sorted
	O(log n)
	*/
	int l = 0,r = size-1;
	
	while(l<=r)
	{
		int mid = l+((r - l)>>1);
		if ( a[mid] == data ) return mid+1;
		if ( data < a[mid]) r = mid - 1;
		else l = mid + 1;
	}
	return -1; // if data not found

}
template <class T>
T  search(T *a, const int size, const T data)
{
	//O(n)
	int i=0;
	for(i=0;i<size;i++)
	{
		if(a[i] == data) return i+1;
	}
	return -1;
}
template <class T>
void selectionSort(T *a, const int size)
{
	//O(n*n)
	int min_loc = 0;
	
	while(min_loc < size)
	{
		int i = min_loc+1;
		while(i<size)
		{
			if(a[i] < a[min_loc]) 
			{
				swapSort ( &a[i],&a[min_loc]); 
			}
			i++;
		}
		min_loc++;
	}

}
template <class T>
void bubbleSort(T *a, const int size)
{
	/*
	Modified bubble sort : If the array is already sorted
	                       then Time Complexity is O(n)
						   O(n^2)
	*/
	int swapCount = 1;
	
	while(swapCount)
	{
		int i = 0;
		swapCount = 0;
		while (i<(size-1))
		{
			if(a[i]>a[i+1]) 
			{ 
				swapSort(&a[i],&a[i+1]); 
				swapCount++;
			}
			i++;
		}
	}

}
template <class T>
void insertionSort(T *a, const int size)
{
	//O(n*n)
	int i=1;
	while(i<size)
	{
		int key = i;
		while(key)
		{
			if(a[key]<a[key-1]){
				swapSort(&a[key],&a[key-1]);
				key--;
			}
			else
			{
				key = 0;
				break;
			}
		}
		i++;
	}
}
template <class T>
void merge(T *a, int left,const int mid,const int right)
{
	int i=0,j=0,k=0;
	const int leftSize = mid-left+1;
	const int rightSize = right - mid;
	T *leftArray; 
	T *rightArray;
	leftArray = new T[leftSize];
	rightArray = new T[rightSize];

	//copy data to the temp arrays
	for(int i=0;i<leftSize;i++)
		leftArray[i] = a[left+i];
	for(int i=0;i<rightSize;i++)
		rightArray[i] = a[mid+1+i];
	i=0;
	j=0;
	k=left;
	while(i<leftSize && j<rightSize)
	{
		if(leftArray[i] <=rightArray[j])
		{
			a[k] = leftArray[i];
			i++;
		}
		else
		{
			a[k] = rightArray[j];
			j++;
		}
		k++;
	}
	//Copy the remaining elements of the left array
	while(i<leftSize)
	{
		a[k] = leftArray[i];
		i++;
		k++;
	}
	//Copy the remaining elements of the right array
	while(j<rightSize)
	{
		a[k] = rightArray[j];
		j++;
		k++;
	}
	delete[] leftArray;
	delete[] rightArray;
}
template <class T>
void mergeSort(T *a,int left, int right)
{
	//O(nlog n)
	int mid = left+((right-left)>>1);//same as (left+right)>>1 , but avoids overflow for large left values
	if(left<right)
	{
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}
template <class T>
void printArray(T *a,const int size)
{
	int i=0;
	std::cout<<std::endl;
	for(i=0;i<size;i++)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl;
	std::cout<<std::endl;
}
void runSorting()
{
	long a[SIZE] = {0},b[SIZE]={0},c[SIZE]={0};
	clock_t startSort;
	int i = 0;
	for(i=SIZE-1;i--;)
		a[i] = rand()&16383;
			
			
			
	memcpy(b,a,SIZE*sizeof(int));
	memcpy(c,a,SIZE*sizeof(int));


	startSort = clock();
	selectionSort(a,SIZE);
	printf("Time for selection sort : %3.4fs\n",(double)(clock()-startSort)/CLOCKS_PER_SEC);
	
	
	startSort = clock();
	bubbleSort(b,SIZE);
	printf("Time for bubble sort    : %3.4fs\n",(double)(clock()-startSort)/CLOCKS_PER_SEC);
	
	startSort = clock();
	mergeSort(c,0,SIZE-1);
	printf("Time for merge sort    : %3.4fs\n",(double)(clock()-startSort)/CLOCKS_PER_SEC);
	
	
	/*
	while(1)
	{
		int data;
		std::cout<<"Enter Item to Search: ";
		std::cin>>data;
		
		clock_t start = clock();
		std::cout<<"Location : "<<binarySearch(a,SIZE,data)<<std::endl;
		printf("Time BS: %.8fs\n",(double)(clock()-start)/CLOCKS_PER_SEC);
		start = clock();
		std::cout<<"Location : "<<search(a,SIZE,data)<<std::endl;
		printf("Time S: %.8fs\n",(double)(clock()-start)/CLOCKS_PER_SEC);
		
	}
	
	*/
}