#include<iostream>
using namespace std;

class graph
{
	int node, edges, g[10][10], visited[10], total;
public:
	graph()
   {
		node = 10;
		total = 0;
		edges = 10;
		for(int i=0;i<10;i++)
		{
			visited[i]=0;

			for(int j=0;j<10;j++)
				g[i][j]=999;
		}

   }

	void createGraph()
	{ int a,b;
		cout<<endl<<"Enter the number of nodes you want in the graph (nodes should be < 10):: ";
		cin>>node;
		cout<<endl<<"Enter total number of edges you want in the graph:: ";
		cin>>edges;

		for(int i=0;i<edges;i++)
		{
		    cout<<endl<<"Enter the edge's vertex 1 :: ";
		    cin>>a;
			cout<<endl<<"Enter the edge's vertex 2 :: ";
			cin>>b;
		    cout<<endl<<"Enter the edge's weight :: ";
		    cin>>g[a][b];

		    g[b][a] = g[a][b];
		}
	}

	void prims_algorithm()
	{
		int min = 999, source, destination;

		cout<<endl<<"Enter the starting node :: ";
		cin>>source;

		visited[source]=1;

	  for(int edgecount=0; edgecount<node-1;edgecount++)
	  {
		  min=999;
		for(int i=0;i<node;i++)
		{
			if(visited[i]==1)
			{
				for(int j=0;j<node;j++)
				{
					if(visited[j]!=1)
					{
						if(g[i][j]< min)
						{
							min= g[i][j];
							source = i;
							destination = j;
						}
					}
				}
			}
		}

		visited[destination] = 1;
		cout<<"\n"<<source<<"---"<<destination<<"\tcost: "<<g[source][destination];
		total += g[source][destination];
	 }

	  cout<<"\n Total cost of MST :: "<<total;
	}
};


int main()
{
	graph g1;
	g1.createGraph();
	g1. prims_algorithm();
}
