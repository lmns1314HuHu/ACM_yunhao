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

struct node {
    int a, b;
}no[1010];

bool cmp(node no1, node no2){
    if(no1.b != no2.b){
        return no1.b > no2.b;
    }
    return no1.a > no2.a;
}

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d%d", &no[i].a, &no[i].b);
    }
    sort(no, no+n, cmp);
    int cnt = 1;
    ll sc = 0;
    for (int i = 0; i < n; i++){
        sc += no[i].a;
        cnt--;
        cnt += no[i].b;
        if(cnt == 0){
            break;
        }
    }
    printf("%lld\n", sc);
    return 0;
}
