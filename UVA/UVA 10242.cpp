#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dist(double x1,double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main()
{
    //freopen("out.txt","w",stdout);
    double x,y,x1,x2,x3,y1,y2,y3,x4,y4;
    while(cin >> x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
    {
        x = 1e12 , y = 1e12;
        pair<double,double> a,b,c;
        if(x1 == x2 && y1 == y2)
        {
            b = {x1,y1};
            a = {x3,y3};
            c = {x4,y4};
        }
        else if(x1 == x3 && y1 == y3)
        {
            b = {x1,y1};
            a = {x2,y2};
            c = {x4,y4};
        }
        else if(x1 == x4 && y1 == y4)
        {
            b = {x1,y1};
            a = {x2,y2};
            c = {x3,y3};
        }
        else if(x2 == x3 && y2 == y3)
        {
            b = {x2,y2};
            a = {x1,y1};
            c = {x4,y4};
        }
        else if(x2 == x4 && y2 == y4)
        {
            b = {x2,y2};
            a = {x1,y1};
            c = {x3,y3};
        }
        else if(x3 == x4 && y3 == y4)
        {
            b = {x3,y3};
            a = {x1,y1};
            c = {x2,y2};
        }
        x = a.first+c.first-b.first , y = a.second+c.second-b.second;
        cout << fixed << setprecision(3) << x << " " << y << endl;
    }
}
