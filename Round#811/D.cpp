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

	int q; cin >> q;
	while (q--) {
		string t; cin >> t;
		int n; cin >> n;
		vector<string> s(n);
		for(int i{0}; i < n; ++i) {
			string si; cin >> si; s[i] = si;
		}
		
		int _minf{0};
		int length{1};
		int indexf{0};
		vector<pair<int, int>> result;
		while (indexf < t.size() - 1) {
			int temp_max{0};
			int number{0};
			if(_minf != -1)
			for(int j{0}; j < length; ++j) {
				for(int k{0}; k < n; ++k) { // проверка всех строк
					if(t.substr(indexf - j, s[k].size()) == s[k]) {
						if(temp_max < indexf - j + s[k].size()) {
							temp_max = indexf - j + s[k].size(); // макс отдаление
							number = k; // индекс строки
						}
					}
				}
				if(temp_max == 0) {
					_minf = -1;
					break;
				}
			}
			length = s[number].size();
			indexf += length;
			result.push_back(make_pair(number+1, indexf - length));
			++_minf;
		}

		cout << "minf " << _minf << '\n';
		if(_minf != -1)
			for(int i{0}; i < result.size(); ++i) {
				cout << result[i].first << ' ' << result[i].second << '\n';
			}
	}

	return 0;
}

