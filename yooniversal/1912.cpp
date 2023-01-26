// 1912
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cache[MAX];
int n;
vi a;

int f(int cur)
{
    //cout << "cur:" << cur << '\n';
    if ( cur < 0 || cur >= n ) return -INF;
    int &ret = cache[cur];
    if ( ret != -INF ) return ret;
    ret = a[cur];
    ret = max(ret, a[cur] + f(cur + 1));

    //cout << "*cur:" << cur << '\n';
    
    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for ( int i = 0; i < MAX; ++i ) cache[i] = -INF;

    cin >> n;
    a.resize(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    
    int ret = -INF;
    for ( int i = 0; i < n; ++i ) 
        ret = max(ret, f(i));

    cout << ret << '\n';

    return 0;
}