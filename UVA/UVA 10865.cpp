#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int tann(pair<int,int> in , pair<int,int> c)
{
    int x = in.first-c.first;
    int y = in.second-c.second;
    if(x == 0 || y == 0) return 0;
    if(x<0&&y<0) return 1;
    if(x>0&& y>0) return 1;
    return -1;
}
int main()
{
    int n;
    while(cin >> n && n)
    {
        vector<pair<int,int> > v;
        for(int i = 0 ; i < n ; i++)
        {
            int x , y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        pair<int,int> center = v[v.size()/2];
        int arr[5] = {};
        for(int i = 0 ; i < v.size() ; i++)
        {
            arr[1+tann(v[i],center)]++;
        }
        cout << arr[2] << " " << arr[0] << endl;
    }
}
