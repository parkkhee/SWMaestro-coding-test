// 6987
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

map<vi, bool> chk;
int t[6][3];

void dfs(int cnt, int next)
{
    if ( cnt >= 5 )
    {
        vi a;
        for ( int i = 0; i < 6; ++i ) for ( int j = 0; j < 3; ++j )
            a.push_back(t[i][j]);

        chk[a] = true;
        return;
    }

    ++next;
    if ( cnt == next ) ++next;

    ii match[3] = { {0,2}, {1,1}, {2,0} };
    for ( auto &cur : match )
    {
        int from = cur.first;
        int to = cur.second;

        t[cnt][from]++; t[next][to]++;
        if ( next < 5 ) dfs(cnt, next);
        else dfs(cnt + 1, 0);
        t[cnt][from]--; t[next][to]--;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    dfs(0, 0);

    for ( int i = 0; i < 4; ++i )
    {
        vi a(18);
        for ( int j = 0; j < 18; ++j ) cin >> a[j];
        if ( chk[a] ) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << '\n';

    return 0;
}