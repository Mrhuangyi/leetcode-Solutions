class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        sort(A.begin(), A.end());
        if(A.size() == 1) {
            return A[0];
        }
        for(int i = A.size()-1; i >= 0; i--) {
            if(i < A.size() -1 && A[i] == A[i+1]) {
                continue;
            }
            if(i == 0 || A[i] != A[i-1]) {
                return A[i];
            }
        }
        return -1;
    }
};
