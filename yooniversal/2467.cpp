// 2961
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

struct P
{
    int v, i;
    P(int v, int i) : v(v), i(i) {}

    bool operator<(P &p)
    {
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

    int s = 0, e = n - 1;
    pair<ll, ll> ret = { a[s], a[e]};
    while ( e-s > 1 )
    {
        ll ans = abs(ret.first + ret.second);
        vector<P> arr;

        if ( s+1 < e ) arr.push_back(P(abs(a[s + 1] + a[e]), 0));
        if ( s < e-1 ) arr.push_back(P(abs(a[s] + a[e - 1]), 1));
        if ( s+1 < e-1 ) arr.push_back(P(abs(a[s + 1] + a[e - 1]), 2));

        sort(arr.begin(), arr.end());

        if ( arr[0].i == 0 )
        {
            if( ans > arr[0].v ) ret = { a[s + 1], a[e] };
            s++;
        }
        else if ( arr[0].i == 1 )
        {
            if( ans > arr[0].v ) ret = { a[s], a[e - 1] };
            e--;
        }
        else if ( arr[0].i == 2 )
        {
            if( ans > arr[0].v ) ret = { a[s + 1], a[e - 1] };
            s++; e--;
        }
    }

    cout << ret.first << " " << ret.second << '\n';

    return 0;
}