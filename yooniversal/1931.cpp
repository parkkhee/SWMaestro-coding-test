// 1931
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 15746;

struct P
{
    int s, e;
    P(int s, int e) : s(s), e(e) {}
    
    bool operator<(P &p)
    {
        if ( e == p.e ) return s < p.s;
        return e < p.e;
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
        int s, e; cin >> s >> e;
        a.push_back(P(s, e));
    }

    sort(a.begin(), a.end());

    int ret = 0;
    int past = 0;
    for ( int i = 0; i < n; ++i )
    {
        if ( past > a[i].s ) continue;
        ++ret;
        past = a[i].e;
    }

    cout << ret << '\n';

    return 0;
}
