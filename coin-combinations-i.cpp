// https://cses.fi/problemset/task/1635
#include <iostream>
#include <vector>
using namespace std;
int n, x, num;
vector<int> coins;

int combine (vector<int> ways, int sum) {
    for(int c: coins) {
        if(sum-c >= 0) {
            ways[sum] += combine(ways, sum-c);
        }
    }
    return ways[sum];
}
int main() {
    cin >> n >> x;
    vector ways (x+1, 0);
    ways[0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> num;
        coins.push_back(num);
    }
    cout << combine(ways,x) << endl;
    return 0;
}
