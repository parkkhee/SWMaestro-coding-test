// 1699
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cache[MAX];

int f(int n)
{
    //if ( n < 0 ) return INF;
    if ( n == 0 ) return 0;
    int &ret = cache[n];
    if ( ret != -1 ) return ret;
    ret = INF;
    
    for ( int i = 1; i <= sqrt(n); ++i )
    {
        if ( n < i * i ) continue;
        ret = min(ret, f(n - i*i) + 1);
    }

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << f(n) << '\n';

    return 0;
}
