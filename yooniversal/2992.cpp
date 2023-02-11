// 2992
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000005, INF = 1000000001, MOD = 1000000000;

string s;
map<string, bool> chk;
bool char_chk[10];
vi val;

void dfs(string& cur)
{
    if ( cur.size() >= s.size() )
    {
        if ( chk[cur] ) return;
        chk[cur] = true;
        val.push_back(stoi(cur));
        return;
    }

    for ( int i = 0; i < s.size(); ++i )
    {
        if ( char_chk[i] ) continue;
        char_chk[i] = true;
        cur += s[i];
        dfs(cur);
        cur.pop_back();
        char_chk[i] = false;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;
    string a = "";
    dfs(a);

    sort(val.begin(), val.end());

    const int input = stoi(s);
    int idx = -1;
    for ( int i = 0; i < val.size(); ++i )
    {
        if ( val[i] == input )
        {
            idx = i;
            break;
        }
    }

    if ( idx + 1 >= val.size() ) cout << 0 << '\n';
    else cout << val[idx + 1] << '\n';

    return 0;
}