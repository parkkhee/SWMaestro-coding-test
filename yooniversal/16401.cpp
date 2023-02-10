// 16401
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000005, INF = 1000000001, MOD = 1000000000;

int m, n;
vi a;

int f(int l, int r)
{
    int mid = (l + r) / 2;
    int ret = -1;
    while ( l < r )
    {
        mid = (l + r) / 2;

        int cnt = 0;
        for ( int i = n - 1; i >= 0; --i )
        {
            if ( a[i] / mid == 0 ) break;
            cnt += a[i] / mid;
        }

        if ( cnt >= m )
        {
            l = mid+1;
            if ( cnt == m ) ret = max(ret, mid);
        }
        else
        {
            r = mid;
        }
    }

    if ( ret == -1 ) return 0;
    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    a.resize(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    cout << f(1, 1000000000) << '\n';

    return 0;
}