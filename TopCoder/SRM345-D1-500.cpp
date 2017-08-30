#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class StoneGame {
public:
	int getScore(vector <int> treasure, vector <int> stones)
	{
		vector<int> ones;
		int f = 0 , elz = 0;
		for(int i = 0 ; i < stones.size() ; i++)
		{
			if(stones[i] == 1) ones.push_back(treasure[i]);
			else elz+=treasure[i] , f+= stones[i];
		}
		sort(ones.begin(),ones.end());
		int ans = 0 ;
		for(int i = ones.size()-1 ;i >= 0 ; i-=2) ans+=ones[i];
		if(ones.size()%2 == 0)
		{
			if(f%2) ans+= elz;
		}
		else
		{
			if(f%2 == 0) ans+=elz;
		}
		return ans;
	}
};
