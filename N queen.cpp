#include <bits/stdc++.h>
using namespace std;
// Currently this isSafe function takes O(N^N) time complexity
bool isSafe(int board[][10], int i, int j, int n)
{
    // Check for the lower columns
    // Row by row fill kr rhe hai so upar ke cols mei check karne ki jroorat nahi hai
    for (int row = 0; row < i; row++)
    {
        if (board[row][j] == 1)
        {
            return false;
        }
    }

    // Check for Left Diagonal
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    // Check for Right Diagonal
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    // Position is safe after checking columns and diagonals.
    return true;
}

bool solveNQueen(int board[][10], int i, int n)
{
    // Base Case
    if (i == n)
    {
        // You have successfully placed queens in all n rows(0...n-1)
        // Print the Board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << "_ ";
                }
            }
            cout << endl;
        }

        cout << endl;
        // yaha return false likhne se hum correct configuration print karlenge aur saath hi saath pichle call ko false return kardenge jisse ki woh previous call ek naya configuration dhoondhega
        return false;
        //         return true;
    }

    // Iterating over the columns
    for (int j = 0; j < n; j++)
    {
        // Check if (i,j)th position is safe to place the queen.
        if (isSafe(board, i, j, n))
        {
            // Here we placed the queen assuming (i,j) is the right position
            board[i][j] = 1;
            // Now we call on remaining rows to check if they return true or false
            bool nextQueenRakhPaaye = solveNQueen(board, i + 1, n);
            if (nextQueenRakhPaaye)
            {
                return true;
            }

            // When control reaches here it means i,j is not the right position -Assumption is wrong
            board[i][j] = 0; // Backtracking
        }
    }
    // We have tried for all positions in current row and couldnt place a queen.
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
    int n;
    cin >> n; // No of rows and columns.
    int i = 0;
    int board[10][10] = {0};
    solveNQueen(board, i, n);

    return 0;
}
