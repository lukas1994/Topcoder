
#line 3 "GoodCompanyDivTwo.cpp"
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

class GoodCompanyDivTwo {
public:
	int countGood(vector <int> s, vector <int> w) {
        set<int> types[100];
        bool diverse[100];
        REP(i, sz(s)) {
            diverse[i] = true;
            types[i].insert(w[i]);
        }
        REP(i, sz(s)) {
            if (s[i] == -1)
                continue;
            if (!types[s[i]].insert(w[i]).second)
                diverse[s[i]] = false;
        }
        int count = 0;
        REP(i, sz(s))
            if (diverse[i])
                count++;
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
		cout << "Testing GoodCompanyDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400540615;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GoodCompanyDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int superior[] = {-1, 0};
				int workType[] = {1, 2};
				_expected = 2;
				_received = _obj.countGood(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(workType, workType+sizeof(workType)/sizeof(int))); break;
			}
			case 1:
			{
				int superior[] = {-1, 0};
				int workType[] = {1, 1};
				_expected = 1;
				_received = _obj.countGood(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(workType, workType+sizeof(workType)/sizeof(int))); break;
			}
			case 2:
			{
				int superior[] = {-1, 0, 1, 1};
				int workType[] = {1, 4, 3, 2};
				_expected = 4;
				_received = _obj.countGood(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(workType, workType+sizeof(workType)/sizeof(int))); break;
			}
			case 3:
			{
				int superior[] = {-1, 0, 1, 0, 0};
				int workType[] = {3, 3, 5, 2, 2};
				_expected = 4;
				_received = _obj.countGood(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(workType, workType+sizeof(workType)/sizeof(int))); break;
			}
			case 4:
			{
				int superior[] = {-1, 0, 1, 1, 1, 0, 2, 5};
				int workType[] = {1, 1, 2, 3, 4, 5, 3, 3};
				_expected = 7;
				_received = _obj.countGood(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(workType, workType+sizeof(workType)/sizeof(int))); break;
			}
			case 5:
			{
				int superior[] = {-1, 0, 0, 1, 1, 3, 0, 2, 0, 5, 2, 5, 5, 6, 1, 2, 11, 12, 10, 4, 7, 16, 10, 9, 12, 18, 15, 23, 20, 7, 4};
				int workType[] = {4, 6, 4, 7, 7, 1, 2, 8, 1, 7, 2, 4, 2, 9, 11, 1, 10, 11, 4, 6, 11, 7, 2, 8, 9, 9, 10, 10, 9, 8, 8};
				_expected = 27;
				_received = _obj.countGood(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(workType, workType+sizeof(workType)/sizeof(int))); break;
			}
			/*case 6:
			{
				int superior[] = ;
				int workType[] = ;
				_expected = ;
				_received = _obj.countGood(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(workType, workType+sizeof(workType)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int superior[] = ;
				int workType[] = ;
				_expected = ;
				_received = _obj.countGood(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(workType, workType+sizeof(workType)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int superior[] = ;
				int workType[] = ;
				_expected = ;
				_received = _obj.countGood(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(workType, workType+sizeof(workType)/sizeof(int))); break;
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
