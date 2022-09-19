#include <bits/stdc++.h>
using namespace std;

void query(priority_queue<int, vector<int>, greater<int>> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return;
}

int main()
{
    // To find largest k numbers whenever a query of -1 is made
    int no;
    int cs = 0;
    int k;
    cin >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (scanf("%d", &no) != EOF)
    {

        if (no == -1)
        {
            query(pq);
        }
        else if (cs < k)
        {
            pq.push(no);
            cs++;
        }
        else
        {
            if (no > pq.top())
            {
                pq.pop();
                pq.push(no);
            }
        }
    }
}
