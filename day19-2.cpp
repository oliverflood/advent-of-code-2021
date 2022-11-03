#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> splitToInt(string s, string delimiter) {
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

vector<vector<int>> grabScanner() {
    string a, c;
    int b;
    vector<vector<int>> scanner;
    while(a != "scanner" ) {
        cin >> a;
    }
    cin >> b >> a;
    while (c != "---") {
        cin >> c;
        if (c == "---" || c == a) {
            // redundant but idc
            break;
        }
        else {
            scanner.push_back(splitToInt(c, ","));
        }
        a = c;
    }
    return(scanner);
}

vector<vector<vector<int>>> getInput(int inputSize) {
    vector<vector<vector<int>>> input;
    for (int i = 0; i < inputSize; ++i)
    {
        input.push_back(grabScanner());
    }
    return(input);
}

void print(vector<vector<int>> scanner) {
    for (int i = 0; i < scanner.size(); ++i)
    {
        for (int k = 0; k < scanner[0].size(); ++k)
        {
            cout << scanner[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printList(vector<vector<vector<int>>> scannerList) {
    for (int j = 0; j < scannerList.size(); ++j) {
        cout << "scanner " << j << endl;
        for (int i = 0; i < scannerList[j].size(); ++i) {
            for (int k = 0; k < scannerList[j][i].size(); ++k) {
                cout << scannerList[j][i][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl << endl;
}

vector<vector<vector<int>>> allTransforms(vector<vector<int>> scanner) {
    vector<vector<vector<int>>> ans;
    for (int i = 0; i < 3; ++i) {
        for (int a = 1; a >= -1; a-=2) {
            for (int b = 1; b >= -1; b-=2) {
                for (int c = 1; c >= -1; c-=2) {
                    vector<vector<int>> scannerMult;
                    for (int k = 0; k < scanner.size(); ++k) {
                        vector<int> beacon = scanner[k];
                        scannerMult.push_back({beacon[(i%3)]*a,beacon[((i+1)%3)]*b,beacon[((i+2)%3)]*c});
                    }
                    ans.push_back(scannerMult);
                }
            }
        }
    }
    for (int i = 0; i < scanner.size(); ++i)
    {
        iter_swap(scanner[i].begin(), scanner[i].begin()+1);
    }
    for (int i = 0; i < 3; ++i) {
        for (int a = 1; a >= -1; a-=2) {
            for (int b = 1; b >= -1; b-=2) {
                for (int c = 1; c >= -1; c-=2) {
                    vector<vector<int>> scannerMult;
                    for (int k = 0; k < scanner.size(); ++k) {
                        vector<int> beacon = scanner[k];
                        scannerMult.push_back({beacon[(i%3)]*a,beacon[((i+1)%3)]*b,beacon[((i+2)%3)]*c});
                    }
                    ans.push_back(scannerMult);
                }
            }
        }
    }
    return(ans);
}



vector<vector<int>> relate(vector<vector<int>> scanner, vector<vector<int>> scanner2) {
    vector<vector<int>> onion;
    vector<vector<int>> s = scanner;
    // for (int i = 0; i < scanner.size(); ++i)
    // {
    //     sort(scanner[i].begin(), scanner[i].end());
    // }
    // for (int i = 0; i < scanner2.size(); ++i)
    // {
    //     sort(scanner2[i].begin(), scanner2[i].end());
    // }
    for (int i = 0; i < scanner.size(); ++i)
    {
        if (find(begin(scanner2), end(scanner2), scanner[i]) != end(scanner2)) {
            onion.push_back(s[i]);
        }
    }
    return(onion);
}

vector<vector<int>> relativeToPoint(vector<vector<int>> scanner, vector<int> point) {
    vector<vector<int>> ans;
    for (int i = 0; i < scanner.size(); ++i)
    {
        vector<int> ansPart;
        for (int k = 0; k < 3; ++k)
        {
            ansPart.push_back(scanner[i][k]-point[k]);
        }
        ans.push_back(ansPart);
    }
    return(ans);
}

vector<vector<int>> addToAll(vector<vector<int>> scanner, vector<int> point) {
    vector<vector<int>> ans;
    for (int i = 0; i < scanner.size(); ++i)
    {
        vector<int> ansPart;
        for (int k = 0; k < 3; ++k)
        {
            ansPart.push_back(scanner[i][k]+point[k]);
        }
        ans.push_back(ansPart);
    }
    return(ans);
}

vector<vector<vector<int>>> pointRelativity(vector<vector<int>> scanner) {
    vector<vector<vector<int>>> pointScanners;
    for (int i = 0; i < scanner.size(); ++i)
    {
        pointScanners.push_back(relativeToPoint(scanner, scanner[i]));
    }
    //pointScanners.push_back(scanner);
    return(pointScanners);
}

vector<vector<vector<vector<int>>>> godList(vector<vector<int>> scanner) {
    vector<vector<vector<vector<int>>>> god;
    vector<vector<vector<int>>> transforms = allTransforms(scanner);
    for (int i = 0; i < transforms.size(); ++i)
    {
        god.push_back(pointRelativity(transforms[i]));
        // if (i == 2) {
        //     cout << "here: " << endl;
        //     print(pointRelativity(transforms[i])[3]);
        //     cout << endl << endl;
        // }
    }
    return(god);
}

void printV(vector<int> v) {
    cout << "/ ";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> addV(vector<int> v1, vector<int> v2) {
    for (int i = 0; i < v1.size(); ++i)
    {
        v1[i] = v1[i] + v2[i];
    }
    return(v1);
}

vector<int> notV(vector<int> v) {
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = -v[i];
    }
    return(v);
}

vector<vector<int>> shift(vector<vector<int>> scanner, int k) {
    vector<vector<int>> ans;
    for (int i = 0; i < scanner.size(); ++i)
    {
        vector<int> temp = {scanner[i][(0+k)%3],scanner[i][(1+k)%3],scanner[i][(2+k)%3]};
        ans.push_back(temp);
    }
    return(ans);
}

vector<vector<int>> allScanners = {{0,0,0}};

vector<vector<int>> compare(vector<vector<int>> scanner, vector<vector<int>> &scanner2) {
    vector<vector<vector<vector<int>>>> god = godList(scanner2);
    //scanner = relativeToPoint(scanner, scanner[0]);
    vector<vector<vector<int>>> pointRel = pointRelativity(scanner);
    vector<vector<int>> onion;

    vector<vector<vector<int>>> scanner2Transforms = allTransforms(scanner2);
    for (int i = 0; i < scanner2Transforms.size(); ++i)
    {
        vector<vector<vector<int>>> scanner2TransformAtPoint = pointRelativity(scanner2Transforms[i]);
        for (int k = 0; k < scanner2TransformAtPoint.size(); ++k)
        {
            for (int j = 0; j < pointRel.size(); ++j)
            {
                onion = relate(pointRel[j], scanner2TransformAtPoint[k]);
                if (onion.size() >= 12) {
                    vector<int> blank = {0,0,0};
                    vector<int> vec1 = scanner[j];

                    vector<int> vec2 = scanner2Transforms[i][k];
                    // cout << "scanner2Transforms: " << endl;
                    // printList(scanner2Transforms);

                    // cout << "i: " << i << "  k: " << k << endl;


                    vector<int> vec3 = addV(vec1, notV(vec2));
                    allScanners.push_back(vec3);
                    // cout << endl << "vec1: " << endl;
                    // printV(vec1);
                    // cout << "vec2: " << endl;
                    // printV(vec2);
                    // printV(scanner2[k]);
                    // cout << "-vec3: " << endl;
                    // printV(vec3);
                    // cout << endl;

                    scanner2 = addToAll(scanner2Transforms[i], vec3); 

                    return(relativeToPoint(onion, vec3));
                }
            }
        }
    }
    return(onion);
}

// //TEST TEST TEST
// vector<int> offset(vector<vector<int>> scanner, vector<vector<int>> &scanner2) {
//     vector<vector<vector<vector<int>>>> god = godList(scanner2);
//     //scanner = relativeToPoint(scanner, scanner[0]);
//     vector<vector<vector<int>>> pointRel = pointRelativity(scanner);
//     vector<vector<int>> onion;
//     for (int i = 0; i < god.size(); ++i)
//     {
//         for (int k = 0; k < god[i].size(); ++k)
//         {
//             for (int j = 0; j < pointRel.size(); ++j)
//             {
//                 onion = relate(pointRel[j], god[i][k]);
//                 if (onion.size() >= 12) {
//                     //cout << "BING CHILLING" << endl;

                    // vector<int> blank = {0,0,0};
                    // vector<int> vec1 = {scanner[(find(pointRel[j].begin(), pointRel[j].end(), blank))-pointRel[j].begin()]};
                    // vector<vector<vector<int>>> tempTransforms = allTransforms(scanner2);
                    // vector<int> vec2 = {tempTransforms[i][(find(god[i][k].begin(), god[i][k].end(), blank))-god[i][k].begin()]};

                    // scanner2 = tempTransforms[i]; // <<<<<<<CRIME AGAINST HUMANITY<<<<<<
//                     vector<int> vec3;
//                     for (int l = 0; l < 3; ++l)
//                     {
//                         vec3.push_back((vec1[l]-vec2[l]));
//                     }
//                     return(vec3);

//                     // cout << "god: " << endl;
//                     // print(god[i][k]);
//                     // cout << "scanner2: " << endl;
//                     // print(scanner2);
//                     // cout << "GODLIST[" << i << "]" << endl;
//                     // printList(god[i]);
//                 }
//             }
//         }
//     }
//     vector<int> a;
//     return(a);
// }



// int beaconCount(vector<vector<vector<int>>> scannerList) {
//     set<vector<int>> beacons;
//     for (int i = 0; i < scannerList.size(); ++i)
//     {
//         for (int k = 0; k < scannerList.size(); ++k)
//         {
//             if (!(i == k)) {
//                 vector<vector<int>> v = compare(scannerList[i], scannerList[k]);
//                 if (v.size() > 0) {
//                     cout << "scanners " << i << " and " << k << " have shared size " << v.size() << endl;
//                     for (int j = 0; j < v.size(); ++j)
//                     {
//                         beacons.insert(v[j]);
//                     }
//                 }   
//             }
//         }
//     }
//     return(beacons.size());
// }

// vector<vector<vector<int>>> findPartners(vector<vector<vector<int>>> scannerList, vector<vector<int>> scanner) {
//     vector<vector<vector<int>>> p;
//     for (int i = 0; i < scannerList.size(); ++i)
//     {
//         if (scannerList[i] != scanner) {
//             if (compare(scanner, scannerList[i]).size() >= 12) {
//                 //cout << "index is " << i << endl;
//                 p.push_back(scannerList[i]);
//             }
//         }
//     }
//     return(p);
// }

// vector<vector<vector<int>>> visitedList;
// set<vector<int>> beacons;


int manhattan(vector<int> point, vector<int> point2) {
    int ans = 0;
    for (int i = 0; i < point.size(); ++i)
    {
        ans += abs(point[i]-point2[i]);
    }
    return(ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    

    vector<vector<vector<int>>> scannerList = getInput(5); // 36
    set<vector<int>> beacons;

    vector<int> visited;
    vector<int> canVisit;
    canVisit.push_back(0);
    while(canVisit.size() > 0) {
        int i = canVisit[canVisit.size()-1];
        canVisit.pop_back();
        for (int k = 0; k < scannerList.size(); ++k)
        {
            if (!(i == k) && find(visited.begin(), visited.end(), k) == visited.end()) {
                vector<vector<int>> e = compare(scannerList[i], scannerList[k]);
                cout << i << " " << k << "   " << e.size() << endl;
                if (e.size() >= 12) {
                    canVisit.push_back(k);
                    visited.push_back(k);
                }
            }
        }
        visited.push_back(i);
    }

    for (int i = 0; i < scannerList.size(); ++i)
    {
        for (int k = 0; k < scannerList[i].size(); ++k)
        {
            beacons.insert(scannerList[i][k]);

        }
    }
    vector<vector<int>> ans(beacons.begin(), beacons.end());
    //print(ans);
    
    cout << endl << "b: " << beacons.size() << endl;

    int answer = 0;
    for (int i = 0; i < allScanners.size(); ++i)
    {
        for (int k = 0; k < allScanners.size(); ++k)
        {
            if (!(i == k)) {
                int temp = manhattan(allScanners[i], allScanners[k]);
                if (temp > answer) {
                    answer = temp;
                }
            }
        }
    }
    cout << "largest manhattan: " << answer << endl;
}
