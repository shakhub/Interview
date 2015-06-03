#include<iostream>
#include "binaryheap.hpp"

#define __BINARYHEAP
using namespace std;

static void swap(int*a, int *b)
{ 
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

MinHeap::MinHeap(int cap)
{
	// initialize the heap 
	size = 0;
	capacity = cap;
	array = new int[capacity];
}
void MinHeap::printArray(void)
{
	if (size == 0 || size > capacity)
	{
		cout << "Heap is empty." << endl;
		return;
	}
	for (int i = 1; i <= size; i++)
		cout << array[i] << " ";

	cout << endl;
}
void MinHeap::minHeapify(int index)
{
	int l = left(index);
	int r = right(index);
	int smallest = index;
	if (index > size || index == 0)
	{
		cout << "Invalid Index" << endl;
		return;
	}

	if (l <= size && array[l] < array[index])
		smallest = l;
	if (r <= size && array[r] < array[smallest])
		smallest = r;
	if (smallest != index)
	{
		swap(&array[smallest], &array[index]);
		minHeapify(smallest);
	}

}
MinHeap::MinHeap(int *arr, int length)
{
	size = length;
	capacity = length + 1;
	array = arr;
	int i = (size - 1) / 2;
	while (i)
	{
		minHeapify(i);
		i--;
	}
}
int MinHeap::extractMin(void)
{
	int min;
	if (size < 1)
	{
		cout << "Heap is empty!" << endl;
		return -1;
	}
	if (size == 1)
	{
		size--;
		return array[1];
	}
	min = array[1];
	array[1] = array[size]; // replace the last element in the array to the first spot
	size--;
	minHeapify(1);
	
	return min;

}
void MinHeap::insertKey(int key)
{
	int index;
	if (size == capacity)
	{
		cout << "Overflow : Cannot insert anymore" << endl;
		return;
	}
	size++;
	index = size;
	array[index] = key;

	while (index > 1 && array[parent(index)] > array[index])
	{
		swap(&array[parent(index)], &array[index]);
		index = parent(index);
	}
}
void MinHeap::decreaseKey(int index, int new_val)
{
	if (index > size || index == 0)
	{
		cout << "Invalid Index" << endl;
		return;
	}

	array[index] = new_val;

	while (index > 1 && array[index] < array[parent(index)])
	{
		swap(&array[index], &array[parent(index)]);
		index = parent(index);
	}

}
void MinHeap::deleteKey(int index)
{
	if (index > size || index == 0)
	{
		cout << "Invalid Index" << endl;
		return;
	}

	decreaseKey(index, 0);
	extractMin();

}

MaxHeap::MaxHeap(int cap)
{
	// initialize the heap 
	size = 0;
	capacity = cap;
	array = new int[capacity];
}
void MaxHeap::printArray(void)
{
	if (size == 0 || size > capacity)
	{
		cout << "Heap is empty." << endl;
		return;
	}
	for (int i = 1; i <= size; i++)
		cout << array[i] << " ";

	cout << endl;
}
void MaxHeap::maxHeapify(int index)
{
	int l = left(index);
	int r = right(index);
	int largest = index;
	if (index > size || index == 0)
	{
		cout << "Invalid Index" << endl;
		return;
	}

	if (l <= size && array[l] > array[index])
		largest = l;
	if (r <= size && array[r] > array[largest])
		largest = r;
	if (largest != index)
	{
		swap(&array[largest], &array[index]);
		maxHeapify(largest);
	}

}
int MaxHeap::extractMax(void)
{
	int max;
	if (size < 1)
	{
		cout << "Heap is empty!" << endl;
		return -1;
	}
	if (size == 1)
	{
		size--;
		return array[1];
	}
	max = array[1];
	array[1] = array[size]; // replace the last element in the array to the first spot
	size--;
	maxHeapify(1);

	return max;

}
void MaxHeap::insertKey(int key)
{
	int index;
	if (size == capacity)
	{
		cout << "Overflow : Cannot insert anymore" << endl;
		return;
	}
	size++;
	index = size;
	array[index] = key;

	while (index > 1 && array[parent(index)] < array[index])
	{
		swap(&array[parent(index)], &array[index]);
		index = parent(index);
	}
}
void MaxHeap::decreaseKey(int index, int new_val)
{
	if (index > size || index == 0)
	{
		cout << "Invalid Index" << endl;
		return;
	}

	array[index] = new_val;

	while (index > 1 && array[index] > array[parent(index)])
	{
		swap(&array[index], &array[parent(index)]);
		index = parent(index);
	}

}
void MaxHeap::deleteKey(int index)
{
	if (index > size || index == 0)
	{
		cout << "Invalid Index" << endl;
		return;
	}

	decreaseKey(index, 0x7FFFFFFF); // 0x7FFFFFFF is the highest int32 value without overflow
	extractMax();

}
void printArray(int* arr, int size)
{
	int i;
	cout << endl;
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	cout << endl;
}
void heapSort(int *array, int size)
{
	/*Heap sort algorithm using extractMin idea.*/
	
	MinHeap h(size);
	
	for (int i = 0; i < size; i++)
		h.insertKey(array[i]);	
	
	//MinHeap h(array, size);
	h.printArray();
	for (int i = 0; i < size; i++)
	{
		array[i] = h.extractMin();
	}

}
void runBinaryHeap(void)
{
	int array[10] = { 1, 4, 9, 3, 5, 8, 2, 7, 6, 10 };
	printArray(array, 10);
	heapSort(array, 10);
	printArray(array, 10);
	
}