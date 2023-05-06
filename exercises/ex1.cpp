#include <iostream>
using namespace std;

typedef long long ll;

int solve(int n) {
	int result = 0;
	for(int i = 1; i < n; i++) {
		if(i % 3 == 0 || i % 5 == 0)
			result += i;
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
