// 2615
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
    int x, y;

    bool operator<(P &p)
    {
        if ( y != p.y ) return y < p.y;
        return x < p.x;
    }
};

int a[20][20];
int dx[] = { -1,-1,-1,0,0,1,1,1 }, dy[] = { -1,0,1,-1,1,-1,0,1 };

bool OOB(int x, int y) { return x < 0 || x >= 19 || y < 0 || y >= 19; }

P solve(int x, int y, int dir)
{
    int nx = x, ny = y;
    vector<P> xy;
    xy.push_back({ x, y });
    
    while ( 1 )
    {
        nx += dx[dir]; ny += dy[dir];
        if ( OOB(nx, ny) || a[nx][ny] != a[x][y] ) break;
        //printf("x:%d y:%d // nx:%d ny:%d\n", x, y, nx, ny);
        xy.push_back({ nx, ny });
    }

    nx = x, ny = y;
    int ndir = 7 - dir;
    while ( 1 )
    {
        nx += dx[ndir]; ny += dy[ndir];
        if ( OOB(nx, ny) || a[nx][ny] != a[x][y] ) break;
        //printf("#x:%d y:%d // nx:%d ny:%d\n", x, y, nx, ny);
        xy.push_back({ nx, ny });
    }

    sort(xy.begin(), xy.end());
    if ( xy.size() == 5 ) return xy[0];
    return { -1, -1 };
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for ( int i = 0; i < 19; ++i ) for ( int j = 0; j < 19; ++j )
    {
        cin >> a[i][j];
    }

    for ( int i = 0; i < 19; ++i ) for ( int j = 0; j < 19; ++j )
    {
        if ( a[i][j] == 0 ) continue;

        for ( int d = 0; d < 4; ++d )
        {
            P ret = solve(i, j, d);
            if(ret.x != -1)
            {
                //printf("i:%d j:%d\n", i, j);
                cout << a[i][j] << '\n';
                cout << ret.x+1 << " " << ret.y+1 << '\n';
                return 0;
            }
        }
    }

    cout << 0 << '\n';

    return 0;
}