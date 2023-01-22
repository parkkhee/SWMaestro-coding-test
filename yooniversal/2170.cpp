// 2170
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
    ll x, y;
    P(ll x, ll y) : x(x), y(y) {}

    bool operator<(P &p)
    {
        return x < p.x;
    }
};

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<P> a;
    for ( int i = 0; i < n; ++i )
    {
        ll x, y; cin >> x >> y;
        a.push_back(P(x, y));
    }
    sort(a.begin(), a.end());

    ll ret = 0;
    ll m_x = INF, m_y = -INF; // min, max (x, y)
    for ( auto& cur : a )
    {
        ll same = 0;
        if ( m_x != INF && m_y != -INF )
        {
            if ( m_y > cur.x ) same = m_y - cur.x;
            same = min(same, cur.y - cur.x);
        }

        ret += cur.y - cur.x - same;
        m_x = min(m_x, cur.x);
        m_y = max(m_y, cur.y);
    }

    cout << ret << '\n';


    return 0;
}
