// 11058
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

ll cache[105];
int n;

ll f(int cnt)
{
    if ( cnt >= n ) return 0;
    ll &ret = cache[cnt];
    if ( ret != -1 ) return ret;
    ret = 0;

    ret = max(ret, f(cnt + 1)+1);
    ret = max(ret, f(cnt + 3)*2);

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