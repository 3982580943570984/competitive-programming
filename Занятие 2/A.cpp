#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define int long long int

using namespace std;

int32_t main(){

	int n; cin >> n;
	vector<int> prices(n);
	for(int i = 0; i < n; i++) { cin >> prices[i]; }

	vector<int> max_values(n+1);
	max_values[0] = 0;
	for(int i = 1; i < n+1; i++){
		max_values[i] = prices[i-1];
		for(int j = 0; j < i; j++){
			if(max_values[i] < max_values[i-j] + max_values[j]) max_values[i] = max_values[i-j] + max_values[j]; 
		}
	}

	cout << *(max_element(max_values.begin(), max_values.end())) << endl;

	system("pause");

	return 0;
}
