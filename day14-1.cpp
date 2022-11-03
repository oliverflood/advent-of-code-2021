#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int findLowest(vector<int> v) {
    int ans = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] < ans) {
            ans = v[i];
        }
    }
    return(ans);
}

int findHighest(vector<int> v) {
    int ans = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] > ans) {
            ans = v[i];
        }
    }
    return(ans);
}

vector<string> step(map<string, string> rules, vector<string> poly) {
    int c = 0;
    int f = poly.size();
    for (int i = 1; i < f; ++i)
    {
        // cout << i << "  ";
        // for (int k = 0; k < poly.size(); ++k)
        // {
        //     cout << poly[k];
        // }
        // cout << endl;
        if (rules.count(poly[i+c-1]+poly[i+c]) > 0) {
            poly.insert(poly.begin()+i+c, rules[poly[i+c-1]+poly[i+c]]);
            c++;
        }
    }
    // cout << "final" << endl;
    // for (int k = 0; k < poly.size(); ++k)
    // {
    //     cout << poly[k];
    // }
    // cout << endl;
    return(poly);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int size = 100;
    vector<string> poly;
    string p;
    cin >> p;

    map<string, string> rules;

    for (int i = 0; i < size; ++i)
    {
        string a, b, c;
        cin >> a >> b >> c;
        rules.insert({a,c});
    }

    for (int i = 0; i < p.length(); ++i)
    {
        poly.push_back(p.substr(i, 1));
    }
    poly = step(rules, poly);
    poly = step(rules, poly);
    cout << "S " << poly.size() << endl;
    for (int i = 0; i < 8; ++i)
    {
        poly = step(rules, poly);
    }

    // for (int i = 0; i < poly.size(); ++i)
    // {
    //     cout << poly[i];
    // }

    set<string> temp1(poly.begin(), poly.end());
    vector<string> types(temp1.begin(), temp1.end());
    vector<int> nums;
    for (int i = 0; i < types.size(); ++i)
    {
        nums.push_back(count(poly.begin(), poly.end(), types[i]));
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << endl;
    }

    cout << findHighest(nums) - findLowest(nums);
    
}
