// 2798
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 9901;

int a[130][130];
int white, blue;

bool allSame(int x, int y, int size)
{
    for ( int i = x; i < x + size; ++i )
    {
        for ( int j = y; j < y + size; ++j )
        {
            if ( a[i][j] != a[x][y] )
                return false;
        }
    }

    return true;
}

void dfs(int x, int y, int size)
{
    if ( allSame(x, y, size) )
    {
        if ( a[x][y] == 0 ) ++white;
        else ++blue;
        return;
    }

    dfs(x, y, size / 2);
    dfs(x + size / 2, y, size / 2);
    dfs(x, y + size / 2, size / 2);
    dfs(x + size / 2, y + size / 2, size / 2);
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for ( int i = 1; i <= n; ++i ) for ( int j = 1; j <= n; ++j ) cin >> a[i][j];

    dfs(1, 1, n);

    cout << white << '\n' << blue << '\n';

    return 0;
}
