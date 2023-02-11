// 18429
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n, k;
int ret;
vi a;
bool chk[10];

void dfs(int sum, int cnt)
{
    if ( sum < 0 ) return;
    if ( cnt >= n )
    {
        ++ret;
        return;
    }

    for ( int i = 0; i < n; ++i )
    {
        if ( chk[i] ) continue;
        chk[i] = true;
        dfs(sum + a[i] - k, cnt + 1);
        chk[i] = false;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    a.resize(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    dfs(0, 0);
    cout << ret << '\n';

    return 0;
}