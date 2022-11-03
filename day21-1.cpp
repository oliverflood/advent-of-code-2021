#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int dice = 0;

int rollDice() {
    int ans = 0;
    for (int i = 0; i < 3; ++i)
    {
        ans += dice+1;
        dice++;
        dice = dice%100;
    }
    return(ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int p1, p2;
    int p1Score = 0;
    int p2Score = 0;
    string a;
    cin >> a >> a >> a >> a >> p1;
    cin >> a >> a >> a >> a >> p2;

    int diceRollCount = 0;

    while(p1Score < 1000 && p2Score < 1000) {
        p1 += rollDice();
        diceRollCount += 3;
        p1 = ((p1-1) % 10)+1;
        p1Score += p1;
        if (p1Score >= 1000) {
            break;
        }
        //cout << "1: " << p1 << "  " << p1Score << endl;

        p2 += rollDice();
        diceRollCount += 3;
        p2 = ((p2-1) % 10)+1;
        p2Score += p2;
        //cout << "2: " << p2 << "  " << p2Score << endl;
    }

    cout << p1Score << " " << p2Score << " " << diceRollCount << endl;
    cout << min(p1Score, p2Score)*diceRollCount;
    
}
