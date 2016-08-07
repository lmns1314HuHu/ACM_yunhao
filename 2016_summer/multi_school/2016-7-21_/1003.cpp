#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int t, n, m, x, y;
vector<int> V[10010];
bool visit[10010];
int cnt;
void dfs(int u){
	for(int i = 0; i < V[u].size(); i++){
		int v = V[u][i];
		if(visit[v]) continue;
		visit[v] = true;
		cnt++;
		dfs(v);
	}
}

int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i <= n; i++) V[i].clear();

		for (int i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			V[x].push_back(y);
			V[y].push_back(x);
		}
		cnt = 0;
	}
	return 0;
}
