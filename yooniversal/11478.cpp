// 11478
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 9901;

map<string, bool> chk;
string s;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    int ret = 0;
    for ( int i = 0; i < s.size(); ++i )
    {
        for ( int size = 1; size <= s.size(); ++size )
        {
            if ( i + size - 1 > s.size() ) break;
            if ( chk[s.substr(i, size)] ) continue;
            chk[s.substr(i, size)] = true;
            ++ret;
        } 
    }

    cout << ret << '\n';

    return 0;
}
