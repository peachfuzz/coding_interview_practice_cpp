#include <vector>
#include <iostream>
#include <unordered_map> // hashmap

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> answer;
        
        unordered_map<int, int> found_number; // for o(n) answer

        for (int i = 0; i < nums.size(); i++)
        {
            // brute force, o(n^2)
            // for (int j = i + 1; j < nums.size(); j++)
            // {
            //     if (nums[i] + nums[j] == target)
            //     {
            //         answer.push_back(i);
            //         answer.push_back(j);
            //         return answer;
            //     }
            // }
            // brute force, o(n^2)
            
            // one-pass hashmap o(n)
            int comp = target - nums[i];

            if (found_number.find(comp) != found_number.end()) // found 
            {
                answer.push_back(found_number.find(comp)->second);
                answer.push_back(i);
                return answer;
            }
            found_number.insert({nums[i], i});
            // one-pass hashmap o(n)
        }

        return answer;
    }
};

int main()
{
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> nums(arr, arr + n);

    int targ = 9;
    vector<int> ret = Solution().twoSum(nums, targ);
    return 0;
}