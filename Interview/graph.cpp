#include<iostream>
#include"graph.hpp"


#define __GRAPH
#define SIZE 6
//char vertex[8] = {'A','B','C','D','E','F','G','H'};

bool Graph::loop()
{
	// Detects cycle in the given graph 
	// uses DFS and extra stack to keep track of 
	// the visited vetices 

	return false;
}
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
void Graph::dfs()
{	
	bool visited[SIZE] = {false};
	std::cout<<std::endl;
	for (int i = 0; i < size; i++)
	{
		if (!visited[i])
			dfs_util(i, visited);
	}
	std::cout<<std::endl;
}
void Graph::bfs(int start)
{
	Queue<int> q(100);
	bool visited[SIZE]={false};
	q.enqueue(start);
	visited[start] = true;
	std::cout<<std::endl;
	std::cout<<"BFS "<<std::endl;
	std::cout<< start << " ";

	while(!q.isEmpty())
	{
		Node<int> *curr = array[q.dequeue()].gethead();
		while(curr!=NULL)
		{
			if(!visited[curr->getData()])
			{
				visited[curr->getData()] = true;
				q.enqueue(curr->getData());
				std::cout<< curr->getData() << " ";
			}
			curr = curr->getNext();
		}
	}

}
void Graph::dfs_path(int start,int end, bool visited[],Stack<int> *s)
{
	visited[start] = true;
	s->push(start);
	if(s->topofstack() == end)
	{
		s->print();
	}
	Node<int> *curr = array[start].gethead();

	while(curr!=NULL)
	{
		if(!visited[curr->getData()])
		{				
			dfs_path(curr->getData(),end,visited,s);
		}
		curr = curr->getNext();
	}
	s->pop();
}
void Graph::path(int start,int end)
{
	/*
	Finds the path between two vertices in the graph. 
	This uses DFS algorithm. This might not be the 
	shortest path between the two vertices.
	Idea is to store the path using a stack in the DFS
	algorithm and print the stack when the end vertex
	is reached by the DFS algorithm.
	*/
	Stack<int> s(SIZE);
	bool visited[SIZE] = {false};
	std::cout<<std::endl;
	std::cout<<"Path "<<start<<"-->"<<end<<" : ";
	dfs_path(start,end,visited,&s);
	

}
void Graph::topologicalsort_util(int start,bool visited[],Stack<int> *s)
{
	Node<int> *curr = array[start].gethead();
	visited[start] = true;
	while (curr != NULL)
	{
		if (!visited[curr->getData()])
			topologicalsort_util(curr->getData(), visited, s);
	}
	s->push(start);
	
}
void Graph::topologicalsort()
{
	Stack<int> s(SIZE);
	bool visited[SIZE] = { false };

	for (int i = 0; i < SIZE; i++)
	{
		if (!visited[i])
			topologicalsort_util(i, visited, &s);
	}
	while (!s.isEmpty())
		std::cout << s.pop() << " ";
	std::cout << std::endl;

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
	Graph g(SIZE);
	
	/*
	g.addedge_d(0, 1);
    g.addedge_d(0, 2);
    g.addedge_d(1, 2);
    g.addedge_d(2, 0);
    g.addedge_d(2, 3);
    g.addedge_d(3, 3);*/
	
	g.addedge_d(5, 2);
	g.addedge_d(5, 0);	
	g.addedge_d(4, 0);
	g.addedge_d(4, 1);
	g.addedge_d(2, 3);
	g.addedge_d(3, 1);
	
		
	/*
	g.addedge(0,1);
    g.addedge(0,6);
    g.addedge(0,3);
    g.addedge(1,4);
    g.addedge(1,5);
    g.addedge(2,7);
	g.addedge(2,5);
	g.addedge(3,5);
	g.addedge(4,6);*/
	
	g.printgraph();
	//g.dfs();
	g.topologicalsort();
	/*
	if(g.loop())
		std::cout<<"Graph has cycle"<<std::endl;
	else
		std::cout<<"Graph no cycle"<<std::endl;
		*/
}