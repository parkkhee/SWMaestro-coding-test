// 13335
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

struct P
{
    int cur, i, v;
};

int sum;
queue<P> q;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, w, L; cin >> n >> w >> L;
    vi a(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];
    
    int next = 0, ret = 0;
    while ( next < n || !q.empty() )
    {
        ++ret;

        if ( q.empty() )
        {
            if ( next >= n ) continue;
            q.push({ 0, next, a[next] });
            sum += a[next++];
        }
        else
        {
            bool chk[1005];
            for ( int i = 0; i < 1005; ++i ) chk[i] = false;

            // 모든 트럭 돌면서 위치 한 칸 움직여주기
            while ( !q.empty() )
            {
                auto p = q.front();
                if ( chk[p.i] ) break;
                chk[p.i] = true; q.pop();

                // 트럭 도착하면 빼주기 + 추가X
                if ( p.cur + 1 >= w )
                {
                    sum -= p.v;
                    continue;
                }

                q.push({ p.cur + 1, p.i, p.v });
            }

            if ( next >= n ) continue;
            if ( sum + a[next] <= L )
            {
                q.push({ 0, next, a[next] });
                sum += a[next++];
            }
        }
    }

    cout << ret << '\n';

    return 0;
}