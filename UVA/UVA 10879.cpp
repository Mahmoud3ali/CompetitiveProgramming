#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    int n , t = 1;
    cin >> n ;
    while(n--)
    {
        int x ;
        cin >> x;
        vector< pair<int,int> > vec;
        for(int i = 2 ; i*i <= x && vec.size() < 2; i++)
        {
            if(x%i == 0)
                vec.push_back({i,x/i});
        }
        cout << "Case #" << t++ << ": " << x << " = " << vec[0].first << " * " << vec[0].second << " = " << vec[1].first << " * " << vec[1].second << "\n" ;
    }
}
