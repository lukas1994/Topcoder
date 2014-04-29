
#line 3 "BigFatInteger2.cpp"
#include <string>
#include <vector>
#include <map>

using namespace std;

class BigFatInteger2 {
public:
	string isDivisible(int A, int B, int C, int D) {
        map<long long, long long> a, c;
        int i = 2;
        while (A > 1 && i*i <= A) {
            long long count = 0;
            while (A % i == 0) {
                count++;
                A /= i;
            }
            a[i] = B*count;
            i++;
        }
        if (A > 1)
            a[A] = B;
        i = 2;
        while (C > 1 && i*i <= C) {
            long long count = 0;
            while (C % i == 0) {
                count++;
                C /= i;
            }
            c[i] = D*count;
            i++;
        }
        if (C > 1)
            c[C] = D;
        for (map<long long, long long>::iterator it = c.begin(); it != c.end(); it++) {
            long long f = it->first, s = it->second;
            if (s > a[f])
                return "not divisible";
        }
        return "divisible";
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
		cout << "Testing BigFatInteger2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396785588;
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
		BigFatInteger2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 6;
				int B = 1;
				int C = 2;
				int D = 1;
				_expected = "divisible";
				_received = _obj.isDivisible(A, B, C, D); break;
			}
			case 1:
			{
				int A = 2;
				int B = 1;
				int C = 6;
				int D = 1;
				_expected = "not divisible";
				_received = _obj.isDivisible(A, B, C, D); break;
			}
			case 2:
			{
				int A = 1000000000;
				int B = 1000000000;
				int C = 1000000000;
				int D = 200000000;
				_expected = "divisible";
				_received = _obj.isDivisible(A, B, C, D); break;
			}
			case 3:
			{
				int A = 8;
				int B = 100;
				int C = 4;
				int D = 200;
				_expected = "not divisible";
				_received = _obj.isDivisible(A, B, C, D); break;
			}
			case 4:
			{
				int A = 999999937;
				int B = 1000000000;
				int C = 999999929;
				int D = 1;
				_expected = "not divisible";
				_received = _obj.isDivisible(A, B, C, D); break;
			}
			case 5:
			{
				int A = 2;
				int B = 2;
				int C = 4;
				int D = 1;
				_expected = "divisible";
				_received = _obj.isDivisible(A, B, C, D); break;
			}
			/*case 6:
			{
				int A = ;
				int B = ;
				int C = ;
				int D = ;
				_expected = ;
				_received = _obj.isDivisible(A, B, C, D); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				int C = ;
				int D = ;
				_expected = ;
				_received = _obj.isDivisible(A, B, C, D); break;
			}*/
			/*case 8:
			{
				int A = ;
				int B = ;
				int C = ;
				int D = ;
				_expected = ;
				_received = _obj.isDivisible(A, B, C, D); break;
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
