#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll N, power;
vector<ll> patches = {0};

ll spray(int ind, int count) {
    /*
    cout << "before: ";
    for(int i = 1; i <= N; i++) {
        cout << patches[i] << " ";
    }
    cout << endl;
    */
    power = N - ind + 1;
    //cout << "power = " << power << endl;
    if(patches[ind] > 0) {
        // Decrease with power
        int i = N;
        while(i > 0 and power > 0) {
            patches[i] -= power;
            power--;
            i--;
        }
    }else if(patches[ind] < 0){
        // Increase with power
        int i = N;
        while(i > 0 and power > 0) {
            patches[i] += power;
            power--;
            i--;
        }
    }else {
        count--;
    }
    /*cout << "after: ";
    for(int i = 1; i <= N; i++) {
        cout << patches[i] << " ";
    }
    cout << endl;
    */
    count++;
    if(patches[ind] == 0) {
        if(ind == N) {
            return count;
        }
        return spray(ind+1, count);
    }
    return spray(ind, count);
}
int main() {
    int level;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> level;
        patches.push_back(level);
    }
    for(int i = 1; i <= N; i++) {
        cout << patches[i] << " ";
    }
    cout << spray(1, 0) << endl;
    return 0;
}
/*
5
1 3 -2 -7 5
 */