// 7576
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n, m;
int a[1005][1005];
int rotten_cnt;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
bool chk[1005][1005];

struct P
{
    int x, y, cnt;
    P(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(vii& start)
{
    int ret = 0;
    queue<P> q;
    for ( auto &st : start )
    {
        q.push(P(st.first, st.second, 0));
        chk[st.first][st.second] = true;
    }

    while ( !q.empty() )
    {
        int x = q.front().x, y = q.front().y, cnt = q.front().cnt; q.pop();
        ret = max(ret, cnt);
        ++rotten_cnt;

        for ( int i = 0; i < 4; ++i )
        {
            int nx = x + dx[i], ny = y + dy[i];
            if ( OOB(nx, ny) || chk[nx][ny] || a[nx][ny] == -1 || a[nx][ny] == 1 ) continue;
            chk[nx][ny] = true;
            a[nx][ny] = 1;
            q.push(P(nx, ny, cnt + 1));
        }
    }

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int size = 0;
    vii start;

    cin >> m >> n;
    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < m; ++j )
    {
        cin >> a[i][j];
        if ( a[i][j] == 1 ) start.push_back({ i, j });
        if ( a[i][j] != -1 ) ++size;
    }

    int ret = bfs(start);

    if ( rotten_cnt != size ) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}