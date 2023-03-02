// 22857
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000009;

int cache[50005][105];
int n, k;
vi a;

int f(int cur, int cnt)
{
    if ( cur >= n ) return 0;
    int &ret = cache[cur][cnt];
    if ( ret != -1 ) return ret;
    ret = 0;

    if ( cur+1 < n && a[cur + 1] % 2 == 0 ) ret = max(ret, f(cur + 1, cnt) + 1);
    if ( cur + 2 < n && cnt > 0 && a[cur + 1] % 2 != 0 ) ret = max(ret, f(cur + 1, cnt - 1));

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    a.resize(n);

    for ( int i = 0; i < n; ++i ) cin >> a[i];
    
    int ret = 0;
    for ( int i = 0; i < n; ++i )
    {
        if ( a[i] % 2 != 0 ) continue;
        ret = max(ret, f(i, k)+1);
    }

    cout << ret << '\n';

    return 0;
}