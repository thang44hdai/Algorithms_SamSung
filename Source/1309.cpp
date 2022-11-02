#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int i = s.length() - 1;
        while (s[i] == '1')
            i--;
        if (i < 0)
            for (int i = 1; i <= s.length(); i++)
                cout << 0;
        else
        {
            s[i] = '1';
            for (int j = i + 1; j < s.length(); j++)
                s[j] = '0';
            cout << s;
        }
        cout << "\n";
    }
    return 0;
}