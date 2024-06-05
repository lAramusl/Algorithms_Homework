class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> ans;
        ans.push_back({ 1 });
        for (int i = 1; i < numRows; ++i)
        {
            std::vector<int> temp;
            std::vector<int> current = ans.back();
            for (int j = 0; j < i + 1; ++j)
            {
                if (j == 0 || j == i)
                {
                    temp.push_back(1);
                }
                else
                {
                    temp.push_back(current[j - 1] + current[j]);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};