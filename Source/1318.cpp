#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int n;
int a[15][15];
int ok[15][15];
vector<char> vt;
vector<vector<char>> sol;
void Try(int i = 1, int j = 1)
{
    if (i == n and j == n and a[i][j] == 1 and ok[i][j] == 1)
    {
        sol.push_back(vt);
        return;
    }
    if (i + 1 <= n and a[i + 1][j] == 1 and ok[i + 1][j] == 0)
    {
        ok[i + 1][j] = 1;
        vt.push_back('D');
        Try(i + 1, j);
        vt.pop_back();
        ok[i + 1][j] = 0;
    }
    if (j + 1 <= n and a[i][j + 1] == 1 and ok[i][j + 1] == 0)
    {
        ok[i][j + 1] = 1;
        vt.push_back('R');
        Try(i, j + 1);
        vt.pop_back();
        ok[i][j + 1] = 0;
    }
    if (j - 1 >= 1 and a[i][j - 1] == 1 and ok[i][j - 1] == 0)
    {
        ok[i][j - 1] = 1;
        vt.push_back('L');
        Try(i, j - 1);
        vt.pop_back();
        ok[i][j - 1] = 0;
    }
    if (i - 1 >= 1 and a[i - 1][j] == 1 and ok[i - 1][j] == 0)
    {
        ok[i - 1][j] = 1;
        vt.push_back('U');
        Try(i - 1, j);
        vt.pop_back();
        ok[i - 1][j] = 0;
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
        for (int i = 1; i <= n; i++)
            fill(ok[i] + 1, ok[i] + n, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        ok[1][1] = 1;
        Try();
        if (sol.size() == 0)
            cout << -1;
        else
        {
            sort(sol.begin(), sol.end());
            for (auto i : sol)
            {
                for (auto j : i)
                    cout << j;
                cout << " ";
            }
        }
        cout << "\n";
        sol.clear();
    }
    return 0;
}