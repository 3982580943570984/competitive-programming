#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> teams;
	vector<pair<int, int>> result;
	vector<int> sum_of_forms(100000, 0);
	for(int i{0}; i < n; i++){
		int home_form; cin >> home_form;
		int guest_form; cin >> guest_form;
		sum_of_forms[home_form]++;
		teams.push_back(make_pair(home_form, guest_form));
		result.push_back(make_pair(n-1, n-1));
	}

	for(int i{0}; i < n; i++){
		int guest_number = teams[i].second;
		cout << result[i].first + sum_of_forms[guest_number] << ' ' << result[i].second - sum_of_forms[guest_number] << endl;
	}

	system("pause");

	return 0;
}
