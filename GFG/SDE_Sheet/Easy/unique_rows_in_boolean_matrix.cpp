/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    vector<vector<int>> ans;
    unordered_set<long long> us;
    for (int i = 0; i < row; i++)
    {
        vector<int> row;
        long long num = 0;
        for (int j = 0; j < col; j++)
        {
            row.push_back(M[i][j]);
            if (M[i][j] == 1)
            {
                num += pow(2, col - j - 1);
            }
        }
        if (us.find(num) == us.end())
        {
            ans.push_back(row);
            us.insert(num);
        }
    }
    return ans;
}
