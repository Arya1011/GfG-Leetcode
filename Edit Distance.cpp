#include<bits/stdc++.h>
using namespace std;

int solve(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    if (n == 0)
    {
        return m;
    }

    if (m == 0)
    {
        return n;
    }

    int dp[n + 1][m + 1];

    //dp[i][j] stores the edit dist for strings of len i and j
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i==0 || j==0){
                dp[i][j]=max(i,j);
            }

             else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = 1+min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }
    return dp[n][m];
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;
        string s1, s2;
        cin >> s1 >> s2;
        cout << solve(s1, s2) << endl;
    }
    return 0;
}
