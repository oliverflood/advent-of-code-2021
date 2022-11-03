#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long c = 0;

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

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    vector<string> input;
    vector<int> fish;

    cin >> s;
    input = split(s, ",");
    for (int i = 0; i < input.size(); ++i)
    {
        fish.push_back(stoi(input[i]));
    }

    int days = 80;
    for (int i = 0; i < days; ++i)
    {
        int newFish = 0;
        for (int k = 0; k < fish.size(); ++k)
        {
            if (fish[k] > 0) {
                fish[k] -= 1;
            }
            else if (fish[k] == 0) {
                fish[k] = 6;
                newFish++;
            }

        }
        for (int i = 0; i < newFish; ++i)
        {
            fish.push_back(8);
        }
    }

    cout << fish.size();
}
