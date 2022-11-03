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
            flashed[k][i] = false;
        }
    }
    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            graph[k][i] += 1;
            if (graph[k][i] > 9 && !flashed[k][i]) {
                flashed[k][i] = true;
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
}

bool allFlashed() {
    bool ans = true;
    for (int k = 0; k < graph.size(); ++k)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            if (!flashed[k][i]) {
                ans = false;
            }
        }
    }
    return ans;
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

    for (int i = 0; i < 500; ++i) // just running an arbitrary large number of times
                                  // in case sublime glitches and keeps this program running forever
    {
        cycle();
        if (allFlashed()) {
            cout <<"step: " << i+1 << endl;
            break;
        }
    }
}
