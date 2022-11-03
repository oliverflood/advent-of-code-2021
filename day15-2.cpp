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
            nodes.push_back({x-1,y,riskLevels[x-1][y]});
        }
    }
    if (x+1 < size*5) {
        if (graph[x+1][y] + current < riskLevels[x+1][y]) {
            riskLevels[x+1][y] = graph[x+1][y] + current;
            nodes.push_back({x+1,y,riskLevels[x+1][y]});
        }
    }
    if (y-1 >= 0) {
        if (graph[x][y-1] + current < riskLevels[x][y-1]) {
            riskLevels[x][y-1] = graph[x][y-1] + current;
            nodes.push_back({x,y-1,riskLevels[x][y-1]});
        }
    }
    if (y+1 < size*5) {
        if (graph[x][y+1] + current < riskLevels[x][y+1]) {
            riskLevels[x][y+1] = graph[x][y+1] + current;
            nodes.push_back({x,y+1,riskLevels[x][y+1]});
        }
    }
}

vector<int> findLowestNode() {
    vector<int> ans = nodes[0];
    int erase = 0;
    for (int i = 0; i < nodes.size(); ++i)
    {
        if (nodes[i][2] < ans[2]) {
            ans = nodes[i];
            erase = i;
        }
    }
    nodes.erase(nodes.begin()+erase);
    return(ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<vector<int>> graph1;
    

    for (int i = 0; i < size; ++i)
    {
        string a;
        cin >> a;
        vector<int> temp;
        //vector<int> temp2;

        for (int k = 0; k < size; ++k)
        {
            temp.push_back(a.at(k)-'0');
            //temp2.push_back(999999999);

        }
        graph1.push_back(temp);
        //riskLevels.push_back(temp2);
    }

    // vector<int> skrt;
    // for (int i = 0; i < size*5; ++i)
    // {
    //     graph.push_back(skrt);
    // }

    graph.clear();
    for (int kk = 0; kk < 5; ++kk)
    {  
        for (int ii = 0; ii < size; ++ii)
        {
            vector<int> tempo;
            for (int k = 0; k < 5; ++k)
            {
                for (int i = 0; i < size; ++i)
                {
                    tempo.push_back(((graph1[ii][i]+k+kk-1)%9)+1);
                }
            }
            graph.push_back(tempo);
        }
    }
    for (int i = 0; i < size*5; ++i)
    {
        vector<int> temp2;
        for (int k = 0; k < size*5; ++k)
        {
            temp2.push_back(999999999);
        }
        riskLevels.push_back(temp2);
    }

    // for (int i = 0; i < size*5; ++i)
    // {

    //     for (int k = 0; k < size*5; ++k)
    //     {
    //         cout << graph[i][k];
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;

    
    riskLevels[0][0] = 0;
    neighborCalc(0,0);

    

    
    
    nodes.push_back({0,1,graph[0][1]});
    nodes.push_back({1,0,graph[1][0]});
    vector<int> currentNode;

    while(nodes.size() > 0) {
        currentNode = findLowestNode();
        if (currentNode[0] == size*5-1 && currentNode[1] == size*5-1) {
            break;
        }
        //nodes.pop_back();
        neighborCalc(currentNode[0], currentNode[1]);
    }

    // for (int i = 0; i < size*5; ++i)
    // {

    //     for (int k = 0; k < size*5; ++k)
    //     {
    //         cout << riskLevels[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    cout << riskLevels[size*5-1][size*5-1];
}
