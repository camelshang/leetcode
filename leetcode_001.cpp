#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
	unordered_map<int, int> map;
	vector<int> result;
	for (unsigned int i = 0; i < nums.size(); i++){
		if (map.find(nums[i]) == map.end()){
			map.insert(make_pair(target - nums[i], i));
		}
		else{
			result.push_back(map[nums[i]]);
			result.push_back(i);
			
		}
	}
	return result;
}
int main(){
	vector<int> nums = { 2, 5,3,4, 11, 15 };
	int target = 9;
	vector<int> res = twoSum(nums, target);
	for (auto i : res){
		cout << i << endl;
	}
	return 0;
}