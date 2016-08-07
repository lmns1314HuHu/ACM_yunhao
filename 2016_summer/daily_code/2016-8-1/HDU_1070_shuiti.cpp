/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: 水题
 | Date: 2016/8/1
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int t, n;
int y, v;
string s;
int curyuan, curday, curv;
string curmilk;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        curmilk == "";
        for (int i = 0; i < n; i++){
            cin >> s >> y >> v;
            int day = v / 200;
            if(day <= 0) continue;
            if(day >= 6) day = 5;
            if(curmilk == ""){
                curmilk = s;
                curday = day;
                curyuan = y;
                curv = v;
            }
            else{
                if(curyuan * day > curday * y){
                    curyuan = y;
                    curday = day;
                    curmilk = s;
                    curv = v;
                }
                else if(curyuan * day == curday * day && curday < day){
                    curyuan = y;
                    curday = day;
                    curmilk = s;
                    curv = v;
                }
                else if(curyuan * day == curday * day && curday == day && curv < v){
                    curyuan = y;
                    curday = day;
                    curmilk = s;
                    curv = v;
                }
            }
        }
        cout << curmilk << endl;
    }
    return 0;
}
