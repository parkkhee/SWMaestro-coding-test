// 2798
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 9901;

int n, m;
int ret;
vi a;

void f(int cnt, int sum, int before)
{
    if ( cnt >= 3 )
    {
        if ( sum > m ) return;
        ret = max(ret, sum);
        return;
    }

    int ret = 0;
    for ( int i = before + 1; i < n; ++i )
    {
        f(cnt + 1, sum + a[i], i);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    a.resize(n);
    for ( int i = 0; i < n; ++i )
    {
        cin >> a[i];
    }

    f(0, 0, -1);

    cout << ret << '\n';

    return 0;
}
