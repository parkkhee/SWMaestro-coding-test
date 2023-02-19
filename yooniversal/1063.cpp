// 1063
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

int dx[] = { 0,0,-1,1,1,1,-1,-1 }, dy[] = { 1,-1,0,0,1,-1,1,-1 };

bool OOB(int x, int y) { return x < 0 || x >= 8 || y < 0 || y >= 8; }

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string a, b; cin >> a >> b;
    ii king = { a[1] - '1', a[0] - 'A' };
    ii stone = { b[1] - '1', b[0] - 'A' };

    int n; cin >> n;
    vi arr;
    while ( n-- )
    {
        string s; cin >> s;
        if ( s == "R" ) arr.push_back(0);
        else if ( s == "L" ) arr.push_back(1);
        else if ( s == "B" ) arr.push_back(2);
        else if ( s == "T" ) arr.push_back(3);
        else if ( s == "RT" ) arr.push_back(4);
        else if ( s == "LT" ) arr.push_back(5);
        else if ( s == "RB" ) arr.push_back(6);
        else if ( s == "LB" ) arr.push_back(7);
    }

    for ( int i = 0; i < arr.size(); ++i )
    {
        int nx = king.first + dx[arr[i]], ny = king.second + dy[arr[i]];
        int nx2 = stone.first + dx[arr[i]], ny2 = stone.second + dy[arr[i]];
        if ( OOB(nx, ny) ) continue;
        if ( nx == stone.first && ny == stone.second )
        {
            if ( OOB(nx2, ny2) ) continue;
            king = { nx, ny };
            stone = { nx2, ny2 };
        } 
        else
        {
            king = { nx, ny };
        }
    }

    string ret;
    ret += king.second + 'A';
    ret += king.first + '1';

    string ret2;
    ret2 += stone.second + 'A';
    ret2 += stone.first + '1';

    cout << ret << '\n' << ret2 << '\n';

    return 0;
}