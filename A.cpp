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
#include <cmath>

using namespace std;
typedef long long ll;
int n;
char bus[1010][10];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", bus[i]);
    }
    bool flag = false;
    for (int i = 0; i < n; i++){
        for (int j = 1; j < 5; j++){
            if(bus[i][j-1] == bus[i][j] && bus[i][j] == 'O'){
                bus[i][j-1] = '+';
                bus[i][j] = '+';
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag){
        printf("YES\n");
        for (int i = 0; i < n; i++){
            printf("%s\n", bus[i]);
        }
    }
    else{
        printf("NO\n");
    }
    return 0;
}
