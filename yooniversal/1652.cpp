// 1652
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n;
int ret, ret2;
char a[101][101];

void chk_row(int cur)
{
    int cnt = 0;
    bool added = false;
    for ( int i = 0; i < n; ++i )
    {
        if ( a[cur][i] == 'X' )
        {
            cnt = 0;
            added = false;
            continue;
        }
        if ( !added && ++cnt >= 2 )
        {
            added = true;
            ++ret;
        }
    }
}

void chk_col(int cur)
{
    int cnt = 0;
    bool added = false;
    for ( int i = 0; i < n; ++i )
    {
        if ( a[i][cur] == 'X' )
        {
            cnt = 0;
            added = false;
            continue;
        }
        if ( !added && ++cnt >= 2 )
        {
            added = true;
            ++ret2;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < n; ++j ) cin >> a[i][j];

    for ( int i = 0; i < n; ++i )
    {
        chk_row(i);
        chk_col(i);
    }

    cout << ret << " " << ret2 << '\n';

    return 0;
}