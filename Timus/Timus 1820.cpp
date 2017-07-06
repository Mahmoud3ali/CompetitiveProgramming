#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n , k;
    while(cin >> n >> k)
    {
        double x = n*2;
        cout << max(2,(int)ceil(x/k)) << endl;
    }
}
