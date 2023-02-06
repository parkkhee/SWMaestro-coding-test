// 2503
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 15746;

struct P
{
    string s;
    int strike, ball;
    P(string s, int strike, int ball) : s(s), strike(strike), ball(ball) {}
};

bool chk(P &p, string& s)
{
    int strike = 0, ball = 0;
    for ( int i = 0; i < 3; ++i )
    {
        if ( p.s[i] == s[i] )
        {
            ++strike;
        }
        else
        {
            for ( int j = 0; j < 3; ++j )
            {
                if ( i == j ) continue;
                if ( p.s[i] == s[j] )
                {
                    ++ball;
                    break;
                }
            }
        }
    }

    if ( strike == p.strike && ball == p.ball ) return true;
    return false;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<P> a;
    for ( int i = 0; i < n; ++i )
    {
        string s; cin >> s;
        int strike, ball;
        cin >> strike >> ball;
        a.push_back(P(s, strike, ball));
    }

    int ret = 0;
    for ( int i = 1; i <= 9; ++i )
    {
        for ( int j = 1; j <= 9; ++j )
        {
            if ( i == j ) continue;

            for ( int k = 1; k <= 9; ++k )
            {
                if ( i == k || j == k ) continue;

                string s = "";
                s += i + '0';
                s += j + '0';
                s += k + '0';
                
                bool flag = true;
                for ( int t = 0; t < n; ++t )
                    if ( !chk(a[t], s) )
                    {
                        flag = false;
                        break;
                    }
                if ( flag )
                    ++ret;
            }
        }

    cout << ret << '\n';

    return 0;
}
