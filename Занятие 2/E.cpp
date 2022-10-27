#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int students, questions;
	cin >> students >> questions;

	vector<vector<int>> scores(questions, vector<int> (5, 0));

	for(int i = 0; i < students; i++){
		string answers;
		cin >> answers;
		int m_ans = 0;
		for(auto answer : answers){
			if(answer == 'A') scores[m_ans][0] += 1;
			if(answer == 'B') scores[m_ans][1] += 1;
			if(answer == 'C') scores[m_ans][2] += 1;
			if(answer == 'D') scores[m_ans][3] += 1;
			if(answer == 'E') scores[m_ans][4] += 1;
			m_ans++;
		}
	}

	vector<int> points(questions);
	for(int i = 0; i < questions; i++){ cin >> points[i]; }

	int result = 0;
	int place = 0;
	for(auto question : scores){
		int dist = *(max_element(question.begin(), question.end()));
		result += dist * points[place++];
	}

	cout << result << endl;

	return 0;
}
