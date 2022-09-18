#include <iostream>
using namespace std;

bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n)
{
    // Base case
    // this will be reached when we finally reach the end of the matrix where we mark the cell as 1 and print the path
    if (i == m && j == n)
    {
        soln[m][n] = 1;
        // Print the path
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    // Recursive Cases
    // Rat Should be inside Grid
    if (i > m || j > n)
    {
        return false;
    }

    // The block which we chose to start with is blocked or the cell which we reach is blocked
    if (maze[i][j] == 'X')
    {
        return false;
    }

    // Assume path exists through current cell
    soln[i][j] = 1;
    // Call recursive function on remaining part of the maze
    bool rightsuccess = ratInMaze(maze, soln, i, j + 1, m, n);
    bool downsuccess = ratInMaze(maze, soln, i + 1, j, m, n);
    // Backtracking
    soln[i][j] = 0; // Basically this means that after returning true or false from a cell we are setting it as false so that next call mei ek alag path mil paaye
    if (rightsuccess || downsuccess)
    {
        return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    int soln[10][10] = {0};
    int m = 4, n = 4;
    bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
    if (ans == false)
    {
        cout << "Path doesnt exist";
    }
    return 0;
}
