#include<bits/stdc++.h>

using namespace std;

class MergersDivTwo
{
public:
	int k ;
	double dp[55][55];
	vector<int> arr;
	double solve(int l , int r)
	{
		if(r-l+1 == k)
		{
			long double ans = 0;
			for (int i = l; i <= r; i++) ans += arr[i];
			return ans/k;
		}
		if(r-l+1 < k)
		{
			return -1e8;
		}
		if(dp[l][r] != -1e9) return dp[l][r];
		double ret = -1e8;
		double sum = 0 ;
		int sz = 0;
		for(int i = r ; i >= l ; i--)
		{
			sum+= arr[i];
			sz++;
			if(sz+1 >= k)
			ret = max(ret, (sum + solve(l, i - 1)) / (sz + 1));
		}
		sum/=(sz);
		ret = max(ret,sum);
		return dp[l][r] = ret;
	}
	double findMaximum(vector<int> r, int K)
	{
		for(int i = 0 ; i < 55 ; i++) for(int j = 0 ; j < 55 ; j++) dp[i][j] = -1e9;
		arr = r;
		sort(arr.begin(),arr.end());
		k = K;
		return solve(0,arr.size()-1);
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	MergersDivTwo *obj;
	double answer;
	obj = new MergersDivTwo();
	clock_t startTime = clock();
	answer = obj->findMaximum(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <int> p0;
	int p1;
	double p2;

	{
	// ----- test 0 -----
	int t0[] = {5,-7,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 1.5;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {5,-7,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 0.3333333333333333;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {1,2,2,3,-10,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 2.9166666666666665;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {-100,-100,-100,-100,-100,100};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = -66.66666666666667;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	int t0[] = {869,857,-938,-290,79,-901,32,-907,256,-167,510,-965,-826,808,890,-233,-881,255,-709,506,334,-184,726,-406,204,-912,325,-445,440,-368};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	p2 = 706.0369290573373;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
