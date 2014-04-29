
#line 3 "LongLongNim.cpp"
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

class LongLongNim {
    public:
        int numberOfWins(int maxN, vector <int> moves) {
            map<long long, pair<bool, int> > m;
            vector<int> culm;
            long long count = 0;
            long long state = (1LL << 22) - 1;
            bool cycle = false;

            for (long long i = 0; i <= maxN; i++) {
                /*if (i < 30) {
                    for (int j = 0; j < 20; j++)
                        cout << (bool)(state & (1<<j));
                    cout << endl;
                }*/
                bool win = false;
                if (m.count(state) > 0) {
                    if (m[state].first)
                        win = true;

                    if (!cycle) {
                        int clen = i-m[state].second;
                        int ccount = culm[i-1] - culm[m[state].second-1];

                        long long div = (maxN-i)/clen;

                        //cout << div << " " << clen << " " << ccount << endl;

                        i += div*clen;
                        count += div*ccount;

                        cycle = true;
                    }
                } 
                else {
                    for (int j = 0; j < sz(moves); j++) {
                        if ((state & (1LL << (moves[j]-1))) == 0) {
                            win = true;
                            break;
                        }
                    }
                    if (!cycle)
                        culm.pb(((i == 0) ? 0 : culm[culm.size()-1]) + (win ? 1 : 0));
                }
                int p = (m.count(state) == 0) ? i : m[state].second;
                if (win) {
                    count++;
                    m[state] = mp(true, p);
                }
                else {
                    m[state] = mp(false, p);
                }

                state <<= 1;
                if (win)
                    state += 1;
                state &= (1LL << 22) - 1;

            }
            return maxN-count;
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
        cout << "Testing LongLongNim (1000.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++)
        {
            ostringstream s; s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1397417499;
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
        LongLongNim _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc)
        {
            case 0:
                {
                    int maxN = 20;
                    int moves[] = {1,2,3};
                    _expected = 5;
                    _received = _obj.numberOfWins(maxN, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
                }
            case 1:
                {
                    int maxN = 999;
                    int moves[] = {1};
                    _expected = 499;
                    _received = _obj.numberOfWins(maxN, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
                }
            case 2:
                {
                    int maxN = 1000000000;
                    int moves[] = {1,2};
                    _expected = 333333333;
                    _received = _obj.numberOfWins(maxN, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
                }
            case 3:
                {
                    int maxN = 6543;
                    int moves[] = {2,4,7,11,20};
                    _expected = 1637;
                    _received = _obj.numberOfWins(maxN, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
                }
                /*case 4:
                  {
                  int maxN = ;
                  int moves[] = ;
                  _expected = ;
                  _received = _obj.numberOfWins(maxN, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
                  }*/
                /*case 5:
                  {
                  int maxN = ;
                  int moves[] = ;
                  _expected = ;
                  _received = _obj.numberOfWins(maxN, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
                  }*/
                /*case 6:
                  {
                  int maxN = ;
                  int moves[] = ;
                  _expected = ;
                  _received = _obj.numberOfWins(maxN, vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
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
