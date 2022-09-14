#include <bits/stdc++.h>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;

        l = new list<int>[V];
    }

    // Here context is to find if a graph is a tree or not so a tree will never be a graph that has a cycle
    bool cycle_detection_bfs_undirected()
    {
        bool *visited = new bool[V];
        int *parent = new int[V];
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            parent[i] = i;
        }
        int src = 0;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto nbr : l[node])
            {
                if (visited[nbr] and parent[node] != nbr) // Second condition means that the node should not be the parent of the nbr node (since for cycle we need some other way to reach tha node othe than parent)
                {
                    // this means cycle is present
                    return false;
                }
                else if (!visited[nbr])
                {
                    // if node has not been visited then we need to assign a parent and set visited as true
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }

    bool cycle_detection_dfs_directed_helper(int node, bool *visited, bool *stack)
    {
        visited[node] = true;
        stack[node] = true; // this just tells us what are the nodes in the current path of the graph
        for (auto nbr : l[node])
        {
            // this is the case where we ar at a node jiska nbr is involved in a cycle
            if (stack[nbr] == true)
            {
                return true;
            }

            else if (!visited[nbr])
            {
                // Calling on neigbours and checking if they are part of a cycle
                bool cycle_mila = cycle_detection_dfs_directed_helper(nbr, visited, stack);
                if (cycle_mila)
                {
                    return true;
                }
            }
        }
        stack[node] = false;
        return false;
    }

    bool cycle_detection_dfs_directed()
    {
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = stack[i] = false;
        }
        return cycle_detection_dfs_directed_helper(0, visited, stack);
    }

    bool cycle_detection_dfs_undirected_helper(int node, bool *visited, int parent)
    {
        visited[node] = true;
        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                // Recursively call to other nodes from that neighbour
                bool cycle_mila = cycle_detection_dfs_undirected_helper(nbr, visited, node);
                if (cycle_mila)
                {
                    return true;
                }
            }
            else if (nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool cycle_detection_dfs_undirected()
    {
        bool *visited = new bool[V];
        // First mark all visited as false
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && cycle_detection_dfs_undirected_helper(i, visited, -1))
            {
                return true;
            }
        }
        return false;
    }

    void addEdge(int x, int y)
    {

        l[x].push_back(y); // If both lines present its a undirected graph
        // l[y].push_back(x); //If this line is removed it means its a directed graph(in all topological_sort cases)
    }

    // Kahns Algorithm
    void topological_sort_bfs() // for acyclic directed graphs
    {
        // indegree of each vertex will be 0 initially
        int *indegree = new int[V];
        for (int i = 0; i < V; i++)
        {
            indegree[i] = 0;
        }

        // update the indegree of each vertex
        for (int i = 0; i < V; i++)
        {
            for (auto y : l[i])
            {
                indegree[y]++;
            }
        }
        // apply bfs
        // first find 0 indegree nodes and push them in queue
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // while removing nodes from the queue also decrease indegree of neighbours by 1
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();
            // Iterate over nbrs and reduce indegree by 1
            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
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
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    // g.addEdge(2, 5);
    // g.addEdge(4, 5);
    // g.addEdge(3, 5);
    // cout << g.cycle_detection_bfs_undirected();
    // if (g.cycle_detection_dfs_undirected())
    // {
    //     cout << "Cycle Exists" << endl;
    // }
    // else
    // {
    //     cout << "No cycle" << endl;
    // }
    // g.topological_sort_bfs();
    cout << g.cycle_detection_dfs_directed() << endl;
}
