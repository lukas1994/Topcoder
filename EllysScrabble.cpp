
#line 3 "EllysScrabble.cpp"
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

class EllysScrabble {
    public:
        string getMin(string L, int D) {
            vector<bool> vis(sz(L), false);
            string S;
            for (int i = 0; i < sz(L); i++) {
                if (i >= D && !vis[i-D]) {
                    S.pb(L[i-D]);
                    vis[i-D] = true;
                    continue;
                }
                char minc = 'Z'+1;
                int mini = -1;
                for (int pos = max(0, i-D); pos < min(sz(L),i+D+1); pos++) {
                    if (!vis[pos] && L[pos] < minc) {
                        minc = L[pos];
                        mini = pos;
                    }
                }
                //cout << mini << endl;
                S.pb(minc);
                vis[mini] = true;
            }
            return S;
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
		cout << "Testing EllysScrabble (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397600774;
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
		EllysScrabble _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string letters = "TOPCODER";
				int maxDistance = 3;
				_expected = "CODTEPOR";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 1:
			{
				string letters = "ESPRIT";
				int maxDistance = 3;
				_expected = "EIPRST";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 2:
			{
				string letters = "BAZINGA";
				int maxDistance = 8;
				_expected = "AABGINZ";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 3:
			{
				string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				int maxDistance = 9;
				_expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 4:
			{
				string letters = "GOODLUCKANDHAVEFUN";
				int maxDistance = 7;
				_expected = "CADDGAHEOOFLUKNNUV";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 5:
			{
				string letters = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
				int maxDistance = 6;
				_expected = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 6:
			{
				string letters = "ABRACADABRA";
				int maxDistance = 2;
				_expected = "AABARACBDAR";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			/*case 7:
			{
				string letters = ;
				int maxDistance = ;
				_expected = ;
				_received = _obj.getMin(letters, maxDistance); break;
			}*/
			/*case 8:
			{
				string letters = ;
				int maxDistance = ;
				_expected = ;
				_received = _obj.getMin(letters, maxDistance); break;
			}*/
			/*case 9:
			{
				string letters = ;
				int maxDistance = ;
				_expected = ;
				_received = _obj.getMin(letters, maxDistance); break;
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
