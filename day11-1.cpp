#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> flashed;
long long flashCount = 0;

void flash(int x, int y) {
    flashCount++;
    for (int k = -1+y; k <= 1+y; ++k)
    {
        for (int i = -1+x; i <= 1+x; ++i)
        {
            if (!(k == y && i == x)) {
                if (k >= 0 && k < graph.size() && i >= 0 && i < graph.size()) {
                    graph[k][i] += 1;
                    if (graph[k][i] > 9 && !flashed[k][i]) {
                        flashed[k][i] = true;
                        //graph[k][i] = 0;
                        flash(i, k);
                        //cout << endl << "fuck " << k << " " << i << endl;
                    }
                } 
            }
        }
    }
}

void cycle() {
    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            graph[k][i] += 1;
            if (graph[k][i] > 9 && !flashed[k][i]) {
                flashed[k][i] = true;
                //graph[k][i] = 0;
                //cout << "tried to flash " << k << " " << i << endl << endl;
                //cout << endl << "eeefuck " << k << " " << i << endl;
                flash(i, k);
            }
        }
    }
    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            if (flashed[k][i]) {
                graph[k][i] = 0;
            }
        }
    }
    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            flashed[k][i] = false;
        }
    }
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int size = 10;

    for (int k = 0; k < size; ++k)
    {
        vector<int> temp;
        vector<bool> temp2;
        string s;
        cin >> s;
        for (int i = 0; i < size; ++i)
        {
            temp.push_back(s.at(i)-'0');
            temp2.push_back(false);
        }
        graph.push_back(temp);
        flashed.push_back(temp2);
    }

    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            cout <<graph[k][i];
        }
        cout << endl;
    }
    cout << endl;

    // for (int k = 0; k < graph.size(); ++k)
    // {
    //     for (int i = 0; i < graph.size(); ++i)
    //     {
    //         cout <<flashed[k][i];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 0; i < 100; ++i)
    {
        cycle();
    }
    
    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            cout <<graph[k][i];
        }
        cout << endl;
    }
    cout << endl << endl;
    cout << "flashCount: " << flashCount;

    // for (int k = 0; k < graph.size(); ++k)
    // {
    //     for (int i = 0; i < graph.size(); ++i)
    //     {
    //         cout <<flashed[k][i];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

}
