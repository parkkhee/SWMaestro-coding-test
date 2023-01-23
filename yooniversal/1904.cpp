// 1904
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 15746;

int n;
int cache[1000005];

int f(int cur)
{
    if ( cur > n ) return 0;
    if ( cur == n ) return 1;
    int &ret = cache[cur];
    if ( ret != -1 ) return ret;
    ret = 0;

    ret = (f(cur + 1) + f(cur + 2)) % MOD;
    ret %= MOD;

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    
    cout << f(0) << '\n';

    return 0;
}
