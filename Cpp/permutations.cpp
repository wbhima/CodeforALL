#include <bits/stdc++.h>
#define N 4
using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return {nums};
    }
    vector<vector<int>> ans;
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        vector<int> temp(nums.begin(), nums.end());
        temp.erase(find(temp.begin(), temp.end(), *it));
        vector<vector<int>> tempans = permute(temp);
        for (auto x : tempans)
        {
            x.insert(x.begin(), *it);
            ans.push_back(x);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums(4, 0);
    for (int i = 0; i < 4; i++)
        cin >> nums[i];
    vector<vector<int>> permutations = permute(nums);
    for (auto vec : permutations)
    {
        for (auto num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}