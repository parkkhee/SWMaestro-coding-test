// 1213
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 15746;



int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;
    map<char, int> cnt;

    for ( int i = 0; i < s.size(); ++i )
    {
        cnt[s[i]]++;
    }

    int odd_cnt = 0;
    char odd_mark = '_';
    for ( char i = 'A'; i <= 'Z'; ++i )
    {
        if ( cnt[i] % 2 != 0 )
        {
            ++odd_cnt;
            cnt[i]--;
            odd_mark = i;
        }
    }

    if(odd_cnt > 1) cout << "I\'m Sorry Hansoo\n";
    else
    {
        string ret = "";
        
        for ( char i = 'A'; i <= 'Z'; ++i )
        {
            if ( cnt[i] == 0 ) continue;
            for(int j=0; j<cnt[i]/2; ++j )
                ret += i;
        }

        string first = ret;
        reverse(ret.begin(), ret.end());
        if ( odd_mark == '_' ) ret = first + ret;
        else ret = first + odd_mark + ret;

        cout << ret << '\n';
    }

    return 0;
}