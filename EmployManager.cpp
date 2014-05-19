
#line 3 "EmployManager.cpp"
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

class EmployManager {
public:
	int maximumEarnings(vector <int> value, vector <string> earning) {
	    int total = 0;
        REP(i, sz(value)) {
            int cost = value[i];
            REP(j, sz(value)) {
                if (j < i) total -= earning[i][j] - '0';
                cost -= earning[i][j] - '0';
            }
            if (cost < 0)
                total += -cost;
        }
        return total;
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
		cout << "Testing EmployManager (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400539605;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EmployManager _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int value[] = {1, 1};
				string earning[] = {"02", "20"};
				_expected = 0;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}
			case 1:
			{
				int value[] = {2, 2};
				string earning[] = {"01", "10"};
				_expected = -1;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}
			case 2:
			{
				int value[] = {1, 2, 3, 4};
				string earning[] = {"0121", "1021", "2201", "1110"};
				_expected = -1;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}
			case 3:
			{
				int value[] = {2, 2, 0, 1, 4, 0, 1, 0, 0, 4};
				string earning[] = {"0100451253",  "1010518123",  "0102989242",  "0020093171",  "4590045480",  "5189400676",  "1893500826",  "2121468008",  "5247872007",  "3321066870"};
				_expected = 156;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}
			/*case 4:
			{
				int value[] = ;
				string earning[] = ;
				_expected = ;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int value[] = ;
				string earning[] = ;
				_expected = ;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int value[] = ;
				string earning[] = ;
				_expected = ;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
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
