#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> adjList;

    public:
    Graph()
    {

    }
    void addEdge(T u,T v,bool bidirect=true)
    {
        adjList[u].push_back(v);

        if (bidirect)
        {
            adjList[v].push_back(u);
        }
    }

    void Print()
    {
        for (auto i:adjList)
        {
            cout<<i.first<<" ->";
            {
                for (auto vertex:i.second)
                {
                    cout<<vertex<<" ";
                }
                cout<<endl;
            }
        }
    }

    void bfsdist(T src)
    {
        map<T,int>dist;
        queue<T>q;
        map<T,T>parent;

        for (auto i:adjList){
            dist[i.first]=INT32_MAX;
        }

        q.push(src);
        dist[src]=0;
        parent[src]=src;

        while(!q.empty())
        {
            T node =q.front();
            cout<<node<<" ";
            q.pop();

            for (auto neighbour:adjList[node])
            {
                if (dist[neighbour]==INT32_MAX)
                {
                    q.push(neighbour);
                   dist[neighbour]=dist[node]+1;
                   parent[neighbour]=node;
                }
            }
        }

        //Printing the distance

        for (auto i:adjList)
        {
            T node = i.first;

            cout<<"Distance of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }
    }

    //dfs

 void dfsHelper(T src,map<T,bool>&visited)
    {
        //whenever come to a node mark it visited
        visited[src]=true;
        cout<<src<<" ";
        //try to find out whether the next node is visted or not

        for(T neighbour:adjList[src])
        {
            if (!visited[neighbour])
            {
                dfsHelper(neighbour,visited);
            }
        }
    }

    void dfs(T src)
    {
        int component=1;
        map<T,bool>visited;
        dfsHelper(src,visited);
        cout<<endl;

        for (auto i:adjList)
        {
            T city =i.first;
            if (!visited[city])
            {
                dfsHelper(city,visited);
                component++;
            }
        }
        cout<<endl;
        cout<<"The no of components in this graph= "<<component<<endl;
    }
};

int main()
{

    /*Graph<int>g;

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.dfs(0);*/
    Graph<string>g1;
    g1.addEdge("A","J");
    g1.addEdge("Am","D");
    g1.addEdge("D","J");
    g1.addEdge("M","J");
    g1.addEdge("M","B");
    g1.addEdge("A","J");
    g1.addEdge("D","B");
    g1.addEdge("X","Y");
    g1.dfs("A");
    

    return 0;
}