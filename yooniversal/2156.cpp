// 2156
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cache[10005][5];
int n;
vi a;

int f(int cur, int cnt)
{
    if ( cur >= n) return 0;
    int &ret = cache[cur][cnt];
    if ( ret != -1 ) return ret;
    ret = 0;

    if(cnt < 2) ret = max(ret, f(cur + 1, cnt + 1) + a[cur]);
    ret = max(ret, f(cur + 1, 0));

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    a.resize(n);

    for ( int i = 0; i < n; ++i ) cin >> a[i];

    cout << f(0, 0) << '\n';

    return 0;
}