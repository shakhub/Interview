#ifndef __GRAPH__H
#define __GRAPH__H
#include<vector>
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

	void addedge(int start,int end)
	{

		array[start].push(end);
		array[end].push(start); // since its an undirected graph};

		array[start].sort();
		array[end].sort();

	}
	void addedge_d(int src,int dest) {array[src].push(dest);} // directed graphs
	void dfs(); // vertext start point
	void dfs_util(int start,bool visited[]);
	void bfs(int start);
	void dfs_path(int start, int end,bool visited[],Stack<int> *list);
	void path(int start,int end);
	void topologicalsort_util(int start, bool visited[], Stack<int> *s);
	void topologicalsort();
	bool loop();
	void printgraph();
};

//function calls
void runGraph();
#endif // __GRAPH__H