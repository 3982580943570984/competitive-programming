#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <map>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> prices(n);
	for(int i{0}; i < n; i++){ cin >> prices[i]; }

	vector<int> front_color(n);
	for(int i{0}; i < n; i++){ cin >> front_color[i]; }

	vector<int> back_color(n);
	multimap<int, pair<int, int>> t_shirts;
	for(int i{0}; i < n; i++){
		cin >> back_color[i];
		t_shirts.insert(pair<int, pair<int, int>>(prices[i], make_pair(front_color[i], back_color[i])));
	}

	int m; cin >> m;
	for(int i{0}; i < m; i++){
		int fav_color; cin >> fav_color;
		int price{-1};
		for(auto t_shirt : t_shirts){
			if(fav_color == t_shirt.second.first || fav_color == t_shirt.second.second){
				price = t_shirt.first;
				t_shirts.erase(t_shirt.first);
				break;
			}
		}
		cout << price << ' ';
	}

	return 0;
}
