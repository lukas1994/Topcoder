
#line 3 "EllysFigurines.cpp"
#include <string>
#include <vector>

using namespace std;

class EllysFigurines {
public:
    int dp[1 << 30];
    vector<string> b;
    int r, c;

    int clear(int x, int i) {
        return x & ~(1 << i);
    }

    int rec(int bit) {
        if (dp[bit] != -1)
            return dp[bit];
        if (bit == 0)
            return dp[bit] = 0;
        dp[bit] = -1;
        for (int i = 0; i < b.size(); i++) {
            int newbit = bit;
            for (int j = 0; j < r; j++)
                if (i+j < b.size())
                    clear(newbit, i+j);
            int res = 1 + rec(newbit);
            if (dp[bit] == -1 || dp[bit] > res)
                dp[bit] = res;

            newbit = bit;
            for (int j = 0; j < r; j++)
                if (i+j < b[0].size())
                    clear(newbit, b.size()+i+j);
            res = 1 + rec(newbit);
            if (dp[bit] == -1 || dp[bit] > res)
                dp[bit] = res;
        }
        return dp[bit];
    }
	int getMoves(vector <string> board, int R, int C) {
		b = board; r = R; c = C;
        for (int i = 0; i < 1<<30; i++)
            dp[i] = -1;
        int bit = 0;
        for (int i = 0; i < b.size(); i++) {
            bool free = true;
            for (int j = 0; j < b[i].size(); j++)
                if (b[i][j] == 'X')
                    free = false;
            bit <<= 1;
            if (!free)
                bit += 1;
        }
        for (int i = 0; i < b.size(); i++) {
            bool free = true;
            for (int j = 0; j < b[i].size(); j++)
                if (b[j][i] == 'X')
                    free = false;
            bit <<= 1;
            if (!free)
                bit += 1;
        }

        return rec(bit);
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
		cout << "Testing EllysFigurines (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396735913;
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
		EllysFigurines _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".X.X.",
				                  "XX..X",
				                  ".XXX.",
				                  "...X.",
				                  ".X.XX"};
				int R = 1;
				int C = 2;
				_expected = 3;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 1:
			{
				string board[] = {".X.X.",
				                  "XX..X",
				                  ".X.X.",
				                  "...X.",
				                  ".X.XX"};
				int R = 2;
				int C = 2;
				_expected = 2;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 2:
			{
				string board[] = {"XXXXXXX"};
				int R = 2;
				int C = 3;
				_expected = 1;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 3:
			{
				string board[] = {"XXXXX",
				                  "X....",
				                  "XXX..",
				                  "X....",
				                  "XXXXX"};
				int R = 1;
				int C = 1;
				_expected = 4;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 4:
			{
				string board[] = {"XXX..XXX..XXX.",
				                  ".X..X....X...X",
				                  ".X..X....X...X",
				                  ".X..X....X...X",
				                  ".X...XXX..XXX.",
				                  "..............",
				                  "...XX...XXX...",
				                  "....X......X..",
				                  "....X....XXX..",
				                  "....X......X..",
				                  "...XXX..XXX..."};
				int R = 1;
				int C = 2;
				_expected = 7;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			/*case 5:
			{
				string board[] = ;
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
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
