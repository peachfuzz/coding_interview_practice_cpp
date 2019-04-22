#include <vector>
#include <iostream>

using namespace std;

class Solution
{
  public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        vector<int> answer = cells;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < cells.size(); j++)
            {
                if (0 < j && j < cells.size() - 1)
                {
                    if (cells[j - 1] == 0 && cells[j + 1] == 0)
                    {
                        answer[j] = 1;
                    }
                    else if (cells[j - 1] == 1 && cells[j + 1] == 1)
                    {
                        answer[j] = 1;
                    }
                    else
                    {
                        answer[j] = 0;
                    }
                }
                else
                { // for first and last items
                    answer[j] = 0;
                }
            }
            cells = answer;
        }
        cout << "ended double loop\n";
        for (int x : answer)
            cout << x << " ";
        cout << endl;
        return answer;
    }
};

int main()
{
    int arr[] = {1, 0, 0, 1, 0, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> prison(arr, arr + n);

    int days = 1000;
    vector<int> ret = Solution().prisonAfterNDays(prison, days);
    return 0;
}