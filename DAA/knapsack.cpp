#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[100], val[100];

    cout << "Enter weights of items: "<<endl;
    for (int i = 1; i <= n; i++)
        cin >> wt[i];

    cout << "Enter values of items: "<<endl;
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int dp[101][101] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i] + dp[i - 1][w - wt[i]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value: " << dp[n][W] << endl;

    cout << "Selected items: ";
    int w = W;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= wt[i];
        }
    }

    return 0;
}
