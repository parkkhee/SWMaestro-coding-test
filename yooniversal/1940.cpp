// 1940
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
    vi a(n);
    for ( int i = 0; i < n; ++i )
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ret = 0;
    for ( int i = 0, j = n - 1; i < j; )
    {
        if ( a[i] + a[j] == m )
        {
            ++ret;
            ++i; --j;
        }
        else if ( a[i] + a[j] < m )
        {
            ++i;
        }
        else
        {
            --j;
        }
    }

    cout << ret << '\n';

    return 0;
}