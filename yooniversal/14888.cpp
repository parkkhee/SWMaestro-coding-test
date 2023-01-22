// 14888
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 15746;

int cache[13][13][13][13][13];
int cache2[13][13][13][13][13];
int n, op[4];
vi a;

int f(int cur, int p, int m, int mul, int div)
{
    if ( cur >= n ) return 0;
    if ( cur == n-1 ) return a[cur];
    int &ret = cache[cur][p][m][mul][div];
    if ( ret != -1 ) return ret;
    ret = -INF;

    if(p-1 >= 0) ret = max(ret, f(cur + 1, p-1, m, mul, div) + a[cur]);
    if(m-1 >= 0) ret = max(ret, f(cur + 1, p, m-1, mul, div) - a[cur]);
    if(mul-1 >= 0) ret = max(ret, f(cur + 1, p, m, mul-1, div) * a[cur]);
    if(div-1 >= 0) ret = max(ret, f(cur + 1, p, m, mul, div-1) / a[cur]);

    return ret;
}

int g(int cur, int p, int m, int mul, int div)
{
    if ( cur >= n ) return INF;
    if ( cur == n - 1 ) return a[cur];
    int &ret = cache2[cur][p][m][mul][div];
    if ( ret != -1 ) return ret;
    ret = INF;

    if ( p - 1 >= 0 ) ret = min(ret, g(cur + 1, p - 1, m, mul, div) + a[cur]);
    if ( m - 1 >= 0 ) ret = min(ret, g(cur + 1, p, m - 1, mul, div) - a[cur]);
    if ( mul - 1 >= 0 ) ret = min(ret, g(cur + 1, p, m, mul - 1, div) * a[cur]);
    if ( div - 1 >= 0 ) ret = min(ret, g(cur + 1, p, m, mul, div - 1) / a[cur]);

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));
    cin >> n;
    a.resize(n);
    for ( int i = n - 1; i >= 0; --i ) cin >> a[i];
    for ( int i = 0; i < 4; ++i ) cin >> op[i];

    cout << f(0, op[0], op[1], op[2], op[3]) << '\n';
    cout << g(0, op[0], op[1], op[2], op[3]) << '\n';

    return 0;
}
