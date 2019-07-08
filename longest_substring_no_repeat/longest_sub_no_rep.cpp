#include <string>        // strings
#include <unordered_map> // hashmap
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty()) // return if empty string
        {
            return 0;
        }

        int length = s.length(); // small optimization
        int answer = 0;
        int temp_answer = 0;
        unordered_map<char, int> characters;

        // edge case: abcabcda
        for (int i = 0; i < length; i++)
        {
            if (characters.find(s[i]) == characters.end()) // not found in string
            {
                pair<char, int> item(s[i], 1);
                characters.insert(item);
                temp_answer++;
            }
            else
            {
                printf("temp: %d\n", temp_answer);
                if (answer < temp_answer)
                    answer = temp_answer;

                temp_answer = 0;
                characters.clear(); // start over
            }
        }

        // go backwards
        for (int i = length - 1; i >= 0; i--)
        {
            if (characters.find(s[i]) == characters.end())
            {
                pair<char, int> item(s[i], 1);
                characters.insert(item);
                temp_answer++;
            }
            else
            {
                if (answer < temp_answer)
                    answer = temp_answer;

                temp_answer = 0;
                characters.clear(); // start over
            }
        }

        return answer;
    }
};

// problem: find longest substring without repeating characters
// ex: string = abcda
// answer: abcd
// ex: string = bbbb
// answer: b

int main()
{
    int answer = 0;
    string test = "abcabcbb"; // other tests - "bbbbbb" (1, b), "pwwkew" (3, kew)
    int actual_answer_length = 8;
    string actual_answer = "abc";

    answer = Solution().lengthOfLongestSubstring(test);
    printf("%d\n", answer);
    return 0;
}