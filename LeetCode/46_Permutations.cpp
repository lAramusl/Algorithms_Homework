class Solution {
public:
    void f_warper(const std::vector<int>& vec, vector<vector<int>>& ans)
    {
        std::vector<std::pair<int, bool>> toBeSend(vec.size());
        for (std::size_t i = 0; i < vec.size(); ++i)
        {
            toBeSend[i].first = vec[i];
            toBeSend[i].second = false;
        }
        std::vector<int> permut;
        f(toBeSend, permut, ans);
    }

    void f(std::vector<std::pair<int, bool>>& vec, std::vector<int>& permut, vector<vector<int>>& ans)
    {
        if (permut.size() == vec.size())
        {
            ans.push_back(permut);
            return;
        }

        for (std::size_t i = 0; i < vec.size(); ++i)
        {
            if (!vec[i].second)
            {
                permut.push_back(vec[i].first);
                vec[i].second = true;
                f(vec, permut, ans);
                vec[i].second = false;
                permut.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        f_warper(nums, ans);

        return ans;
    }





};