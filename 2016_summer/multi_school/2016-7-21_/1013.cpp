#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int _cnt[2010][2010];
bool _mat[2010][2010];
int t, n, m, k;
int x, y;
int p[5];
vector<int> V[2010];

int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);

		memset(_mat, 0, sizeof(_mat));
		memset(_cnt, 0, sizeof(_cnt));
		for (int i = 0; i <= n; i++) V[i].clear();

		for (int i = 0; i < k; i++){
			scanf("%d%d", &x, &y);
			_mat[x][y] = true;
			V[x].push_back(y);
		}
		for (int i = 0; i < 4; i++){
			scanf("%d", &p[i]);
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				_cnt[i][j] = _cnt[i-1][j] + _cnt[i][j-1] - _cnt[i-1][j-1];
				if(_mat[i][j] == true)
					_cnt[i][j]++;
			}
		}
		
		for (int i = )
	}
	return 0;
}
