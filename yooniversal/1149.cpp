// 1149
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 1000000000;

int cache[1005][3];
int n;
vvi a;

int f(int cur, int color)
{
    if ( cur >= n ) return 0;
    if ( cur == n - 1 ) return a[cur][color];
    int &ret = cache[cur][color];
    if ( ret != -1 ) return ret;
    ret = INF;

    for ( int i = 0; i < 3; ++i )
    {
        if ( i == color ) continue;
        ret = min(ret, f(cur + 1, i) + a[cur][color]);
    }

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    a.resize(n);
    for ( int i = 0; i < n; ++i )
    {
        a[i].resize(3);
        for ( int j = 0; j < 3; ++j )
        {
            cin >> a[i][j];
        }
    }

    int ret = INF;
    for ( int i = 0; i < 3; ++i )
    {
        ret = min(ret, f(0, i));
    }

    cout << ret << '\n';

    return 0;
}
