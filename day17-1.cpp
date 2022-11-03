#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int x1, x2, y, y2;

int height = 0;

bool shoot(int vx, int vy) {
    int vx1 = vx;
    int vy1 = vy;
    int xpos = 0;
    int ypos = 0;
    int maxY = 0;
    while (ypos > y) {
        //cout << xpos << " " << ypos << endl;
        xpos += vx;
        ypos += vy;
        if (vy == 0) {
            maxY = ypos;
        }
        if (xpos >= x1 && xpos <= x2 && ypos >= y && ypos <= y2) {
            if (maxY > height) {
                height = maxY;
                //cout << vx1 << " " << vy1 << endl;
            }
            return(true);
        }
        if (vx > 0) {
            vx--;
        }
        else if (vx < 0) {
            vx++;
        }
        vy--;
    }
    return(false);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    string a, b, c, d;
    cin >> d >> c >> a >> b;

    x1 = stoi(a.substr(2, a.find_first_of(".")-2));
    x2 = stoi(a.substr(a.find_first_of(".")+2, a.length()-a.find_first_of(".")+1));
    y = stoi(b.substr(2, b.find_first_of(".")-2));
    y2 = stoi(b.substr(b.find_first_of(".")+2, b.length()-b.find_first_of(".")+2));
    
    long long counter = 0;
    for (int i = 0; i < x2+5; ++i)
    {
        for (int k = y-5; k < 1000; ++k)
        {
            if (shoot(i, k)) {
                counter++;
            }
        }
    }
    cout << "h: " << height << endl;
    shoot(0,0);
    cout << "ans: " << counter;
}

//1006 too low