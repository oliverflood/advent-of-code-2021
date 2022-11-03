#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> riskLevels;
vector<vector<int>> nodes;
int size = 100;

void neighborCalc(int x, int y) {
    int current = riskLevels[x][y];
    if (x-1 >= 0) {
        if (graph[x-1][y] + current < riskLevels[x-1][y]) {
            riskLevels[x-1][y] = graph[x-1][y] + current;
            nodes.push_back({x-1,y});
        }
    }
    if (x+1 < size) {
        if (graph[x+1][y] + current < riskLevels[x+1][y]) {
            riskLevels[x+1][y] = graph[x+1][y] + current;
            nodes.push_back({x+1,y});
        }
    }
    if (y-1 >= 0) {
        if (graph[x][y-1] + current < riskLevels[x][y-1]) {
            riskLevels[x][y-1] = graph[x][y-1] + current;
            nodes.push_back({x,y-1});
        }
    }
    if (y+1 < size) {
        if (graph[x][y+1] + current < riskLevels[x][y+1]) {
            riskLevels[x][y+1] = graph[x][y+1] + current;
            nodes.push_back({x,y+1});
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    

    for (int i = 0; i < size; ++i)
    {
        string a;
        cin >> a;
        vector<int> temp;
        vector<int> temp2;

        for (int k = 0; k < size; ++k)
        {
            temp.push_back(a.at(k)-'0');
            temp2.push_back(999999999);

        }
        graph.push_back(temp);
        riskLevels.push_back(temp2);
    }

    
    riskLevels[0][0] = 0;
    neighborCalc(0,0);

    

    
    
    nodes.push_back({0,1});
    nodes.push_back({1,0});
    vector<int> currentNode;
    while(nodes.size() > 0) {
        currentNode = nodes[nodes.size()-1];
        nodes.pop_back();
        neighborCalc(currentNode[0], currentNode[1]);
    }
    // for (int i = 0; i < size; ++i)
    // {

    //     for (int k = 0; k < size; ++k)
    //     {
    //         cout << graph[i][k];
    //     }
    //     cout << endl;
    // }

    // cout << endl << endl;

    // for (int i = 0; i < size; ++i)
    // {

    //     for (int k = 0; k < size; ++k)
    //     {
    //         cout << riskLevels[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    cout << riskLevels[size-1][size-1];
}
