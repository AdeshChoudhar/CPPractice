// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;

    int kthLargest(Node *root, int K)
    {
        int ans;
        kthLargestUtil(root, K);
        ans = pq.empty() ? -1 : pq.top();
        return ans;
    }

    void kthLargestUtil(Node *root, int K)
    {
        if (root == nullptr)
        {
            return;
        }
        if (pq.size() < K)
        {
            pq.push(root->data);
        }
        else
        {
            pq.push(root->data);
            pq.pop();
        }
        kthLargestUtil(root->left, K);
        kthLargestUtil(root->right, K);
    }
};
