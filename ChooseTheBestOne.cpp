
#line 3 "ChooseTheBestOne.cpp"
#include <algorithm>
#include <list>
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

class ChooseTheBestOne {
public:
	int countNumber(int N) {
        list<int> data;
        REP(i, N)
            data.pb(i+1);
        int pos = 0;
        for (long long t = 1; t < N; t++) {
            pos = (pos+t*t*t-1) % sz(data);
            list<int>::iterator it = data.begin();
            REP(i, pos) it++;
            data.erase(it);
        }
		return data.front();
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
		cout << "Testing ChooseTheBestOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400537578;
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
		ChooseTheBestOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				_expected = 2;
				_received = _obj.countNumber(N); break;
			}
			case 1:
			{
				int N = 6;
				_expected = 6;
				_received = _obj.countNumber(N); break;
			}
			case 2:
			{
				int N = 10;
				_expected = 8;
				_received = _obj.countNumber(N); break;
			}
			case 3:
			{
				int N = 1234;
				_expected = 341;
				_received = _obj.countNumber(N); break;
			}
			case 4:
			{
				int N = 1506;
				_expected = 767;
				_received = _obj.countNumber(N); break;
			}
			case 5:
			{
				int N = 2462;
				_expected = 1286;
				_received = _obj.countNumber(N); break;
			}
			case 6:
			{
				int N = 3423;
				_expected = 1635;
				_received = _obj.countNumber(N); break;
			}
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
