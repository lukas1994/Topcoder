
#line 3 "RedPaint.cpp"
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

class RedPaint {
public:
    map<pair<pair<int, int>, int>, double> mp;
    double calc(int i, int j, int n) {
        pair<pair<int, int>, int> p = mp(mp(i,j),n);
        if (mp.count(p) > 0)
            return mp[p];
        if (n == 0)
            return i+j+1;

        double res = 0;

        if (i == 0) {
            res += calc(i,j+1,n-1);
        }
        else
            res += calc(i-1,j+1,n-1);
        if (j == 0)
            res += calc(i+1,j,n-1);
        else
            res += calc(i+1,j-1,n-1);

        res /= 2.0;
        mp[p] = res;
        return res;

    }
    map<pair<pair<int, int>, bool>, double> mp2;
    double calc2(int len, int n, bool right) {
        pair<pair<int, int>, bool> p = mp(mp(len,n),right);
        if (mp.count(p) > 0)
            return mp[p];
        if (n == 0)
            return len;
        if (n < 0)
            return 0;
        double res = 0.0;
        res += pow(0.5, len)*calc2(len, n-len, !right);
        for (int i = 1; n - 2*i >= 0; i++)
            res += pow(0.5, 2*i)*calc2(len, n-2*i, right);
        res += 0.5*calc2(len+1, n-1, right);
        mp[p] = res;
        return res;
    }
	double expectedCells(int N) {
        return calc2(1, N, true);
        //return calc(0,0,N);
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
		//cout << "Testing RedPaint (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398528767;
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
		RedPaint _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 0;
				_expected = 1.0;
				_received = _obj.expectedCells(N); break;
			}
			case 1:
			{
				int N = 1;
				_expected = 2.0;
				_received = _obj.expectedCells(N); break;
			}
			case 2:
			{
				int N = 2;
				_expected = 2.5;
				_received = _obj.expectedCells(N); break;
			}
			case 3:
			{
				int N = 4;
				_expected = 3.375;
				_received = _obj.expectedCells(N); break;
			}
			case 4:
			{
				int N = 500;
				_expected = 2;
				_received = _obj.expectedCells(N); break;
			}
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.expectedCells(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = ;
				_received = _obj.expectedCells(N); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
