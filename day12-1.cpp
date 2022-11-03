#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ans = 0;

bool isUpper(string s) {
    bool t = true;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s.at(i) != toupper(s.at(i))) {
            t = false;
        }
    }
    return(t);
}

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

void path(vector<vector<string>> v, vector<string> visited, string pos) {
    visited.push_back(pos);
    if (pos == "end") {
        ans++;
        for (int i = 0; i < visited.size(); ++i)
        {
            cout << visited[i] << " ";
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i][0] == pos && v[i][1] != "start") { 
                if (find(visited.begin(), visited.end(), v[i][1]) == visited.end()) {
                    // if its not been visited before
                    //cout << v[i][0] << " " << v[i][1] << endl;
                    path(v, visited, v[i][1]);
                }
                else if (isUpper(v[i][1])) {
                    // if its uppercase
                    //cout << v[i][0] << " " << v[i][1] << endl;
                    path(v, visited, v[i][1]);
                }
            }
            if (v[i][1] == pos && v[i][0] != "start") {
                if (find(visited.begin(), visited.end(), v[i][0]) == visited.end()) {
                    //cout << v[i][0] << " " << v[i][1] << endl;
                    path(v, visited, v[i][0]);
                }
                else if (isUpper(v[i][0])) {
                    //cout << v[i][0] << " " << v[i][1] << endl;
                    path(v, visited, v[i][0]);
                }
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int size = 24;
    vector<vector<string>> v;

    for (int i = 0; i < size; ++i)
    {
        string a;
        cin >> a;
        v.push_back(split(a, "-"));
    }

    // for (int i = 0; i < v.size(); ++i)
    // {
    //     for (int k = 0; k < 2; ++k)
    //     {
    //         cout << v[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    vector<string> visited;
    //visited.push_back("start");
    path(v, visited, "start");


    cout << endl << "ans: " << ans << endl;
}
