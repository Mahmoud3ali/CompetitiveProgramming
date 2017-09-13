#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin >> n ;
	vector<int> v;
	for(int i = 0 ; i < n ; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	if(n == 1) cout << v[0] << endl;
	else if(n == 2) cout << max(v[0],v[1]);
	else
	{
		ll ans = 0 ;
		while(v.size() >= 4)
		{
			ans+= min(2*v[1]+v[0]+v.back() , 2*v[0]+v[v.size()-1]+v[v.size()-2]);
			v.pop_back();
			v.pop_back();
		}
		if(v.size() == 3) ans+= v[0]+v[1]+v[2];
		else if(v.size() == 2) ans+= max(v[0],v[1]);
		cout << ans << endl;
	}
//	else if(n == 3) cout << v[0]+v[1]+v[2] << endl;
//	else if(n == 4) cout << min(v[0]+3*v[1]+v[3] , 2*v[0]+v[1]+v[2]+v[3]) << endl;
}
