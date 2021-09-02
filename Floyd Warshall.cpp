vector<vector<int>> floyd_warshall(int n, vector<vector<pair<int, int>>> &adj)
{

    //dist will contain the shortest distance between all possible pairs
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

        //kth phase
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
