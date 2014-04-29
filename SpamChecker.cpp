
#line 3 "SpamChecker.cpp"
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

class SpamChecker {
public:
	string spamCheck(string log, int good, int bad) {
	    long long score = 0;
        for (int i = 0; i < sz(log); i++) {
            if (log[i] == 'o')
                score += good;
            else
                score -= bad;
            if (score < 0)
                return "SPAM";
        } 
        return "NOT SPAM";
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
		cout << "Testing SpamChecker (200.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397923215;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 200.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SpamChecker _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string judgeLog = "ooooxxxo";
				int good = 2;
				int bad = 3;
				_expected = "SPAM";
				_received = _obj.spamCheck(judgeLog, good, bad); break;
			}
			case 1:
			{
				string judgeLog = "ooooxxxo";
				int good = 3;
				int bad = 4;
				_expected = "NOT SPAM";
				_received = _obj.spamCheck(judgeLog, good, bad); break;
			}
			case 2:
			{
				string judgeLog = "xooooooooooooooooooooooooooo";
				int good = 1000;
				int bad = 1;
				_expected = "SPAM";
				_received = _obj.spamCheck(judgeLog, good, bad); break;
			}
			case 3:
			{
				string judgeLog = "oxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
				int good = 1000;
				int bad = 1;
				_expected = "NOT SPAM";
				_received = _obj.spamCheck(judgeLog, good, bad); break;
			}
			case 4:
			{
				string judgeLog = "ooxoxoxooxoxxoxoxooxoxoxoxxoxx";
				int good = 15;
				int bad = 17;
				_expected = "SPAM";
				_received = _obj.spamCheck(judgeLog, good, bad); break;
			}
			case 5:
			{
				string judgeLog = "oooxoxoxoxoxoxooxooxoxooxo";
				int good = 16;
				int bad = 18;
				_expected = "NOT SPAM";
				_received = _obj.spamCheck(judgeLog, good, bad); break;
			}
			/*case 6:
			{
				string judgeLog = ;
				int good = ;
				int bad = ;
				_expected = ;
				_received = _obj.spamCheck(judgeLog, good, bad); break;
			}*/
			/*case 7:
			{
				string judgeLog = ;
				int good = ;
				int bad = ;
				_expected = ;
				_received = _obj.spamCheck(judgeLog, good, bad); break;
			}*/
			/*case 8:
			{
				string judgeLog = ;
				int good = ;
				int bad = ;
				_expected = ;
				_received = _obj.spamCheck(judgeLog, good, bad); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
