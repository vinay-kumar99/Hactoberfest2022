class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> left(A);
        
        //prefix sum of array A
        std::partial_sum(left.begin(), left.end(), left.begin());

        //max among sliding windows of size L(M) on left(right)
        vector<int> Lmaxleft(A.size(), 0), Lmaxright(A.size(), 0);
        vector<int> Mmaxleft(A.size(), 0), Mmaxright(A.size(), 0);
        
        for(int i=0; i<A.size(); i++) {
            if(i>=L-1) {
                Lmaxleft[i] = left[i] - left[i-L+1] + A[i-L+1];
            }
            if(i>=M-1) {
                Mmaxleft[i] = left[i] - left[i-M+1] + A[i-M+1];
            }
            if(i>0) {
                Lmaxleft[i] = std::max(Lmaxleft[i], Lmaxleft[i-1]);
                Mmaxleft[i] = std::max(Mmaxleft[i], Mmaxleft[i-1]);
            }
        }
        for(int i=A.size()-1; i>=0; i--) {
            if(i+L-1<A.size()) {
                Lmaxright[i] = left[i+L-1] - left[i] + A[i];
            }
            if(i+M-1<A.size()) {
                Mmaxright[i] = left[i+M-1] - left[i] + A[i];
            }
            if(i<A.size()-1) {
                Lmaxright[i] = std::max(Lmaxright[i], Lmaxright[i+1]);
                Mmaxright[i] = std::max(Mmaxright[i], Mmaxright[i+1]);
            }
        }
        

        //largest sum with L followed by M
        int result=0;
        for(int i=L-1; i+1+M-1<A.size(); i++) {
            result = std::max(result, Lmaxleft[i] + Mmaxright[i+1]);
        }
        //largest sum with M followed by L
        for(int i=M-1; i+1+L-1<A.size(); i++) {
            result = std::max(result, Mmaxleft[i] + Lmaxright[i+1]);
        }
        return result;
    }
};
