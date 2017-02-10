// keyboard row

// 哈希表存储字母以及对应行的关系
// 检查每个单词中的字母是否属于同一行

class Solution{

public:

  vector<string> findWords(vector<string> &words){
    for(auto &c:"qwertyuiop") m[c]=1;
    for(auto &c:"asdfghjkl") m[c]=2;
    for(auto &c:"zxcvbnm") m[c]=3;

    vector<string> res;
    for(auto w:words){
      if (sameRow(w)) res.push_back(w);
    }
    return res;
  }

  bool sameRow(const string &s){
    if(s.empty()) return true;
    int row = m[tolower(s[0])];
    for(auto &c:s){
      if (m[tolower[c]] != row) return false;
    }
    return true;
  }

private:
  unordered_map<char,int> m;

}