// 1158
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 1000000000;

int n, k;
queue<int> q;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for ( int i = 1; i <= n; ++i )
        q.push(i);

    int cnt = 0;
    vi ret;
    while ( !q.empty() )
    {
        int cur = q.front(); q.pop();
        if ( ++cnt != k )
        {
            q.push(cur);
            continue;
        }

        ret.push_back(cur);
        cnt = 0;
    }

    cout << "<";
    for ( int i=0; i<ret.size(); ++i )
    {
        cout << ret[i];
        if ( i != ret.size() - 1 ) cout << ", ";
    }
    cout << ">\n";

    return 0;
}
