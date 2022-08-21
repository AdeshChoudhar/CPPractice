// Function to push an integer into the stack.
void MyStack::push(int x)
{
    StackNode *node = new StackNode(x);
    node->next = this->top;
    this->top = node;
}

// Function to remove an item from top of the stack.
int MyStack::pop()
{
    if (this->top == nullptr)
    {
        return -1;
    }
    StackNode *tmp = this->top;
    this->top = tmp->next;
    int top = tmp->data;
    delete tmp;
    return top;
}
