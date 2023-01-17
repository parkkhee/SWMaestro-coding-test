// 1149
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 1000000000;

int a[9][9];
bool not_zero[9][9];
bool row_chk[9][10];
bool col_chk[9][10];
bool block_chk[9][10];

const ii block_start[9] = {
    {0,0}, {0,3}, {0,6},
    {3,0}, {3,3}, {3,6},
    {6,0}, {6,3}, {6,6}
};

int block_number(int r, int c)
{
    if ( r < 3 )
    {
        if ( c < 3 ) return 0;
        if ( c < 6 ) return 1;
        return 2;
    }
    else if ( r < 6 )
    {
        if ( c < 3 ) return 3;
        if ( c < 6 ) return 4;
        return 5;
    }

    if ( c < 3 ) return 6;
    if ( c < 6 ) return 7;
    return 8;
}

void dfs(int cur)
{
    if ( cur >= 81 )
    {
        for ( int i = 0; i < 9; ++i )
        {
            for ( int j = 0; j < 9; ++j )
            {
                cout << a[i][j];
            }
            cout << '\n';
        }

        exit(0);

        return;
    }
    
    int r = cur / 9, c = cur % 9;

    if ( not_zero[r][c] )
    {
        dfs(cur + 1);
        return;
    }

    for ( int i = 1; i <= 9; ++i )
    {
        if ( row_chk[r][i] || col_chk[c][i] || block_chk[block_number(r, c)][i] ) continue;
        row_chk[r][i] = col_chk[c][i] = block_chk[block_number(r, c)][i] = true;

        a[r][c] = i;
        dfs(cur + 1);
        a[r][c] = 0;

        row_chk[r][i] = col_chk[c][i] = block_chk[block_number(r, c)][i] = false;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for ( int i = 0; i < 9; ++i )
    {
        for ( int j = 0; j < 9; ++j )
        {
            char c; cin >> c;
            a[i][j] = c - '0';
            
            if ( a[i][j] != 0 )
            {
                not_zero[i][j] = true;
                row_chk[i][a[i][j]] = true;
                col_chk[j][a[i][j]] = true;
                block_chk[block_number(i, j)][a[i][j]] = true;
            }
        }
    }

    dfs(0);

    return 0;
}
