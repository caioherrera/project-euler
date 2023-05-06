#include <iostream>
#include <set>
#include <queue>
#include <tuple>
using namespace std;

typedef long long ll;

// product, factor1, factor2
typedef tuple<int, int, int> mult;

bool isPalindrome(int n) {
	int aux = n;
	int res = 0;
	while(aux > 0) {
		res = res * 10 + (aux % 10);
		aux /= 10;
	}
	return res == n;
}

int maxValueWithNDigits(int n) {
	int result = 0;
	while(n--) {
		result = result * 10 + 9;
	}
	return result;
}

int solve(int n) {

	set<int> visited;
	priority_queue<mult> pq;
	int aux = maxValueWithNDigits(n);

	pq.push({aux * aux, aux, aux});
	visited.insert(aux * aux);

	while(!pq.empty()) {

		mult curr = pq.top();
		pq.pop();
		int res = get<0>(curr), f1 = get<1>(curr), f2 = get<2>(curr);

		visited.insert(res);

		if(isPalindrome(res)) {
			cout << f1 << " * " << f2 << " = " << res << endl;
			return res;
		}

		int next = (f1 - 1) * f2;
		if(visited.find(next) == visited.end()) {
			pq.push({next, f1 - 1, f2});
			visited.insert(next);
		}
		
		next = f1 * (f2 - 1);
		if(visited.find(next) == visited.end()) {
			pq.push({next, f1, f2 - 1});
			visited.insert(next);
		}
	}
	return -1;
}

int main() {
	ll n;
	while(cin >> n) {
		cout << solve(n) << endl;
	}
	return 0;
}
