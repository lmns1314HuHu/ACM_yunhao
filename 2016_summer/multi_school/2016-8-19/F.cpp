#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

bool grid[55][55];
int ren[15][2];
int t, n, k;
int R[15];
int cnt[1<<10];
bool used[15];
int dis = {-1,0,0,-1,0,1,1,0};

int getused(int num){
    int jishu = 0, i = 0;
    while(num != 0){
        used[i++] = num % 2;
        if(used[i]) jishu++;
        num /= 2;
    }
    return jishu;
}

void bfs(int x, int y, int rk){
    grid[x][y] = true;
    queue< pair<int, int> > q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        int 
    }
}

int main()
{
    while(~scanf("%d", &n)){
        memset(grid, 0, sizeof grid);
        scanf("%d", &k);
        for (int i = 0; i < k; i++){
            scanf("%d%d", &ren[i][0], &ren[i][1]);
        }
        for (int i = 0; i < k; i++){
            scanf("%d", &R[i]);
        }
        for (int i = 0; i < (1<<k); i++){
            memset(grid, 0, sizeof grid);
            int len = getused(i);
            for (int j = 0; j < k; j++){
                if(used[i]){
                    bfs(ren[i][0], ren[i][1], R[i]);
                }
            }
            bool check = true;
            for (int x = 0; x < n; x++){
                for (int y = 0; y < n; y++){
                    if(!grid[y][x]){
                        check = false;
                        break;
                    }
                }
                if(!check)
                    break;
            }
            if(!check){
                cnt[i] = -1;
            }
            else{
                cnt[i] = len;
            }
        }
        int res = 100000000;
        for (int i = 0; i < k; i++){
            if(cnt[i] == -1) continue;
            if(cnt[i] < res) 
                res = cnt;
        }
        printf("%d\n", res);
    }
    return 0;
}
