
#line 3 "EllysFractions.cpp"
#include <algorithm>
#include <stack>
#include <bitset>
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define sz(x) int((x).size())
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define square(a) (a)*(a)
#define mp(a,b) make_pair((a),(b))

const int oo = numeric_limits<int>::max();

class EllysFractions {
public:
    set<int> primes;
    long long dp[300];
    long long get(int N) {
        if (dp[N] != -1)
            return dp[N];

        primes.clear();
        for (int k = 2; k <= N; k++) {
            int N = k;
    	    for (int i = 2; N > 1; i++) {
                if (N % i == 0)
                    primes.insert(i);
                while (N % i == 0) N /= i;
            }
        }
        //cout << primes.size() << endl;
        return dp[N] = (((long long) 1) << (primes.size()-1));
	}

	long long getCount(int N) {
        for (int i = 0; i < 300; i++)
            dp[i] = -1;
        dp[0] = dp[1] = 0;
        long long counter = 0;
        for (int i = 1; i <= N; i++)
            counter += get(i);
        return counter;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing EllysFractions (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396913559;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysFractions _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				_expected = 0LL;
				_received = _obj.getCount(N); break;
			}
			case 1:
			{
				int N = 2;
				_expected = 1LL;
				_received = _obj.getCount(N); break;
			}
			case 2:
			{
				int N = 3;
				_expected = 3LL;
				_received = _obj.getCount(N); break;
			}
			case 3:
			{
				int N = 5;
				_expected = 9LL;
				_received = _obj.getCount(N); break;
			}
			case 4:
			{
				int N = 100;
				_expected = 177431885LL;
				_received = _obj.getCount(N); break;
			}
			/*case 5:
			{
				int N = ;
				_expected = LL;
				_received = _obj.getCount(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = LL;
				_received = _obj.getCount(N); break;
			}*/
			/*case 7:
			{
				int N = ;
				_expected = LL;
				_received = _obj.getCount(N); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
