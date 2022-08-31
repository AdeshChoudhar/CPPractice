// Function to push an element into stack using two queues.
void QueueStack::push(int x)
{
    while (!(this->q1.empty()))
    {
        this->q2.push(this->q1.front());
        this->q1.pop();
    }
    this->q1.push(x);
    while (!(this->q2.empty()))
    {
        this->q1.push(this->q2.front());
        this->q2.pop();
    }
}

// Function to pop an element from stack using two queues.
int QueueStack::pop()
{
    int ans = -1;
    if (!(this->q1.empty()))
    {
        ans = this->q1.front();
        this->q1.pop();
    }
    return ans;
}
