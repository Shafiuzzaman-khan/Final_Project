#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stack>
using namespace std;

void DFS(int vertex, int **graph, int source, int *visited)
{
    stack<int>dfs_stack;
    visited[source] = 1;
    dfs_stack.push(source);
    while(!dfs_stack.empty())
    {
        int top = dfs_stack.top();
        dfs_stack.pop();
        for(int i = 0; i<vertex; i++)
        {
            if(graph[top][i] ==1 && visited[i] == 0)
            {
                dfs_stack.push(i);
                visited[i] = 1;
            }
        }
        visited[top] =2;
    }
}
int main()
{
    ifstream file;
    file.open("Database.txt");
    char x;
    file>>x;
    int n = x-64;
    int **Graph = new int *[n];
    for(int i=0; i<n; i++)
    {
        Graph[i] = new int [n];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            Graph[i][j] = 0;
        }
    }
    char ch1, ch2;
    while(!file.eof())
    {
        file>>ch1;
        file>>ch2;

        Graph[ch1-65][ch2-65] =1;
        Graph[ch2-65][ch1-65] =1;
    }
    cout<<"Scanned Graph is: \n"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<Graph[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<endl;

    int *visited = new int[n];
    int c=0;

    for(int i=0; i<n; i++)
    {
        if(visited[i] == 0)
        {
            DFS(n, Graph, i, visited);
            c++;
        }
    }

    cout<<"Maximum Number of Subgraph is:"<<c<<endl;
}
