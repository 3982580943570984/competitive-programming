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

	int t; cin >> t;
	for(int i{0}; i < t; i++) {
		int n; cin >> n;
		vector<int> result(n);
		vector<int> r_position;
		int block_r{0};
		for(int j{0}; j < n; j++) { 
			int block; cin >> block;
			result[block - 1] += 1;
			if(!block_r) block_r = block;
			if(block == block_r) r_position.push_back(j);
		}

		int maxx{1};
		int current{1};
		for(int j{1}; j < r_position.size(); j++) {
			int length = r_position[j] - r_position[j-1] - 1;
			if(length == 1 && r_position[j+1] == r_position[j] + 1 && maxx > 1) {
				current += 1;
				j++;
				if(maxx < current) maxx = current;
				continue;
			}

			if(length % 2) {
				current = 1;
			}else {
				current += 1;
				if(maxx < current) maxx = current;
			}
		}

		result[block_r - 1] = maxx;

		for(int j{0}; j < result.size(); j++) {
			cout << result[j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
