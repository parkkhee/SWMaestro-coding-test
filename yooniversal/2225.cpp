// 2225
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 1000000000;

int n, k;
int a[205][205];

int f(int sum, int cnt)
{
    if ( sum > n ) return 0;
    if ( cnt == k )
    {
        if ( sum != n ) return 0;
        return 1;
    }
    int &ret = a[sum][cnt];
    if ( ret != -1 ) return ret;
    ret = 0;

    for ( int i = 0; i <= n; ++i )
    {
        ret = (ret + f(sum + i, cnt + 1)) % MOD;
        ret %= MOD;
    }

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(a, -1, sizeof(a));
    cin >> n >> k;

    cout << f(0, 0) << '\n';

    return 0;
}
