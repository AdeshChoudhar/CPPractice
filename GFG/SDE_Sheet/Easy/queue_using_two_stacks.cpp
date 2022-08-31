// Function to push an element in queue by using 2 stacks.
void StackQueue::push(int x)
{
    while (!(this->s1.empty()))
    {
        this->s2.push(this->s1.top());
        this->s1.pop();
    }
    this->s1.push(x);
    while (!(this->s2.empty()))
    {
        this->s1.push(this->s2.top());
        this->s2.pop();
    }
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue::pop()
{
    int ans = -1;
    if (!(this->s1.empty()))
    {
        ans = this->s1.top();
        this->s1.pop();
    }
    return ans;
}
