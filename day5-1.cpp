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

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<vector<int>> lines;
    int inputSize = 500;

    for (int i = 0; i < inputSize; ++i)
    {
        string a, b, c;
        cin >> a >> b >> c;
        vector<string> a2 = split(a,",");
        vector<string> c2 = split(c,",");
        vector<int> temp;
        lines.push_back(temp);
        lines[i].push_back(stoi(a2[0]));
        lines[i].push_back(stoi(a2[1]));
        lines[i].push_back(stoi(c2[0]));
        lines[i].push_back(stoi(c2[1]));
    }

    vector<vector<int>> normLines;
    for (int i = 0; i < lines.size(); ++i)
    {
        if (lines[i][0] == lines[i][2] || lines[i][1] == lines[i][3]) {
            normLines.push_back(lines[i]);
        }
    }

    int bigNum = 0;
    for (int i = 0; i < normLines.size(); ++i)
    {
        bigNum += abs(normLines[i][0]-normLines[i][1]) + abs(normLines[i][2]-normLines[i][3]);
    }
    // cout << "bigNum: " << bigNum << endl;
    // cout << "normLinesSize: " << normLines.size() << endl;
    // cout << "normLinesSize^2: " << pow(normLines.size(),2);

    vector<int> point;
    for (int i = 0; i < 1000; ++i)
    {
        point.push_back(0);
    }
    vector<vector<int>> points;
    for (int i = 0; i < 1000; ++i)
    {
        points.push_back(point);
    }

    for (int i = 0; i < normLines.size(); ++i)
    {
        // if they're horizontal
        if(normLines[i][1] == normLines[i][3]) {
            for (int k = min(normLines[i][0],normLines[i][2]); k <= max(normLines[i][0],normLines[i][2]); ++k)
            {
                points[normLines[i][1]][k] += 1;
            }
        }

        // if they're vertical
        if(normLines[i][0] == normLines[i][2]) {
            for (int k = min(normLines[i][1],normLines[i][3]); k <= max(normLines[i][1],normLines[i][3]); ++k)
            {
                points[k][normLines[i][0]] += 1;//switched
            }
        }
    }

    //diagonal lines

    vector<vector<int>> diagonals;
    for (int i = 0; i < lines.size(); ++i)
    {
        if (!count(normLines.begin(), normLines.end(), lines[i])) {
            diagonals.push_back(lines[i]);
        }
    }
    cout << diagonals[0][0];

    vector<vector<int>> diagonalsLR;
    vector<vector<int>> diagonalsRL;

    for (int i = 0; i < diagonals.size(); ++i)
    {
        if ((diagonals[i][0] < diagonals[i][2] && diagonals[i][1] < diagonals[i][3]) || (diagonals[i][0] > diagonals[i][2] && diagonals[i][1] > diagonals[i][3])) {
            diagonalsLR.push_back(diagonals[i]);
        }
        else {
            diagonalsRL.push_back(diagonals[i]);
        }
    }

    //something wrong
    for (int i = 0; i < diagonalsLR.size(); ++i)
    {
        int minY = min(diagonalsLR[i][1], diagonalsLR[i][3]);
        int minX = min(diagonalsLR[i][0], diagonalsLR[i][2]);
        for (int k = 0; k < abs(diagonalsLR[i][0] - diagonalsLR[i][2])+1; ++k)
        {
            points[minY+k][minX+k] += 1;
        }
    }

    for (int i = 0; i < diagonalsRL.size(); ++i)
    {
        int minY;
        int minX;
        if (diagonalsRL[i][0] < diagonalsRL[i][2]) {
            minY = diagonalsRL[i][1];
            minX = diagonalsRL[i][0];
        }
        else {
            minY = diagonalsRL[i][3];
            minX = diagonalsRL[i][2];
        }
        for (int k = 0; k < abs(diagonalsRL[i][0] - diagonalsRL[i][2])+1; ++k)
        {
            points[minY-k][minX+k] += 1;
        }
    }


    int ans = 0;
    for (int i = 0; i < points.size(); ++i)
    {
        for (int k = 0; k < points.size(); ++k) {
            if (points[i][k] > 1) {
                ans++;
            }
        }
    }
    cout << "final ans: " << ans;

}

// 106110 too high
// not 106405