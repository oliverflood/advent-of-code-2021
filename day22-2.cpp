#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); ++i)
    {
        for (int k = 0; k < v[0].size(); ++k)
        {
            cout << (to_string(v[i][k])!="0"?to_string(v[i][k]):".") << " ";
        }
        cout << endl;
    }
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

vector<int> getPair(string s) {
    vector<int> pair;
    pair.push_back(stoi(s.substr(s.find("=")+1, (s.find("."))-(s.find("=")+1))));
    pair.push_back(stoi(s.substr(s.find(".")+2, s.length()-(s.find("=")+1))));
    return(pair);
}

vector<pair<vector<vector<int>>, bool>> getInput(int lineCount) {
    vector<pair<vector<vector<int>>, bool>> input;
    for (int i = 0; i < lineCount; ++i)
    {
        vector<vector<int>> temp;
        string a, s;
        cin >> a >> s;
        
        vector<string> splitString = split(s, ",");
        for (int k = 0; k < splitString.size(); ++k)
        {
            vector<int> pair = getPair(splitString[k]);
            temp.push_back(pair);
        }
        bool isOn = false;
        if (a == "on") {
            isOn = true;
        }
        input.push_back(pair<vector<vector<int>>, bool>(temp, isOn));
    }
    return(input);
}

long long area(vector<vector<int>> cube) {
    long long a = 1;
    //cout << "a: " << a << endl;
    for (int i = 0; i < cube.size(); ++i)
    {
        a = ((long long)a)*(long long)(abs(cube[i][0]-cube[i][1])+1);
        //cout << "a: " << a << endl;
    }
    return(a);
}

vector<vector<int>> intersection(vector<vector<int>> cube1, vector<vector<int>> cube2) {
    vector<vector<int>> newCube;
    for (int i = 0; i < 3; ++i)
    {
        vector<int> temp;
        temp.push_back(max(min(cube1[i][0], cube1[i][1]), min(cube2[i][0], cube2[i][1])));
        temp.push_back(min(max(cube1[i][0], cube1[i][1]), max(cube2[i][0], cube2[i][1])));
        if (temp[0] > temp[1]) {
            vector<vector<int>> empty;
            return(empty);
        }
        newCube.push_back(temp);
    }
    return(newCube);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    vector<pair<vector<vector<int>>, bool>> steps = getInput(420); //5035531490130659
    //vector<vector<int>> universe = {{-50,50},{-50,50},{-50,50}};
    
    //steps.insert(steps.begin(), pair<vector<vector<int>>, bool>(universe, 0));

    // for (int i = 0; i < steps.size(); ++i)
    // {
    //     print(steps[i].first);
    //     cout << steps[i].second << endl;
    //     cout << area(steps[i].first) << endl;
    // }
    // vector<vector<int>> yeet = {{1,1},{1,1},{1,1}};
    // print(intersection(yeet, steps[0].first));
    // cout << area(intersection(steps[1].first, steps[0].first));

    // for (int i = 0; i < steps.size(); ++i)
    // {
    //     for (int k = 0; k < steps[i].first.size(); ++k)
    //     {
    //         for (int j = 0; j < steps[i].first[k].size(); ++j)
    //         {
    //             steps[i].first[k][j] += 1000000;
    //         }
    //     }
    // }

    vector<pair<vector<vector<int>>, bool>> list2;
    long long totalArea = 0;
    for (int i = 0; i < steps.size(); ++i)
    {
        totalArea += steps[i].second*area(steps[i].first);
        cout << endl << "i: " << i << "  totalArea: " << totalArea << endl;
        vector<pair<vector<vector<int>>, bool>> listTemp;
        
        for (int k = i-1; k >= 0; k--)
        {
            if (true) { //!(k==0 && i==0)
                if (steps[i].second == steps[k].second && steps[k].second != 0) {
                    vector<vector<int>> temp = intersection(steps[i].first, steps[k].first);
                    if (temp.size() > 0) {
                        listTemp.push_back(pair<vector<vector<int>>, bool>(temp, !steps[i].second));
                        totalArea -= (steps[i].second==0?-1:1)*area(temp);
                        //cout << "S k: " << k << "  totalArea: " << totalArea << endl;
                    }
                }
                else if (steps[k].second != 0) { // steps[i] is our current cube, steps[k] are all past cubes
                    vector<vector<int>> temp = intersection(steps[i].first, steps[k].first);
                    if (temp.size() > 0) {
                        listTemp.push_back(pair<vector<vector<int>>, bool>(temp, steps[i].second));
                        totalArea += (steps[i].second==0?-1:1)*area(temp);
                        //cout << "D k: " << k << "  totalArea: " << totalArea << endl;
                    }
                }
            }
        }

        for (int j = 0; j < list2.size(); ++j)
        {
            if (steps[i].second == list2[j].second) {
                vector<vector<int>> temp = intersection(steps[i].first, list2[j].first);
                if (temp.size() > 0) {
                    listTemp.push_back(pair<vector<vector<int>>, bool>(temp, !steps[i].second));
                    totalArea -= (steps[i].second==0?-1:1)*area(temp);
                    //cout << "S j: " << j << "  totalArea: " << totalArea << endl;
                }
            }
            else {               
                vector<vector<int>> temp = intersection(steps[i].first, list2[j].first);
                if (temp.size() > 0) {
                    listTemp.push_back(pair<vector<vector<int>>, bool>(temp, steps[i].second));
                    totalArea += (steps[i].second==0?-1:1)*area(temp);
                    //cout << "D j: " << j << "  totalArea: " << totalArea << endl;
                }
            }
        }
        for (int i = 0; i < listTemp.size(); ++i)
        {
            list2.push_back(listTemp[i]);
        }
        
    }

    cout << "steps: " << endl;
    for (int i = 0; i < steps.size(); ++i)
    {
        print(steps[i].first);
        cout << (steps[i].second?"on":"off") << endl;
        cout << "area: " << area(steps[i].first) << endl << endl;
    }
    cout << endl;

    // cout << "list2: " << endl;
    // for (int i = 0; i < list2.size(); ++i)
    // {
    //     print(list2[i].first);
    //     cout << (list2[i].second?"on":"off") << endl;
    //     cout << "area: " << area(list2[i].first) << endl << endl;
    // }

    cout << endl << "totalArea: " << totalArea << endl;



    long long testArea = 0;
    for (int i = 0; i < steps.size(); ++i)
    {
        testArea += (steps[i].second==0?0:1)*area(steps[i].first);
    }
    cout << endl << "maxArea: " << testArea << endl;
    for (int i = 0; i < list2.size(); ++i)
    {
        testArea += (list2[i].second==0?-1:1)*area(list2[i].first);
    }
    cout << endl << "testArea: " << testArea << endl;
    cout << "rightAns: 2758514936282235 " << endl;
    set<pair<vector<vector<int>>, bool>> list3(list2.begin(), list2.end());
    cout << list3.size();
    //42116

    // print(steps[59].first);
    // cout << area(steps[59].first) << endl;
    
}


//1337028013896457 too high

//610150301644086