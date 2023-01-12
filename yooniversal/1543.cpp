// 1543
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 9901;

string s, w;
int a[2505];

int dfs(int start)
{
    if ( start > s.size()-w.size() ) return 0;
    int &ret = a[start];
    if ( ret != -1 ) return ret;
    ret = 0;

    bool flag = true;
    for ( int j = start; j < start + w.size(); ++j )
    {
        int k = j - start;
        if ( s[j] != w[k] )
        {
            flag = false;
            break;
        }
    }
    if ( flag )
        ret = max(ret, 1 + dfs(start + w.size()));
    
    int next = -1;
    for ( int i = start + 1; i < s.size(); ++i )
    {
        if ( s[i] == w[0] )
        {
            next = i;
            break;
        }
    }

    if(next != -1)
        ret = max(ret, dfs(next));

    return ret;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    getline(cin, s);
    getline(cin, w);

    memset(a, -1, sizeof(a));

    cout << dfs(0) << '\n';


    return 0;
}
