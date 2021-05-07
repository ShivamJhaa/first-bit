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

};

int main()
{
    /*Graph<string> g;
    g.addEdge("Puitn","Trump",false);
    g.addEdge("Puitn","Modi",false);
    g.addEdge("Puitn","Pope",false);
    g.addEdge("Modi","Trump",true);
    g.addEdge("Modi","Yogi",true);
    g.addEdge("Yogi","Prabhu",false);
    g.addEdge("Prabhu","Modi",false);

    //g.Print();
    g.bfs("Puitn");*/

    Graph<int>g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);

    g.bfsdist(0);

    return 0;
}