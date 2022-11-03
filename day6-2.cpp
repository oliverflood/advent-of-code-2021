#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

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

long long sum(vector<long long> list) {
    long long c = 0;
    for (int i = 0; i < list.size(); ++i)
    {
        c += list[i];
    }
    return(c);
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

    vector<long long> days;
    for (int i = 0; i < 9; ++i)
    {
        days.push_back(0);
    }

    for (int i = 0; i < fish.size(); ++i)
    {
        days[fish[i]] += 1;
    }

    int dayCount = 256;
    for (int i = 0; i < dayCount; ++i)
    {
        long long temp = days[0];
        for (int k = 0; k < days.size()-1; ++k)
        {
            days[k] = days[k+1];
        }
        days[6] += temp;
        days[8] = temp;
    }

    cout << sum(days);
}
