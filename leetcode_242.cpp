// valid anagram

// sort
bool isAnagram(string s, sting t) {
  if (s.length() != t.length()) {
    return false;
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s == t;
}

// hash table
bool isAnagram(string s, sting t) {
  if (s.length() != t.length()) {
    return false;
  }
  unordered_map<char, int> m;
  for (int i = 0; i < s.length(); i++) {
    m[c[i]]++;
    m[t[i]]--;
  }
  for (auto c : m) {
    if (c.second) {
      return false;
    }
    return true;
  }
}