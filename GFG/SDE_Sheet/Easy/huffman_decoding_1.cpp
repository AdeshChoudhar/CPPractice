/*Complete the function below
Which contains 2 arguments
1) root of the tree formed while encoding
2) Encoded String*/
string decode_file(struct MinHeapNode *root, string s)
{
    string ans;
    for (int i = 0, n = s.length(); i < n;)
    {
        struct MinHeapNode *curr = root;
        while (curr != nullptr)
        {
            if ((curr->left == nullptr) && (curr->right == nullptr))
            {
                ans.push_back(curr->data);
                break;
            }
            if (s[i] == '0')
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
            i += 1;
        }
    }
    return ans;
}
