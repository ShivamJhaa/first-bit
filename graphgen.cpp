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

    g.Print();

    return 0;
}