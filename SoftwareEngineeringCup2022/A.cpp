#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int price1, price2, price3, price4, price5;
	cin >> price1 >> price2 >> price3 >> price4 >> price5;
	int amount1 = (n + 15) / 16 * price1;
	int amount2 = (n + 7) / 8 * price2;
	int amount3 = (n + 3) / 4 * price3;
	int amount4 = (n + 1) / 2 * price4;
	int amount5 = n * price5;

	cout << min({amount1, amount2, amount3, amount4, amount5});

	return 0;
}
