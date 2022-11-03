#include<bits/stdc++.h>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace	std;

vector<string> split(string s, string delimiter) {
	vector<string> v;
	int pos1 = 0;

	for (int i = 0; i < count(s.begin(), s.end(), delimiter.at(0))+1; ++i)
	{
		
		int pos2 = s.find(delimiter, pos1);
		v.push_back(s.substr(pos1, pos2-pos1));
		pos1 = pos2+1;
	}

	return(v);
}

int findIndex(vector<int> v, int num) {
	return(distance(v.begin(), find(v.begin(), v.end(), num)));
}

int findLowest(vector<int> v) {
	int ans = v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] < ans) {
			ans = v[i];
		}
	}
	return(ans);
}

int findHighest(vector<int> v) {
	int ans = v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] > ans) {
			ans = v[i];
		}
	}
	return(ans);
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string data;
	cin >> data;

	vector<string> v = split(data, ",");
	vector<int> bingos;
	for (int i = 0; i < v.size(); ++i)
	{
		bingos.push_back(stoi(v[i]));
	}

	vector<vector<int>> boards;

	for (int i = 0; i < 100; ++i)
	{
		vector<int> board;
		for (int k = 0; k < 25; ++k)
		{
			int a;
			cin >> a;
			board.push_back(a);
		}
		boards.push_back(board);
	}



	vector<vector<int>> Hstrips;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			vector<int> strip;
			for (int k = 0; k < 5; ++k)
			{
				strip.push_back(findIndex(bingos, boards[i][k+(5*j)]));
			}
			Hstrips.push_back(strip);
		}
	}

	vector<int> HstripsAnswers;
	for (int i = 0; i < Hstrips.size(); ++i)
	{
		HstripsAnswers.push_back(findHighest(Hstrips[i]));
	}
	//cout << findIndex(HstripsAnswers, findLowest(HstripsAnswers)) << endl;


	vector<vector<int>> Vstrips;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			vector<int> strip;
			for (int k = 0; k < 5; ++k)
			{
				strip.push_back(findIndex(bingos, boards[i][j+(5*k)]));
			}
			Vstrips.push_back(strip);
		}
	}
	vector<int> VstripsAnswers;
	for (int i = 0; i < Vstrips.size(); ++i)
	{
		VstripsAnswers.push_back(findHighest(Vstrips[i]));
	}
	int lastNumPlayed;




	int winner;
	if (findLowest(HstripsAnswers) < findLowest(VstripsAnswers)) {
		winner = findIndex(HstripsAnswers, findLowest(HstripsAnswers));
		lastNumPlayed = bingos[HstripsAnswers[winner]];
	}
	else {
		winner = findIndex(VstripsAnswers, findLowest(VstripsAnswers));
		lastNumPlayed = bingos[VstripsAnswers[winner]];

	}
	winner = (winner/int(5));


	//cout << lastNumPlayed;

	int ans = 0;
	for (int i = 0; i < boards[winner].size(); ++i)
	{
		//cout << boards[winner][i] << " ";
		if (findIndex(bingos, boards[winner][i]) > findIndex(bingos, lastNumPlayed)) {
			cout << boards[winner][i] << " ";
			ans += boards[winner][i];
		}
	}
	ans *= lastNumPlayed;
	cout << "board: " << winner << "   lastNumPlayed: " << lastNumPlayed;
	cout << endl << endl << "ans: " << ans;


//assuming I have actually found winning board


}

// 89145 too high
// 7849686 too high

/* line 273
81 23  6 14 26
86 42 82 95 85
77 52 38  2 33
69 98 54 37  4
78 39  3 75 80
*/