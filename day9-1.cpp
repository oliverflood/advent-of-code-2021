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

int findIndex(vector<int> v, int num) {
    return(distance(v.begin(), find(v.begin(), v.end(), num)));
}

void sortString(string &str)
{
   sort(str.begin(), str.end());
}

bool contains(string a, string b) {
    for (int i = 0; i < b.length(); ++i)
    {
        if (a.find(b.substr(i, 1))==std::string::npos) {
            return false;
        }
    }
    return true;
}

bool equivalent(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }
    for (int i = 0; i < b.length(); ++i)
    {
        if (a.find(b.substr(i, 1))==std::string::npos) {
            return false;
        }
    }
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int inputSize = 100;
    vector<string> input;

    string b = "";
    for (int i = 0; i < 102; ++i)
    {
        b += "9";
    }

    input.push_back(b);
    for (int i = 0; i < 100; ++i)
    {
        string a;
        cin >> a;
        input.push_back("9"+a+"9");
    }
    input.push_back(b);

    // for (int i = 0; i < input.size(); ++i)
    // {
    //     cout << input[i] << endl;
    // }
    cout << "hi";

    int total = 0;
    for (int i = 1; i < 101; ++i)
    {
        for (int k = 1; k < 101; ++k)
        {
            //cout << input[i].at(k);
            if ((input[i].at(k) < input[i+1].at(k)) &&(input[i].at(k) < input[i-1].at(k)) &&(input[i].at(k) < input[i].at(k-1))&&(input[i].at(k) < input[i].at(k+1))) {
                total += input[i].at(k) - '0'+1;
                //cout << i << " " << k << "  " << input[i].at(k) << endl;
            }
        }
        //cout << endl;
    }
    cout << endl << total;
    //cout << "hi";


    //cout << int('1'>'0');
}
