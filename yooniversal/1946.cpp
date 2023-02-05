// 1946
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int cache[MAX];
int n;

int f(int cur, vii& arr)
{
    if ( cur >= n-1 ) return 0;
    int &ret = cache[cur];
    if ( ret != -1 ) return ret;
    ret = 0;

    for ( int i = cur + 1; i < n; ++i )
    {
        if ( arr[cur].second < arr[i].second )
        {
            //printf("f(%d):%d\n", i, f(i,arr));
            //ret = max(ret, f(i, arr));
        }
        else
        {
            //printf("*f(%d):%d\n", i, f(i, arr));
            ret = max(ret, f(i, arr) + 1);
        }
    }

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while ( t-- )
    {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        vii arr;
        for ( int i = 0; i < n; ++i )
        {
            int a, b; cin >> a >> b;
            arr.push_back({ a, b });
        }
        sort(arr.begin(), arr.end());

        //int ret = 0;
        //for ( int i = 0; i < n; ++i )
        //    ret = max(ret, f(i, arr) + 1);

        //cout << f(0, arr) << '\n';
        //for ( int i = 0; i < n; ++i ) printf("cache(%d):%d\n", i, cache[i]+1);
    }

    return 0;
}