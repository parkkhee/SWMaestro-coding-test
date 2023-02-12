// 14567
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n, m;
int cache[1005];
vi pre[1005];

int f(int cur)
{
    if ( cur == 0 ) return 0;
    int &ret = cache[cur];
    if ( ret != -1 ) return ret;
    ret = 1;

    for ( auto &next : pre[cur] )
    {
        ret = max(ret, f(next) + 1);
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
    while ( m-- )
    {
        int a, b; cin >> a >> b;
        pre[b].push_back(a);
    }

    for ( int i = 1; i <= n; ++i )
    {
        cout << f(i) << " ";
    }
    cout << '\n';

    return 0;
}