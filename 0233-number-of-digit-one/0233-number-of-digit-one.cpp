class Solution {
public:
    int countDigitOne(int n) {

        long long ans = 0;

        int numAfter = 0;
        long long placeVal = 1;

        while(n > 0){
            int digit = n % 10;
            int numBefore = n/10;
            
            long long contribution;
            if(digit == 0){
                contribution = placeVal * numBefore;
            } else if(digit == 1){
                contribution = (1 + numAfter) + (numBefore * (placeVal));
            } else {
                contribution = (1+numBefore)*(placeVal);
            }

            ans += contribution;

            numAfter = (digit*placeVal) + numAfter;
            placeVal *= 10;
            n = numBefore;
        }

        return ans;
    }
};
