#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for(int i{0}; i < t; i++){
		int r; cin >> r;
		int b; cin >> b;
		int d; cin >> d;

		string result = "NO";

		int maxx = max(r,b);
		int max_packets = min(r,b);

		if((d+1)*max_packets >= maxx) result = "YES";

		cout << result << endl;
		
	}

	system("pause");
	return 0;
}
