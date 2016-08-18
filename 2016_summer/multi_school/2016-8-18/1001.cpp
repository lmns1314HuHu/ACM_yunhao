#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define maxn 100010
int t, n, m;
int num[maxn];
int l1, r1, l2, r2;
int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        for (int i = 0; i < m; i++){
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            l1--, r1--,l2--,r2--;
            if(l1 > l2){
                swap(l1, l2);
                swap(r1, r2);
            }
            int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1, len = len1 + len2;
            if(l2 > r1){
                double res = 0;
                if(len % 2 == 0){
                    int zhong = len / 2, zhonghou = zhong+1;
                    if(zhonghou <= len1){
                        res = (double)(num[l1-1 + zhong] + num[l1-1 + zhonghou]) / 2.0;
                    }
                    else if(zhong > len1){
                        zhong -= len1;
                        res = (double)(num[l2-1 + zhong] + num[l2-1 + zhong+1]) / 2.0;
                    }
                    else{
                        res  = (double)(num[r1] + num[l2]) / 2.0;
                    }
                }
                else{
                    int zhong = len/2+1;
                    if(zhong <= len1){
                        res = (double)(num[l1-1+zhong]);
                    }
                    else{
                        zhong -= len1;
                        res = (double)(num[l2-1+zhong]);
                    }
                }
                printf("%.1lf\n", res);
            }
            else if(l2 <= r1){
                double res = 0;
                if(len % 2 == 0){
                    int zhong = len / 2, zhonghou = zhong+1;
                    bool flag = false;
                    if(l2 == l1) flag = true;
                    if(l2 - l1 + 1 >= zhong && !flag){
                        res = (double)(num[l1-1 + zhong] + num[l1-1 + zhonghou]) / 2.0;
                    }
                    else if((min(r1, r2) - l2 + 1)*2 + l2-1-l1+1 > zhong){
                        zhong -= (l2-1 - l1 + 1);
                        zhonghou -= (l2-1 - l1 + 1);
                        if(zhong % 2 == 1) res = (double)(num[l2-1 + zhong/2 + 1]);
                        else res = (double)(num[l2-1 + zhong/2] + num[l2-1 + zhong/2 + 1]) / 2.0;
                    }
                    else{
                        zhong -= (l2-1 - l1 + 1);
                        zhonghou -= (l2-1 - l1 + 1);
                        zhong -= (min(r1, r2) - l2 + 1)*2;
                        zhonghou -= (min(r1, r2) - l2 + 1) * 2;
                        zhong++, zhonghou++;
                        res = (double)(num[min(r1, r2)-1 + zhong] + num[min(r1, r2)-1 + zhonghou]) / 2.0;
                    }
                }
                else{
                    int zhong = len / 2 + 1;
                    if(l2 - l1 + 1 >= zhong)
                        res = (double)(num[l1-1 + zhong]);
                    else if((min(r1, r2) - l2 + 1)*2 + l2-1- l1 + 1 >= zhong){
                        zhong -= (l2-1 - l1 + 1);
                        res = (double)(num[l2-1 + ((zhong + 1)/2)]);
                    }
                    else{
                        zhong -= (l2-1 - l1 + 1);
                        zhong -= (min(r1, r2) - l2 + 1) * 2;
                        zhong++;
                        res = (double)(num[min(r1, r2)-1 + zhong]);
                    }
                }
                printf("%.1lf\n", res);
            }
        }
    }
    return 0;
}
