#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    deque<int> g, s;
    vector<int> arr{2, 5, -1, 7, -3, -1, -2};
    int n = arr.size();
    int k;
    cin >> k;
    int i = 0;
    //first k elements
    while (i < k) {


        while (!g.empty() && arr[g.back()] < arr[i]) {
            g.pop_back();
        }

        while (!s.empty() && arr[s.back()] > arr[i]) {
            s.pop_back();
        }

        g.push_back(i);
        s.push_back(i);
        i++;
    }

    int sum = 0;


    for (; i < n; i++) {

        sum += arr[s.front()] + arr[g.front()];

        //not in range
        while (!s.empty() && s.front() <= i - k) {
            s.pop_front();
        }

        while (!g.empty() && g.front() <= i - k) {
            g.pop_front();
        }

        while (!s.empty() && arr[s.back()] >= arr[i]) {
            s.pop_back();
        }

        while (!g.empty() && arr[g.back()] <= arr[i]) {
            g.pop_back();
        }

    }


    if (!s.empty()) {

        sum += arr[s.front()] < arr[s.back()] ? arr[s.front()] : arr[s.back()];

    }

    if (!g.empty()) {
        sum += arr[g.front()] > arr[g.back()] ? arr[g.front()] : arr[g.back()];
    }


    cout << sum << endl;
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
