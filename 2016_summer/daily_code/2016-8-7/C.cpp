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

char yuan[100010];
int n;
char pr[15][5];

int main()
{
    scanf("%s", yuan);
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", pr[i]);
    }
    int len = strlen(yuan);
    int cnt = 0;
    ll res = 0;
    for (int i = 0; i < len - 1; i++){
        bool flag = false;
        for (int j = 0; j < n; j++){
            if((yuan[i] == pr[j][0] && yuan[i+1] == pr[j][1]) ||
                (yuan[i] == pr[j][1] && yuan[i+1] == pr[j][0])){
                cnt++;
                flag = true;
                break;
            }
        }
        cout << cnt << endl;
        if(!flag){
            if(cnt != 0){
                int hou = 0, qian = 0;
                for (int j = i+1; j < n-1; j++){
                    if(yuan[j] == yuan[i]) hou++;
                }
                for (int j = i; )
                if(yuan[i] == yuan[i+1]){
                    if(i-cnt-1 >= 0 && yuan[i-cnt] == yuan[i-cnt-1]){
                        res += ( ceil(cnt/2.0) +1);
                    }
                    res += ceil(cnt/2.0);
                }
                else{
                    res += ceil(cnt/2.0);
                }
            }
            cnt = 0;
            cout << "res = " << res << endl;
        }
    }
    res += ceil(cnt/2.0);
    printf("%lld\n", res);
    return 0;
}
