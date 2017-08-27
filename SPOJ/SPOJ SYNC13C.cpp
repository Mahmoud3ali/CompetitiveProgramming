#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a , b;
		cin >> a >> b;
		if(a%2 == 0 || b%2 == 0) cout << "Suresh\n";
		else cout << "Ramesh\n";
	}
}
