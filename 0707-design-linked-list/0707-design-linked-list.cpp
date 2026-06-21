class MyLinkedList {
public:
    
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };
    
    Node* head;
    int size;

    MyLinkedList() {
        head = new Node(0); // dummy node
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        
        Node* curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head->next;
        head->next = node;
        size++;
    }
    
    void addAtTail(int val) {
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        
        Node* node = new Node(val);
        node->next = curr->next;
        curr->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */