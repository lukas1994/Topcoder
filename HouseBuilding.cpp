
#line 3 "HouseBuilding.cpp"
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
/*int abs(int a) {
    return (a<0)?-a:a;
}*/
class HouseBuilding {
public:
	int getMinimum(vector <string> area) {
	    int mini = 100000000;
        for (int h = 0; h <= 10; h++) {
            int current = 0;
            for (int i = 0; i < area.size(); i++) {
                for (int j = 0; j < area[i].size(); j++) {
                    int delta = min(abs(h-area[i][j]+'0'), abs(h-area[i][j]+'0'+1));
                    current += delta;
                }
            }
            mini = min(mini, current);
        }
        return mini;
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
		cout << "Testing HouseBuilding (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396725899;
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
		HouseBuilding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string area[] = {"10",
				                 "31"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 1:
			{
				string area[] = {"54454",
				                 "61551"};
				_expected = 7;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 2:
			{
				string area[] = {"989"};
				_expected = 0;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 3:
			{
				string area[] = {"90"};
				_expected = 8;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 4:
			{
				string area[] = {"5781252",
				                 "2471255",
				                 "0000291",
				                 "1212489"};
				_expected = 53;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			/*case 5:
			{
				string area[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string area[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string area[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
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
