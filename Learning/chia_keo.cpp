#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int n, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b;
    int c = n * (2 * b / n);
    if (c <= 2 * a)
        cout << a << " " << a;
    else if (c >= a + b)
        cout << b << " " << c - b;
    else
        cout << c - a << " " << a;

    return 0;
}