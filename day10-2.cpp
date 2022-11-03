#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int findIndex(vector<int> v, int num) {
    return(distance(v.begin(), find(v.begin(), v.end(), num)));
}

long long calcScore(vector<char> stack) {
    map<char, int> table {{'(',1},{'[',2},{'{',3},{'<',4}};
    long long score = 0;
    reverse(stack.begin(), stack.end());
    for (int i = 0; i < stack.size(); ++i)
    {
        score *= 5;
        score += table[stack[i]];
    }
    return score;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int inputSize = 94;
    vector<long long> answers;
    
    map<char, char> pair {{')','('},{']','['},{'}','{'},{'>','<'}};

    for (int k = 0; k < inputSize; ++k)
    {
    	string s;
    	cin >> s;
    	vector<char> stack;

    	for (int i = 0; i < s.length(); ++i)
    	{
    		char in = s.at(i);

    		if (in == '[' || in == '{' || in == '(' || in == '<') {
    			stack.push_back(in);
    		}
    		if (in == ']' || in == '}' || in == ')' || in == '>') {
    			if (stack[stack.size()-1] != pair[in]) {
    				break;
    			}
    			else {
    				stack.pop_back();
    			}
    		}

            if (i == s.length()-1) {
                answers.push_back(calcScore(stack));
            }
    	}
    }
  
    sort(answers.begin(), answers.end());
    for (int i = 0; i < answers.size(); ++i)
    {
        cout << answers[i] << endl;
    }

    cout << endl << "answer: " << answers[(answers.size()-1)/2] << endl;

}
// 1483081 TOO LOW
