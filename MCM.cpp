

#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];

//recursive approach
int solve(vector<int>A, int i, int j) {

    if (i + 1 >= j) {
        return 0;
    }

    int ans = INT_MAX;

    for (int k = i + 1; k <= j - 1; k++) {

        //cost for multiplying from i->j
        int cost = solve(A, i, k);
        cost += solve(A, k, j);
        //I have to multiply the final matrices which i get
        cost += A[i] * A[j] * A[k];
    }
    return ans;

}


int solve(vector<int> &A, int i, int j)
{

    //only one matrix
    if (j <= i + 1)
    {
        return 0;
    }

    int ans = INT_MAX;
    if (dp[i][j] == 0)
    {
        for (int pivot = i + 1; pivot <= j - 1; pivot++)
        {

            int cost = solve(A, i, pivot);
            cost += solve(A, pivot, j);
            cost += A[i] * A[pivot] * A[j];
            ans = min(cost, ans);
        }
        dp[i][j] = ans;
    }

    return dp[i][j];
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
    cin >> n;
    //VECTOR A REPRESENTS THE DIMENSIONS OF THE MATRICES BEING MULTIPLIED
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    memset(dp, 0, sizeof(dp));
    cout << solve(A, 0, n - 1) << endl;
}
