#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {

        unordered_set<int> seen;

        for (int num : nums)
        {

            // If number already exists, duplicate found
            if (seen.find(num) != seen.end())
            {
                return true;
            }

            seen.insert(num);
        }

        return false;
    }
};

int main()
{

    Solution solution;

    vector<int> nums = {1, 2, 3, 1};

    bool result = solution.containsDuplicate(nums);

    if (result)
    {
        cout << "Duplicate Found" << endl;
    }
    else
    {
        cout << "No Duplicate" << endl;
    }

    return 0;
}