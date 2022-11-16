#include <bits/stdc++.h>
#pragma GCC optize("Ofast")
using namespace std;
int k;
string s;
void findMax(string &res, int cnt)
{
    if (!k)
        return;
    char tmp = s[cnt];
    for (int i = cnt; i < s.length(); i++)
        if (tmp < s[i])
            tmp = s[i];
    if (tmp != s[cnt])
        k--;
    for (int i = s.length() - 1; i >= cnt; i--)
    {
        if (s[i] == tmp)
        {
            swap(s[cnt], s[i]);
            if (s.compare(res) > 0)
                res = s;
            findMax(res, cnt + 1);
            swap(s[cnt], s[i]);
        }
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
        cin >> k >> s;
        string res = s;
        findMax(res, 0);
        cout << res << endl;
    }
    return 0;
}
