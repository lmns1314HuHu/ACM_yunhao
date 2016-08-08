#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t;
int w, h, n;
int a, b;
int grid1[110][110];
int grid2[110][110];
int tu1[10010];
int tu2[10010];

bool inside(int x, int y){
	return x >= 0 && y >= 0 && x < w && y < h;
}

int calc_f(int u, int v, int grid[][110]){
	int cnt = 0;
	bool flagup = false, flagdown = false;
	bool flagleft = false, flagright = false;
	int step = 1;
	while(!flagup || !flagdown || !flagleft || !flagright){
		if(!flagup){
			if(inside(u-step, v) && grid[u-step][v]) cnt++;
			else flagup = true;
		}
		if(!flagdown){
			if(inside(u+step, v) && grid[u+step][v]) cnt++;
			else flagdown = true;
		}
		if(!flagleft){
			if(inside(u, v-step) && grid[u][v-step]) cnt++;
			else flagleft = true;
		}
		if(!flagright){
			if(inside(u, v+step) && grid[u][v+step]) cnt++;
			else flagright = true;
		}
		step++;
	}
	return cnt;
}

int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &w, &h, &n);
		memset(grid1, 0, sizeof grid1);
		memset(grid2, 0, sizeof grid2);
		memset(tu1, 0, sizeof tu1);
		memset(tu2, 0, sizeof tu2);
		for (int i = 0; i < n; i++){
			scanf("%d%d", &a, &b);
			grid1[a][b] = 1;
		}
		for (int i = 0; i < n; i++){
			scanf("%d%d", &a, &b);
			grid2[a][b] = 1;
		}
		int cur1 = 0, cur2 = 0;
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++){
				if(grid1[i][j] == 0) continue;
				tu1[cur1++] = calc_f(i, j, grid1);
			}
		}
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++){
				if(grid2[i][j] == 0) continue;
				tu2[cur2++] = calc_f(i, j, grid2);
			}
		}
		sort(tu1, tu1+cur1);
		sort(tu2, tu2+cur2);
		bool res = false;
		for (int i = 0; i < n; i++){
			if(tu1[i] != tu2[i]){
				res = true;
				break;
			}
		}
		if(res) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}