#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double eps = 1e-12;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n ;
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1+=eps;
    y1+=eps;
    x2-=eps;
    y2-=eps;
    bool ans = 1;
    double strt = -1e9, endd = 1e9;
    while(n--)
    {
        double x, y, vx,vy;
        cin >> x >> y >> vx >> vy;
        double mini = -1, maxi = -1;
        double s = 0, e = 1e15;
        while(e-s >= eps)
        {
            double mid = e/2+s/2;
            double X = x + vx*mid;
            double Y = y + vy*mid;
            if(X-x1 >= eps && x2-X >= eps && Y-y1 >= eps && y2-Y >= eps) mini = mid, e = mid;
            else if(X-x1 < eps)
            {
                if(vx > 0)
                    s = mid;
                else
                    e = mid;
            }
            else if(x2-X < eps)
            {
                if(vx > 0)
                    e = mid;
                else
                    s = mid;
            }
            else if(Y-y1 < eps)
            {
                if(vy > 0)
                    s = mid;
                else
                    e = mid;
            }
            else
            {
                if(vy > 0)
                    e = mid;
                else
                    s = mid;
            }
        }
        s = 0, e = 1e15;
        while(e-s >= eps)
        {
            double mid = e/2+s/2;
            double X = x + vx*mid;
            double Y = y + vy*mid;
            if(X-x1 >= eps && x2-X >= eps && Y-y1 >= eps && y2-Y >= eps) maxi = mid, s = mid;
            else if(X-x1 < eps)
            {
                if(vx > 0)
                    s = mid;
                else
                    e = mid;
            }
            else if(x2-X < eps)
            {
                if(vx > 0)
                    e = mid;
                else
                    s = mid;
            }
            else if(Y-y1 < eps)
            {
                if(vy > 0)
                    s = mid;
                else
                    e = mid;
            }
            else
            {
                if(vy > 0)
                    e = mid;
                else
                    s = mid;
            }
        }
        //cout << mini << " " << maxi << endl;
        if(mini == -1 || maxi == -1) ans = 0;
        strt = max(strt,mini);
        endd = min(endd,maxi);
    }
    if(ans && endd-strt >= eps) cout << fixed << setprecision(8) << strt << endl;
    else cout << "-1\n";
}
