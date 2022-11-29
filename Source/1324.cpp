#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
#define ll long long
ll p, q;
void sol()
{
    while (1)
    {
        if (q % p == 0)
        {
            cout << "1/" << q / p;
            return;
        }
        ll mau = ceil((double)q / p);
        cout << "1/" << mau << " + ";
        p = p * mau - q;
        q = q * mau;
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
        cin >> p >> q;
        sol();
        cout << "\n";
    }
    return 0;
}