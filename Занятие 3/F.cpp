#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <string>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	map<string, int> names;
	for(int i{0}; i < n; i++){
		string name; cin >> name;
		pair<map<string,int>::iterator,bool> iter = names.insert(pair<string, int>(name, 1));
		if(!iter.second){
			string in = name + to_string(iter.first->second);
			names.insert(pair<string, int>(name + to_string(iter.first->second), iter.first->second++));
			cout << in << endl; 
		}else{
			cout << "OK" << endl;
		}
	}

	return 0;
}
