// 1049
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

    int n, m; cin >> n >> m;
    int pkg = INF, each = INF;
    while ( m-- )
    {
        int a, b; cin >> a >> b;
        pkg = min(pkg, a);
        each = min(each, b);
    }

    int ret = 0;
    if ( pkg <= 6 * each )
    {
        ret += (n / 6) * pkg;
        n %= 6;
    }
    else
    {
        ret += n * each;
        n = 0;
    }

    if ( n != 0 )
        ret += min(pkg, n * each);

    cout << ret << '\n';

    return 0;
}