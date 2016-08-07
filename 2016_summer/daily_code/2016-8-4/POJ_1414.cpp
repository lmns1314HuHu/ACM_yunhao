/**==================================
 | Author: YunHao
 | OJ: POJ
 | Kind: 
 | Date: 2016/8/4
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int n, c;
int grid[110][110];
int setnum[110][110];
int cnt;
vector < pair<int, int> > v[70];
int dis=[][2] = {1,0, 0,1, -1,0, 0,-1, -1,-1, 1,1};

int main()
{
    while(~scanf("%d%d", &n, &c)){
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                scanf("%d", &grid[i][j]);
            }
        }
        for (int i = 0; i < 70; i++)
            v.clear();
        memset(setnum, 0, sizeof setnum);
        cnt = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                if(grid[i][j] == 0){
                    v[0].push_back(make_pair(i, j));
                    continue;
                }
                if(setnum[i][j] == 0){
                    setnum[i][j] = cnt++;
                    v[setnum[i][j]].push_back(make_pair(i, j));
                }
                if(i+1 < n && grid[i][j] == grid[i+1][j]){
                    setnum[i+1][j] = setnum[i][j];
                    v[setnum[i][j]].push_back(make_pair(i+1, j));
                }
                if(i+1 < n && grid[i][j] == grid[i+1][j+1]){
                    setnum[i+1][j+1] = setnum[i][j];
                    v[setnum[i][j]].push_back(make_pair(i+1, j+1));
                }
                if(j+1 <= i && grid[i][j] == grid[i][j+1]){
                    setnum[i][j+1] = setnum[i][j];
                    v[setnum[i][j]].push_back(make_pair(i, j+1));
                }
            }
        }
        int mx = 0;
        for(int i = 0; i < v[0].size(); i++){
            int x0 = v[0][i].first, y0 = v[0][i].second;
            grid[x0][y0] = c;
            for (int j = 0; j < 6; j++){
                int x1 = x0 + dis[j][0], y1 = y0 + dis[j][1];

                if(x1 >= 0 && x1 < n && y1 >= 0 && y1 <= x1){
                    int jihe = setnum[x1][y1];
                    bool flag = false;

                    for (int k = 0; k < v[jihe].size(); k++){
                        int jihex = v[jihe][k].first, jihey = v[jihe][k].second;
                        for (int l = 0; l < 6; l++){
                            int jihex1 = jihex + dis[l][0], jihey1 = jihey + dis[l][1];
                            if(jihex1 >= 0 && jihex1 < n && jihey1 >= 0 && jihey1 <= jihex1){
                                if(grid[jihex1][jihey1] == 0){
                                    flag = true;
                                    break;
                                }
                            }
                        }
                        if(flag)
                            break;
                    }
                    if(!flag){
                        mx += v[jihe].size();
                    }
                }
            }
            grid[x0][y0] = 0;
        }
    }
    return 0;
}
