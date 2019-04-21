#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// suggested solution will not work when str is:
// abcabc
// will split by abca and bc
// pass through and hash all vals?

class Solution
{
  public:
    vector<int> partitionLabels(string S)
    {
        int last[26];
        for (int i = 0; i < S.length(); ++i)
            last[S[i] - 'a'] = i; // setting "last" values

        int j = 0, anchor = 0;

        // here's where we'll store our values
        vector<int> ans;

        for (int i = 0; i < S.length(); ++i)
        {
            j = j > last[S[i] - 'a'] ? j : last[S[i] - 'a'];
            if (i == j)
            {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;

        // int len = s.length();

        // int partLen = 0;

        // int left = 0;
        // int right = 0;

        // vector<int> answer;
        // int total = 0;

        // right = len;

        // map<char, int> element_and_count;

        // // for (auto x : element_and_count)
        // //     cout << x.first << " " << x.second << endl;

        // for (int i = 0; i < len; i++)
        // {

        //     // cout << s[i];
        //     element_and_count[s[i]]++;
        //     int j, k;
        //     for (j = len - 1; j >= i; j--)
        //     {
        //         if (s[i] == s[j] && element_and_count[s[i]] > 0)
        //         {
        //             // cout << s[i];
        //             total = total + right;
        //             partLen = j - i + 1;
        //             answer.push_back(partLen);
        //             cout << i << " " << j << "\n";
        //             k = i;
        //             i = j;
        //             break;
        //         }
        //     }

        //     // just for visualization purposes
        //     for (k = k; k <= i; k++)
        //     {
        //         cout << s[k];
        //         element_and_count[s[k]]++;
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // return answer;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line = "ababcbacadefegdehijhklij";
    // getline(cin, line);
    vector<int> ret = Solution().partitionLabels(line);

    string out = integerVectorToString(ret);
    cout << out << endl;
    return 0;
}
