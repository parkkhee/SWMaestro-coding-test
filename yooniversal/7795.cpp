// 7795
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

    int t; cin >> t;
    while ( t-- )
    {
        int n, m; cin >> n >> m;
        vi a(n), b(m);
        for ( int i = 0; i < n; ++i ) cin >> a[i];
        for ( int i = 0; i < m; ++i ) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        /*
        cout << "================\n";
        for ( int i = 0; i < n; ++i ) cout << a[i] << " ";
        cout << '\n';
        for ( int i = 0; i < m; ++i )  cout << b[i] << " ";
        cout << '\n';*/

        int ret = 0;
        for ( int i = 0, j = 0; i < n; ++i )
        {
            //printf("i:%d j:%d\n", i, j);
            while ( i<n && j<m && a[i] > b[j] )
            {
                //printf("-- i:%d j:%d\n", i, j);
                ++j;

            }
            ret += j;

            if ( j >= m )
            {
                if ( i < n ) ret += j * (n - (i + 1));
                break;
            }
        }

        cout << ret << '\n';
    }

    return 0;
}