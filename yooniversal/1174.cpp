// 1174
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000009;

bool decrease(int v)
{
    string s = to_string(v);

    for ( int i = 0; i < s.size() - 1; ++i )
    {
        if ( s[i] + i < s.size() - 1 )
            return false;

        if ( s[i] <= s[i + 1] ) 
            return false;
    }

    return true;
}

void solve(int target)
{
    int cur = 0, cnt = 0;

    while ( 1 )
    {
        if ( decrease(cur) )
        {
            ++cnt;
            if ( cnt == target )
            {
                cout << cur << '\n';
                exit(0);
            }
        }

        ++cur;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    if ( n > 1023 )
    {
        cout << -1 << '\n';
        return 0;
    }

    solve(n);

    return 0;
}