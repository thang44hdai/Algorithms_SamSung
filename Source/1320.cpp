#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
int n, k;
int a[25];
vector<int> vt;
set<vector<int>> sol;
void Try(int i = 1, int sum = 0)
{
    if (sum > k)
        return;
    else if (sum == k)
    {
        sol.insert(vt);
        return;
    }
    for (int j = i; j <= n; j++)
    {
        vt.push_back(a[j]);
        Try(j, sum + a[j]);
        vt.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        Try();
        for (auto i : sol)
        {
            vector<int> a = i;
            cout << "[";
            for (int j = 0; j < a.size() - 1; j++)
                cout << a[j] << " ";
            cout << a[a.size() - 1] << "] ";
        }
        if (sol.size() == 0)
            cout << -1;
        sol.clear();
        cout << "\n";
    }
    return 0;
}
