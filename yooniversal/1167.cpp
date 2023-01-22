// 1167
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
    int n, d;
    P(int n, int d) : n(n), d(d) {};
};

int n;
int ret;
int leaf = -1;
vector<vector<P>> a;
bool chk[MAX];

void dfs(int cur, int sum)
{
    if ( ret < sum )
    {
        ret = sum;
        leaf = cur;
    }

    for ( auto &next : a[cur] )
    {
        if ( chk[next.n] ) continue;
        chk[next.n] = true;
        dfs(next.n, sum + next.d);
    }

}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n + 1);
    
    for ( int i = 0; i < n; ++i )
    {
        int cur; cin >> cur;
        
        while ( 1 )
        {
            int next, d; cin >> next;
            if ( next == -1 ) break;
            cin >> d;
            a[cur].push_back(P(next, d));
        }
    }

    chk[1] = true;
    dfs(1, 0);

    memset(chk, false, sizeof(chk));
    chk[leaf] = true;
    dfs(leaf, 0);
    
    cout << ret << '\n';

    return 0;
}
