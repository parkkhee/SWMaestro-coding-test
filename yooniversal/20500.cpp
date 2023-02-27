// 20500
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000007;

ll cache[1520];
int n;

ll f(int cur)
{
    if ( cur <= 1 ) return 0;
    if ( cur <= 3 ) return 1;
    ll &ret = cache[cur];
    if ( ret != -1 ) return ret;
    ret = 0;

    for ( int i = 2; i <= cur; ++i )
        ret = max(ret, f(cur - i) + f(i)) % MOD;
    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    cout << f(n) << '\n';

    return 0;
}