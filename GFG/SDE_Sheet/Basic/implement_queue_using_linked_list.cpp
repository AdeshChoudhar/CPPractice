// Function to push an element into the queue.
void MyQueue::push(int x)
{
    QueueNode *node = new QueueNode(x);
    if ((this->front == nullptr) && (this->rear == nullptr))
    {
        this->front = node;
        this->rear = node;
    }
    else
    {
        this->rear->next = node;
        this->rear = node;
    }
}

// Function to pop front element from the queue.
int MyQueue::pop()
{
    if (front == nullptr)
    {
        return -1;
    }
    QueueNode *tmp = this->front;
    this->front = tmp->next;
    if (this->front == nullptr)
    {
        this->rear = nullptr;
    }
    int top = tmp->data;
    delete tmp;
    return top;
}
