#include <bits/stdc++.h>
using namespace std;
 
bool valid(vector<int> &ranks, int mid, int n, int p)
{
 
    int time = 0;
    int protas = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        time = ranks[i];
        int j = 2;
        while (time <= mid)
        {
            protas++;
            time += ranks[i] * j;
            j++;
        }
        if (protas >= p)
        {
            return true;
        }
    }
    return false;
}
 
void solve()
{
 
    int t;
    cin >> t;
    while (t--)
    {
        int p;
        cin >> p;
        int c;
        cin >> c;
        vector<int> ranks(c);
        for (int i = 0; i < c; i++)
        {
            cin >> ranks[i];
        }
 
        int s = 0;
        int e = 1e8;
        int ans;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (valid(ranks, mid, c, p))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        cout << ans << endl;
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
 
    solve();
} 
