#include<iostream>
#include"graph.hpp"


#define __GRAPH

//char vertex[8] = {'A','B','C','D','E','F','G','H'};

void Graph::dfs_util(int start,bool visited[])
{
	visited[start] = true;
	std::cout << start << " ";

	Node<int> *curr = array[start].gethead();

	while(curr!=NULL)
	{
		if(!visited[curr->getData()])
			dfs_util(curr->getData(),visited);
		curr = curr->getNext();
	}

}
void Graph::dfs(int start)
{	
	bool visited[8] = {false};

	dfs_util(start,visited);

}
void Graph::bfs_util(int start,bool visited[],Queue<int> *q)
{
	visited[start] = true;
	std::cout<< start << " ";
	Node<int> *curr = array[start].gethead();
	while(curr!=NULL)
	{
		if(!visited[curr->getData()])
		{
			visited[curr->getData()] = true;
			q->enqueue(curr->getData());
		}
		
		curr = curr->getNext();
	}
	if(!q->isEmpty())
		bfs_util(q->dequeue(),visited,q);

}
void Graph::bfs(int start)
{
	bool visited[8] = {false};
	Queue<int> q(8);
	bfs_util(start,visited,&q);
}
void Graph::printgraph()
{
	for(int i=0;i<size;i++)
	{
		std::cout<< "["<<i << "] ->";
		array[i].print_list();
	}
}

void runGraph()
{
	Graph g(8);
	
	/*
	g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
	*/
	
	g.addedge(0,1);
    g.addedge(0,6);
    g.addedge(0,3);
    g.addedge(1,4);
    g.addedge(1,5);
    g.addedge(2,7);
	g.addedge(2,5);
	g.addedge(3,5);
	g.addedge(4,6);
	
	g.printgraph();
	g.bfs(0);
	
	
}