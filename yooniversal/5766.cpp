// 5766
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 9901;

struct P
{
    int number, cnt;

    bool operator<(P &p)
    {
        return cnt < p.cnt;
    }
};

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;

    while ( 1 )
    {
        cin >> n >> m;
        if ( n == 0 && m == 0 ) break;

        vector<P> a(505);
        for ( int i = 0; i < n; ++i )
        {
            for ( int j = 0; j < m; ++j )
            {
                int person; cin >> person;
                a[person].number = person;
                a[person].cnt++;
            }
        }

        sort(a.rbegin(), a.rend());

        int target = a[1].cnt;
        vi ret;
        for ( int i = 1; ; ++i )
        {
            if ( target != a[i].cnt ) break;
            ret.push_back(a[i].number);
        }

        sort(ret.begin(), ret.end());
        for ( auto &next : ret )
        {
            cout << next << " ";
        }
        cout << '\n';
    }

    return 0;
}
