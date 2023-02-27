// 15724
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000007;

int n, m;
int a[1025][1025];

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            int v; cin >> v;
            a[i][j] = j > 0 ? a[i][j - 1] + v : v;
        }
    }

    int k; cin >> k;
    while ( k-- )
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1; --x2; --y2;

        int ret = 0;
        for ( int i = x1; i <= x2; ++i )
        {
            if ( y1 > 0 ) ret += a[i][y2] - a[i][y1 - 1];
            else ret += a[i][y2];
        }

        cout << ret << '\n';
    }

    return 0;
}