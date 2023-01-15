// 11047
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 9901;



int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; ll k;
    cin >> n >> k;

    vector<ll> a(n);
    for ( int i = n-1; i >= 0; --i ) cin >> a[i];

    int ret = 0;
    int i = 0;
    while ( k != 0 )
    {
        if ( a[i] <= k )
        {
            ret += k / a[i];
            k %= a[i];
        }

        ++i;
    }

    cout << ret << '\n';

    return 0;
}
