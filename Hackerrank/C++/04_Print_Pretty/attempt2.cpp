#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */

        // A
        cout << hex << showbase << nouppercase << left << (long) (long) A << endl;
        // B
        cout << setprecision(2) << showpos << right <<  setw(15) << setfill('_') << fixed << B << endl;
        // C
        cout << setprecision(9) << uppercase << scientific << C << endl;

	}
	return 0;

}