#ifndef __GRAPH__H
#define __GRAPH__H
#include"linkedlist.hpp"
#include"stacks.hpp"
#include"queue.hpp"

class Graph
{
	/*
	This is an undirected and unweighted graph class 
	with adjacency list data structure.
	*/
	int size;
	LinkedList<int> *array; //array of linked lists
public:
	Graph(int size){ array = new LinkedList<int>[size]; this->size = size;}
	~Graph(){delete []array;}
	void addedge(int src,int dest) 
	{
		array[src].push(dest);
		array[dest].push(src); // since its an undirected graph};
	}
	void addedge_d(int src,int dest) {array[src].push(dest);} // directed graphs
	void dfs(int start); // vertext start point
	void dfs_util(int start,bool visited[]);
	void bfs(int start);
	void bfs_util(int start, bool visited[], Queue<int> *q);
	void printgraph();
};

//function calls
void runGraph();
#endif // __GRAPH__H