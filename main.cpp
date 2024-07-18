#include <iostream>
using namespace std;


int DP (int N, int count) {
    for(int i = 1; i <= 6; i++) {
        if(N-i == 0) {
            count++;
        }else if (N-i < 0) {
            return count;
        }
        count = DP(N-i, count);
    }
    return count;
}
int main()
{
    int N;
    cin >> N;
    cout << DP(N, 0) << endl;
    return 0;
}
