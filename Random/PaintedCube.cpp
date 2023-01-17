#include <iostream>

using namespace std;

int main () {
	int n, f; cin >> n >> f;
	if (f == 0) {
		cout << (n - 2) * (n - 2) * (n - 2) << endl;
	}
	if (f == 1) {
		cout << 6 * (n - 2) * (n - 2) << endl;
	}
	if (f == 2) {
		cout << 12 * (n - 2) << endl;
	}
	if (f == 3) {
		cout << 8 << endl;
	}
}
