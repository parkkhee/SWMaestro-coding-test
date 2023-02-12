// 1439
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cnt[2];

int check(string &s, int start)
{
    
    for ( int i = start; i < s.size(); ++i )
    {
        if ( s[i] != s[start] )
        {
            if ( s[start] == '0' ) ++cnt[0];
            else ++cnt[1];
            return i;
        }
    }

    if ( s[start] == '0' ) ++cnt[0];
    else ++cnt[1];

    return s.size();
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;
    int last = 0;
    while ( 1 )
    {
        last = check(s, last);
        if ( last >= s.size() ) break;
    }

    cout << min(cnt[0], cnt[1]) << '\n';

    return 0;
}