// 11055
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n;
int cache[1005];
vi a;

int f(int cur)
{
    if ( cur >= n ) return 0;
    int &ret = cache[cur];
    if ( ret != -1 ) return ret;
    ret = 0;

    ret = a[cur];
    for ( int i = cur + 1; i < n; ++i )
        if ( a[cur] < a[i] )
            ret = max(ret, f(i) + a[cur]);

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    a.resize(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    int ret = 0;
    for ( int i = 0; i < n; ++i )
        ret = max(ret, f(i));

    cout << ret << '\n';

    return 0;
}