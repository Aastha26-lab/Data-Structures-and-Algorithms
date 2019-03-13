//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int countAllWays(int n) {
    int DP[n + 1];
    DP[0] = DP[1] = DP[2] = 1;
    DP[3] = 2;
    for (int i = 4; i <= n; i++) {
        DP[i] = DP[i - 1] + DP[i - 3] + DP[i - 4];
    }
    return DP[n];
}

int main() {
    int n;
    cout << "\nEnter Number\t:\t";
    cin >> n;
    cout << "\nTotal Number of Ways\t:\t " << countAllWays(n) << "\n";
    
    return 0;
}

