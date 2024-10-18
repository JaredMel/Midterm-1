#include <iostream>
using namespace std;
//Declares and Initilizes variables
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
//the DoublyLinkedList Class
class DoublyLinkedList {
private:
    //the Node struct
    struct Node {
        //Declares and Initilizes attributes
        int data;
        Node* prev;
        Node* next;
        //Node constructor
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            //Sets attribute values
            data = val;
            prev = p;
            next = n;
        }
    };
    //Declares and initilizes attributes
    Node* head;
    Node* tail;
public:
    //DoublyLinkedList constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }
    //the insert_after method
    void insert_after(int value, int position) {
        //Checks if position is less than 0
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }
        //Creates the new Node struct with its values set to value
        Node* newNode = new Node(value);
        //Checks if the list is empty
        if (!head) {
            head = tail = newNode;
            return;
        }
        //Creates a temp node and sets it to head
        Node* temp = head;
        //Traverses the DoublyLinkedList to find the correct position
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;
        //Checks if position exceeds the List's size and deletes the Node
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }
        //adds the newNode by 
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return;

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (pos == 1) {
            pop_front();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }

        if (!temp->next) {
            pop_back();
            return;
        }

        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid
compiler warning


    return 0;
}