#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int n, m, a;
int num[500010];
bool visit[500010];
stack< pair<int, int> > stk;

int main()
{
    while(~scanf("%d%d", &n, &m)){
        memset(visit, 0, sizeof visit);
        while(stk.size()) stk.pop();
        int cur = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &a);
            while(!stk.empty() && pr.top().first < a){
                stk.pop();
                cur--;
            }
            if(!stk.empty() && pr.top().first == a){
                stk.pop();
            }
        }
    }
    return 0;
}
