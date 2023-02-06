// 1138
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n;
vi a;

void solve()
{
    int v[15];
    for ( int i = 0; i < 15; ++i ) v[i] = INF;

    for ( int i = 0; i < n; ++i )
    {
        
        int cnt = 0;
        bool flag = false;
        for ( int j = 0; j < n; ++j )
        {
            if ( v[j] > i + 1 ) ++cnt;
            if ( cnt == a[i] )
            {
                if ( v[j + 1] == INF )
                {
                    flag = true;
                    v[j + 1] = i + 1;
                }
                if(flag) break;
            }
        }

        if ( !flag ) v[0] = i + 1;
    }

    for ( int i = 0; i < n; ++i ) cout << v[i] << " ";
    cout << '\n';
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];

    solve();

    return 0;
}