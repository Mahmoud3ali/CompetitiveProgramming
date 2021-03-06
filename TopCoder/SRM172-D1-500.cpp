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
#include <cstring>

using namespace std;

class Fifteen
{
public:
	int dp[(1<<11)][(1<<11)][2];
	bool won(int a)
	{
		vector<int> v;
		for(int i = 1 ; i < 10 ; i++)
			if( (a&(1<<i)) ) v.push_back(i);
		for(int i = 0 ; i < v.size() ; i++)
			for(int j = 0 ; j < v.size() ; j++)
				for(int z = 0 ; z < v.size() ; z++) if(i != j && j != z && i != z && v[i]+v[j]+v[z] == 15) return 1;
		return 0;
	}
	int solve(int a, int b, bool player)
	{
		int nw = 0;
		bool vis[10] = {0};
		for(int i = 1 ; i < 10 ; i++)
			if( (a&(1<<i)) || (b&(1<<i)) ) nw++ , vis[i] = 1;
		if(nw == 9) return 2;
		if(dp[a][b][player] != -1) return dp[a][b][player];
		int ret = 0;
		for(int i = 1 ; i < 10 && !ret ; i++)
		{
			if(!vis[i])
			{
				if(player == 0)
				{
					if(won(a|(1<<i)))
						ret = 1;
					else
					{
						int tmp = solve(a | (1 << i), b, !player);
						if (tmp == 2) tmp = 1;
						ret |= !tmp;
					}
				}
				else
				{
					if (won(b | (1 << i)))
						ret = 1;
					else
					{
						int tmp = solve(a , b | (1 << i), !player);
						if (tmp == 2)
							tmp = 0;
						ret |= !tmp;
					}
				}
			}
		}
		return dp[a][b][player] = ret;
	}
	string outcome(vector<int> moves)
	{
		memset(dp,-1,sizeof dp);
		int a = 0, b = 0;
		bool player = 1;
		for (int i = 0; i < moves.size(); i++)
		{
			if (!player)
				a |= (1 << moves[i]);
			else
				b |= (1 << moves[i]);
			player = !player;
		}
		int ans = -1;
		for(int i = 1 ; i < 10 ; i++)
		{
			if( (a&(1<<i)) == 0  && (b&(1<<i)) == 0)
			{
				if(won(a|(1<<i)) || solve(a|(1<<i),b,1) == 0)
				{
					ans = i;
					break;
				}
			}
		}
		if(ans == -1) return "LOSE";
		else
		{
			string ss = "WIN ";
			ss+= (ans+'0');
			return ss;
		}
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector<int> p0, bool hasAnswer, string p1)
{
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i)
	{
		if (i > 0)
		{
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	Fifteen *obj;
	string answer;
	obj = new Fifteen();
	clock_t startTime = clock();
	answer = obj->outcome(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " seconds" << endl;
	if (hasAnswer)
	{
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer)
	{
		res = answer == p1;
	}
	if (!res)
	{
		cout << "DOESN'T MATCH!!!!" << endl;
	}
	else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
	{
		cout << "FAIL the timeout" << endl;
		res = false;
	}
	else if (hasAnswer)
	{
		cout << "Match :-)" << endl;
	}
	else
	{
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main()
{
	bool all_right;
	all_right = true;

	vector<int> p0;
	string p1;

	{
		// ----- test 0 -----
		int t0[] =
		{ 5, 9, 3 , 2 , 1};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "WIN 4";
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] =
		{ 4, 8, 6, 5, 2 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "LOSE";
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] =
		{ 2, 4, 7, 6, 9, 8, 5 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "WIN 1";
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] =
		{ 9, 2, 1, 6, 3, 4, 8 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "WIN 5";
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		int t0[] =
		{ 1 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "LOSE";
		all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		int t0[] =
		{ 6, 3, 7, 8, 1 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "WIN 2";
		all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
		// ------------------
	}

	if (all_right)
	{
		cout << "You're a stud (at least on the example cases)!" << endl;
	}
	else
	{
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
