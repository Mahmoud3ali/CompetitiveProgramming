#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n ;
    pair<int,int> arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        arr[i] = {x,i+1};
    }
    vector<pair<int,int> > ans;
    sort(arr,arr+n);
    vector<int> curr;
    bool solvable = 1;
    for(int i = 0 ; i < n; i++)
    {
        if(arr[i].first == 0)
        {
            curr.push_back(arr[i].second);
        }
        else
        {
            for(int j = 0 ; j < arr[i].first && solvable ; j++)
            {
                if(curr.size() == 0)
                {
                    solvable = 0 ;
                    break;
                }
                ans.push_back({arr[i].second , curr[curr.size()-1]});
                curr.pop_back();
            }
            curr.push_back(arr[i].second);
        }
    }
    if(!solvable) cout << "NO\n";
    else
    {
        cout << "YES\n";
        for(int i = 0 ; i < ans.size() ; i++)
        {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}
