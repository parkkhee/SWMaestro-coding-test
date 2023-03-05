// 2531
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000007;

int n, d, k, c;
bool chk[30005];
vi a;

int solve(int start)
{
    int ret = 0;
    vi idxs;

    for ( int i = start, cnt = 0; cnt < k; i = (i + 1) % n, ++cnt )
    {
        if ( chk[a[i]] ) continue;
        chk[a[i]] = true;
        idxs.push_back(a[i]);
        ++ret;
    }

    if ( !chk[c] ) ++ret;

    for ( auto &cur : idxs )
        chk[cur] = false;

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> d >> k >> c;
    a.resize(n);
    
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    int ret = 0;
    for ( int i = 0; i < n; ++i )
    {
        ret = max(ret, solve(i));
    }

    cout << ret << '\n';

    return 0;
}