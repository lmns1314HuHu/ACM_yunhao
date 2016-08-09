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
int A[100010];
int B[100010];

int stk[100010];
bool visit[100010];
bool mg[100010];
char st[10];
char ch;

int main()
{
    int clk = 1;
    while(~scanf("%d", &n) && n){
        int curstk = 0;
        int curA = 0;
        int curB = 0;
        memset(visit, 0, sizeof visit);
        memset(mg, 0, sizeof mg);
        printf("Case #%d:\n", clk++);
        for (int i = 0; i < n; i++){
            scanf("%s", st);

            if(strcmp(st, "push") == 0){
                getchar();
                scanf("%c %d", &ch, &num);

                if(ch == 'A'){
                    stk[curstk++] = num;
                    A[curA++] = curstk-1;
                }
                else if(ch == 'B'){
                    stk[curstk++] = num;
                    B[curB++] = curstk-1;
                }
            }


            else if(strcmp(st, "pop") == 0){
                getchar();
                scanf("%c", &ch);

                if(ch == 'A'){
                    visit[A[curA-1]] = true;
                    printf("%d\n", stk[A[curA-1]]);
                    if(mg[A[curA-1]]){
                        bool flag = false;
                        for (int j = 1; j <= A[curA-1]; j++){
                            if(!visit[A[curA-1]-j]){
                                mg[A[curA-1]-j] = true;
                                A[curA-1] = A[curA-1]-j;
                                flag = true;
                                break;
                            }
                        }
                        if(!flag){
                            curA--;
                        }
                    }
                    else{
                        curA--;
                    }
                }
                else if(ch == 'B'){
                    visit[B[curB-1]] = true;
                    printf("%d\n", stk[B[curB-1]]);
                    if(mg[B[curB-1]]){
                        bool flag = false;
                        for (int j = 1; j <= B[curB-1]; j++){
                            if(!visit[B[curB-1]-j]){
                                mg[B[curB-1]-j] = true;
                                B[curB-1] = B[curB-1]-j;
                                flag = true;
                                break;
                            }
                        }
                        if(!flag){
                            curB--;
                        }
                    }
                    else{
                        curB--;
                    }
                }
            }


            else if(strcmp(st, "merge") == 0){
                getchar();
                char ch2;
                scanf("%c %c", &ch, &ch2);

                if(ch == 'A'){
                    curA = 0;
                    curB = 0;
                    int idx = curstk - 1;
                    while(visit[idx])idx--;
                    A[curA++] = idx;
                    mg[idx] = true;
                }
                else{
                    curA = 0;
                    curB = 0;
                    int idx = curstk - 1;
                    while(visit[idx])idx--;
                    B[curB++] = idx;
                    mg[idx] = true;
                }
            }
            //cout << endl;
            //cout << 'A' << endl;
            //for (int j = 0; j < curA; j++){
                //cout << A[j] << " ";
            //}
            //cout << endl;
            //cout << "B" << endl;
            //for (int j = 0; j < curB; j++){
                //cout << B[j] << " ";
            //}
            //cout << endl;
            //cout << "stk    ";
            //for (int j = 0; j < curstk; j++){
                //cout << stk[j] << " ";
            //}
            //cout << endl;
            //cout << "mg     ";
            //for (int j = 0; j < curstk; j++){
                //cout << mg[j] << " ";
            //}
            //cout << endl;
            //cout << "visit  ";
            //for (int j = 0; j < curstk; j++){
                //cout << visit[j] << " ";
            //}
            //cout << endl;

        }
    }
    return 0;
}
