#include <iostream>
#include <map>
#include <list>
#include <queue>
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

    void dfs_call(int s, map<int, bool> &visited)
    {
        cout << s << " ->";
        visited[s] = true;
        for (auto nbrs : m[s])
        {
            if (!visited[nbrs])
            {
                dfs_call(nbrs, visited);
            }
        }
    }
    void dfs()
    {
        map<int, bool> visited;
        for (auto x : m)
        {
            visited[x.first] = false;
        }
        dfs_call(0, visited);
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
    g.dfs();
    return 0;
}
