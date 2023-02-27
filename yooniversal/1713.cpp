// 1713
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

struct P
{
    int u, cnt, time;
    bool operator<(P &p)
    {
        if ( cnt != p.cnt ) return cnt < p.cnt;
        return time < p.time;
    }
};

int n;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<P> a;
    cin >> n;
    int t; cin >> t;
    int time = 0;
    while ( t-- )
    {
        ++time;
        int u; cin >> u;

        bool flag = false;
        for ( auto &cur : a )
        {
            if ( cur.u != u ) continue;
            ++cur.cnt;
            flag = true;
            break;
        }

        if ( flag ) continue;

        if ( a.size() < n ) a.push_back({ u, 0, time });
        else
        {
            sort(a.rbegin(), a.rend());
            a.pop_back();
            a.push_back({ u, 0, time });
        }
    }

    vi r;
    for ( int i = 0; i < a.size(); ++i )
        r.push_back(a[i].u);

    sort(r.begin(), r.end());

    for ( auto &ret : r )
        cout << ret << " ";
    cout << '\n';

    return 0;
}