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

int n, num;
int mi, mx;

int main()
{
    scanf("%d", &n);
    mi = 100000;
    mx = -100000;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        if(i == 0){
           mx = num;
           mi = num;
        }
        else{
            if(num < mi){
                cnt ++;
                mi = num;
            }
            if(num > mx){
                cnt ++;
                mx = num;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
