/**==================================
 | Author: YunHao
 | OJ: 
 | Kind: 
 | Date: 
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

int grid[100][100];
bool visit[100][100];
#define mod 110119
int n, m, r;

ll zuhe(ll n, ll m){
    if(m > n-m) m = n-m;
    ll res = 1;
    for (ll i = 0; i < m; i++){
        res = ((res * ((n-i) % mod) % mod) / ((i+1) % mod)) % mod;
    }
    return res;
}

int main()
{
    memset(grid, 0, sizeof grid);
    memset(visit, false, sizeof visit);
    queue< pair<int, int> > q;
    q.push(make_pair(0, 0));
    visit[0][0] = true;
    grid[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        int xnew = x + 1, ynew = y + 2;
        if(xnew >= 0 && ynew >= 0 && xnew < 100 && ynew < 100){
            grid[xnew][ynew] += grid[x][y];
            if(!visit[xnew][ynew]){
                visit[xnew][ynew] = true;
                q.push(make_pair(xnew, ynew));
            }
        }
        xnew = x + 2, ynew = y + 1;
        if(xnew >= 0 && ynew >= 0 && xnew < 100 && ynew < 100){
            grid[xnew][ynew] += grid[x][y];
            if(!visit[xnew][ynew]){
                visit[xnew][ynew] = true;
                q.push(make_pair(xnew, ynew));
            }
        }
    }
    //for (int i = 0; i < 20; i++){
        //printf("%3d ", i);
        //for (int j = 0; j < 20; j++){
            //if(visit[i][j]){
                //printf("%d ", grid[i][j]);
            //}
            //else
                //printf("- ");
        //}
        //cout << endl;
    //}
    for (int i = 1; i < 100; i++){
        for (int j = 0; j <= i; j++){
            cout << zuhe(i, j) << " ";
        }
        cout << endl;
    }
    while(~scanf("%d%d%d", &n, &m, &r)){
        int shou = (n + m) / 3 + 1;
        int nu = n - shou + 1;
        int res = zuhe(shou, nu);
    }
    return 0;
}
