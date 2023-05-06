#include <iostream>
using namespace std;

typedef long long ll;

int solve(int n) {
	ll result = 0;
	int f0 = 0, f1 = 1;
	while(f1 < n) {
		if(f1 % 2 == 0)
			result += f1;
		int aux = f0;
		f0 = f1;
		f1 += aux;
	}
	return result;
}

int main() {
	int n;
	while(cin >> n) {
		cout << solve(n) << endl;
	}
	return 0;
}
