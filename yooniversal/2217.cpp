// 2217
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vi a(n);
    
    for ( int i = 0; i < n; ++i )
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ret = 0;
    for ( int i = 0; i < n; ++i )
    {
        ret = max(ret, a[i] * (n - i));
    }
    cout << ret << '\n';

    return 0;
}