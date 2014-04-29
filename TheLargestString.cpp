
#line 3 "TheLargestString.cpp"
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

class TheLargestString {
public:
    string dp[48][48][2];
    string s, t;
    string calc(int i, int len, bool I) {
        if (dp[i][len][I] != "")
            return dp[i][len][I];
        dp[i][len][] = make(i, i+len)
        if (i + len == s.size())
            return dp[i][len];
        string res1 = calc(i, len-1), res2 = calc(i+1, len-1);
        dp[i][len] = max(
        for (int k = i; k < j; k++) {
            string left = calc(i, k), right = calc(k+1, j);
            dp[i][j] = max(dp[i][j], left+right);
        }
        return dp[i][j][n];
    }
	string find(string s0, string t0) {
        s = s0; t = t0;
        return calc(0, s.size());
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
		cout << "Testing TheLargestString (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396807676;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheLargestString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "ab";
				string t = "zy";
				_expected = "by";
				_received = _obj.find(s, t); break;
			}
			case 1:
			{
				string s = "abacaba";
				string t = "zzzaaaa";
				_expected = "cbaaaa";
				_received = _obj.find(s, t); break;
			}
			case 2:
			{
				string s = "x";
				string t = "x";
				_expected = "xx";
				_received = _obj.find(s, t); break;
			}
			case 3:
			{
				string s = "abbabbabbababaaaabbababab";
				string t = "bababbaabbbababbbbababaab";
				_expected = "bbbbbbbbbbbbbbbbbbaaab";
				_received = _obj.find(s, t); break;
			}
			/*case 4:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.find(s, t); break;
			}*/
			/*case 5:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.find(s, t); break;
			}*/
			/*case 6:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.find(s, t); break;
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
