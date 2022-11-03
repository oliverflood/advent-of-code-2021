#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int versionNumTotal = 0;
int start = 0;

vector<bool> hexToBin(string s) {
    vector<bool> binary;
    map<char, vector<bool>> hexTable = {{'0',{0,0,0,0}}, {'1',{0,0,0,1}}, 
                                        {'2',{0,0,1,0}}, {'3',{0,0,1,1}},
                                        {'4',{0,1,0,0}}, {'5',{0,1,0,1}},
                                        {'6',{0,1,1,0}}, {'7',{0,1,1,1}},
                                        {'8',{1,0,0,0}}, {'9',{1,0,0,1}}, 
                                        {'A',{1,0,1,0}}, {'B',{1,0,1,1}},
                                        {'C',{1,1,0,0}}, {'D',{1,1,0,1}}, 
                                        {'E',{1,1,1,0}}, {'F',{1,1,1,1}}};
    for (int i = 0; i < s.length(); ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            binary.push_back(hexTable[s.at(i)][k]);
        }
    }
    return(binary);
}

long long binToDec(vector<bool> binary) {
    long long ans = 0;
    for (int i = 0; i < binary.size()-1; ++i)
    {
        ans += binary[i] * pow(2, binary.size()-1-i);
    }
    if (binary[binary.size()-1]) {
        ans++;
    }
    return(ans);
}

long long findPacket(int ID, vector<long long> packets) {
    if (ID == 0) {
        long long total = 0;
        for (int i = 0; i < packets.size(); ++i)
        {
            total += packets[i];
        }
        return(total);
    }
    if (ID == 1) {
        long long total = 1;
        for (int i = 0; i < packets.size(); ++i)
        {
            total *= packets[i];
        }
        return(total);
    }
    if (ID == 2) {
        long long m = packets[0];
        for (int i = 0; i < packets.size(); ++i)
        {
            if (packets[i] < m) {
                m = packets[i];
            }
        }
        return(m);
    }
    if (ID == 3) {
        long long m = packets[0];
        for (int i = 0; i < packets.size(); ++i)
        {
            if (packets[i] > m) {
                m = packets[i];
            }
        }
        return(m);
    }
    if (ID == 5) {
        if (packets[0] > packets[1]) {
            return(1);
        }
        else {
            return(0);
        }
    }
    if (ID == 6) {
        if (packets[0] < packets[1]) {
            return(1);
        }
        else {
            return(0);
        }
    }
    if (ID == 7) {
        if (packets[0] == packets[1]) {
            return(1);
        }
        else {
            return(0);
        }
    }
}

long long parse(vector<bool> bin) {
    cout << "start: " << start << endl;
    if (start >= bin.size()) {
        cout << endl << "VersionNumTotal: " << versionNumTotal << " " << start << endl;
        exit(1);
    }
    int initial = start;
    int version = binToDec({bin[start], bin[start+1], bin[start+2]});
    start += 3;
    int ID = binToDec({bin[start], bin[start+1], bin[start+2]});
    start += 3;

    versionNumTotal += version;
    if (ID == 4) {
        vector<bool> ans;
        bool initBit = 1;

        while(initBit) {
            initBit = bin[start];
            for (int i = 1; i < 5; ++i)
            {
                ans.push_back(bin[start+i]);
            }
            start += 5;
        }
        cout << "ans: " << binToDec(ans) << endl;
        return(binToDec(ans));
    }
    else {
        bool op = bin[start];
        start++;
        if (op) {
            int numSubContained;

            vector<bool> temp;
            for (int i = 0; i < 11; ++i)
            {
                temp.push_back(bin[i+start]);
            }
            start += 11;
            numSubContained = binToDec(temp);
            cout << "numSub " << numSubContained << endl;
            vector<long long> packets;

            for (int i = 0; i < numSubContained; ++i)
            {
                packets.push_back(parse(bin));
            }
            return(findPacket(ID, packets));
        }
        else {
            int subBitsContained;
            vector<bool> temp;
            for (int i = 0; i < 15; ++i)
            {
                temp.push_back(bin[i+start]);
            }
            start += 15;
            subBitsContained = binToDec(temp);
            cout << "sub " << subBitsContained << endl;
            vector<long long> packets;
            while (subBitsContained > 0) {
                int temp1 = start;

                packets.push_back(parse(bin));
                //start += temp1;
                subBitsContained -= start - temp1;

            }
            return(findPacket(ID, packets));
        }
    }

    //return(-1000000);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;

    vector<bool> bin = hexToBin(s);
    cout << s.length() << "  " << bin.size() << endl;
    for (int i = 0; i < bin.size(); ++i)
    {
        cout << bin[i];
        if (i% 10 == 9) {
            cout << " ";
        }
    }
    cout << endl;

    cout << parse(bin);

    cout << endl << "VersionNumTotal: " << versionNumTotal << endl;
}
