// 2229
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 1000000000;

int n;
int cache[1005][1005];
vi a;

int f(int s, int e)
{
    if ( s >= e ) return 0;
    if ( s + 1 == e ) return abs(a[s] - a[e]);
    int &ret = cache[s][e];
    if ( ret != -1 ) return ret;
    ret = 0;
    
    int minn = min(a[s], a[e]), maxx = max(a[s], a[e]);
    for ( int i = s; i < e; ++i )
    {
        ret = max(ret, f(s, i) + f(i + 1, e));
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }
    ret = max(ret, maxx - minn);

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    a.resize(n+1);
    for ( int i = 1; i <= n; ++i ) cin >> a[i];

    cout << f(1, n) << '\n';

    return 0;
}
