#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> boxes(n);
	for(int i{0}; i < n; i++){ cin >> boxes[i];	}

	int result{0};
	while(boxes.size()){
		set<int> temp_set(boxes.begin(), boxes.end());
		result++;
		for(auto value : temp_set){ boxes.erase(find(boxes.begin(), boxes.end(), value)); }
	}

	cout << result << endl;

	system("pause");

	return 0;
}
