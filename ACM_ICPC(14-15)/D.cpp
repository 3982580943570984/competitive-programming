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
#define inf 1000000007

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum, alone_one_bed, alone_two_bed;
	cin >> sum >> alone_one_bed >> alone_two_bed;
	int n; cin >> n;
	vector<pair<int, int>> friends(n);
	for(int i{0}; i < n; ++i) {
		int pay_sum, advantage; cin >> pay_sum >> advantage;
		friends[i] = make_pair(pay_sum, advantage);
	}

	int m; cin >> m;
	int max_advantage{0};
	string result{"Forget about apartments. Live in the dormitory."};
	for(int i{0}; i < m; ++i) {
		int numb_bed, advantage;
		long double rent;
		cin >> numb_bed >> rent >> advantage;
		if(numb_bed == 1) {
			if(rent <= sum && max_advantage <= alone_one_bed + advantage) {
				max_advantage = alone_one_bed + advantage;
				result = "You should rent the apartment #" + to_string(i + 1) + " alone.";
			}
		}

		if(numb_bed == 2) {
			if(rent <= sum && max_advantage <= alone_two_bed + advantage) {
				max_advantage = alone_two_bed + advantage;
				result = "You should rent the apartment #" + to_string(i + 1) + " alone.";
			}

			int j{0};
			for(const auto& _friend : friends) {
				++j;
				if(_friend.first >= rent/2 && sum >= rent/2) {
					if(max_advantage <= _friend.second + advantage) {
						max_advantage = _friend.second + advantage;
						result = "You should rent the apartment #" + to_string(i + 1) + " with the friend #" + to_string(j) + ".";
					}
				}
			}
		}
	}

	cout << result << '\n';

	return 0;
}

