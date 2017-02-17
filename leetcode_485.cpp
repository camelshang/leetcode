// max consecutive ones

int findMaxConsecutiveOnes(vector<int> &nums){
	int max=0,sum=0;
    for(auto m:nums){
        sum = (sum + m) * m;
        if(sum > max){
            max = sum;
        }
    }
    return max;
}