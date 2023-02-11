// 13142
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000005, INF = 1000000001, MOD = 1000000000;

int GCD(int a, int b)
{
    if ( a < b ) swap(a, b);

    int tmp = a;
    while ( b != 0 )
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while ( t-- )
    {
        int n; cin >> n;
        
        int ret = 0;
        const int len = sqrt(n);
        for(int i=1; i<=len; ++i) {
            if ( n % i != 0 ) continue;
            if ( GCD(n/i, i) == 1 ) ++ret;
        }

        cout << ret << '\n';
    }

    return 0;
}