#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<string> split2(string s, string delimiter) {
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

vector<int> split(string s, string delimiter) {
    vector<int> v;
    int pos1 = 0;

    for (int i = 0; i < count(s.begin(), s.end(), delimiter.at(0))+1; ++i)
    {
        
        int pos2 = s.find(delimiter, pos1);
        v.push_back(stoi(s.substr(pos1, pos2-pos1)));
        pos1 = pos2+1;
    }

    return(v);
}

vector<vector<int>> fold(vector<vector<int>> points, int line, bool isY) {
    for (int i = 0; i < points.size(); ++i)
    {
        if (points[i][isY] > line) {
            points[i][isY] = line-(points[i][isY]-line);
        }
    }
    return(points);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int size = 782;
    vector<vector<int>> points;

    for (int i = 0; i < size; ++i)
    {
        string a;
        cin >> a;
        points.push_back(split(a, ","));
    }

    for (int i = 0; i < 12; ++i)
    {
        string a, b, c;
        cin >> a >> b >> c;
        vector<string> temp = split2(c, "=");
        if (temp[0] == "y") {
            points = fold(points, stoi(temp[1]), true);
        }
        else {
            points = fold(points, stoi(temp[1]), false);
        }
    }

    set<vector<int>> s(points.begin(), points.end());
    //cout << s.size();
    vector<vector<int>> points2(s.begin(), s.end());

    for (int i = 0; i < points2.size(); ++i)
    {
        //cout << points2[i][0] << " " << points2[i][1] << endl;
    }
    for (int i = 0; i <= 5; ++i)
    {
        for (int k = 0; k <= 38; ++k)
        {
            vector<int> t;
            t.push_back(k);
            t.push_back(i);
            if (find(points2.begin(), points2.end(), t) != points2.end()) {
                cout << "##";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }

}
