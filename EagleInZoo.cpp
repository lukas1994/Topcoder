
#line 3 "EagleInZoo.cpp"
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

class EagleInZoo {
public:
    double ps[100] = {0.0};
    vector<int> cs[100];
    int N;

    double dfs(int node, double p) {
        double res = 1-ps[node];
        //cout << node << " " << p << endl;
        for (int i = 0; i < sz(cs[node]); i++)
            res += dfs(cs[node][i], p*ps[node]/sz(cs[node])) / sz(cs[node]);
        ps[node] += (1-ps[node])*p;

        return res;
    }

	double calc(vector <int> parent, int K) {
        N = sz(parent)+1;
        REP(i, sz(parent))
            cs[parent[i]].push_back(i+1);
        REP(k, K-1) {
            dfs(0, 1.0);
        }
        //REP(i, 10)
        //    cout << i << " " << ps[i] << endl;
        return dfs(0, 1.0);
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
		cout << "Testing EagleInZoo (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397924531;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EagleInZoo _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {0,0};
				int K = 2;
				_expected = 1.0;
				_received = _obj.calc(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), K); break;
			}
			case 1:
			{
				int parent[] = {0,0};
				int K = 3;
				_expected = 0.5;
				_received = _obj.calc(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), K); break;
			}
			case 2:
			{
				int parent[] = {0,1,0,3};
				int K = 4;
				_expected = 0.75;
				_received = _obj.calc(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), K); break;
			}
			case 3:
			{
				int parent[] = {0,0,1,1,2,4,4,4,5,5,6,6};
				int K = 20;
				_expected = 0.14595168754091617;
				_received = _obj.calc(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), K); break;
			}
			case 4:
			{
				int parent[] = {0,1,2,3,2,1,1,7,0,9,10,11,12,13,14,15,16,17,18,14,9};
				int K = 24;
				_expected = 0.3272154791654077;
				_received = _obj.calc(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), K); break;
			}
			case 5:
			{
				int parent[] = {0,1,2,3,4,5,6,7,8,9,10};
				int K = 50;
				_expected = 0.0;
				_received = _obj.calc(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), K); break;
			}
			/*case 6:
			{
				int parent[] = ;
				int K = ;
				_expected = ;
				_received = _obj.calc(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int K = ;
				_expected = ;
				_received = _obj.calc(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), K); break;
			}*/
			/*case 8:
			{
				int parent[] = ;
				int K = ;
				_expected = ;
				_received = _obj.calc(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), K); break;
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
