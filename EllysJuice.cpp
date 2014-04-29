
#line 3 "EllysJuice.cpp"
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

class EllysJuice {
public:
	vector <string> getWinners(vector <string> players) {
	    set<string> winners;
        sort(all(players));
        do {
            map<string, double> m;
            for (int i = 0; i < players.size(); i++) {
                double amount = pow(2,-(i/2+1));
                /*if (m.count(players[i]) > 0)
                    m[players[i]] = amount;
                else*/
                    m[players[i]] += amount;
            }
            bool ok = true;
            string winner = "";
            double amount = 0;
            for (map<string, double>::iterator it = m.begin(); it != m.end(); it++) {
                //cout << it->first << " " << it->second << endl;
                if (winner == "") {
                    winner = it->first;
                    amount = it->second;
                    ok = true;
                }
                else if (amount == it->second)
                    ok = false;
                else if (amount < it->second) {
                    winner = it->first;
                    amount = it->second;
                    ok = true;
                }
            }
            //cout << "---" << endl;
            if (ok)
                winners.insert(winner);
        } while (next_permutation(all(players)));
        vector<string> w;
        for (set<string>::iterator it = winners.begin(); it != winners.end(); it++)
            w.pb(*it);
        return w;
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
		cout << "Testing EllysJuice (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396912325;
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
		EllysJuice _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string players[] = { "elly", "kriss", "stancho", "elly", "stancho" };
				string __expected[] = {"elly", "stancho" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}
			case 1:
			{
				string players[] = {"torb", "elly", "stancho", "kriss"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}
			case 2:
			{
				string players[] = {"elly", "elly", "elly", "elly", "elly"};
				string __expected[] = {"elly" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}
			case 3:
			{
				string players[] = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" };
				string __expected[] = {"ariadne", "elly", "stancho" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}
			case 4:
			{
				string players[] = {"this", "test", "is", "really", "really", "evil"};
				string __expected[] = {"really"};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}
			/*case 5:
			{
				string players[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string players[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
