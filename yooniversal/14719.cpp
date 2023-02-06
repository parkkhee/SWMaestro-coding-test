// 14719
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n, m;
int ret;
vi a;
bool chk[505][505];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

ii have_wall(int x, int y)
{
    ii ret = { -1, -1 };
    int ny = y;
    while(1) {
        ny = ny - 1;
        if ( OOB(x, ny) ) return { -1, -1 };
        if ( a[ny] >= x )
        {
            ret.first = ny;
            break;
        }
    }

    ny = y;
    while ( 1 )
    {
        ny = ny + 1;
        if ( OOB(x, ny) ) return { -1, -1 };
        if ( a[ny] >= x )
        {
            ret.second = ny;
            return ret;
        }
    }

    return { -1, -1 };
}

void fill(int x, int sy, int ey)
{
    for ( int cy = sy; cy <= ey; ++cy )
        chk[x][cy] = true;

    ret += ey - sy + 1;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for ( int i = 0; i < m; ++i )
    {
        int x; cin >> x;
        a.push_back(x-1);
    }
    
    for ( int x = 0; x < n; ++x ) for ( int y = 0; y < m; ++y )
    {
        if ( chk[x][y] || x <= a[y] ) continue;
        ii wall = have_wall(x, y);
        if ( wall.first != -1 )
            fill(x, wall.first + 1, wall.second - 1);
    }

    cout << ret << '\n';

    return 0;
}