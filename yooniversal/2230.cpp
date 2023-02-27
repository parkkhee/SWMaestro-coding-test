// 2230
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cache[MAX];
int n, m;
vi a;

int f(int cur)
{
    if ( cur == 0 )
    {
        if ( m == 0 ) return 0;
        return INF;
    }
    int &ret = cache[cur];
    if ( ret != -1 ) return ret;
    ret = INF;

    ret = min(ret, f(cur - 1));
    for ( int i = cur; i >= 0; --i )
    {
        if ( a[cur] - a[i] >= m )
        {
            ret = min(ret, a[cur] - a[i]);
            break;
        }
    }

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    a.resize(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];
    sort(a.begin(), a.end());

    cout << f(n - 1) << '\n';

    return 0;
}