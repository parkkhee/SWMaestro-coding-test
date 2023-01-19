// 2253
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cache[10005][155];
int n, m;
bool not_jump[10005];

int f(int cur, int speed)
{
    if ( cur > n ) return INF;
    if ( not_jump[cur] ) return INF;
    if ( cur == n ) return 0;
    int &ret = cache[cur][speed];
    if ( ret != -1 ) return ret;
    ret = INF;

    if ( cur != 1 )
    {
        int speeds[3] = { speed - 1, speed, speed + 1 };
        for ( auto &next_speed : speeds )
        {
            if ( next_speed < 1 ) continue;
            ret = min(ret, f(cur + next_speed, next_speed) + 1);
        }
    }
    else
    {
        ret = min(ret, f(cur + 1, 1) + 1);
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
    for ( int i = 0; i < m; ++i )
    {
        int x; cin >> x;
        not_jump[x] = true;
    }

    int ret = f(1, 1);
    if ( ret == INF ) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}
