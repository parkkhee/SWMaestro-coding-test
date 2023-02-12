// 18310
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000005, INF = 1000000001, MOD = 1000000000;

struct P
{
    ll v, diff;

    bool operator<(P &p)
    {
        if(diff != p.diff) return diff < p.diff;
        return v < p.v;
    }
};

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> a(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];
    sort(a.begin(), a.end());

    ll mid = (a[0] + a[n - 1]) / 2;
    vector<P> b;
    for ( int i = 0; i < n; ++i )
    {
        cout << a[i] << " " << abs(a[i] - mid) << '\n';
        b.push_back({ a[i], abs(a[i] - mid) });
    }
    sort(b.begin(), b.end());

    /*
    ll ret = b[0].v, ret2 = b[1].v;
    ll sum = 0, sum2 = 0;
    for ( int i = 0; i < n; ++i ) sum += abs(a[i] - ret);
    for ( int i = 0; i < n; ++i ) sum2 += abs(a[i] - ret2);

    if ( sum < sum2 ) cout << ret << '\n';
    else if ( sum > sum2 ) cout << ret2 << '\n';
    else cout << min(ret, ret2) << '\n';
    */

    cout << b[0].v << '\n';

    return 0;
}