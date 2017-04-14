#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int so[(int) 1e7+5] ;
int main()
{
    for(int i = 1; i <= 200 ; i++) so[i*i*i] = i;
    for(int a = 0 ; a <= 200 ; a++)
    {
        int y = a*a*a;
        for(int i = 2 ; i <= 200 ; i++)
        {
            for(int j = i+1 ; j <= 200 ; j++)
            {
                int x = y-(i*i*i + j*j*j);
                if(x > 0 && so[x] > j)
                {
                    cout << "Cube = " << a << ", Triple = (" << i << "," << j << "," << so[x] << ")\n" ;
                }
            }
        }
    }
}
