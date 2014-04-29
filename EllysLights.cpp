
#line 3 "EllysLights.cpp"
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

class EllysLights {
public:
    vector<long long> ss;
    vector<bool> done;
    vector<vector<int> > poss;
    int N, M, maxcount;
    map<long long, int> cache;
    int dp(long long state, int count) {
        if (state == 0)
            return 0;
        if (count > 1+N) {
            cout << "*" << endl;
            return -1;  
        }
        if (cache.count(state) > 0)
            return cache[state];

        /*for (int i = 0; i < done.size(); i++)
            cout << done[i];
        cout << endl;*/
        int minv = -1;
        for (int i = 0; i < M; i++) {
            if (state & (1LL << (i))) {
                for (int j = 0; j < poss[i].size(); j++) {
                    //cout << "try " << poss[i][j] << endl;
                    if (done[poss[i][j]])
                        continue;
                    //cout << "NOW" << endl;
                    done[poss[i][j]] = true;
                    /*for (int k = 0; k < count; k++)
                        cout << " . ";
                    cout << poss[i][j] << ": ";*/
                    long long newstate = state ^ ss[poss[i][j]];
                    //cout << newstate << endl;
                    int v = dp(newstate, count+1);
                    //cout << "-> " << v << endl;
                    done[poss[i][j]] = false;
                    if (minv == -1 || (v != -1 && minv > v))
                        minv = v;
                }
                break;
            }
        }
        if (minv != -1)
            minv += 1;
        cache[state] = minv;
        return minv;
    }
	int getMinimum(string initial, vector <string> switches) {
        N = switches.size();
        M = initial.size();
        poss.resize(M);
        done.resize(N, false);
		for (int i = 0; i < switches.size(); i++) {
            long long s = 0;
            vector<int> d;
            for (int j = 0; j < switches[i].size(); j++) {
                if (switches[i][j] == 'Y') {
                    s |= 1LL << j;
                    d.pb(j);
                }
            }
            //cout << s << endl;
            ss.pb(s);
            for (int j = 0; j < d.size(); j++)
                poss[d[j]].pb(i);
        }
        /*cout << "---" << endl;
        for (int i = 0; i < poss.size(); i++) {
            for (int j = 0; j < poss[i].size(); j++)
                cout << poss[i][j] << " ";
            cout << endl;
        }
        cout << "---" << endl;*/
        long long init = 0;
        for (int i = 0; i < initial.size(); i++) {
            if (initial[i] == 'Y')
                init |= 1LL << i;
        }
        //cout << "init: " << init << endl;
        return dp(init, 0);
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
		cout << "Testing EllysLights (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396988521;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysLights _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string initial = "YNYNNN";
				string switches[] = {"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"};
				_expected = 2;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 1:
			{
				string initial = "YNYNYN";
				string switches[] = {"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"};
				_expected = 4;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 2:
			{
				string initial = "YYN";
				string switches[] = {"YNY", "NYN"};
				_expected = -1;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 3:
			{
				string initial = "NNYNYNYYYNNYYYYN";
				string switches[] = {"NYNYNYNYNYNYNYNY",
				                     "YNYNYNYNYNYNYNYN",
				                     "NNNNNNNNNNNNNNNN",
				                     "YNNNNNNNNNNNNNNN",
				                     "NYNNNNNNNNNNNNNN",
				                     "NNYNNNNNNNNNNNNN",
				                     "NNNYNNNNNNNNNNNN",
				                     "NNNNYNNNNNNNNNNN",
				                     "NNNNNYNNNNNNNNNN",
				                     "NNNNNNYNNNNNNNNN",
				                     "NNNNNNNYNNNNNNNN",
				                     "NNNNNNNNYNNNNNNN",
				                     "NNNNNNNNNYNNNNNN",
				                     "NNNNNNNNNNYNNNNN",
				                     "NNNNNNNNNNNYNNNN",
				                     "NNNNNNNNNNNNYNNN",
				                     "NNNNNNNNNNNNNYNN",
				                     "NNNNNNNNNNNNNNYN",
				                     "NNNNNNNNNNNNNNNY"};
				_expected = 6;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 4:
			{
				string initial = "NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY";
				string switches[] = {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
				                     "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
				                     "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
				                     "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
				                     "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
				                     "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
				                     "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
				                     "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
				                     "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
				                     "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
				                     "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
				                     "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"};
				_expected = 7;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 5:
			{
				string initial = "NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN";
				string switches[] = {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
				                     "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
				                     "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
				                     "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
				                     "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
				                     "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
				                     "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
				                     "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
				                     "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
				                     "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
				                     "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
				                     "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
				                     "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
				                     "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"};
				_expected = -1;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 6:
			{
				string initial = "YNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYN";
                string switches[] = {"YNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                                     "YYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                                     "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN", 
                                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYY"};
				_expected = 25;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			/*case 7:
			{
				string initial = ;
				string switches[] = ;
				_expected = ;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string initial = ;
				string switches[] = ;
				_expected = ;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
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
