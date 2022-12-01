#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
using namespace std;
/*
    dp[x]: độ dài dãy con tăng dài nhất kết thúc tại phần tử có giá trị là x.
    dp[x] bằng độ dài lớn nhất của các dãy con tăng dài nhất kết thúc tại các phần tử có giá trị từ 1-> x-1 rồi cộng thêm 1(thêm phần tử x vào dãy con đó).
    -> dp[x]=dp[1->(x-1)]+1;
    Ta có cây FEN quản lý mảng dp với fen[i]=max(dp[1->i])
*/
ll fen[1000005];
ll a[1000005];
ll n;
ll Max = 0;
// update độ dài lên node cha
void Update(ll i, ll len)
{
    while (i <= Max)
    {
        fen[i] = max(fen[i], len);
        i += i & -i;
    }
}
// lấy max dp[1->(x-1)]
ll get(ll i)
{
    ll tmp = -1;
    while (i > 0)
    {
        tmp = max(fen[i], tmp);
        i -= i & -i;
    }
    return tmp;
}
ll sol()
{
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll len;
        if (a[i] == 1)
            len = 1;
        else
            len = get(a[i] - 1) + 1; // dp[x]=dp[1->(x-1)]+1
        Update(a[i], len);
        ans = max(ans, len); // lấy độ dài lớn nhất của các dãy con
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        Max = max(Max, a[i]);
    }
    cout << sol();
    return 0;
}
