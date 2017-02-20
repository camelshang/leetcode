// first unique character in a string

int firstUniqChar(string s)
{
    if (s.size() == 1)
    {
        return 0;
    }
    unordered_map<char, int> m;
    for (auto &c : s)
    {
        m[c]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}