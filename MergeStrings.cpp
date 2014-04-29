
#line 3 "MergeStrings.cpp"
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class MergeStrings {
public:
    string dp[60][60];
    bool done[60][60];
    string s, a, b;
    string possible(int posA, int posB) {
        if (done[posA][posB])
            return dp[posA][posB];
        if (posA+posB == s.size())
            return "";
        done[posA][posB] = true;

        if (posA < a.size() && posB < b.size() && ((a[posA] == s[posA+posB] && b[posB] == s[posA+posB]) || s[posA+posB] == '?')) {
            string resA = a[posA] + possible(posA+1, posB), resB = b[posB] + possible(posA, posB+1);
            bool okA = true, okB = true;
            for (int i = 0; i < resA.size(); i++)
                if (resA[i] == '*')
                    okA = false;
            for (int i = 0; i < resB.size(); i++)
                if (resB[i] == '*')
                    okB = false;
            if (okA && okB)
                return dp[posA][posB] = min(resA, resB);
            if (okA)
                return dp[posA][posB] = resA;
            if (okB)
                return dp[posA][posB] = resB;
        }
        if (posA < a.size() && (a[posA] == s[posA+posB] || s[posA+posB] == '?'))
            return dp[posA][posB] = a[posA]+possible(posA+1,posB);
        if (posB < b.size() && (b[posB] == s[posA+posB] || s[posA+posB] == '?'))
            return dp[posA][posB] = a[posB]+possible(posA,posB+1);

        //assert(true);

        return "*";
    }
    string getmin(string S, string A, string B) {
        for (int i = 0; i < 60; i++)
            for (int j = 0; j < 60; j++)
                done[i][j] = false;
        s = S; a = A; b = B;
        return possible(0,0);
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
		cout << "Testing MergeStrings (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396697399;
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
		MergeStrings _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "??CC??";
				string A = "ABC";
				string B = "BCC";
				_expected = "ABCCBC";
				_received = _obj.getmin(S, A, B); break;
			}
			case 1:
			{
				string S = "WHAT?";
				string A = "THE";
				string B = "WA";
				_expected = "";
				_received = _obj.getmin(S, A, B); break;
			}
			case 2:
			{
				string S = "PARROT";
				string A = "PARROT";
				string B = "";
				_expected = "PARROT";
				_received = _obj.getmin(S, A, B); break;
			}
			case 3:
			{
				string S = "???????????";
				string A = "AZZAA";
				string B = "AZAZZA";
				_expected = "AAZAZZAAZZA";
				_received = _obj.getmin(S, A, B); break;
			}
			case 4:
			{
				string S = "????K??????????????D???K???K????????K?????K???????";
				string A = "KKKKKDKKKDKKDDKDDDKDKK";
				string B = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD";
				_expected = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK";
				_received = _obj.getmin(S, A, B); break;
			}
			/*case 5:
			{
				string S = ;
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getmin(S, A, B); break;
			}*/
			/*case 6:
			{
				string S = ;
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getmin(S, A, B); break;
			}*/
			/*case 7:
			{
				string S = ;
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.getmin(S, A, B); break;
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
