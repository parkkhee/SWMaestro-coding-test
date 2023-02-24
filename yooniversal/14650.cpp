// 14650
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000007;

int n;
int ret;

void dfs(string &s)
{
    if ( s.size() >= n )
    {
        int sum = 0;
        for ( int i = 0; i < s.size(); ++i )
            sum += s[i] - '0';

        if ( sum % 3 == 0 ) ++ret;
        return;
    }

    char chs[] = { '0','1','2' };
    for ( auto &ch : chs )
    {
        s += ch;
        dfs(s);
        s.pop_back();
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    string a = "1";
    dfs(a);

    a = "2";
    dfs(a);

    cout << ret << '\n';

    return 0;
}