// 2022
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000007;

map<string, bool> chk;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<string> a, b;

    int n; cin >> n;
    for ( int i = 0; i < n; ++i )
    {
        string s; cin >> s;
        a.push_back(s);
    }

    for ( int i = 0; i < n; ++i )
    {
        string s; cin >> s;
        b.push_back(s);
    }

    int ret = 0;
    for ( int i = 0, j = 0; i < n && j < n;)
    {
        if ( chk[a[i]] )
        {
            ++i;
            continue;
        }

        if ( a[i] == b[j] )
        {
            chk[a[i++]] = true;
            chk[b[j++]] = true;
        }
        else
        {
            chk[b[j++]] = true;
            ++ret;
        }
    }

    cout << ret << '\n';

    return 0;
}