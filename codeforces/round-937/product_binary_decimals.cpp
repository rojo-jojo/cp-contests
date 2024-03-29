#include<bits/stdc++.h>
#include<iostream>
#include <sstream>
#include<iomanip>
using namespace std;

vector <int> binary_decimals;
int MAXNUM = 100000;

bool ok(int n) {
    bool ans = false;
    if (n == 1) return true;
    for (int i: binary_decimals) {
        if (n % i == 0) {
            ans = ans | ok(n/i);
        }
    }
    return ans;
}

void solve(int num) {
    cout << (ok(num) ? "YES\n": "NO\n");
}

void generate_binary_repo() {
    int curr;
    for (int i=2; i < MAXNUM; i++) {
        bool bad = false;
        curr = i;
        while (curr) {
            if (curr % 10 > 1) {
                bad = true; 
                break;
            }
            curr /= 10;
        }
        if (!bad) binary_decimals.push_back(i);

    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    generate_binary_repo();
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);    
    }
    return 0;
}