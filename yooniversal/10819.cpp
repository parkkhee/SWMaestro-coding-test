// 10819
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 15746;

int ret = -INF;
int n;
bool chk[10];
vi arr;

void f(vi &a)
{
    int sum = 0;
    for ( int i = 1; i < a.size(); ++i )
        sum += abs(a[i - 1] - a[i]);

    ret = max(ret, sum);
}

void make_arr(vi& a, int size)
{
    if ( size >= n )
    {
        f(a);
        return;
    }

    for ( int i = 0; i < n; ++i )
    {
        if ( chk[i] ) continue;
        chk[i] = true;
        a.push_back(arr[i]);
        make_arr(a, a.size());
        a.pop_back();
        chk[i] = false;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    arr.resize(n);
    for ( int i = 0; i < n; ++i ) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vi new_arr;
    make_arr(new_arr, new_arr.size());

    cout << ret << '\n';

    return 0;
}