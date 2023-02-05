// 8979
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
    int num, x, y, z, rank;
    bool operator<(P &p)
    {
        if ( p.x != x ) return p.x < x;
        if ( p.y != y ) return p.y < y;
        return p.z < z;
    }
};

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<P> a;
    for ( int i = 0; i < n; ++i )
    {
        int num, x, y, z;
        cin >> num >> x >> y >> z;
        a.push_back({ num, x, y, z, -1 });
    }

    sort(a.begin(), a.end());

    int prev_rank = 0, cnt = 0;
    P prev = { -1, 0, 0, 0, -1 };
    for ( auto& cur : a )
    {
        ++cnt;
        if ( prev.x == cur.x && prev.y == cur.y && prev.z == cur.z ) cur.rank = prev_rank;
        else cur.rank = cnt;

        prev = cur;
        prev_rank = cur.rank;

        if ( cur.num == k )
        {
            cout << cur.rank << '\n';
            break;
        }
    }

    return 0;
}