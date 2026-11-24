using namespace std;

// Node
template <typename T>
class Node {
public:
  // Store the data of the node
  T data;

  // Pointer to the next node
  Node<T>* next;

  // Explicit parameterized constructor
  explicit Node(T data) : data(data), next(nullptr) {}
};

// LinkedList
template <typename T>
class LinkedList {
public:
  // Head pointer of the linked list
  Node<T>* head;

  // Default constructor
  LinkedList() : head(nullptr) {}

  // Explicit parameterized constructor
  explicit LinkedList(const vector<T>& vec) : head(nullptr) {
    if (vec.empty()) {
      return;
    }

    Node<T>* curr = nullptr;

    for (auto x : vec) {
      if (curr == nullptr) {
        this->head = new Node<T>(x);
        curr = this->head;
      } else {
        curr->next = new Node<T>(x);
        curr = curr->next;
      }
    }
  }

  // Disallow copy constructor
  LinkedList(const LinkedList&) = delete;

  // Disallow copy assignment
  LinkedList& operator=(const LinkedList&) = delete;

  // Allow move constructor
  LinkedList(LinkedList&& ll) noexcept : head(exchange(ll.head, nullptr)) {}

  // Allow move assignment
  LinkedList& operator=(LinkedList&& ll) noexcept {
    if (this != &ll) {
      clear();
      head = ll.head;
      ll.head = nullptr;
    }
    return *this;
  }

  // Destructor
  ~LinkedList() {
    clear();
  }

private:
  // Helper function to clear the linked list
  void clear() {
    Node<T>* next;
    while (this->head != nullptr) {
      next = this->head->next;
      delete this->head;
      this->head = next;
    }
  }
};
