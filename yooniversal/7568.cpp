// 7568
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
    int x, y, i;
    P(int x, int y, int i) : x(x), y(y), i(i) {}
    
    bool operator<(P &p)
    {
        //return x > p.x && y > p.y;
        if ( x > p.x && y > p.y ) return true;
        if ( x <= p.x && y <= p.y ) return false;
        return true;
    }
};

int n;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    vector<P> arr;
    for ( int i = 0; i < n; ++i )
    {
        int x, y; cin >> x >> y;
        arr.push_back(P(x, y, i));
    }

    sort(arr.begin(), arr.end());

    //cout << "=============\n";
    //for ( int i = 0; i < n; ++i ) printf("%d %d\n", arr[i].x, arr[i].y);

    int ret[51];
    int rank = 1;
    for ( int i = 0; i < n-1; ++i )
    {
        ret[arr[i].i] = rank;
        if ( arr[i].x > arr[i+1].x && arr[i].y > arr[i+1].y ) {
            rank = i + 2;
        }
    }

    ret[arr[n - 1].i] = rank;

    for ( int i = 0; i < n; ++i ) cout << ret[i] << " ";
    cout << '\n';

    return 0;
}
