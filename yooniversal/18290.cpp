// 18290
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n, m, k;
int a[15][15];
int ret = -INF;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
bool chk[15][15];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void dfs(int start, int cnt, int val)
{
    if ( cnt >= k )
    {
        ret = max(ret, val);
        return;
    }

    const int len = n * m;
    for ( int r = start; r<len; ++r )
    {
        int i = r / m, j = r % m;
        if ( chk[i][j] ) continue;
        chk[i][j] = true;
        vii near;
        for ( int t = 0; t < 4; ++t )
        {
            int nx = i + dx[t], ny = j + dy[t];
            if ( OOB(nx, ny) || chk[nx][ny] ) continue;
            chk[nx][ny] = true;
            near.push_back({ nx,ny });
        }

        int next = i * m + j + 1;
        dfs(next, cnt + 1, val + a[i][j]);

        chk[i][j] = false;
        for ( auto& nn : near )
            chk[nn.first][nn.second] = false;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < m; ++j )
    {
        cin >> a[i][j];
    }

    dfs(0, 0, 0);

    cout << ret << '\n';

    return 0;
}