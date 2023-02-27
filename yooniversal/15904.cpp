// 15904
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

    string s;
    getline(cin, s);
    char ch[4] = { 'U','C','P','C' };

    int j = 0;
    for ( int i = 0; i < s.size(); ++i )
    {
        if ( j >= 4 ) break;
        if ( s[i] == ch[j] ) ++j;
    }

    if ( j >= 4 ) cout << "I love UCPC\n";
    else cout << "I hate UCPC\n";

    return 0;
}