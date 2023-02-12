// 1717
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000005, INF = 1000000001, MOD = 1000000000;

int uni[MAX];

int parent(int a)
{
    if ( uni[a] == a ) return a;
    return uni[a] = parent(uni[a]);
}

void make_union(int a, int b)
{
    a = parent(a); b = parent(b);
    if ( a < b ) uni[b] = a;
    else uni[a] = b;
}

bool same_parent(int a, int b)
{
    a = parent(a); b = parent(b);
    return a == b;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for ( int i = 0; i < MAX; ++i ) uni[i] = i;

    int n, m; cin >> n >> m;
    while ( m-- )
    {
        int mode, a, b; cin >> mode >> a >> b;
        if ( mode == 0 ) make_union(a, b);
        else
        {
            if ( same_parent(a, b) ) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}