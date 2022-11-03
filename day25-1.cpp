#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); ++i)
    {
        for (int k = 0; k < v[i].size(); ++k)
        {
            if (v[i][k] == 0) {
                cout << ".";
            }
            else if (v[i][k]==1) {
                cout << ">";
            }
            else {
                cout << "v";
            }
            //cout << v[i][k];
        }
        cout << endl;
    }
}

vector<vector<int>> step(vector<vector<int>> graph) {
    vector<vector<int>> graph2 = graph;
    //cout << graph.size();
    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph[k].size(); ++i)
        {
            // cout << "hi";
            if (graph[k][i] == 1 && graph[k][(i+1)%graph[0].size()] == 0) {
                // cout << "i: " << (i+1)%graph.size() << endl;
                graph2[k][(i+1)%graph[0].size()] = 1;
                graph2[k][i] = 0;
            }
        }
    }
    graph = graph2;
    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph[k].size(); ++i)
        {
            if (graph[k][i] == 2 && graph[(k+1)%graph.size()][i] == 0) {
                graph2[(k+1)%graph.size()][i] = 2;
                graph2[k][i] = 0;
            }
        }
    }
    return(graph2);
}

vector<vector<int>> getInput(int y) {
    vector<vector<int>> graph;
    for (int i = 0; i < y; ++i)
    {
        string s;
        cin >> s;
        vector<int> temp;
        for (int k = 0; k < s.size(); ++k)
        {
            if (s.at(k) == '.') {
                temp.push_back(0);
            }
            else {
                temp.push_back(s.at(k)=='>'?1:2);
            }
        }
        graph.push_back(temp);
    }
    return(graph);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<vector<int>> graph = getInput(137);
    vector<vector<int>> graph2 = graph;

    // cout << "Initial state: " << endl;
    // print(graph);
    // cout << endl;

    for (int i = 1; i < 10000; ++i)
    {
        //cout << "step: " << i << endl;
        //print(graph);
        graph2 = step(graph);
        if (graph == graph2) {
            cout << i << endl;
            break;
        }
        graph = graph2;
        //cout << endl;
    }
    // while(graph != graph2) {
    //     graph2 = graph;
    //     graph = step(graph);
    //     c++;
    // }

    //print(graph);

}
