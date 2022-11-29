#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
int n, m;
int a[50];
vector<int> vt;
bool check = false;
void print()
{
    cout << "[";
    for (int i = 0; i < vt.size() - 1; i++)
        cout << vt[i] << " ";
    cout << vt[vt.size() - 1] << "]";
}
void Try(int i = 0, int sum = 0)
{
    if (sum > m)
        return;
    if (sum == m)
    {
        check = true;
        print();
    }
    for (int j = i; j < n; j++)
    {
        vt.push_back(a[j]);
        Try(j, sum + a[j]);
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
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Try();
        if (check == false)
            cout << -1;
        vt.clear();
        cout << "\n";
    }

    return 0;
}