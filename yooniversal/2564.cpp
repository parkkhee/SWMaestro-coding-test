// 2564
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;



int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> m >> n;
    int sz; cin >> sz;
    vii a;
    while ( sz-- )
    {
        int d, v; cin >> d >> v;
        if(d == 1) a.push_back({ 0,v });
        else if ( d == 2 ) a.push_back({ n,v });
        else if ( d == 3 ) a.push_back({ v,0 });
        else a.push_back({ v,m });
    }

    int cd, cv; cin >> cd >> cv;
    int x, y;
    if ( cd == 1 ) { x = 0; y = cv; }
    else if ( cd == 2 ) { x = n; y = cv; }
    else if ( cd == 3 ) { x = cv; y = 0; }
    else { x = cv; y = m; }

    int ret = 0;
    for ( auto& store : a )
    {
        int diff_x = abs(store.first - x);
        int diff_y = abs(store.second - y);
        if ( diff_x == n ) ret += min(store.second + y + diff_x, 2 * m - store.second - y + diff_x);
        else if ( diff_y == m ) ret += min(store.first + x + diff_y, 2 * n - store.first - x + diff_y);
        else ret += min(diff_x + diff_y, 2 * n + 2 * m - diff_x + diff_y);
    }

    cout << ret << '\n';

    return 0;
}