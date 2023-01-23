// 1343
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

string s;

bool four_empty(int cur)
{
    if ( cur + 3 >= s.size() ) return false;
    for ( int i = cur; i < cur + 4; ++i )
    {
        if ( s[i] != 'X' ) return false;
    }
    return true;
}


bool two_empty(int cur)
{
    if ( cur + 1 >= s.size() ) return false;
    for ( int i = cur; i < cur + 2; ++i )
    {
        if ( s[i] != 'X' ) return false;
    }
    return true;
}

void dfs(int cur)
{
    if ( cur >= s.size() )
    {
        cout << s << '\n';
        exit(0);
        return;
    }

    if ( s[cur] == '.' )
    {
        dfs(cur + 1);
        return;
    }

    if ( four_empty(cur) )
    {
        s[cur] = s[cur + 1] = s[cur + 2] = s[cur + 3] = 'A';
        dfs(cur + 4);
        s[cur] = s[cur + 1] = s[cur + 2] = s[cur + 3] = 'X';
    }
    else if ( two_empty(cur) )
    {
        s[cur] = s[cur + 1] = 'B';
        dfs(cur + 2);
        s[cur] = s[cur + 1] = 'X';
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    dfs(0);

    cout << -1 << '\n';

    return 0;
}
