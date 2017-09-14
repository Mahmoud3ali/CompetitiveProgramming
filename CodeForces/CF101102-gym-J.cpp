#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[(1<<9)][(int) 1e5+5];
template <class T>
inline void cinn(T &ret)
{
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    ret = c - '0';
    while(c = getchar(), c>='0' && c<='9')
        ret = ret * 10 + (c - '0');
}

inline void coutt(int a)
{
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
       coutt(a / 10);
    }
    putchar(a % 10 + '0');
}
int main()
{
	int t;
	cinn(t);
	while(t--)
	{
		int n,q;
		cinn(n);
		cinn(q);
		for(int i = 1 ; i <= n ; i++)
		{
			int x;
			cinn(x);
			int v = 0;
			for(int j = 1 ; j <= 10 ; j++)
				if(x%j == 0)
					v |= (1<<(j-2));
			for(int j = 0 ; j < (1<<9) ; j++)
			{
				bool f = (j&v) ;
				ans[j][i] = ans[j][i-1]+f;
			}
		}
		while(q--)
		{
			int x , y , z;
			cinn(x);
			cinn(y);
			cinn(z);
			if(z&1)
				coutt(y-x+1);
			else
				coutt(ans[z>>1][y]-ans[z>>1][x-1]);
			puts("");
		}
	}
}
