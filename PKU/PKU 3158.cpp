#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int main()
{
    string a, b;
    cin >> a >> b;
    while(a.size() < 300) a+='0';
    while(b.size() < 300) b+='0';
    int ans = 1e9;
    for(int k = 0 ; k < 150 ; k++)
    {
        for(int i = 0 , j = k;; i++, j++)
        {
            if(a[i] == b[j] && a[i] == '2') break;
            if(a[i] == '0' && b[j] == '0')
            {
                ans = min(ans,max(j,i));
                break;
            }
        }
        for(int i = k , j = 0;; i++, j++)
        {
            if(a[i] == b[j] && a[i] == '2') break;
            if(a[i] == '0' && b[j] == '0')
            {
                ans = min(ans,max(j,i));
                break;
            }
        }
    }
    cout << ans << endl;
}
