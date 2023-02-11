// 24479
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n, m, r;
int cnt;
int ret[MAX];
bool chk[MAX];
vi a[MAX];


void dfs(int cur)
{
    ret[cur] = ++cnt;

    for ( auto &next : a[cur] )
    {
        if ( chk[next] ) continue;
        chk[next] = true;
        dfs(next);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> r;
    while ( m-- )
    {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for ( int i = 1; i <= n; ++i )
        sort(a[i].begin(), a[i].end());

    chk[r] = true;
    dfs(r);

    for ( int i = 1; i <= n; ++i )
        cout << ret[i] << '\n';

    return 0;
}