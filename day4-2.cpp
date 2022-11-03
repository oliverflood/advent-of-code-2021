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

	for (int i = 0; i < boards.size(); ++i)
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
	for (int i = 0; i < boards.size(); ++i)
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
	vector<int> HstripsAnswersPerBoards;
	for (int i = 0; i < HstripsAnswers.size()/5; ++i)
	{
		vector<int> HstripsAnswersPerBoard;
		for (int k = 0; k < 5; ++k)
		{
			HstripsAnswersPerBoard.push_back(HstripsAnswers[(i*5)+k]);
		}
		HstripsAnswersPerBoards.push_back(findLowest(HstripsAnswersPerBoard));
	}
	//cout << findIndex(HstripsAnswers, findLowest(HstripsAnswers)) << endl;
	cout << "Hstrip winner: " << findHighest(HstripsAnswersPerBoards) << endl;
	cout << "Hstrip winner index: " << findIndex(HstripsAnswersPerBoards, findHighest(HstripsAnswersPerBoards)) << endl;


	vector<vector<int>> Vstrips;
	for (int i = 0; i < boards.size(); ++i)
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
	vector<int> VstripsAnswersPerBoards;
	for (int i = 0; i < VstripsAnswers.size()/5; ++i)
	{
		vector<int> VstripsAnswersPerBoard;
		for (int k = 0; k < 5; ++k)
		{
			VstripsAnswersPerBoard.push_back(VstripsAnswers[(i*5)+k]);
		}
		VstripsAnswersPerBoards.push_back(findLowest(VstripsAnswersPerBoard));
	}
	cout << "Vstrip winner: " << findHighest(VstripsAnswersPerBoards) << endl;
	cout << "Vstrip winner index: " << findIndex(VstripsAnswersPerBoards, findHighest(VstripsAnswersPerBoards)) << endl;

	vector<int> both;
	for (int i = 0; i < VstripsAnswersPerBoards.size(); ++i)
	{
		if (VstripsAnswersPerBoards[i] < HstripsAnswersPerBoards[i]) {
			both.push_back(VstripsAnswersPerBoards[i]);
		}
		else {
			both.push_back(HstripsAnswersPerBoards[i]);
		}
	}


	int winner;
	// if (findHighest(HstripsAnswersPerBoards) > findHighest(VstripsAnswersPerBoards)) {
	// 	winner = findIndex(HstripsAnswersPerBoards, findHighest(HstripsAnswersPerBoards));//changed to highest
	// 	lastNumPlayed = bingos[HstripsAnswersPerBoards[winner]];
	// }
	// else {
	// 	winner = findIndex(VstripsAnswersPerBoards, findHighest(VstripsAnswersPerBoards));//^^^^
	// 	lastNumPlayed = bingos[VstripsAnswersPerBoards[winner]];

	// }
	//winner = (winner/int(5));
	winner = findIndex(both, findHighest(both));
	lastNumPlayed = bingos[HstripsAnswersPerBoards[winner]];

	cout << endl << "lastNumPlayed: " << lastNumPlayed << endl;
	cout << endl << "winner: " << winner << endl;

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
	cout << endl << endl << "ans: " << ans;
	cout << endl << boards[winner][0];


//assuming I have actually found winning board
}

// 16356 too low
// 63570 too high

//winner 43