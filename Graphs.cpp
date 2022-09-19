#include <bits/stdc++.h>
using namespace std;

class Graph
{
    list<int> *l;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v]; // allocating a array of list
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList()
    {
        // Iterate over vertices
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << " ";
            for (int x : l[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjList();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation for generic data
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> l;

public:
    void addEdge(T x, T y, bool bidir, int wt)
    {

        l[x].push_back(make_pair(y, wt));
        if (bidir)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void printAdjList()
    {
        // Iterate over the keys
        for (auto p : l)
        {
            T city = p.first;
            list<pair<T, int>> nbrs = p.second;
            cout << city << "--> ";
            for (auto nbr : nbrs)
            {
                T dest = nbr.first;
                int dist = nbr.second;

                cout << dest << " " << dist << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("a", "b", true, 20);
    g.addEdge("b", "d", true, 40);
    g.addEdge("a", "c", true, 10);
    g.addEdge("c", "d", true, 40);
    g.addEdge("a", "d", false, 50);
    g.printAdjList();
    return 0;
}

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
// //////////////////////////////////////////////////////////////////////////////////////////////
// //Graph Traversal

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

//////////////////////////////////////////////////////////////////////////////////////////////////
// Snake and ladder problem
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
        // l[y].push_back(x);
    }

    void bfs(T src, T dest)
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

    // Single source shortest path problem in unweighted graph
    int bfsSSSP(T src, T dest)
    {
        map<T, int> dist;
        map<T, T> parent; // this map will store the value of the parent nodes
        queue<T> q;
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;
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
                    parent[nbr] = node; // Storing parent node of each node of the graph
                }
            }
        }
        // Print the dist to every node
        //  for (auto node_pair : l)
        //  {
        //      T node = node_pair.first;
        //      int d = dist[node];
        //      cout << "Node " << node << " D from src " << d << endl;
        //  }
        // Print path
        T temp = dest;
        while (temp != src)
        {
            cout << temp << "<--";
            temp = parent[temp];
        }
        cout << src << "<--";
        cout << endl;
        // return number of die throws
        return dist[dest];
    }
};

int main()
{
    // Already listing the jump at each position on the board +ve indicates ladder -ve indicates snake
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    // Add all edges to the graph
    Graph<int> g;
    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];
            if (j <= 36)
            {
                g.addEdge(i, j); // Unweighted directed edges
            }
        }
    }
    g.addEdge(36, 36);
    cout << g.bfsSSSP(0, 36);
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////

// Disjoint Set Union Algorithm

/*
There are N cities numbered 0-(N-1) chhose two cities which do not have a path between them
(basically matlab they must be parts of different connected components)

There are total M undirected paths given as pairs (X,Y)

eg

5 3
0 1
2 3
0 4

We have to find out number of ways in which city can be chosen
*/

#include <bits/stdc++.h>
using namespace std;
class dsu
{

public:
    vector<int> par, sz;
    int total_comp;
    void init(int n)
    {

        par.resize(n);
        sz.resize(n); // Size vector basically batayega ki ek element kitne doosre elements ka superparent hai(isko sabke liye 1 se initialize karenge)

        for (int i = 0; i < n; i++)
        {
            par[i] = i; // Initially we will have each element of the set as its parent
            sz[i] = 1;  // Since initially every element is its own parent and superparent
        }

        total_comp = n; // This will contain the total number of components
    }

    int get_superparent(int x)
    {

        // Base case
        if (x == par[x])
        {

            return x;
        }
        else
        {
            // This is example of path compression mskes it an O(1) operation
            return par[x] = get_superparent(par[x]);
        }
    }

    void unite(int x, int y)
    {
        // this function will tell me which cities have been connected and will accordingly change their superparents
        int super_parent_x = get_superparent(x);
        int super_parent_y = get_superparent(y);

        // if superparents are not equal then it means we need to connect them since they are parts of different connected components
        if (super_parent_x != super_parent_y)
        {

            par[super_parent_x] = super_parent_y;
            // Now superparent of x is also y so we update sz vector for y(sz[super_parent_y] will give total number of elements having super_parent_y as superparent)
            sz[super_parent_y] += sz[super_parent_x];
            sz[super_parent_x] = 0; // Becasue now super_parent_x is no longer superparent of any set of points ab woh y se connect hogaya hai.size vector mei sirf un elements ki value non zero hogi jo kisi connected component ke superparent hai
            // On merging one connected component will be reduced
            total_comp--;
        }
    }
};

int32_t main()
{

    int n, m;
    cin >> n >> m;
    dsu obj;
    obj.init(n); // Initialize with n
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        obj.unite(x, y);
    }
    int ans = 0;
    // all elements will now be in their connected components
    for (int i = 0; i < n; i++)
    {
        // i is being considered as x
        int super_parent_i = obj.get_superparent(i);
        ans += n - obj.sz[super_parent_i];
    }

    cout << ans / 2 << endl; // Since graph is undirected so divide by 2
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cycle detection using DSU algorithm O(m) since there are m edges and path compression is constant time
// Basically is we are making a connection between to nodes and we find that those two nodes are already part of same component(have the same superparent) then we can say cycle exists
#include <bits/stdc++.h>
using namespace std;

class dsu
{

public:
    vector<int> par, sz;
    int total_comp;
    void init(int n)
    {

        par.resize(n);
        sz.resize(n); // Size vector basically batayega ki ek element kitne doosre elements ka superparent hai(isko sabke liye 1 se initialize karenge)

        for (int i = 0; i < n; i++)
        {
            par[i] = i; // Initially we will have each element of the set as its parent
            sz[i] = 1;  // Since initially every element is its own parent and superparent
        }

        total_comp = n; // This will contain the total number of components
    }

    int get_superparent(int x)
    {

        // Base case
        if (x == par[x])
        {

            return x;
        }
        else
        {
            // This is example of path compression mskes it an O(1) operation
            return par[x] = get_superparent(par[x]);
        }
    }

    void unite(int x, int y)
    {

        // this function will tell me which cities have been connected and will accordingly change their superparents

        int super_parent_x = get_superparent(x);
        int super_parent_y = get_superparent(y);

        // if superparents are not equal then it means we need to connect them since they are parts of different connected components
        if (super_parent_x != super_parent_y)
        {

            par[super_parent_x] = super_parent_y;
            // Now superparent of x is also y so we update sz vector for y(sz[super_parent_y] will give total number of elements having super_parent_y as superparent)
            sz[super_parent_y] += sz[super_parent_x];
            sz[super_parent_x] = 0; // Becasue now super_parent_x is no longer superparent of any set of points ab woh y se connect hogaya hai.size vector mei sirf un elements ki value non zero hogi jo kisi connected component ke superparent hai
            // On merging one connected component will be reduced
            total_comp--;
        }
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    dsu obj;
    obj.init(n); // Initialize with n
    bool cycle = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        // obj.unite(x, y);
        // x and y are in different components
        if (obj.get_superparent(x) != obj.get_superparent(y))
        {
            obj.unite(x, y);
        }
        else
        {
            // It means x and y are in same component
            // So there a;ready exits a path between x and y
            cycle = 1;
            break;
        }
    }

    if (cycle)
    {
        cout << "Cycle exists in Graph" << endl;
    }
    else
    {
        cout << "No cycle in Graph" << endl;
    }
    int ans = 0;
    // all elements will now be in their connected components
    for (int i = 0; i < n; i++)
    {
        // i is being considered as x
        int super_parent_i = obj.get_superparent(i);
        ans += n - obj.sz[super_parent_i];
    }

    cout << ans / 2 << endl; // Since graph is undirected so divide by 2
}

///////////////////////////////////////////////////////////////////////////////////////////
// Krukskal's algo for MST
#include <bits/stdc++.h>
using namespace std;

class dsu
{
public:
    vector<int> par, sz;
    int total_comp;
    void init(int n)
    {
        par.resize(n);
        sz.resize(n); // Size vector basically batayega ki ek element kitne doosre elements ka superparent hai(isko sabke liye 1 se initialize karenge)

        for (int i = 0; i < n; i++)
        {
            par[i] = i; // Initially we will have each element of the set as its parent
            sz[i] = 1;  // Since initially every element is its own parent and superparent
        }
        total_comp = n; // This will contain the total number of components
    }

    // O(1)
    int get_superparent(int x)
    {
        // Base case
        if (x == par[x])
        {

            return x;
        }
        else
        {
            // This is example of path compression mskes it an O(1) operation
            return par[x] = get_superparent(par[x]);
        }
    }

    // O(1)
    void unite(int x, int y)
    {
        // this function will tell me which cities have been connected and will accordingly change their superparents
        int super_parent_x = get_superparent(x);
        int super_parent_y = get_superparent(y);
        // if superparents are not equal then it means we need to connect them since they are parts of different connected components
        if (super_parent_x != super_parent_y)
        {

            par[super_parent_x] = super_parent_y;
            // Now superparent of x is also y so we update sz vector for y(sz[super_parent_y] will give total number of elements having super_parent_y as superparent)
            sz[super_parent_y] += sz[super_parent_x];
            sz[super_parent_x] = 0; // Becasue now super_parent_x is no longer superparent of any set of points ab woh y se connect hogaya hai.size vector mei sirf un elements ki value non zero hogi jo kisi connected component ke superparent hai
            // On merging one connected component will be reduced
            total_comp--;
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
    int n, m, ans;
    ans = 0;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        // Graph is 1 based indexing so we need to change into 0 based(to match conditions in our code)
        x--;
        y--;
        // Sorting happens according to first value in pair
        edges[i] = {w, x, y};
    }
    // Now we need to sort edges according to weights
    sort(edges.begin(), edges.end());
    dsu G;
    G.init(n);
    for (int i = 0; i < m; ++i)
    {
        int x = edges[i][1];
        int y = edges[i][2];
        int w = edges[i][0];

        // No cycle should be formed
        if (G.get_superparent(x) != G.get_superparent(y))
        {
            G.unite(x, y);
            cout << w << " " << x << " " << y << endl;
            // include all edges which dont form a cycle
            ans += w;
        }
    }
    cout << ans << endl;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MST using Prim's Algorithm O(ElogV)
#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v[n + 1];
    int visited[n + 1]{0};
    long long int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back({y, w});
        v[y].push_back({x, w});
    }
    // this will maintain the distance of all nodes from the current node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // We are already putting source node in the priority queue
    Q.push({0, 1});
    // weight,node
    while (!Q.empty())
    {
        pair<int, int> best = Q.top();
        Q.pop();
        int weight = best.first;
        int to_which_node = best.second;
        // not an active edge
        if (visited[to_which_node])
        {
            continue;
        }
        visited[to_which_node] = 1;
        ans += weight;
        // Otherwise choose min weight path to one of the neighbours
        for (auto p : v[to_which_node])
        {
            // Means we have not visited the node so push all possible nodes from this node to the next node(ie,. the edge is an active edge)
            if (!visited[p.first])
            {
                Q.push({p.second, p.first});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bellman Ford Algorithm
#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(vector<vector<int>> gr, int src, int n)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    // relax all edges n-1 times
    // This step will be O(EV) complexity since E-1 iterations and we process V vertices
    // Basically we are solving wrt to the worst case of the algorithm and not throughe bst case so in worst case we need to go through n-1 iterations
    for (int i = 0; i < n - 1; i++)
    {
        for (auto x : gr)
        {
            int from = x[0];
            int to = x[1];
            int weight = x[2];
            // Relax the edges
            // dist[from] means dist of from from source and dist[to] means dist of to from src
            if (dist[from] != INT_MAX && dist[to] > dist[from] + weight)
            { // We have to prevent overflow
                dist[to] = dist[from] + weight;
            }
        }
    }

    // Now check for negative cycle(basically matlab if we can further relax and edge after all n-1 iterations isla matlab negative cycle exists)
    for (auto x : gr)
    {
        int from = x[0];
        int to = x[1];
        int weight = x[2];

        // Relax the edges
        if (dist[from] != INT_MAX && dist[to] > dist[from] + weight)
        { // We have to prevent overflow
            // if any edge is further being relaxed then negative weight cycle hai
            cout << "Negative Weight Cycle Exists" << endl;
            exit(0);
        }
    }
    return dist;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, from, to, w;
    cin >> n >> m;

    vector<vector<int>> gr;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> w;
        gr.push_back({from, to, w});
    }

    vector<int> dist = bellman_ford(gr, 1, n);
    for (int i = 1; i < dist.size(); i++)
    {
        cout << "Dist from source to " << i << " is " << dist[i] << endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Floyd Warshall Algo

/*
2 basic conditions
if(d[i][j]>d[i][k]+d[k][j]){
    d[i][j]=d[i][k]+d[k][j]
}
path[i][j]=path[k][j];
*/

// O(v^3)
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floyd_warshall(int n, vector<vector<pair<int, int>>> &adj)
{

    // dist will contain the shortest distance between all possible pairs
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 2e9));
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
        for (auto edges : adj[i])
        {
            int nbr = edges.first;
            int weight = edges.second;
            dist[i][nbr] = weight;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        // kth phase
        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= n; j++)
            {

                if (dist[i][k] == 2e9 || dist[k][j] == 2e9)
                {
                    continue;
                }

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "Negative weight cycle exists" << endl;
            exit(0);
        }
    }

    return dist;
}
// better code
void floyd_warshall(vector<vector<int>> &gr, int v, int e)
{

    // choose phases
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (gr[i][k] == INT_MAX || gr[k][j] == INT_MAX)
                {
                    continue;
                }
                gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << i << " to " << j << " min path is of dist " << gr[i][j] << " units" << endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e;
    cin >> v >> e;
    vector<vector<int>> gr(v, vector<int>(v, INT_MAX));
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
            {
                gr[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < e; i++)
    {
        int from, to, wt;
        cin >> from >> to >> wt;
        gr[from][to] = wt;
    }
    floyd_warshall(gr, v, e);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bipartite Graph Check
#include <bits/stdc++.h>
using namespace std;
#define N 100005
vector<int> gr[N];
// In this array we are declaring 0 as not coloured,1 as coloured with first colour and 2 as colored with second color
int vis[N]{0};
bool odd_cycle = false;
void dfs(int curr, int par, int col)
{

    vis[curr] = col;
    for (auto nbrs : gr[curr])
    {
        if (vis[nbrs] == 0)
        {
            // Not been visited yet
            dfs(nbrs, curr, 3 - col); // col can be passsed either as 1 or 2
        }
        else if (nbrs != par && vis[nbrs] == col)
        { // cycle detection check and confirming color
            odd_cycle = true;
            return;
        }
    }
    return;
}

void bipartite_graph()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    // there can be more than one component in the graphx
    for (int i = 0; i < gr.size(); i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, 1);
        }
    }

    if (odd_cycle)
    {
        cout << "Odd Cycle exists and graph is not bipartite\n";
    }
    else
    {
        cout << "Graph is bipartite\n";
    }
    return;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int curr = 1;
    int par = 0;
    bipartite_graph();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Kusrajus Algorithm for Strongly Connected Components
#include <bits/stdc++.h>
using namespace std;
#define N 100005
vector<int> gr[N], grr[N];

// In this array we are declaring 0 as not coloured,1 as coloured with first colour and 2 as colored with second color
int vis[N]{0};
// int component[N]{ 0 };
vector<int> order;

vector<int> component[N];

bool odd_cycle = false;

void dfs(int curr)
{
    vis[curr] = 1;
    for (auto nbr : gr[curr])
    {
        if (!vis[nbr])
        {
            dfs(nbr);
        }
    }
    // Once we have visited all neighbours then push into order vector
    order.push_back(curr);
    return;
}

void dfs_reverse(int curr, int col)
{
    component[col].push_back(curr);
    vis[curr] = 1;
    for (auto nbr : grr[curr])
    {
        if (!vis[nbr])
        {
            dfs_reverse(nbr, col);
        }
    }
    return;
}

void kusrajus()
{
    int n, m;
    cin >> n >> m;

    // Create graph
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        grr[y].push_back(x);
    }

    // Now create order array
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    // reset the visited array and perfom dfs on reversed array
    memset(vis, 0, sizeof(vis));

    // check in the reversed graph
    // we can also pass a color argument which would show if nodes are part of the same component
    int col = 1;
    for (int i = n; i >= 1; i--)
    {
        if (!vis[order[i]])
        {
            dfs_reverse(order[i], col);
            col++; // pass a new color for coloring next strongly connected component
        }
    }

    // print the strongly connected components
    //  for (int i=1;i<=n;i++) {
    //      cout<<i<<"-->"<<component[i]<<endl;
    //  }

    for (auto comps : component)
    {
        for (auto nodes : comps)
        {
            cout << nodes << " ";
        }
        cout << '\n';
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int curr=1;
    // int par=0;
    kusrajus();
    return 0;
}

////////////////////////////////////////////////////////
/*
You are given a graph with N vertices and M edges. Master parent is the vertex which has no parent but may have 0 or more children. In any connected component of the graph, vertex with the lowest value in that component serves as the master parent. A vertex is called beautiful if it has more children than its parent. Count the number of beautiful vertices in the given graph. The graph has no cycles or self loops.

Input Format
First line consists of two space separated integers denoting N and M and the following M lines consist of two space separated integers X and Y denoting there is an edge between vertices X and Y.

Constraints
1 <= N <= 100000 0 <= M <= N-1 1 <= x,y <= N

Output Format
Print the number of beautiful vertices in the graph.

Sample Input
4 3
1 2
2 3
2 4
Sample Output
1
Explanation
In this graph, we have vertices 1,2,3 and 4. Since 1 is the lowest among these, so it becomes the master vertex. Now, 1 has only 1 child while 2 has two children.So, 2 is a beautiful vertex. There are no more beautiful vertices in the graph.

*/

#include <bits/stdc++.h>
using namespace std;
map<int, int> no_of_child;
map<int, int> parent;
map<int, bool> visited;
void dfs(int src, map<int, list<int>> &gr)
{
    visited[src] = true;
    for (auto child : gr[src])
    {
        if (!visited[child])
        {
            parent[child] = src;
            no_of_child[src]++;
            dfs(child, gr);
        }
    }
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, list<int>> gr;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    // visited[1]=true;
    parent[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        // this will help us choose the superparent of each component which will be the smalles node in the component
        if (!visited[i])
        {
            dfs(i, gr);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] > 0 && no_of_child[i] > no_of_child[parent[i]])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

////////////////////////////////////////////////////////////
/*
You are given a graph with N vertices and M edges. Master parent is the vertex which has no parent but may have 0 or more children. In any connected component of the graph, vertex with the lowest value in that component serves as the master parent. A vertex is called beautiful if it has more children than its parent. Count the number of beautiful vertices in the given graph. The graph has no cycles or self loops.
Input Format

First line consists of two space separated integers denoting N and M and the following M lines consist of two space separated integers X and Y denoting there is an edge between vertices X and Y.
Constraints

1 <= N <= 100000 0 <= M <= N-1 1 <= x,y <= N
Output Format

Print the number of beautiful vertices in the graph.
Sample Input

4 3
1 2
2 3
2 4

Sample Output

1

Explanation
In this graph, we have vertices 1,2,3 and 4. Since 1 is the lowest among these, so it becomes the master vertex. Now, 1 has only 1 child while 2 has two children.So, 2 is a beautiful vertex. There are no more beautiful vertices in the graph.
*/

#include <bits/stdc++.h>
using namespace std;
map<int, int> no_of_child;
map<int, int> parent;
map<int, bool> visited;
void dfs(int src, map<int, list<int>> &gr)
{
    visited[src] = true;
    for (auto child : gr[src])
    {
        if (!visited[child])
        {
            parent[child] = src;
            no_of_child[src]++;
            dfs(child, gr);
        }
    }
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, list<int>> gr;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    // visited[1]=true;
    parent[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, gr);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] > 0 && no_of_child[i] > no_of_child[parent[i]])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

select salary from emp1
        where n -
    1 = (select count(distinct(salary)) from emp2 where emp2.salary >= emp1.salary)
