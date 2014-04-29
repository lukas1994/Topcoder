
#line 3 "LittleElephantAndString.cpp"
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

class LittleElephantAndString {
public:
	int getNumber(string A, string B) {
        map<char, int> m;
        REP(i, sz(A))
            m[A[i]]++;
        REP(i, sz(B))
            m[B[i]]--;
        for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
            if (it->second != 0)
                return -1;
        int v = 0;
        for (int i = sz(A)-1, j = sz(B) - 1; i >= 0; ) {
            if (A[i] == B[j]) {
                i--; j--;
            }
            else {
                i--;
                v++;
            }
        }
        return v;
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
		cout << "Testing LittleElephantAndString (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397164222;
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
		LittleElephantAndString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A = "ABC";
				string B = "CBA";
				_expected = 2;
				_received = _obj.getNumber(A, B); break;
			}
			case 1:
			{
				string A = "A";
				string B = "B";
				_expected = -1;
				_received = _obj.getNumber(A, B); break;
			}
			case 2:
			{
				string A = "AAABBB";
				string B = "BBBAAA";
				_expected = 3;
				_received = _obj.getNumber(A, B); break;
			}
			case 3:
			{
				string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				string B = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
				_expected = 25;
				_received = _obj.getNumber(A, B); break;
			}
			case 4:
			{
				string A = "A";
				string B = "A";
				_expected = 0;
				_received = _obj.getNumber(A, B); break;
			}
			case 5:
			{
				string A = "DCABA";
				string B = "DACBA";
				_expected = 2;
				_received = _obj.getNumber(A, B); break;
			}
			/*case 6:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
			}*/
			/*case 7:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
			}*/
			/*case 8:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
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
