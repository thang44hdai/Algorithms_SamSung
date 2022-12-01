#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int prime[10004570];
void sang()
{
    fill(prime, prime + 10004570, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= 3163; i++)
        if (prime[i] == 1)
            for (int j = i * i; j <= 10004570; j += i)
                prime[j] = 0;
}
int cnt = 0;
void check(ll n)
{
    ll m = n;
    int x = n % 10;
    n /= 10;
    while (n)
    {
        if (x < n % 10)
            return;
        n /= 10;
    }
    cnt++;
    cout << m << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sang();
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        if (prime[i])
            check(i);
    cout << "\n"
         << cnt;
    return 0;
}
