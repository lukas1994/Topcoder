
#line 3 "FoxAndDoraemon.cpp"
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

class FoxAndDoraemon {
public:
    int dp[51][51];
    int c;
    vector<int> w;
    int calc(int fox, int k) {
        if (fox >= k)
            return w[k-1];
        if (dp[fox][k] != -1)
            return dp[fox][k];
        dp[fox][k] = calc(2*fox, k)+c;
        for (int i = 1; i < fox; i++) {
            dp[fox][k] = min(dp[fox][k], max(calc(fox-i, k-i), w[k-1]));
        }
        return dp[fox][k];
    }
	int minTime(vector <int> workCost, int splitCost) {
		for (int i = 0; i < 51; i++)
            for (int j = 0; j < 51; j++)
                dp[i][j] = -1;
        sort(all(workCost));
        c = splitCost;
        w = workCost;
        return calc(1, workCost.size());
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
		cout << "Testing FoxAndDoraemon (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396999260;
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
		FoxAndDoraemon _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int workCost[] = {1,2};
				int splitCost = 1000;
				_expected = 1002;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 1:
			{
				int workCost[] = {3,6,9,12};
				int splitCost = 1000;
				_expected = 2012;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 2:
			{
				int workCost[] = {1000,100,10,1};
				int splitCost = 1;
				_expected = 1001;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 3:
			{
				int workCost[] = {1712,1911,1703,1610,1697,1612};
				int splitCost = 100;
				_expected = 2012;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 4:
			{
				int workCost[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
				int splitCost = 3000;
				_expected = 15000;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 5:
			{
				int workCost[] = {58};
				int splitCost = 3600;
				_expected = 58;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			/*case 6:
			{
				int workCost[] = ;
				int splitCost = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}*/
			/*case 7:
			{
				int workCost[] = ;
				int splitCost = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}*/
			/*case 8:
			{
				int workCost[] = ;
				int splitCost = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
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
