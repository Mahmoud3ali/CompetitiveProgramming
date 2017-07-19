#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int dp[502][(int) 1e4];
vector<int> a, b;
int main()
{
    bool good = 0;
    pair<int,pair<int,int> > ans;
    ans = {1e9,{1e9,1e9}};
    int n;
    cin >> n;
    if(n > 2 || n == 0)
        cout << "-1\n";
    else if(n == 1)
        cout << "1 2 3\n";
    else
        cout << "3 4 5\n";
}
