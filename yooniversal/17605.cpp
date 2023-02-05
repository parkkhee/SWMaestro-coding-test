// 17605
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

pair<bool, ii> p(string &s)
{
    int l = 0, r = s.size() - 1;
    while ( l < r )
    {
        if ( s[l] != s[r] ) return { false, {l, r} };
        ++l; --r;
    }

    return { true, {0,0} };
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while ( t-- )
    {
        string s; cin >> s;
        auto chk = p(s);
        if ( chk.first ) cout << 0 << '\n';
        else
        {
            int l = chk.second.first, r = chk.second.second;
            
            string ns = s.substr(0, max(0, l)) + s.substr(l+1);
            string ns2 = s.substr(0, max(0, r)) + s.substr(r+1);
            auto ret1 = p(ns);
            auto ret2 = p(ns2);
            if ( p(ns).first || p(ns2).first ) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }

    return 0;
}