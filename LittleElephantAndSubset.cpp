
#line 3 "LittleElephantAndSubset.cpp"
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

#define MOD (1000000007LL)
class LittleElephantAndSubset {
public:
    long long maskCount[1 << 10];
    int n;
    void calc(int curr, long long state) {
        if (curr > n)
            return;
        maskCount[state]++;
        maskCount[state] %= MOD;
        for (int i = 0; i < 10; i++) {
            if ((curr == 0 && i == 0) || state & (1 << i))
                continue;
            calc(10*curr+i, state | (1 << i));
        }
    }
	int getNumber(int N) {
        long long d[1 << 10], res;
        REP(i, 1 << 10) {
            d[i] = 0;
            maskCount[i] = 0;
        }
        d[0] = 1;

        n = N;
        calc(0,0);


        /*for (int i = 0; i < 100; i++)
            if (maskCount[i] > 0)
                cout << i << ": " << maskCount[i] << endl;
        cout << "---" << endl;*/

        for (int state = 1; state < 1 << 10; state++) {
        
            for (int i = 0; i < 1 << 10; i++) {
                if (state & i)
                    continue;
                d[state | i] += ((maskCount[state]*d[i] % MOD));
                /*if (d[state|i]>0)
                    cout << (state|i) << ": " << d[state|i] << endl;*/
                d[state | i] %= MOD;
            }

        }

        res = 0;
        for (int i = 1; i < 1 << 10; i++) {
            res += d[i];
            res %= MOD;
        }
        return res % MOD;
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
		cout << "Testing LittleElephantAndSubset (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397167360;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LittleElephantAndSubset _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				_expected = 7;
				_received = _obj.getNumber(N); break;
			}
			case 1:
			{
				int N = 10;
				_expected = 767;
				_received = _obj.getNumber(N); break;
			}
			case 2:
			{
				int N = 47;
				_expected = 25775;
				_received = _obj.getNumber(N); break;
			}
			case 3:
			{
				int N = 4777447;
				_expected = 66437071;
				_received = _obj.getNumber(N); break;
			}
			case 4:
			{
				int N = 474747474;
				_expected = 84676111;
				_received = _obj.getNumber(N); break;
			}
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.getNumber(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = ;
				_received = _obj.getNumber(N); break;
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
