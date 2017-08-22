#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
	double q , p;
	cin >> q >> p;
	q/=100;
	p/=100;
	// P(A) -> prop of gettin head on first
	// P(A) = 0.5*p + 0.5*q "P(getting first coin and getting head (OR) getting 2nd coin and getting head)
	// P(B) -> prop of gettin head on 2nd (no need)
	// P(A^B) -> prop of getting head on 1st & 2nd
	// when he catch some coin he throw it again he doesn't switch (1st mistake)
	// P(A^B) can't be calculated as P(A)*P(B) (2nd mistake)
	// P(A^B) = 0.5*p*p + 0.5*q*q
	// prop of getting 1st coin and get 2 heads in a row (OR) getting 2nd coin and get 2 heads in a row
	// P(B|A) -> prop of getting head on the 2nd given that u got head in the 1st
	// P(B|A) = P(A^B)/P(A)
	cout << fixed << setprecision(7) << (p*p + q*q)/(p+q) << endl;
}
