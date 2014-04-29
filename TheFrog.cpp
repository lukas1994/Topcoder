
#line 3 "TheFrog.cpp"
#include <string>
#include <vector>

using namespace std;

class TheFrog {
public:
    vector <int> l, r;
    bool doesWork(double s) {
        for (int i = 0; i < l.size(); i++)
            if (l[i] < s && s < r[i])
                return false;
        return true;
    }
	double getMinimum(int D, vector <int> L, vector <int> R) {
        l = L; r = R;

        double eps = 1e-9;
        double l = eps/2, r = D+eps/2;
        while (r-l > eps) {
            double m = (l+r)/2;
            if (doesWork(m)) {
                r = m;
            }
            else {
                l = m;
            }
        }
        return l;
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
		cout << "Testing TheFrog (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396726504;
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
		TheFrog _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int D = 16;
				int L[] = {2};
				int R[] = {7};
				_expected = 7.0;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 1:
			{
				int D = 25;
				int L[] = {11, 3};
				int R[] = {21, 7};
				_expected = 10.5;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 2:
			{
				int D = 100;
				int L[] = {0};
				int R[] = {100};
				_expected = 100.0;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 3:
			{
				int D = 100;
				int L[] = {0, 50};
				int R[] = {50, 100};
				_expected = 50.0;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 4:
			{
				int D = 30000;
				int L[] = {17, 25281, 5775, 2825, 14040};
				int R[] = {55, 26000, 5791, 3150, 14092};
				_expected = 787.8787878787879;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			/*case 5:
			{
				int D = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int D = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int D = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
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
