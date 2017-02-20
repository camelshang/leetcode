// single number
#include <iostream>
#include <vector>


using namespace std;

int sigleNumber(vector<int> &nums){
    int len = nums.size(), res=0;
    if(len%2==0){
        return 0;
    }
    else{
        for(auto m:nums){
            res ^= m;
        }        
        return res;
    }
}

int main(){
    vector<int> a = {1,1,2};
    cout << sigleNumber(a) << endl;
}