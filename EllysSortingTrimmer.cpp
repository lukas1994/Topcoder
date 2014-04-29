
#line 3 "EllysSortingTrimmer.cpp"
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

class EllysSortingTrimmer {
public:
    int l;
    string apply(string s, int i) {
        string ss = s.substr(i,l);
        sort(all(ss));
        return s.substr(0,i)+ss;
    }
	string getMin(string S, int L) {
        l = L;
        string mins = S;
        for (int i = sz(S)-L; i >= 0; i--)
            mins = min(mins, apply(mins, i));
        return mins;
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
		cout << "Testing EllysSortingTrimmer (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397599925;
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
		EllysSortingTrimmer _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "ABRACADABRA";
				int L = 5;
				_expected = "AAAAA";
				_received = _obj.getMin(S, L); break;
			}
			case 1:
			{
				string S = "ESPRIT";
				int L = 3;
				_expected = "EIP";
				_received = _obj.getMin(S, L); break;
			}
			case 2:
			{
				string S = "BAZINGA";
				int L = 7;
				_expected = "AABGINZ";
				_received = _obj.getMin(S, L); break;
			}
			case 3:
			{
				string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				int L = 13;
				_expected = "ABCDEFGHIJKLM";
				_received = _obj.getMin(S, L); break;
			}
			case 4:
			{
				string S = "GOODLUCKANDHAVEFUN";
				int L = 10;
				_expected = "AACDDEFGHK";
				_received = _obj.getMin(S, L); break;
			}
			case 5:
			{
				string S = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
				int L = 21;
				_expected = "AAAAAAAAABBDDDDDDDEEI";
				_received = _obj.getMin(S, L); break;
			}
			case 6:
			{
				string S = "TOPCODER";
				int L = 3;
				_expected = "CDT";
				_received = _obj.getMin(S, L); break;
			}
			/*case 7:
			{
				string S = ;
				int L = ;
				_expected = ;
				_received = _obj.getMin(S, L); break;
			}*/
			/*case 8:
			{
				string S = ;
				int L = ;
				_expected = ;
				_received = _obj.getMin(S, L); break;
			}*/
			/*case 9:
			{
				string S = ;
				int L = ;
				_expected = ;
				_received = _obj.getMin(S, L); break;
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
