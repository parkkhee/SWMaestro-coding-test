// 16922
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000005, INF = 1000000001, MOD = 1000000000;

int n;
int ret;
bool chk[MAX][21];
int v[4] = { 1,5,10,50 };

void dfs(int val, int cnt)
{
    if ( cnt >= n )
    {
        ++ret;
        return;
    }


    for ( auto &vv : v )
    {
        if ( chk[val + vv][cnt + 1] ) continue;
        chk[val + vv][cnt + 1] = true;
        dfs(val + vv, cnt + 1);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    dfs(0, 0);
    cout << ret << '\n';

    return 0;
}