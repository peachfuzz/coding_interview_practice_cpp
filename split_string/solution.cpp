#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
  public:
    vector<int> partitionLabels(string S)
    {
        int last[26] = {};

        // finding max position of each letter
        for (int i = 0; i < S.length(); ++i)
        {
            last[S[i] - 'a'] = i;
        }

        int j = 0, anchor = 0;

        // here's where we'll store our values
        vector<int> ans;

        for (int i = 0; i < S.length(); ++i)
        {
            j = j > last[S[i] - 'a'] ? j : last[S[i] - 'a'];
            cout << j << endl;
            if (i == j)
            {
                // adding
                ans.push_back(i - anchor + 1);
                // always ahead of i
                anchor = i + 1;
            }
        }

        return ans;
    }
};

int main()
{
    string line = "ababcbacadefegdehijhklij";
    // getline(cin, line);
    vector<int> ret = Solution().partitionLabels(line);
    return 0;
}
