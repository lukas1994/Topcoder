
#line 3 "EllysLamps.cpp"
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

class EllysLamps {
public:
	int getMin(string L) {
        int count = 0;
	    for (int i = 0; i < sz(L)-1; i++) {
            if ((L[i] == 'Y' && L[i+1] == 'N') || (L[i] == 'N' && L[i+1] == 'Y')) {
                count++;
                i++;
            }
            else if (i+2 < sz(L) && L[i] == 'Y' && L[i+1] == 'Y' && L[i+2] == 'Y') {
                count++;
                i+=2;
            }
        }
        return count;
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
		cout << "Testing EllysLamps (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397750215;
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
		EllysLamps _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string lamps = "YNNYN";
				_expected = 2;
				_received = _obj.getMin(lamps); break;
			}
			case 1:
			{
				string lamps = "NNN";
				_expected = 0;
				_received = _obj.getMin(lamps); break;
			}
			case 2:
			{
				string lamps = "YY";
				_expected = 0;
				_received = _obj.getMin(lamps); break;
			}
			case 3:
			{
				string lamps = "YNYYYNNNY";
				_expected = 3;
				_received = _obj.getMin(lamps); break;
			}
			case 4:
			{
				string lamps = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY";
				_expected = 13;
				_received = _obj.getMin(lamps); break;
			}
			/*case 5:
			{
				string lamps = ;
				_expected = ;
				_received = _obj.getMin(lamps); break;
			}*/
			/*case 6:
			{
				string lamps = ;
				_expected = ;
				_received = _obj.getMin(lamps); break;
			}*/
			/*case 7:
			{
				string lamps = ;
				_expected = ;
				_received = _obj.getMin(lamps); break;
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
