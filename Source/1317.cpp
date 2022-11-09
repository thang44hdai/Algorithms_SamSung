#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int n;
int a[15][15];
vector<char> vt;
bool check = false;
void Try(int i = 1, int j = 1)
{
    if (i == n and j == n and a[i][j] == 1)
    {
        check = true;
        for (auto c : vt)
            cout << c;
        cout << " ";
        return;
    }
    if (i + 1 <= n and a[i + 1][j] == 1)
    {
        vt.push_back('D');
        Try(i + 1, j);
        vt.pop_back();
    }
    if (j + 1 <= n and a[i][j + 1] == 1)
    {
        vt.push_back('R');
        Try(i, j + 1);
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
        check = false;
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        if (a[1][1] == 0 or a[n][n] == 0)
        {
            cout << -1 << "\n";
            continue;
        }
        Try();
        if (check == false)
            cout << -1;
        cout << "\n";
    }
    return 0;
}
