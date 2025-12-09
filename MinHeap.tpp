template <typename T>
void MinHeap<T>::siftUp(int i) {
    while (i > 0 && data[i] < data[parent(i)]) {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    int n = data.size();
    while (true) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < n && data[l] < data[smallest])
            smallest = l;
        if (r < n && data[r] < data[smallest])
            smallest = r;

        if (smallest == i)
            break;

        swap(data[i], data[smallest]);
        i = smallest;
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    data.push_back(value);
    siftUp(data.size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue = data[0];
    if (data.empty())
        throw runtime_error("Heap is empty");

    
    data[0] = data.back();
    data.pop_back();
    if (!data.empty())
        siftDown(0);

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    siftUp(index);
    siftDown(index);
}
