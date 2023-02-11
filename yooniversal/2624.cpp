// 2624
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n, k;
int cache[105][10005];
vii a;

int f(int cur, int sum)
{
    if ( sum == k ) return 1;
    if ( cur >= n ) return 0;
    int &ret = cache[cur][sum];
    if ( ret != -1 ) return ret;
    ret = 0;

    for ( int i = 0; i <= a[cur].second; ++i )
    {
        if ( sum + a[cur].first * i > k ) continue;
        ret += f(cur + 1, sum + a[cur].first*i);
    }

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> k >> n;
    for ( int i = 0; i < n; ++i )
    {
        int v, cnt; cin >> v >> cnt;
        a.push_back({ v,cnt });
    }

    cout << f(0, 0) << '\n';

    return 0;
}