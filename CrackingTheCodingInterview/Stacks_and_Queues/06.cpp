//
// Problem: An animal shelter, which holds only dogs and cats, operates on a
//          strictly "first in, first out" basis. People must adopt either the
//          "oldest" (based on arrival time) of all animals at the shelter, or
//          they can select whether they would prefer a dog or a cat (and will
//          receive the oldest animal of that type). They cannot select which
//          specific animal they would like. Create the data structures to
//          maintain this system and implement operations such as enqueue,
//          dequeueAny, dequeueDog, and dequeueCat. You may use the built-in
//          Linked List data structure
//

#include "../../utils/utils.h"

class AnimalShelterQueue {
private:
  int time;

  // NOTE: LinkedList is not the optimal choice, use stack for simplicity.
  LinkedList<int> cats;
  LinkedList<int> dogs;

  Node<int>* catsTail;
  Node<int>* dogsTail;

public:
  AnimalShelterQueue() : time(0), catsTail(nullptr), dogsTail(nullptr) {}

  string enqueue(string animal) {
    string res = "Unknown. Registration not done.";

    if (animal == "cat") {
      Node<int>* cnode = new Node(this->time);
      if (this->cats.head == nullptr) {
        this->cats.head = cnode;
        this->catsTail = cnode;
      } else {
        this->catsTail->next = cnode;
        this->catsTail = cnode;
      }
    } else if (animal == "dog") {
      Node<int>* dnode = new Node(this->time);
      if (this->dogs.head == nullptr) {
        this->dogs.head = dnode;
        this->dogsTail = dnode;
      } else {
        this->dogsTail->next = dnode;
        this->dogsTail = dnode;
      }
    } else {
      return res;
    }

    string name;
    name.push_back(animal[0] + ('A' - 'a'));
    name += animal.substr(1) + "#" + to_string(this->time);

    res = name + " is registered.";

    this->time += 1;

    return res;
  }

  string dequeueAny() {
    string res = "Unavailable. All animals were adopted.";

    if ((this->cats.head != nullptr) && (this->dogs.head != nullptr)) {
      if (this->cats.head->data < this->dogs.head->data) {
        res = this->dequeueCat();
      } else {
        res = this->dequeueDog();
      }
    } else if (this->cats.head != nullptr) {
      res = this->dequeueCat();
    } else if (this->dogs.head != nullptr) {
      res = this->dequeueDog();
    }

    return res;
  }

  string dequeueCat() {
    string res = "Unavailable. All cats were adopted.";

    if (this->cats.head == nullptr) {
      return res;
    }

    res = "Cat#" + to_string(this->cats.head->data) + " is adopted.";

    Node<int>* cnode = this->cats.head;
    this->cats.head = this->cats.head->next;
    cnode->next = nullptr;
    delete cnode;

    if (this->cats.head == nullptr) {
      catsTail = nullptr;
    }

    return res;
  }

  string dequeueDog() {
    string res = "Unavailable. All dogs were adopted.";

    if (this->dogs.head == nullptr) {
      return res;
    }

    res = "Dog#" + to_string(this->dogs.head->data) + " is adopted.";

    Node<int>* dnode = this->dogs.head;
    this->dogs.head = this->dogs.head->next;
    dnode->next = nullptr;
    delete dnode;

    if (this->dogs.head == nullptr) {
      this->dogsTail = nullptr;
    }

    return res;
  }
};

int main() {
  AnimalShelterQueue asq;

  vector<vector<string>> ops = {
      {"dequeueAny"},
      {"dequeueCat"},
      {"dequeueDog"},
      {"enqueue", "cat"},
      {"enqueue", "cat"},
      {"dequeueAny"},
      {"enqueue", "dog"},
      {"enqueue", "dog"},
      {"dequeueAny"},
      {"enqueue", "cat"},
      {"enqueue", "dog"},
      {"dequeueAny"},
      {"dequeueCat"},
      {"dequeueDog"},
      {"dequeueDog"},
      {"dequeueAny"},
      {"enqueue", "bird"},
  };

  cout << "INPUT(s):" << endl;
  printMatrix(ops, "ops = ");

  vector<string> ans;

  for (auto op : ops) {
    if (op[0] == "enqueue") {
      ans.push_back(asq.enqueue(op[1]));
    } else if (op[0] == "dequeueAny") {
      ans.push_back(asq.dequeueAny());
    } else if (op[0] == "dequeueCat") {
      ans.push_back(asq.dequeueCat());
    } else if (op[0] == "dequeueDog") {
      ans.push_back(asq.dequeueDog());
    }
  }

  cout << "OUTPUT(s):" << endl;
  for (auto res : ans) {
    cout << res << endl;
  }

  return 0;
}
