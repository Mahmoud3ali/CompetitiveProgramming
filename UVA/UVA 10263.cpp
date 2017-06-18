#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dotprod(pair<double,double> v1, pair<double,double> v2)
{
    return v1.first*v2.first + v1.second*v2.second;
}
double crossprod(pair<double,double> v1, pair<double,double> v2)
{
    return v1.first*v2.second - v1.second*v2.first;
}
pair<double,double> get_vec(double x1, double y1, double x2, double y2)
{
    pair<double,double> ret;
    ret.first = x2-x1, ret.second = y2-y1;
    return ret;
}
double norm(pair<double,double> v)
{
    return sqrt(dotprod(v,v));
}
// (0)
pair<double,double> get_projection(double x, double y, double x1, double y1, double x2, double y2)
{
    pair<double,double> v = get_vec(x1,y1,x2,y2);
    pair<double,double> v2 = get_vec(x1,y1,x,y);
    double dot = dotprod( v2, v);
    double project = (double) dot/norm(v);
    double ansx = (double) project*v.first/norm(v)+x1, ansy = (double) project*v.second/norm(v)+y1;
    if(abs(ansx) < 1e-4) ansx = 0.0000;
    if(abs(ansy) < 1e-4) ansy = 0.0000;
    return { ansx, ansy };
}
int main()
{
    //freopen("out.txt" , "w" , stdout);
    double x, y;
    while(cin >> x >> y)
    {
        pair<double,double> tmp, ans;
        double best = 1e11;
        double n ;
        cin >> n ;
        double x1,y1,x2,y2;
        cin >> x1>> y1;
        while(n--)
        {
            cin >> x2>>y2;
            tmp = get_projection(x,y,x1,y1,x2,y2);
            if(tmp.first < min(x1,x2) || tmp.second < min(y2,y1) || tmp.second > max(y2,y1) || tmp.first > max(x2,x1))
            {
                double a = (x1-x)*(x1-x) + (y1-y)*(y1-y);
                double b = (x2-x)*(x2-x) + (y2-y)*(y2-y);
                if(a < b) tmp = {x1,y1};
                else tmp = {x2,y2};
            }
            if((tmp.first-x)*(tmp.first-x) + (tmp.second-y)*(tmp.second-y) < best)
            {
                best = (tmp.first-x)*(tmp.first-x) + (tmp.second-y)*(tmp.second-y);
                ans = tmp;
            }
            x1 = x2;
            y1 = y2;
        }
        cout << fixed << setprecision(4) << ans.first << "\n" << ans.second << "\n";
    }
}
