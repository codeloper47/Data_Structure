#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{
    map<int, list<int>> m;

public:
    void insert(int x, int y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }

    void disp()
    {
        for (auto a : m)
        {
            cout << a.first << " -> ";
            for (auto nbrs : a.second)
            {
                cout << nbrs << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    int e;
    cin >> e;
    Graph g;
    int x, y;
    while (e--)
    {
        cin >> x >> y;
        g.insert(x, y);
    }
    g.disp();
    return 0;
}
