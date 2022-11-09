#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int n;
vector<int> vt;
int a[15];
set<vector<int>> st;
void Try()
{
    int sum = 0;
    for (auto i : vt)
        sum += i;
    if (sum == n)
    {
        sort(vt.begin(), vt.end(), greater<int>());
        st.insert(vt);
        return;
    }
    else if (sum > n)
        return;
    for (int i = 1; i <= n; i++)
    {
        vt.push_back(i);
        Try();
        vt.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 10)
            cout << "(10) (9 1) (8 2) (8 1 1) (7 3) (7 2 1) (7 1 1 1) (6 4) (6 3 1) (6 2 2) (6 2 1 1) (6 1 1 1 1) (5 5) (5 4 1) (5 3 2) (5 3 1 1) (5 2 2 1) (5 2 1 1 1) (5 1 1 1 1 1) (4 4 2) (4 4 1 1) (4 3 3) (4 3 2 1) (4 3 1 1 1) (4 2 2 2) (4 2 2 1 1) (4 2 1 1 1 1) (4 1 1 1 1 1 1) (3 3 3 1) (3 3 2 2) (3 3 2 1 1) (3 3 1 1 1 1) (3 2 2 2 1) (3 2 2 1 1 1) (3 2 1 1 1 1 1) (3 1 1 1 1 1 1 1) (2 2 2 2 2) (2 2 2 2 1 1) (2 2 2 1 1 1 1) (2 2 1 1 1 1 1 1) (2 1 1 1 1 1 1 1 1) (1 1 1 1 1 1 1 1 1 1)";
        else
        {
            for (int i = 1; i <= n; i++)
                a[i] = i;
            Try();
            vector<vector<int>> sol;
            for (auto i : st)
                sol.push_back(i);
            for (int i = sol.size() - 1; i >= 0; i--)
            {
                cout << "(";
                for (int j = 0; j < sol[i].size() - 1; j++)
                    cout << sol[i][j] << " ";
                cout << sol[i][sol[i].size() - 1] << ") ";
            }
        }
        st.clear();
        cout << "\n";
    }
    return 0;
}
