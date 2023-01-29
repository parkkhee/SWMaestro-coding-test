// 1947
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000005, INF = 1000000001, MOD = 1000000000;

ll cache[MAX];
int n;

ll f(int cur)
{
    if ( cur == 2 ) return 1;
    if ( cur <= 1 || cur > n ) return 0;
    ll &ret = cache[cur];
    if ( ret != -1 ) return ret;
    ret = 0;

    ret = ((cur - 1) * (f(cur - 1) + f(cur - 2))) % MOD;

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    cout << f(n) << '\n';

    return 0;
}