// 14651
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000009;

int cache[33335][3];
int n;

int f(int cur, int rem)
{
    if ( cur >= n ) return rem == 0;
    int &ret = cache[cur][rem];
    if ( ret != -1 ) return ret;
    ret = 0;

    for ( int i = 0; i < 3; ++i )
    {
        if ( cur == 0 && i == 0 ) continue;
        ret = (ret + f(cur + 1, (rem + i) % 3)) % MOD;
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

    cout << f(0, 0) << '\n';

    return 0;
}