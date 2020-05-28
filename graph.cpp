#include<bits/stdc++.h>
using namespace std;


void print(int**edge,int v,int sv,bool* visited)
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
        print(edge,v,i,visited);
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
    print(edge,v,0,visited);
}
