#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string nw;
long double solve(int idx)
{
    nw[idx] = ' ';
    long double ans ;
    long double p , a , b;
    string arr[4] ;
    int j = 0 ;
    for(int i = idx+1 ;; i++)
    {
        if(nw[i] == ')')
        {
            nw[i] = ' ';
            break;
        }
        else if(nw[i] == '(')
        {
            long double x = solve(i);
            if(j == 0) p = x;
            else if(j == 1) a = x;
            else b = x;
            arr[j] = "ahmed";
            j++;
        }
        else if(nw[i] == ' ' && arr[j].size() != 0)
        {
            j++;
        }
        else if(nw[i] != ' ') arr[j]+=nw[i];
        nw[i] = ' ' ;
    }
    stringstream ss ;
    if(arr[0] != "ahmed") {ss << arr[0] ; ss >> p ; ss.clear();}
    if(arr[1] != "ahmed") {ss << arr[1] ; ss >> a ; ss.clear();}
    if(arr[2] != "ahmed") {ss << arr[2] ; ss >> b ; ss.clear();}
    ans = (p*(a+b) + (1.0000000-p)*(a-b));
    return ans;
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        long double ans;
        if(s[0] == '(' && s[1] == ')') break;
        if(s[0] == '(')
        {
            nw = s;
            ans = solve(0);
        }
        else
        {
            stringstream ss;
            ss << s;
            ss >> ans;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
}
