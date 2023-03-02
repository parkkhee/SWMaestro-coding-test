// 2659
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000009;

bool chk[4];
int cnt;

void solve(int cur, int target)
{
    string result = to_string(target);
    
    while ( 1 )
    {
        string origin = to_string(cur);
        while ( origin[0] == '0' || origin[1] == '0' || origin[2] == '0' || origin[3] == '0' )
        {
            ++cur;
            origin = to_string(cur);
        }
        
        vi arr;
        for ( int i = 0; i < 4; ++i )
        {
            int v = 0;
            for ( int j = i, cnt = 0; cnt < 4; j = (j + 1) % 4, ++cnt )
                v = v * 10 + origin[j]-'0';

            arr.push_back(v);
        }
        sort(arr.begin(), arr.end());

        string after = to_string(arr[0]);

        if ( origin == after ) ++cnt;

        if ( after == result )
        {
            cout << cnt << '\n';
            exit(0);
        }

        ++cur;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vi a(4);
    for ( int i = 0; i < 4; ++i ) cin >> a[i];

    vi arr;
    for ( int i = 0; i < 4; ++i )
    {
        int v = 0;
        for ( int j = i, cnt = 0; cnt < 4; j = (j + 1) % 4, ++cnt )
            v = v * 10 + a[j];

        arr.push_back(v);
    }

    sort(arr.begin(), arr.end());

    solve(1111, arr[0]);

    return 0;
}