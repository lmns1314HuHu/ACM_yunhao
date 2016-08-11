#include<cstdio>

char s[100005];

int main ()
{
    int T, n;
    scanf("%d" ,&T);
    while(T --)
    {
        scanf("%d", &n);
        scanf("%s", s);
        int a = 0, b = 0;
        for(int i = 0; i < n; i ++)
        {
            if(s[i] == '(')
                a ++;
            if(s[i] == ')')
                b ++;
        }
        if(a != b)
        {
            printf("No\n");
            continue;
        }

        int flag = 0, ans = 1;
        a = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                a ++;
            if(s[i] == ')')
            {
                if(a == 0)
                {
                    if(flag)
                    {
                        ans = 0;
                        break;
                    }
                    flag = 1;
                }
                else
                    a --;
            }
        }
        if(ans == 0 || (flag == 0 && n == 2))
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
