#include <iostream>
using namespace std;


//Given an integer n, find the  square root of an integer up to p places of decimal

double square_root(int n, int p){

	int s = 0, e = n-1;

	int integer_part = 0;

	while(s <= e){

		int mid = s + (e-s)/2;
		if(mid*mid == n){
			integer_part = mid;
			break;
		}
		else if(mid*mid < n){
			integer_part = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}

	double ans = double(integer_part);

	double inc = 0.1;
	for(int i = 0; i < p; i++){


		while(ans*ans <= n){
			ans += inc;
		}
		ans = ans - inc;
		inc = inc/10;
	}

	return ans;

}
int main() {
	// your code goes here

	cout << square_root(25,3) << endl;
	cout << square_root(24,3) << endl;
	cout << square_root(12,3) << endl;
	cout << square_root(10,3) << endl;
	cout << square_root(1,3) << endl;
	cout << square_root(2,3) << endl;

	return 0;
}
