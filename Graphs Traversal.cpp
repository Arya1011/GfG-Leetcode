#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{

    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);

        // dont use bidirectional edge when using DFS for directed graph
        // l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited)
    {
        cout << src << " ";
        // Initialize the src as visited
        visited[src] = true;
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                // Recursively call the dfs_helper on the remaining nodes
                dfs_helper(nbr, visited);
            }
        }
        return;
    }

    void topological_sort_dfs_helper(T src, map<T, bool> &visited, list<T> &ordering)
    {

        visited[src] = true;

        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                topological_sort_dfs_helper(nbr, visited, ordering);
            }
        }
        ordering.push_front(src);
        return;
    }

    void topological_sort_dfs()
    {
        map<T, bool> visited;
        list<T> ordering;
        // Mark all the nodes as not visited in the beginning
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // call helper function
        for (auto p : l)
        {
            T node = p.first;
            if (!visited[node])
            {
                topological_sort_dfs_helper(node, visited, ordering);
            }
        }
        for (auto it : ordering)
        {
            cout << it << endl;
        }
    }

    void connectedComponents()
    {
        map<T, bool> visited;
        // Mark all the nodes as not visited in the beginning
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // Iterate over the vertices and init dfs call
        int cnt = 1;
        for (auto p : l)
        {
            T node = p.first;

            if (!visited[node])
            {
                cout << "Component " << cnt << ":";
                dfs_helper(node, visited);
                cout << endl;
                cnt++;
            }
        }
    }

    void dfs(T src)
    {
        map<T, bool> visited;
        // Mark all the nodes as not visited in the beginning
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // Call the helper
        dfs_helper(src, visited);
    }

    void bfs(T src)
    {
        map<T, bool> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            // Jab visit kr liya toh remove from queue
            T node = q.front();
            q.pop();

            cout << node << " ";

            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    // If neighbour not visited push it into queue
                    q.push(nbr);
                    // Mark it as visited
                    visited[nbr] = true;
                }
            }
        }
    }

    // Single source shortest path problem in unweighted,undirected graph
    void bfsSSSP(T src)
    {
        map<T, int> dist;

        queue<T> q;

        for (auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            // Jab visit kr liya toh remove from queue
            T node = q.front();
            q.pop();

            // cout << node << " ";

            for (auto nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    // If neighbour not visited push it into queue
                    q.push(nbr);
                    // Mark distance of each child node as parent node ka dist +1 since woh waale node parent node se 1 dist pe hoyenge
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        // Print the dist to every node
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout << "Node " << node << " Dist from src " << d << endl;
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph<int> g;

    // g.addEdge("Python", "Data Preprocessing");
    // g.addEdge("Python", "Pytorch");
    // g.addEdge("Python", "ML Basics");
    // g.addEdge("Pytorch", "Deep Learning");
    // g.addEdge("Data Preprocessing", "ML Basics");
    // g.addEdge("ML Basics", "Deep Learning");
    // g.addEdge("Deep Learning", "Face Recognition");
    // g.addEdge("Data set", "Face Recognition");

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(8, 8);

    // g.bfs(0);
    // g.dfs(0);
    g.bfsSSSP(0);

    // g.connectedComponents();

    // g.topologicalSort();

    return 0;
}
