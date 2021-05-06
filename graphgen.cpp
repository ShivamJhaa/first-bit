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

    void bfs(T src)
    {
        map<T,bool>visited;
        queue<T>q;

        q.push(src);
        visited[src]=true;

        while(!q.empty())
        {
            T node =q.front();
            cout<<node<<" ";
            q.pop();

            for (auto neighbour:adjList[node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }

};

int main()
{
    Graph<string> g;
    g.addEdge("Puitn","Trump",false);
    g.addEdge("Puitn","Modi",false);
    g.addEdge("Puitn","Pope",false);
    g.addEdge("Modi","Trump",true);
    g.addEdge("Modi","Yogi",true);
    g.addEdge("Yogi","Prabhu",false);
    g.addEdge("Prabhu","Modi",false);

    //g.Print();
    g.bfs("Puitn");

    return 0;
}