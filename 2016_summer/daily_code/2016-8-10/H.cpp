#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int dp[110][110];

int main()
{
    int n;
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                scanf("%d", &dp[i][j]);
            }
        }
        for (int i = n-2; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                dp[i][j] = dp[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        printf("%d\n", dp[0][0]);
    }
    return 0;
}
