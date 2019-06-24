#include <stdio.h>
#include <stddef.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// given 2 lists, add numbers from left to right
// list is backwards
// ex: 2 > 3 > 4, 5 > 3 > 7
// 432 + 735 = 1167

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *num_one, ListNode *num_two)
    {
        ListNode *my_answer = NULL;
        int single_place = 0;
        int next_place = 0;

        while (num_one->val != NULL || num_two->val != NULL)
        {
            single_place = num_one->val + num_one->val + next_place;
            next_place = 0;
            if (single_place > 9) // highest possible output is 18
            {
                my_answer->val = single_place - 10;
                next_place = 1;
            }
            else // addition is 9 or less
            {
                my_answer->val = single_place;
            }
        }

        if (num_one->val == NULL && num_two->val == NULL)
        {
            return my_answer;
        }
        else if (num_one->val == NULL)
        {
        }
        else if (num_two->val == NULL) // not sure if I need this check, by deduction this is it
        {
        }
    }
};

int main()
{

    return 0;
}