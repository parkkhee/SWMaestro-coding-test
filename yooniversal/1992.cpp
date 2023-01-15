// 1992
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 9901;

char a[65][65];

bool allSame(int sx, int sy, int len)
{
    char target = a[sx][sy];
    for ( int x = sx; x < sx + len; ++x )
    {
        for ( int y = sy; y < sy + len; ++y )
        {
            if ( target != a[x][y] ) return false;
        }
    }

    return true;
}

void dfs(int x, int y, int len)
{
    if ( len <= 0 ) return;
    
    if ( allSame(x, y, len) ) cout << a[x][y];
    else
    {
        cout << "(";
        int next_len = len / 2;
        dfs(x, y, next_len);
        dfs(x, y + next_len, next_len);
        dfs(x + next_len, y, next_len);
        dfs(x + next_len, y + next_len, next_len);
        cout << ")";
    }
}


int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < n; ++j ) cin >> a[i][j];

    dfs(0, 0, n);
    cout << '\n';

    return 0;
}
