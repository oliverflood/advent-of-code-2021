#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// I'd like to sincerely apologize for how ugly this code is

void cycle(long long (&u)[2][11][11][22][22], long long &p1Wins, long long &p2Wins) {
    long long u2[2][11][11][22][22];
    copy(&u[0][0][0][0][0], &u[0][0][0][0][0]+11*11*22*22*2, &u2[0][0][0][0][0]);

    for (int a = 1; a <= 10; ++a) {
        for (int b = 1; b <= 10; ++b) {
            for (int c = 0; c <= 21; ++c) {
                for (int d = 0; d <= 21; ++d) {
                    long long inc = u2[0][a][b][c][d];
                    if (inc > 0) {
                        u[0][a][b][c][d] -= inc;

                        for (int i = 1; i <= 3; ++i) {
                            for (int i2 = 1; i2 <= 3; ++i2) {
                                for (int i3 = 1; i3 <= 3; ++i3) {
                                    if (c+((a+i+i2+i3-1)%10)+1 >= 21) {
                                        p1Wins += inc;
                                        //u2[a][b][c][d] = 0;
                                    }
                                    else {
                                        u[1][((a+i+i2+i3-1)%10)+1][b][c+((a+i+i2+i3-1)%10)+1][d] += inc;
                                        //cout << (((a+i-1)%10)+1) << " " << b << " " << (c+((a+i-1)%10)+1) << " " << d << endl;
                                    }
                                }
                            }
                        }
                        //u2[a][b][c][d] -= inc;
                    }
                }
            }
        }
    }
    for (int a = 1; a <= 10; ++a) {
        for (int b = 1; b <= 10; ++b) {
            for (int c = 0; c <= 21; ++c) {
                for (int d = 0; d <= 21; ++d) {
                    long long inc = u2[1][a][b][c][d];
                    if (inc > 0) {
                        u[1][a][b][c][d] -= inc;
                        for (int i = 1; i <= 3; ++i) {
                            for (int i2 = 1; i2 <= 3; ++i2) {
                                for (int i3 = 1; i3 <= 3; ++i3) {
                                    if (d+((b+i+i2+i3-1)%10)+1 >= 21) {
                                        p2Wins += inc;
                                        //u2[a][b][c][d] = 0;
                                    }
                                    else {
                                        u[0][a][((b+i+i2+i3-1)%10)+1][c][d+((b+i+i2+i3-1)%10)+1] += inc;
                                        //cout << (((a+i-1)%10)+1) << " " << b << " " << (c+((a+i-1)%10)+1) << " " << d << endl;
                                    }
                                }
                            } 
                        }
                        //u2[a][b][c][d] -= inc;
                    }
                }
            }
        }
    }
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

    long long universes[2][11][11][22][22]{};
    long long p1Wins = 0;
    long long p2Wins = 0;

    universes[0][p1][p2][p1Score][p2Score] += 1;

    for (int i = 0; i < 20; ++i)
    {
        cycle(universes, p1Wins, p2Wins);
        cout << p1Wins << " " << p2Wins << endl;
    }
    cout << endl << "444356092776315 341960390180808" << endl;

    cout << endl << "end";
}
