
#line 3 "FruitTrees.cpp"
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

class FruitTrees {
public:
    int gcd(int a, int b) {
        if (a < b)
            swap(a, b);
        return (b == 0) ? a : gcd(b, a%b);
    }
	int maxDist(int apple, int kiwi, int grape) {
        int maxi = 0;
        for (int i = 1; i < apple; i++) {
            for (int j = 1; j < apple; j++) {
                if (i == j)
                    continue;
                int mini = min(min(mm(0, i), mm(0,j)), mm(i,j));
                maxi = max(maxi, mini);
            }
        }
        return maxi;
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
		cout << "Testing FruitTrees (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396818932;
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
		FruitTrees _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int apple = 1;
				int kiwi = 5;
				int grape = 8;
				_expected = 0;
				_received = _obj.maxDist(apple, kiwi, grape); break;
			}
			case 1:
			{
				int apple = 3;
				int kiwi = 3;
				int grape = 6;
				_expected = 1;
				_received = _obj.maxDist(apple, kiwi, grape); break;
			}
			case 2:
			{
				int apple = 40;
				int kiwi = 30;
				int grape = 20;
				_expected = 5;
				_received = _obj.maxDist(apple, kiwi, grape); break;
			}
			case 3:
			{
				int apple = 899;
				int kiwi = 1073;
				int grape = 1147;
				_expected = 14;
				_received = _obj.maxDist(apple, kiwi, grape); break;
			}
			case 4:
			{
				int apple = 2000;
				int kiwi = 2000;
				int grape = 2000;
				_expected = 666;
				_received = _obj.maxDist(apple, kiwi, grape); break;
			}
			/*case 5:
			{
				int apple = ;
				int kiwi = ;
				int grape = ;
				_expected = ;
				_received = _obj.maxDist(apple, kiwi, grape); break;
			}*/
			/*case 6:
			{
				int apple = ;
				int kiwi = ;
				int grape = ;
				_expected = ;
				_received = _obj.maxDist(apple, kiwi, grape); break;
			}*/
			/*case 7:
			{
				int apple = ;
				int kiwi = ;
				int grape = ;
				_expected = ;
				_received = _obj.maxDist(apple, kiwi, grape); break;
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
