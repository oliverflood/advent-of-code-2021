#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int findIndex(vector<int> v, int num) {
    return(distance(v.begin(), find(v.begin(), v.end(), num)));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int inputSize = 94;
    int answer = 0;
    map<char, int> table {{')',3},{']',57},{'}',1197},{'>',25137}};
    map<char, char> pair {{')','('},{']','['},{'}','{'},{'>','<'}};


    for (int k = 0; k < inputSize; ++k)
    {
    	string s;
    	cin >> s;
    	vector<char> stack;

    	for (int i = 0; i < s.size(); ++i)
    	{
    		char in = s.at(i);

    		if (in == '[' || in == '{' || in == '(' || in == '<') {
    			stack.push_back(in);
    		}
    		else if (in == ']' || in == '}' || in == ')' || in == '>') {
    			if (stack[stack.size()-1] != pair[in]) {
    				answer += table[in];
    				break;
    			}
    			else {
    				stack.pop_back();
    			}
    		}
    	}
    }

    cout << "answer: " << answer;
}