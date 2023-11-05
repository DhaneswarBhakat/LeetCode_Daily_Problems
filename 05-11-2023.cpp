class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int currentWinner = arr[0];
    int consecutiveWins = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > currentWinner) {
            currentWinner = arr[i];
            consecutiveWins = 1;
        } else {
            consecutiveWins++;
        }

        if (consecutiveWins == k) {
            return currentWinner;
        }
    }

    return currentWinner;
        
    }
};
