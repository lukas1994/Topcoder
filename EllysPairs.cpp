
#line 3 "EllysPairs.cpp"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class EllysPairs {
public:
	int getDifference(vector <int> k) {
	    sort(k.begin(), k.end());
        int mini = 10000000, maxi = 0;
        for (int i = 0; i < k.size()/2; i++) {
            int k0 = k[i]+k[k.size()-1-i];
            mini = min(mini, k0);
            maxi = max(maxi, k0);
        }
        return maxi-mini;
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
		cout << "Testing EllysPairs (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396735691;
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
		EllysPairs _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int knowledge[] = {2, 6, 4, 3};
				_expected = 1;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}
			case 1:
			{
				int knowledge[] = {1, 1, 1, 1, 1, 1};
				_expected = 0;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}
			case 2:
			{
				int knowledge[] = {4, 2, 4, 2, 1, 3, 3, 7};
				_expected = 2;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}
			case 3:
			{
				int knowledge[] = {5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4};
				_expected = 3;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}
			/*case 4:
			{
				int knowledge[] = ;
				_expected = ;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int knowledge[] = ;
				_expected = ;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int knowledge[] = ;
				_expected = ;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
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
