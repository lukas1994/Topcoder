
#line 3 "SimilarNames2.cpp"
#include <string>
#include <vector>

using namespace std;

class SimilarNames2 {
public:
    vector<int> graph[51];
    int l;
    const long long MOD = 1000000007;
    long long dp[51][51];
    long long dfs(int v, int c) {
        if (dp[v][c] != -1)
            return dp[v][c];
        if (c == l)
            return 1;
        dp[v][c] = 0;
        for (int i = 0; i < graph[v].size(); i++)
            dp[v][c] += dfs(graph[v][i], c+1);
        return dp[v][c];
    }
	int count(vector <string> names, int L) {
        l = L;
		for (int i = 0; i < 51; i++) {
            graph[i].clear();
            for (int j = 0; j < 51; j++)
                dp[i][j] = -1;
        }
        for (int i = 0; i < names.size(); i++) {
            for (int j = 0; j < names.size(); j++) {
                if (i == j || names[i].size() > names[j].size())
                    continue;
                bool ok = true;
                for (int k = 0; k < names[i].size(); k++)
                    if (names[i][k] != names[j][k])
                        ok = false;
                if (ok)
                    graph[i].push_back(j);
            }
        }
        long long res = 0;
        for (int i = 0; i < names.size(); i++)
            res += dfs(i, 1);
        for (int i = 2; i <= names.size()-L; i++) {
            res *= i;
            res %= MOD;
        }
        return res;
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
		cout << "Testing SimilarNames2 (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396788645;
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
		SimilarNames2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string names[] = {"kenta", "kentaro", "ken"};
				int L = 2;
				_expected = 3;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), L); break;
			}
			case 1:
			{
				string names[] = {"hideo", "hideto", "hideki", "hide"};
				int L = 2;
				_expected = 6;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), L); break;
			}
			case 2:
			{
				string names[] = {"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"};
				int L = 3;
				_expected = 24;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), L); break;
			}
			case 3:
			{
				string names[] = {"taro", "jiro", "hanako"};
				int L = 2;
				_expected = 0;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), L); break;
			}
			case 4:
			{
				string names[] = {"alice", "bob", "charlie"};
				int L = 1;
				_expected = 6;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), L); break;
			}
			case 5:
			{
				string names[] = {"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun",
				                  "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"};
				int L = 3;
				_expected = 276818566;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), L); break;
			}
			/*case 6:
			{
				string names[] = ;
				int L = ;
				_expected = ;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), L); break;
			}*/
			/*case 7:
			{
				string names[] = ;
				int L = ;
				_expected = ;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), L); break;
			}*/
			/*case 8:
			{
				string names[] = ;
				int L = ;
				_expected = ;
				_received = _obj.count(vector <string>(names, names+sizeof(names)/sizeof(string)), L); break;
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
