// 1253
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n;
map<int, bool> chk;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    vi a(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];
    sort(a.begin(), a.end());

    int ret = 0;
    for ( int i = 0; i < n; ++i )
    {
        if ( chk[a[i]] )
        {
            ++ret;
            continue;
        }

        int L = i == 0 ? 1 : 0;
        if ( L >= n ) continue;

        int R = lower_bound(a.begin(), a.end(), a[i] - a[L]) - a.begin();
        while ( R == i || L >= R ) R++;
        if ( R >= n ) continue;

        while ( L < n && R < n )
        {
            if ( a[L] + a[R] == a[i] )
            {
                chk[a[i]] = true;
                ++ret;
                break;
            }

            if ( a[L] + a[R] < a[i] )
            {
                while ( L == i ) ++L;
                if ( L >= n ) break;

                int R_st = lower_bound(a.begin(), a.end(), a[i] - a[L]) - a.begin();
                int R_ed = upper_bound(a.begin(), a.end(), a[i] - a[L]) - a.begin();

                while ( 1 )
                {
                    int sz = R_ed - R_st;
                    if ( sz == 0 )
                    {
                        ++L;
                        if ( L >= n ) break;
                        continue;
                    }

                    if ( sz == 1 && R_st == i )
                    {
                        ++L;
                        if ( L >= n ) break;
                        continue;
                    }

                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}