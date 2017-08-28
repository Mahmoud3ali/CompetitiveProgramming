#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool make(int addo , int addz , int z , int o , int ex)
{
	if(addz == 0)
	{
		if(o+ex >= addo+z) return 1;
		else return 0;
	}
	else
	{
		if(z+ex >= addz+o) return 1;
		else return 0;
	}
}
int main()
{
	string s;
	cin >> s;
	int zero = 0 , one = 0 , estfham = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == '0') zero++;
		else if(s[i] == '1') one++;
		else estfham++;
	}
	// make n+3 , n
	bool zz = 0 , zo = 0 , oz = 0 , oo = 0;
	if(make(2,0,zero,one,estfham)) oo = 1;
	if(make(0,1,zero,one,estfham)) zz = 1;
	// case (n,n)
	if(s.size()%2 == 0 && zero <= s.size()/2 && one <= s.size()/2)
	{
		int f = s.size()/2;
		if(f == zero)
		{
			if(s.back() == '0') oz = 1;
			else zo = 1;
		}
		else if(f == one)
		{
			if(s.back() == '1') zo = 1;
			else oz = 1;
		}
		else
		{
			if (s.back() == '0') oz = 1;
			if (s.back() == '1') zo = 1;
			if (s.back() == '?') oz = 1, zo = 1;
		}
	}
	// case (n+1,n)
	int f = s.size()/2;
	if(s.size()%2 && zero <= f && one <= f+1)
	{
		if (f == zero)
		{
			if (s.back() == '0') oz = 1;
			else zo = 1;
		}
		else if (f+1 == one)
		{
			if (s.back() == '1') zo = 1;
			else oz = 1;
		}
		else
		{
			if(s.back() == '0') oz = 1;
			if(s.back() == '1') zo = 1;
			if(s.back() == '?') oz = 1 , zo = 1;
		}
	}
	vector<string> arr;
	if(oo) arr.push_back("11");
	if(oz) arr.push_back("10");
	if(zo) arr.push_back("01");
	if(zz) arr.push_back("00");
	sort(arr.begin(),arr.end());
	for(int i = 0 ; i < arr.size() ; i++) cout << arr[i] << "\n";
}
