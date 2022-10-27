#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input; cin >> input;
	string result = "";
	for(int i = 0; i < input.size(); i++){
		if(result.back() != input[i]) result += input[i];
		else result.pop_back();
	}

	cout << result << endl;

	return 0;
}
