// 17845
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000007;

int cache[10005][1005];
int n, k;
vii a;

int f(int t, int cur)
{
    if ( t <= 0 || cur >= k ) return 0;
    int &ret = cache[t][cur];
    if ( ret != -1 ) return ret;
    ret = 0;

    if(a[cur].second <= t) ret = max(ret, f(t - a[cur].second, cur + 1) + a[cur].first);
    ret = max(ret, f(t, cur + 1));

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n >> k;

    for ( int i = 0; i < k; ++i )
    {
        int cnt, t; cin >> cnt >> t;
        a.push_back({ cnt, t });
    }

    cout << f(n, 0) << '\n';

    return 0;
}