#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int n, m;
int dp[1000010];
int mx[1000010];
int num[1000010];

int main()
{
    while(~scanf("%d%d", &m, &n)){
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        for (int i = 1; i <= m; i++){
            for (int j = 0; j < n; j++){
                dp[j] = max(dp[j-1]+num[j], mx[j-1]+num[j]);
                if(dp[i] > mx[j]){
                    mx[j] = dp[i];
                }
            }
        }
    }
    return 0;
}
