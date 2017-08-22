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

class YetAnotherORProblem
{
public:
	vector<long long> a;
	int mod = 1000000009;
	int dp[62][(1 << 11)], n;
	int solve(int idx, int mask)
	{
//		cerr << idx << " " << mask << endl;
		if (idx == 0)
			return 1;
		if (dp[idx][mask] != -1)
			return dp[idx][mask];
		int ret = 0;
		int mask_0 = mask, p = idx - 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] & (1LL << p))
			{
				mask_0 |= (1LL << i);
			}
		}
		ret += solve(idx - 1, mask_0);
		for (int i = 0; i < n; i++)
		{
			int next = mask_0;
			if (mask & (1LL << i)) // 3ndo excess mn 2bl kda asln
			{
				// el mask msh hyt8yr l2n mdam fi excess yb2a hyfdl fi 2odam
				ret+= solve(idx-1,next);
				ret%=mod;
			}
			else
			{
				if((a[i] &(1LL << p)))
				{
					next -= (1LL << i);
					ret+= solve(idx-1,next);
					ret%=mod;
				}
			}
		}
		return dp[idx][mask] = ret;
	}
	int countSequences(vector<long long> R)
	{
		a = R;
		n = a.size();
		for (int i = 0; i < 62; i++)
			for (int j = 0; j < (1 << 11); j++)
				dp[i][j] = -1;
		return solve(61, 0);
	}
};
bool KawigiEdit_RunTest(int testNum, vector<long long> p0, bool hasAnswer,
		int p1)
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
	YetAnotherORProblem *obj;
	int answer;
	obj = new YetAnotherORProblem();
	clock_t startTime = clock();
	answer = obj->countSequences(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " seconds" << endl;
	if (hasAnswer)
	{
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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

	vector<long long> p0;
	int p1;

	{
		// ----- test 0 -----
		long long t0[] =
		{ 3ll, 5ll };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 15;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		long long t0[] =
		{ 3ll, 3ll, 3ll };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 16;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		long long t0[] =
		{ 1ll, 128ll };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 194;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		long long t0[] =
		{ 26ll, 74ll, 25ll, 30ll };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 8409;
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		long long t0[] =
		{ 1000000000ll, 1000000000ll };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 420352509;
		all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
