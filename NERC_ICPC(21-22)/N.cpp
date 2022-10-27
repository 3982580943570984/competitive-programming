#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>

#define int long long int
#define inf 1000000007

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n1, n2, n3; cin >> n1 >> n2 >> n3;
	
		string word;
		int y1 = 0, vow1 = 0;
		int y2 = 0, vow2 = 0;
		int y3 = 0, vow3 = 0;

		for(int i{0}; i < n1; ++i) {
			cin >> word;
			for(auto ch : word) {
				if(tolower(ch) == 'y') {
					++y1;
			}
				if(tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') ++vow1;
			}
		}

		for(int i{0}; i < n2; ++i) {
			cin >> word;
			for(auto ch : word) {
				if(tolower(ch) == 'y') {
					++y2;
				}
				if(tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') ++vow2;
			}
		}

		for(int i{0}; i < n3; ++i) {
			cin >> word;
			for(auto ch : word) {
				if(tolower(ch) == 'y') {
					++y3;
				}
				if(tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') ++vow3;
			}
		}

		vow1 + y1 >= 5 && vow1 <= 5 &&
		vow2 + y2 >= 7 && vow2 <= 7 &&
		vow3 + y3 >= 5 && vow3 <= 5 ? cout << "YES" << '\n' : cout << "NO" << '\n';

	}

	return 0;
}

