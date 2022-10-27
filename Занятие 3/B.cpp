#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <string>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int result{0};
		int n; cin >> n;
		int candy_min = 1000000000, orange_min = 1000000000;

		vector<int> candies;
		for(int j = 0; j < n; j++){
			int candy_value; cin >> candy_value;
			if(candy_min > candy_value) candy_min = candy_value;
			candies.push_back(candy_value);
		}

		vector<int> oranges;
		for(int j = 0; j < n; j++){
			int orange_value; cin >> orange_value;
			if(orange_min > orange_value) orange_min = orange_value;
			oranges.push_back(orange_value);
		}

 		for(int j{0}; j < n; j++){
			int min_twice = min(candies[j] - candy_min, oranges[j] - orange_min);
			candies[j] -= min_twice;
			oranges[j] -= min_twice;
			result += min_twice + candies[j] - candy_min + oranges[j] - orange_min;
		}

		cout << result << endl;

	}

	return 0;
}
