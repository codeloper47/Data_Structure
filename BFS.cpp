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
    void bfs(int s)
    {
        map<int, bool> visited;
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty())
        {
            int node = q.front();
            cout << node << "->";
            q.pop();
            for (auto nbrs : m[node])
            {
                if (!visited[nbrs])
                {
                    q.push(nbrs);
                    visited[nbrs] = true;
                }
            }
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
    g.bfs(0);
    return 0;
}
