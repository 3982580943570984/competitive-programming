#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q; cin >> q;
	while(q--){
		string result = "NO";
		int n_rubles; cin >> n_rubles;
		int one_rubles; cin >> one_rubles;
		int n; cin >> n;
		int sum; cin >> sum;

		if(n_rubles * n + one_rubles >= sum){
			int n_amount = sum / n; // Кол-во вмещаемых n_rubles
			if(n_amount <= n_rubles){
				if(sum - n * n_amount <= one_rubles) result = "YES";
			}else{
				if(sum - n * n_rubles <= one_rubles) result = "YES";
			}
		}

		cout << result << endl;

	}

	return 0;
}
