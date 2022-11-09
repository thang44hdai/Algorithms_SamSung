#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
string s;
vector<char> vt;
int n;
int ok[20];
void Try(int i = 0)
{
    for (auto k : vt)
        cout << k;
    cout << " ";
    for (int j = i; j < n; j++)
    {
        if (!ok[j])
        {
            vt.push_back(s[j]);
            ok[j] = 1;
            Try(j + 1);
            vt.pop_back();
            ok[j] = 0;
        }
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
        cin >> n >> s;
        n = s.length();
        fill(ok, ok + n, 0);
        Try();
        cout<<"\n";
    }
    return 0;
}