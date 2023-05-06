#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll solve(ll n) {
	ll result = 1;

	ll upperBound = min(n - 1, (ll)sqrt(n) + 1);

	while(n % 2 == 0) {
		n /= 2;
		result = 2;
	}

	for(ll i = 3; i <= upperBound; i += 2) {
		while(n % i == 0) {
			result = max(result, i);
			n /= i;
		}
	}

	return result;
}

int main() {
	ll n;
	while(cin >> n) {
		cout << solve(n) << endl;
	}
	return 0;
}
