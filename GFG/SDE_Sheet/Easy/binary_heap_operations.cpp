// Function to extract minimum value in heap and then to store
// next minimum value at first index.
int MinHeap::extractMin()
{
    if (this->heap_size <= 0)
    {
        return -1;
    }
    if (this->heap_size == 1)
    {
        this->heap_size -= 1;
        return this->harr[0];
    }
    else
    {
        int mnm = this->harr[0];
        this->heap_size -= 1;
        this->harr[0] = this->harr[this->heap_size];
        this->MinHeapify(0);
        return mnm;
    }
}

// Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    if (i >= this->heap_size)
    {
        return;
    }
    this->decreaseKey(i, INT_MIN);
    this->extractMin();
}

// Function to insert a value in Heap.
void MinHeap::insertKey(int k)
{
    if (this->heap_size == this->capacity)
    {
        return;
    }
    this->decreaseKey(this->heap_size, k);
    this->heap_size += 1;
}
