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

int t, n;
int num;

int check(int num){
    int cnt = 0;
    while(num > 0){
        if(num % 2 == 1)
            cnt++;
        num /= 2;
    }
    return cnt;
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num);
            int tmp = check(num);
            if()
            res ^= num;
        }
        if(res == 0){
            printf("Second player wins.\n");
        }
        else
            printf("First player wins.\n");
    }
    return 0;
}
