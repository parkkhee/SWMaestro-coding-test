// 2661
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n;

bool check(string &s)
{
    for ( int size = 1; size <= s.size() - 1; ++size )
    {
        const int start = s.size() - size;
        string a = "", b = "";

        for ( int i = start - size, j = start; i >= 0 && i < start && j < s.size(); ++i, ++j )
        {
            a += s[i]; b += s[j];
        }

        if ( a.size() > 0 && b.size() > 0 && a == b ) return false;
        
    }

    return true;
}

void dfs(string &s)
{
    if ( s.size() >= n )
    {
        cout << s << '\n';
        exit(0);
    }

    char ch[] = { '1', '2', '3' };
    for ( auto &c : ch )
    {
        s += c;
        if(check(s)) dfs(s);
        s.pop_back();
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    string s = "";
    dfs(s);

    return 0;
}