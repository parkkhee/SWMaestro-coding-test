// 1106
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cache[1005][25];
int c, n;
vii a;

int f(int person, int cur)
{
    if ( person >= c ) return 0;
    if ( cur >= n ) return INF;
    int &ret = cache[person][cur];
    if ( ret != -1 ) return ret;
    ret = INF;

    bool flag = false;
    for ( int i = 0; ; ++i )
    {
        if ( flag ) break;
        if ( person + a[cur].second * i >= c ) flag = true;
        ret = min(ret, f(person + a[cur].second * i, cur + 1) + a[cur].first * i);
    }

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> c >> n;
    for ( int i = 0; i < n; ++i )
    {
        int cost, person; cin >> cost >> person;
        a.push_back({ cost, person });
    }

    cout << f(0, 0) << '\n';

    return 0;
}