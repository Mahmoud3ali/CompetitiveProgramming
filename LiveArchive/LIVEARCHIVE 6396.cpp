/*
 * f(k) = size()!/ (freq(p1)! * freq(p2) * freq(p3) *....) (multinomial thereom)
 * first thing to notice that if you're going to use 3 different frequencies
 * you need to assign the largest frequency to the first prime , then 2nd then 3rd , and so on
 * so you need to find only vectors of the form where v[i] >= v[i+1] for any i
 * also these vectors must satisfy the coniditon that f( vector<> ) <= (1<<63-1)
 * this can be done recursively using long double to avoid over flow problems and some prime factorization
 * as not to calculate factorials of numbers >= 22
 * then for each of these vectors find f( vector[i] )
 * and minimize f(ans) through all the vectors which have the same f()
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,73, 79, 83, 89, 97 };
long double MAXI = (1LL << 62);
vector<int> curr;
vector<vector<int> > st;
void go(int last, int pow, long double now)
{
	if (curr.size()) st.push_back(curr);
	long double f = now;
	for (int i = 1; i <= pow; i++)
	{
		f *= primes[last + 1];
		if (f >= MAXI)
			break;
		curr.push_back(last + 1);
		go(last + 1, i, f);
	}
	while (curr.size() && curr.back() == last + 1)
		curr.pop_back();
}
vector<int> fact(int s)
{
	vector<int> ans;
	for (int i = 0; i < 25; i++)
	{
		while (s % primes[i] == 0)
			ans.push_back(i), s /= primes[i];
	}
	return ans;
}
long double beb(vector<int> &up, vector<int> &down)
{
	long double ans = 1;
	for (int i = 0; i < 100; i++)
	{
		int diff = up[i] - down[i];
		for (int j = 0; j < diff; j++)
		{
			ans *= primes[i];
		}
	}
	return ans;
}
ll solve(ll ans1 , vector<int> b)
{
	ll ans2 = 1;
	for (auto i : b)
		ans2 *= primes[i];
	if (ans1 < ans2)
		return ans1;
	else
		return ans2;
}
int main()
{
	MAXI *= 2;
	MAXI--;
	go(-1, 63, 1);
	map<ll, ll> mp;
	for (auto i : st)
	{
		vector<int> up, down;
		up.resize(100);
		down.resize(100);
		for(int j = 2 ; j <= i.size() ; j++)
		{
			vector<int> ans = fact(j);
			for(int k = 0 ; k < ans.size() ; k++)
				up[ans[k]]++;
		}
		int arr[100] = {};
		for(auto k : i) arr[k]++;
		for(int k = 0 ; k < 100 ; k++)
		{
			for(int j = 2 ; j <= arr[k] ; j++)
			{
				vector<int> ans = fact(j);
				for (int f = 0; f < ans.size(); f++)
					down[ans[f]]++;
			}
		}
		ll ans = beb(up,down);
		if(mp.find(ans) != mp.end()) mp[ans] = solve(mp[ans],i);
		else mp[ans] = solve(MAXI,i);
	}
	ll n;
	while (cin >> n)
	{
		cout << n << " " << mp[n] << "\n";
	}
}
