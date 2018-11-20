//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k) { 
  if (k==0 || k==n) 
    return 1; 
  return  binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k); 
}
 
 
int main () {
    cout << "\nEnter n\t:\t";
    int n;
    cin >> n;
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout << "\nEnter p\t:\t";
    int p;
    cin >> p;
    cout <<"\nThe result is\t:\t" << binomialCoeff(n,k)%p;
    cout << endl;
    return 0;
}
