// 13305
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 1000000000;



int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> d(n - 1);
    for ( int i = 0; i < n - 1; ++i ) cin >> d[i];
    
    vector<ll> place(n);
    for ( int i = 0; i < n; ++i ) cin >> place[i];

    ll ret = 0;
    int cur = 0;
    while ( cur < n - 1 )
    {
        ll min = place[cur];
        int next = cur;
        for ( int i = cur+1; i < n; ++i )
        {
            if ( min > place[i] )
            {
                min = place[i];
                next = i;
                break;
            }
        }

        //printf("cur:%d next:%d\n", cur, next);

        if ( next == cur ) next = n - 1;

        for ( int i = cur; i < next; ++i )
        {
            //printf("d[%d]:%d place[%d]:%d\n", i, d[i], cur, place[cur]);
            ret += d[i] * place[cur];
        }

        cur = next;
    }

    cout << ret << '\n';

    return 0;
}
