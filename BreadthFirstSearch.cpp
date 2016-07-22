#include<iostream>
#include<queue>
#define INIT 0
#define WAIT 1
#define VISITED 2
using namespace std;
class BreadthFirstSearch
{
	private : 
	int graph[9][9];
	int state[9];
	int n;
	public :
	BreadthFirstSearch()
	{
		n=9;
		graph[0][1]=1;
		graph[0][4]=1;
		graph[0][3]=1;
		graph[1][2]=1;
		graph[2][5]=1;
		graph[1][4]=1;
		graph[3][4]=1;
		graph[3][6]=1;
		graph[6][7]=1;
		graph[6][4]=1;
		graph[4][7]=1;
		graph[4][5]=1;
		graph[7][8]=1;
		graph[7][5]=1;
	}
	void breadthirstSearch(int start)
	{
		for(int i=0;i<n;i++)
			state[i]=INIT;
		queue<int> * que=new queue<int>(); 
		que->push(start);
		state[start]=WAIT;
		while(!que->empty())
		{
			int current_vertex=que->front();
			que->pop();
			cout<< current_vertex << " " ;
			state[current_vertex]=VISITED;
			for(int i=0;i<n;i++)
			{
				if(graph[current_vertex][i]!=0 && state[i]==INIT)
				{
					que->push(i);
					state[i]=WAIT;
				}
			}
		}
	}
	
};
int main()
{
	BreadthFirstSearch *search=new BreadthFirstSearch();
	search->breadthirstSearch(0);
}
