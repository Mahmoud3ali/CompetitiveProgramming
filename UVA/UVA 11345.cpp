#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t , f = 1;
    cin >> t;
    while(t--)
    {
        int mx= -1e9 ,my = -1e9 , xx = 1e9 , xy = 1e9;
        int n;
        cin >> n;
        for(int i = 0 ;i < n ; i++)
        {
            int x1 ,y1,x2,y2;
            cin >> x1>>y1>>x2>>y2;
            mx = max(mx,x1);
            my = max(my,y1);
            xx = min(xx,x2);
            xy = min(xy,y2);
        }
        cout << "Case " << f++ << ": " ;
        if(mx <= xx && my <= xy)
        {
            cout << (xy-my)*(xx-mx) << endl;
        }
        else cout << "0\n";
    }
}
