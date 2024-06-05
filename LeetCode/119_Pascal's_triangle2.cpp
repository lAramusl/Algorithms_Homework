class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        std::vector<int> ans(rowIndex + 1);
        std::size_t n = ans.size();
        long long factor = 1;
        for (std::size_t i = 0; i < (ans.size() / 2) + 1; ++i)
        {
            ans[i] = factor;
            ans[n - i - 1] = factor;
            factor = (factor * (n - i - 1)) / (i + 1);
        }

        return ans;
    }
};