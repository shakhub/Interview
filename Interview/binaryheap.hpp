#ifndef BINARYHEAP_H
#define BINARYHEAP_H

class MinHeap
{
	int capacity;
	int size;
	int *array;
public:
	MinHeap(int cap); //constructor
	MinHeap(int *array, int size); //constructor
	int parent(int index) { return index >> 1; }
	int left(int index) { return index << 1; }
	int right(int index) { return ((index << 1) + 1); }
	int getMin() { return array[1]; };

	void printArray(void);
	void minHeapify(int index); 
	void insertKey(int key);
	void decreaseKey(int index, int new_val); // replace the key value at index by new_val
	void deleteKey(int index); // deletes a key stores at index	
	int extractMin(void);

};
class MaxHeap
{
	int capacity;
	int size;
	int *array;
public:
	MaxHeap(int cap); //constructor
	int parent(int index) { return index >> 1; }
	int left(int index) { return index << 1; }
	int right(int index) { return ((index << 1) + 1); }
	int getMax() { return array[1]; };

	void printArray(void);
	void maxHeapify(int index); // 
	void insertKey(int key);
	void deleteKey(int index); // deletes a key stores at index
	void decreaseKey(int index, int new_val); // replace the key value at index by new_val	
	int extractMax();
};
static void swap(int*, int *);
void heapSort(int *,int );
void runBinaryHeap(void);
#endif // BINARYHEAP_H
