// 1038
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int n;
int cnt;

void f(string& s, int size)
{
    if ( s.size() == size )
    {
        ++cnt;
        if ( cnt == n )
        {
            cout << s << '\n';
            exit(0);
        }

        return;
    }

    for ( int i = 0; i <= 9; ++i )
    {
        if ( s[s.size() - 1] - '0' <= i ) continue;
        s += i + '0';
        f(s, size);
        s.pop_back();
    }

    if ( cnt >= 1022 )
    {
        cout << -1 << '\n';
        exit(0);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    if ( n == 0 )
    {
        cout << 0 << '\n';
        return 0;
    }

    for ( int sz = 1;; ++sz )
    {
        for ( int i = 1; i <= 9; ++i )
        {
            string s = "";
            s += i + '0';
            f(s, sz);
        }
    }

    return 0;
}