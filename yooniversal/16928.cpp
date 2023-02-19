// 16928
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

struct P
{
    int cur, cnt;
    P(int cur, int cnt) : cur(cur), cnt(cnt) {}
};

int n, m;
int up[105], down[105];
bool chk[105];

int bfs()
{
    
    queue<P> q;
    q.push(P(1, 0));
    chk[1] = true;

    while ( !q.empty() )
    {
        P now = q.front(); q.pop();
        int cur = now.cur, cnt = now.cnt;

        if ( cur == 100 ) return cnt;

        for ( int i = 1; i <= 6; ++i )
        {
            int next = cur + i;
            if ( next > 100 || chk[next] ) continue;
            chk[next] = true;

            // »ç´Ù¸®
            if ( up[next] != 0 )
            {
                if ( chk[up[next]] ) continue;
                chk[up[next]] = true;
                q.push(P(up[next], cnt + 1));
                continue;
            }

            // ¹ì
            if ( down[next] != 0 )
            {
                if ( chk[down[next]] ) continue;
                chk[down[next]] = true;
                q.push(P(down[next], cnt + 1));
                continue;
            }

            q.push(P(next, cnt + 1));
        }
    }

    return -1;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for ( int i = 0; i < n; ++i )
    {
        int x, y; cin >> x >> y;
        up[x] = y;
    }

    for ( int i = 0; i < m; ++i )
    {
        int x, y; cin >> x >> y;
        down[x] = y;
    }

    cout << bfs() << '\n';

    return 0;
}