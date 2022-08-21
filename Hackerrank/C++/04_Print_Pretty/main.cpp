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
        int a_int;
        A *= 10;    // Strip the decimal of a
        a_int = (int) A;
        if(a_int % 10 >= 5){
            a_int += 5;
            a_int /= 10;
        }else{
            a_int /= 10;
        }
        
        int n;
        n = a_int;
        int rest_array[100];
        int i = 0;
        cout << "0x";
        while(n != 0){
            rest_array[i] = n % 16;
            i++;
            n /= 16;
        }
        while(i--){
            switch (rest_array[i]){
                case 10: cout << 'A'; break;
                case 11: cout << 'B'; break;
                case 12: cout << 'C'; break;
                case 13: cout << 'D'; break;
                case 14: cout << 'E'; break;
                case 15: cout << 'F'; break;
                default: cout << rest_array[i]; break;
            }
        }
        cout << endl;


        // B
        long long size = 10000000000;
        while(B < size){
            cout << "_";
            size /= 10;
        }

        if(B < 0){
            cout << "-";
        }else{
            cout << "+";
        }

        B *= 1000;
        int b_int = (int) B;
        if(b_int % 10 >= 5){
            b_int += 5;
            b_int /= 10;
            B = (double) b_int / 100;
        }else{
            b_int /= 10;
            B = (double) b_int / 100;
        }
        cout << B;
        B *= 100;
        int bb = (int) B;
        if(bb % 100 == 0){
            cout << ".00" << endl;
        }else if(bb % 10 == 0){
            cout << 0 << endl;
        }else{
            cout << endl;
        }


        // C
        long long f = 10000000000;
        int pow_of_10 = 9;
        while(C < f){
            f /= 10;
            pow_of_10--;
        }

        cout << C << endl;
        C *= 10000000000;
        long long c_long = (long) C;
        if(c_long % 10 > 5){
            c_long += 5;
            c_long / 10;
        }else{
            c_long / 10;
        }
        C = c_long;
        C /= 1000000000;
        cout << C << "E";
        if(pow_of_10 < 0){
            cout << "-";
        }else{
            cout << "+";
        }
        if(pow_of_10 < 10 && pow_of_10 > -10){
            cout << 0;
        }
        cout << pow_of_10 << endl;
    
	}
	return 0;

}