#include<iostream>
using namespace std;
int findminvertex(int* distance,bool*visited,int n)
{
	int minvertex=-1;
	for(int i=0;i<n;i++)
	{//find min vertex
		if(!visited[i]&&(minvertex==-1||distance[i]<distance[minvertex]))
			{
				minvertex=i;

			}
	}
	return minvertex;
}
void dijkstra(int**edge,int n)
{
	int*distance=new int[n];
	bool*visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		distance[i]=INT_MAX;
		visited[i]=false;
	}
	//distance of source or starting vertex
	distance[0]=0;
	for(int i=0;i<n-1;i++)
	{
		int minvertex=findminvertex(distance,visited,n);
		visited[minvertex]=true;
		for(int j=0;j<n;j++)
		{
			if(edge[minvertex][j]!=0&&!visited[j])
			{
				int dist=distance[minvertex]+edge[minvertex][j];
				if(dist<distance[j])
				{
					distance[j]=dist;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<i<<" "<<distance[i]<<endl;
	}
	delete [] visited;
	delete [] distance;
}
int main()
{
	int n,e;
	cin>>n>>e;
	int**edge=new int*[n];
	for(int i=0;i<n;i++)
	{
		edge[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			edge[i][j]=0;
		}
	}

	for(int i=0;i<e;i++)
	{
		int first,last,weight;
		cin>>first>>last>>weight;
		edge[first][last]=weight;
		edge[last][first]=weight;
	}

	cout<<endl;
	dijkstra(edge,n);

	for(int i=0;i<n;i++)
	{
		delete [] edge[i];
	}
	delete[] edge;
}

/*5 7
0 4 1
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9
3 4 4*/

