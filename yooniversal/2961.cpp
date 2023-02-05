// 2961
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n;
ll ret = INF;
vector<pair<ll, ll>> a;

void dfs(int cur, ll mul, ll sum, bool flag)
{
    if ( cur >= n )
    {
        if ( flag) return;
        ret = min(ret, abs(mul - sum));
        return;
    }

    dfs(cur + 1, mul * a[cur].first, sum + a[cur].second, false);
    dfs(cur + 1, mul, sum, flag);
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for ( int i = 0; i < n; ++i )
    {
        ll s, b; cin >> s >> b;
        a.push_back({ s, b });
    }

    dfs(0, 1, 0, true);

    cout << ret << '\n';

    return 0;
}