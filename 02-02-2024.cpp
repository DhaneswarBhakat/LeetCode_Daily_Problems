class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int digit = 1; digit <= 9; ++digit) {
            int num = digit;
            int nextDigit = digit + 1;
            while (num <= high && nextDigit <= 9) {
                num = num * 10 + nextDigit;
                if (low <= num && num <= high) {
                    result.push_back(num);
                }
                nextDigit++;
            }
        }
        sort(result.begin(), result.end());
        return result;
        
    }
};
