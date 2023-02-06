// 2023
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
map<int, bool> not_prime;

bool is_not_prime(int n)
{
    //cout << "n:" << n << " bool:" << not_prime[n] << '\n';
    if ( not_prime[n] ) return true;
    int SN = sqrt(n);
    for ( int i = 2; i <= SN; i++ )
    {
        if ( not_prime[i] ) continue;
        for ( int j = i + i; j <= n; j += i )
            not_prime[j] = true;
    }

    return not_prime[n];
}

void dfs(string& s)
{
    if ( s.size() >= n )
    {
        if ( stoi(s) == 1 ) return;
        ret.push_back(s);
        return;
    }

    if ( s.size() >= 1 && s[0] == '1' ) return;

    for ( int i = 1; i <= 9; i ++ )
    {
        string new_s = s;
        new_s += i + '0';
       
        bool flag = true;
        for ( int sz = 1; sz <= new_s.size(); ++sz )
        {
            if ( is_not_prime(stoi(new_s.substr(0, sz))) )
            {
                flag = false;
                //cout << "[not pass] sz:" << sz << " new_s:" << new_s << " ns:"<< new_s.size() << " s:"<< s << '\n';
                break;
            }
        }

        if ( flag ) dfs(new_s);
        new_s.pop_back();
        //cout << "aft new_s:" << new_s << '\n';
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

    //sort(ret.begin(), ret.end());
    for ( string &s : ret )
        cout << s << '\n';

    return 0;
}