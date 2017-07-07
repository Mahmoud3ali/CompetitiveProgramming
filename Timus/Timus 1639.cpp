#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n , m;
    cin >> n >> m;
    n*=m;
    if(n%2 == 0) cout << "[:=[first]\n";
    else cout << "[second]=:]\n";
}
