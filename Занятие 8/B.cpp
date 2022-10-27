#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int

// greatest common divisor
int gcd (int a, int b) { return b ? gcd (b, a % b) : a; }

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int strength, n;
	cin >> strength >> n;

	vector<pair<int, int>> dragons;
	for(int i = 0; i < n; i++){
		int drag_strength, bonus;
		cin >> drag_strength >> bonus;

		if(strength > drag_strength) strength += bonus;
		else dragons.push_back(make_pair(drag_strength, bonus));
	}

	sort(dragons.begin(), dragons.end());

	int count{0};
	for(auto dragon : dragons){
		if(dragon.first < strength) {
			strength += dragon.second;
			count++;
		}else{
			break;
		}
	}

	if(count != dragons.size()) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}
