// 21608
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 1000000000;

struct xy
{
    int x, y;
    bool operator<(xy &a)
    {
        if ( x != a.x ) return x < a.x;
        return y < a.y;
    }
};

int a[21][21];
int n;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
bool like_chk[405][405];

bool OOB(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}

ii select(int person)
{
    int score[21][21];
    memset(score, 0, sizeof(score));

    // 1번 조건
    int max_score = 0;
    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < n; ++j )
    {
        if ( a[i][j] != 0 ) continue;
        for ( int k = 0; k < 4; ++k )
        {
            int nx = i + dx[k], ny = j + dy[k];
            if ( OOB(nx, ny) ) continue;
            if ( like_chk[person][a[nx][ny]] )
                max_score = max(max_score, ++score[i][j]);
        }
    }
    
    vii good;
    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < n; ++j )
    {
        if ( a[i][j] != 0 ) continue;
        if ( max_score == score[i][j] )
            good.push_back({ i,j });
    }

    if ( good.size() == 1 ) return good[0];

    // 2번 조건
    int blank[21][21];
    memset(blank, 0, sizeof(blank));

    int max_blank = 0;
    for ( auto &xy : good )
    {
        if ( a[xy.first][xy.second] != 0 ) continue;
        for ( int k = 0; k < 4; ++k )
        {
            int nx = xy.first + dx[k], ny = xy.second + dy[k];
            if ( OOB(nx, ny) || a[nx][ny] != 0 ) continue;
            max_blank = max(max_blank, ++blank[xy.first][xy.second]);
        }
    }

    vector<xy> good2;
    for ( auto& xy : good )
    {
        if ( a[xy.first][xy.second] != 0 ) continue;
        if ( max_blank == blank[xy.first][xy.second] )
            good2.push_back({ xy.first, xy.second });
    }

    if ( good2.size() == 1 ) return { good2[0].x, good2[0].y };

    // 3번 조건
    sort(good2.begin(), good2.end());
    return { good2[0].x, good2[0].y };
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    const int len = n * n;
    vi order;
    for ( int i = 0; i < len; ++i )
    {
        int index; cin >> index;
        order.push_back(index);
        for ( int j = 0; j < 4; ++j )
        {
            int v; cin >> v;
            like_chk[index][v] = true;
        }
    }

    // 자리 선택
    for ( auto& o : order )
    {
        ii xy = select(o);
        a[xy.first][xy.second] = o;
    }

    // 점수 계산
    int ret = 0;
    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < n; ++j )
    {
        int cur = a[i][j];
        int cnt = 0;
        for ( int k = 0; k < 4; ++k )
        {
            int nx = i + dx[k], ny = j + dy[k];
            if ( OOB(nx, ny) ) continue;
            if ( like_chk[cur][a[nx][ny]] ) ++cnt;
        }

        if ( cnt <= 1 ) ret += cnt;
        else if ( cnt == 2 ) ret += 10;
        else if ( cnt == 3 ) ret += 100;
        else ret += 1000;
    }

    cout << ret << '\n';

    return 0;
}