/* Given a set of distinct integers, nums, return all possible subsets
Note : The solution set must not contain duplicate subsets.
For example,
If nums = [ 1, 2, 3 ],
a solution is :

[ [3], [1], [2], [ 1, 2, 3 ], [ 1, 3 ], [ 2, 3 ], [ 1, 2 ], [] ]
*/

// backtracking method
vector<vector<int>> subsets(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> subs;
  vector<int> sub;
  genSubsets(nums, 0, sub, subs);
  return subs;
}

void genSubsets(vector<int> &nums, int start, vector<int> &sub,
                vector<vector<int>> &subs) {
  subs.push_back(sub);
  for (int i = start; i < nums.size(); i++) {
    sub.push_back(nums[i]);
    genSubsets(nums, i + 1, sub, subs);
    sub.pop_back();
  }
}

// iteration
vector<vector<int>> subsets(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> subs(1, vector<int>());
  for (int i = 0; i < nums.size(); i++) {
    int n = subs.size();
    for (int j = 0; j < n; j++) {
      subs.push_back(subs[j]);
      subs.back().push_back(nums[i]);
    }
  }
  return subs;
}

// bit manipulation
/*
0) 0 0 0  -> Dont take 3 , Dont take 2 , Dont take 1 = { }
1) 0 0 1  -> Dont take 3 , Dont take 2 ,   take 1       =  {1 }
2) 0 1 0  -> Dont take 3 ,    take 2       , Dont take 1 = { 2 }
3) 0 1 1  -> Dont take 3 ,    take 2       ,      take 1    = { 1 , 2 }
4) 1 0 0  ->    take 3      , Dont take 2  , Dont take 1 = { 3 }
5) 1 0 1  ->    take 3      , Dont take 2  ,     take 1     = { 1 , 3 }
6) 1 1 0  ->    take 3      ,    take 2       , Dont take 1 = { 2 , 3 }
7) 1 1 1  ->    take 3     ,      take 2     ,      take 1     = { 1 , 2 , 3 }
*/
vector<vector<int>> subsets(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int num_subset = pow(2, nums.size());
  vector<vector<int>> res(num_subset, vector<int>());
  for (int i = 0; i < nums.size(); i++)
    for (int j = 0; j < num_subset; j++)
      if ((j >> i) & 1)
        res[j].push_back(nums[i]);
  return res;
}