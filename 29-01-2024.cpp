class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
    int n = matrix[0].size();
    int count = 0;

    // Compute the prefix sum matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    // Iterate over all possible pairs of columns
    for (int col1 = 0; col1 < n; ++col1) {
        for (int col2 = col1; col2 < n; ++col2) {
            unordered_map<int, int> prefixSumCount;
            prefixSumCount[0] = 1;
            int currentSum = 0;

            // Iterate over all rows and compute the sum of the submatrix formed by col1 and col2
            for (int row = 0; row < m; ++row) {
                int colSum = matrix[row][col2] - (col1 > 0 ? matrix[row][col1 - 1] : 0);
                currentSum += colSum;

                // Check if there is a submatrix with the target sum ending at the current row
                if (prefixSumCount.find(currentSum - target) != prefixSumCount.end()) {
                    count += prefixSumCount[currentSum - target];
                }

                // Increment the count of the current prefix sum
                prefixSumCount[currentSum]++;
            }
        }
    }

    return count;
        
    }
};
