// next greater element 1

// stack保存降序的子序列，若进来的数x比stack里都要大，则这些数的next greater element都是x，将之存入hash table

#include<iostream>
#include<vector>
#include <unordered_map>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    unordered_map<int,int> ht;
    stack<int> stk;
    for(int i=0;i<nums.size();i++) {
        while(!stk.empty() && nums[stk.top()]<nums[i]) { 
            ht[nums[stk.top()]]=nums[i];
            stk.pop();
        }
        stk.push(i);
    }

    int n = findNums.size();
    vector<int> res(n);
    for(int i=0;i<n;i++) {
        auto it = ht.find(findNums[i]);
        res[i]=it==ht.end()?-1:it->second;
    }

    return res;
}

int main(){
	vector<int> a={4,1,2};
	vector<int> b={1,3,4,2};
	vector<int> c = nextGreaterElement(a,b);
	for(auto m:c){
		cout << m << endl;
	}
	return 0;
}