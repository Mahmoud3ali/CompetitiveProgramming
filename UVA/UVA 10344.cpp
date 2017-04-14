#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
bool pr[(int) 2e7+5];
int main()
{
    int x[5] ;
    char p[] = {'+','-','*'};
    while(cin >> x[0])
    {
        for(int i = 1 ; i < 5 ; i++) cin >> x[i] ;
        if(x[0]+x[1]+x[2]+x[3]+x[4] == 0) break;
        int cnt = 0 ;
        sort(x,x+5);
        do
        {
            for(int i = 0 ; i < 3 ; i++)
            {
                for(int j = 0 ; j < 3 ; j++)
                {
                    for(int k = 0 ; k < 3 ; k++)
                    {
                        for(int a = 0 ; a < 3 ; a++)
                        {
                            int ans = x[0] ;
                            if(p[i] == '+') ans+= x[1];
                            else if(p[i] == '-') ans-= x[1];
                            else ans*=x[1];

                            if(p[j] == '+') ans+= x[2];
                            else if(p[j] == '-') ans-= x[2];
                            else ans*=x[2];

                            if(p[k] == '+') ans+= x[3];
                            else if(p[k] == '-') ans-= x[3];
                            else ans*=x[3];

                            if(p[a] == '+') ans+= x[4];
                            else if(p[a] == '-') ans-= x[4];
                            else ans*=x[4];
                            //cout << x[0] << p[i] << x[1]<< p[j] << x[2]<< p[k]<<x[3]<<p[a]<<x[4]<< " = " << ans << endl ;
                            if(ans == 23) cnt++;
                        }
                    }
                }
            }
        }
        while(next_permutation(x,x+5));
        if(cnt) cout << "Possible\n" ;
        else cout << "Impossible\n" ;
    }
}
