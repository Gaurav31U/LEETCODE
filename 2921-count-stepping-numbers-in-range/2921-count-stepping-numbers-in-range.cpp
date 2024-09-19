class Solution {
public:    
    int countSteppingNumbers(string low, string high) { 
        //first we are checking for the range 0 to low -->count of stepping numbers
        memset(stepCount, -1, sizeof(stepCount));
        long long left = countStepNums(low, 0, 1, 1, 0);
        
        //checking for the count of stepping numbers in the range 0 to high
        memset(stepCount, -1, sizeof(stepCount));
        long long right = countStepNums(high, 0, 1, 1, 0);
        
        long long answer = (right % mod - left % mod + mod) % mod;
        
        //since the answer is not checking for the number at the low in the range then we will check for it seperately
        bool incLow = true;
        for (long long indx = 0; indx < (long long) low.size(); indx++){
            if (indx != 0 && abs(low[indx] - low[indx - 1]) != 1) incLow = false;
        }
        if (incLow) answer = (answer + 1) % mod;

        return answer;
    }
private:
    long long mod = 1e9 + 7;
    //100 digits in a number 10 ^ 100

    // 2nd dimesion is for whether you passed a digit equal to the digit in the same index upper bound of range which is numStr->> if yes -- then you are bounded other wise you can take any digit after it as per your choice
    
    //3rd dimension is for whether the previous digits include before current digit to be considered to be included are zero or not ? if yes then you can take any digit of your choice, if no then you can only take those digits whose absoulte difference with previous digit included is one
    
    //4th dimesnion is for how many options are you having to fill the current position-- if there are no constraints there are 0 to 9 i.e. 10 options available only  
    long long stepCount[101][2][2][10];
    //numStr is upper end of the range ->> o to upperend
    long long countStepNums(string & numStr, long long numIndx, long long isBounded,
     long long arePrevZeroes, long long prevDigs) {
        if (numIndx == (long long) numStr.size()) {
            return (arePrevZeroes == 1) ? 0 : 1;//not considering the case in which the number is having leading zeroes then in such case as soon as we have formed the number of digits equal to number of digits in the upper end of the range 
        }

        if (stepCount[numIndx][isBounded][arePrevZeroes][prevDigs] != -1) return stepCount[numIndx][isBounded][arePrevZeroes][prevDigs];

        long long answer = 0, willBeZero = -1, newisBounded = -1;
        long long limit =(isBounded) ? (numStr[numIndx] - '0') :  9;

        for (long long dig = 0; dig <= limit; dig++) {
            willBeZero = (arePrevZeroes && dig == 0) ? 1 :  0;
            newisBounded = (isBounded && dig == limit) ? 1 : 0;
            //either the pervious digits were zero or the abs diff with prev digit is 1
            if (arePrevZeroes || abs(dig - prevDigs) == 1) {
                answer = (answer % mod + countStepNums(numStr, numIndx + 1, newisBounded, willBeZero, dig) % mod)%mod;
            }
        }

        stepCount[numIndx][isBounded][arePrevZeroes][prevDigs] = answer;
        return answer;
    }
    
};