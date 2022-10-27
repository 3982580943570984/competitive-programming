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
	vector<int> possible_turns = {0};
	for(int i{0}; i < n; i++){
		int turn; cin >> turn;
		vector<int> temp;
		for(auto _turn : possible_turns){
			temp.push_back(_turn + turn);
			temp.push_back(_turn - turn);
		}
		possible_turns = temp;
	}

	string result = "NO";

	for(auto turn : possible_turns)
		if (turn % 360 == 0) {
			result = "YES";
			break;
		}
	cout << result << '\n';

	return 0;
}
