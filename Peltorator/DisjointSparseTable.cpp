#include <cstdint>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits.h>
#include <limits>
#include <numeric>
#include <stdint.h>
#include <type_traits>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int
#define all(x) (x).begin(), x.end()

const int mod = (int)1e9 + 7;

using namespace std;

struct SparseTable
{
};

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &elem : a)
		cin >> elem;

	for (auto &&elem : a)
	{
		std::cin >> elem;
		std::cout << elem << std::endl;
	}

	int q;
	cin >> q;

	return 0;
}
