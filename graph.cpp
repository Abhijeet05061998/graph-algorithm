#include<bits/stdc++.h>
using namespace std;
void printDFS(int**edge,int v,int sv,bool* visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<v;i++)
    {
         if(sv==i)
    {
        continue;
    }
    if(edge[sv][i]==1)
    {
        if(visited[i])
        {
            continue;
        }
        printDFS(edge,v,i,visited);
    }

  }
}

void printBFS(int**edge,int n,int sv)
{
    queue<int>pendingvertices;
    bool*visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    pendingvertices.push(sv);
    visited[sv]=true;
    while(pendingvertices.size()!=0)
    {
        int currentvertex=pendingvertices.front();
        pendingvertices.pop();
        cout<<currentvertex<<endl;
        for(int i=0;i<n;i++)
        {
            if(i==currentvertex)
            {
                continue;
            }
            if(edge[currentvertex][i]==1&&  !visited[i])
            {
                pendingvertices.push(i);
                visited[i]=true;
            }
        }
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    int**edge=new int*[v];
     for(int i=0;i<v;i++)
    {
        edge[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            edge[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int first,second;
        cin>>first>>second;
        edge[first][second]=1;
        edge[second][first]=1;
    }
    bool*visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    cout<<"DFS:"<<endl;
    printDFS(edge,v,0,visited);

    cout<<"BFS:"<<endl;
    printBFS(edge,v,0);
}
