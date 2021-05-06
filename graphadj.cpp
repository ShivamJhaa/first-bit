#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>*l;

    public:
    Graph(int d)
    {
        v=d;
        l= new list<int>[v];
    }

    void addEdge(int u,int v,bool bidirect=true)
    {
        l[u].push_back(v);
        if (bidirect)
        {
            l[v].push_back(u);
        }
    }

    void printAdjacentList()
    {
        for (int i=0;i<v;i++)
        {
            cout<<i<<" -> ";
            for (auto vertex:l[i])
            {
                cout<<vertex<<" ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printAdjacentList();

    return 0;
}