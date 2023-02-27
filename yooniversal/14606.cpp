// 14606
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cache[15];
int n;

int f(int cur)
{
    if ( cur <= 1 ) return 0;
    int &ret = cache[cur];
    if ( ret != -1 ) return ret;
    ret = 0;

    for ( int i = 1; i <= cur / 2; ++i )
        ret = max(ret, f(cur - i) + f(i) + (cur - i) * i);
    
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