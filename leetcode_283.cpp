// move zeros


// index i for num in nums
// index j for num!=0 in nums

void moveZeros(vector<int> &nums){
    if(nums.size() == 0){
        return;
    }
    int j=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] != 0){
            if(i > j){
                nums[j] = nums[i];
                nums[i] = 0;
            }
            j++;
        }
            
    }
}


void moveZeros(vector<int> &nums){
    for(int i=0,j=0;i<nums.size();i++){
        if(nums[i] != 0){
            swap(nums[j++],nums[i]);
        }
    }
}

//C++11 
void moveZeroes(vector<int>& nums) {
    fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
}