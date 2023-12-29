#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
char a[1004][1004];
int n,m,sx,sy,dx[4]={-1,0,0,1},dy[4]={0,1,-1,0},ret,y,x;
int fire_c[1004][1004], per_c[1004][1004];
bool in(int y, int x) {
    return 0<=y&&y<n&&0<=x&&x<m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    queue<pair<int, int> > q;
    cin>>n>>m;
    fill(&fire_c[0][0], &fire_c[0][0] + 1004*1004, INF);
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j]=='F'){
                fire_c[i][j]=1;
                q.push(make_pair(i, j));
            }
            else if (a[i][j]=='J'){
                sy=i;sx=j;
            }
        }
    }
    while (q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!in(ny,nx)) continue;
            if(fire_c[ny][nx] != INF || a[ny][nx]=='#') continue;
            fire_c[ny][nx] = fire_c[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
    per_c[sy][sx]=1;
    q.push(make_pair(sy,sx));
    while (q.size())
    {
        y=q.front().first;
        x=q.front().second;
        q.pop();
        if (x==m-1||y==n-1||x==0||y==0) {
            ret = per_c[y][x];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!in(ny,nx))continue;
            if(per_c[ny][nx]||a[ny][nx]=='#')continue;
            if(fire_c[ny][nx]<=per_c[y][x]+1)continue;
            per_c[ny][nx]=per_c[y][x]+1;
            q.push(make_pair(ny,nx));
        }
    }
    if (ret != 0) cout << ret << '\n';
    else cout << "IMPOSSIBLE \n";
    return 0;    
}