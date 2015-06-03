#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable{
	int size;
	int *table;
public:
	HashTable(int arrSize);//constructor
	void hash();
	void hash(int *array,int size);//hasing function	
	void setSize(int arrSize){size = arrSize;}
	int getSize(){return size;}
	int hashValue(int key);
	bool isPresent(int key);
};


void runHashFunct(void);
#endif // HASHTABLE_H