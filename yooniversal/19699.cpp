// 19699
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n, m;
bool chk[10005];
bool prime[10005];
vi a;
vi ret;

void getPrime()
{
    memset(prime, true, sizeof(prime));
    for ( int i = 1; i <= 10000; ++i )
    {
        const int len = sqrt(i);
        for ( int j = 2; j <= len; ++j )
        {
            if ( i % j != 0 ) continue;
            prime[i] = false;
            break;
        }
    }
}

void dfs(int cur, int cnt, int sum)
{
    if ( cnt >= m )
    {
        if ( prime[sum] )
            ret.push_back(sum);

        return;
    }

    for ( int i = cur + 1; i < n; ++i )
    {
        dfs(i, cnt + 1, sum + a[i]);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    getPrime();

    cin >> n >> m;
    a.resize(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i];

    dfs(-1, 0, 0);

    if ( ret.size() > 0 )
    {
        sort(ret.begin(), ret.end());
        for ( auto &r : ret )
        {
            if ( chk[r] ) continue;
            chk[r] = true;
            cout << r << " ";
        }
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}