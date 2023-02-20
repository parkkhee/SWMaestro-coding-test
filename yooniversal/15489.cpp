// 15489
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cache[35][35];

int f(int r, int c)
{
    if ( r <= 1 || c <= 1 || c >= r ) return 1;
    int &ret = cache[r][c];
    if ( ret != -1 ) return ret;
    ret = 0;

    ret = f(r - 1, c - 1) + f(r - 1, c);
    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    int r, c, w; cin >> r >> c >> w;

    int ret = 0;
    for ( int row = r; row < r + w; ++row )
        for ( int col = c; col <= c + row - r; ++col )
            ret += f(row, col);

    cout << ret << '\n';

    return 0;
}