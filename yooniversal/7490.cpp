// 7490
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n;
vector<string> ret;

pair<vi, vector<char>> new_string(string &s)
{
    vi num;
    vector<char> ops;

    int tmp = 0;
    for ( int i = 0; i < s.size(); ++i )
    {
        if ( '0' <= s[i] && s[i] <= '9' ) tmp = tmp * 10 + (s[i] - '0');
        else if ( s[i] == '+' || s[i] == '-' )
        {
            ops.push_back(s[i]);
            num.push_back(tmp);
            tmp = 0;
        }
    }

    num.push_back(tmp);

    return { num, ops };
}

bool test(string &s)
{
    auto tmp = new_string(s);
    vi num = tmp.first;
    vector<char> ops = tmp.second;

    int ret = num[0];
    for ( int i = 0; i < ops.size(); ++i )
    {
        if ( ops[i] == '+' )
        {
            ret = ret + num[i + 1];
        }
        else
        {
            ret = ret - num[i + 1];
        }
    }

    return ret == 0;
}

void dfs(string& s, int size)
{
    s += size + '0';

    if ( size >= n )
    {
        if ( test(s) ) ret.push_back(s);

        s.pop_back();
        return;
    }

    char ops[] = { '+', '-', ' ' };
    for ( auto &op : ops )
    {
        s += op;
        dfs(s, size + 1);
        s.pop_back();
    }

    s.pop_back();
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while ( t-- )
    {
        ret.clear();
        cin >> n;
        
        string s = "";
        dfs(s, 1);

        sort(ret.begin(), ret.end());

        for ( auto &r : ret )
        {
            cout << r << '\n';
        }

        cout << '\n';
    }

    return 0;
}