class MyCircularQueue {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;
    int capacity;
public:
    
    MyCircularQueue(int k) {
       front=rear=NULL;
       size=0;
       capacity=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        Node *t=new Node(value);
        if(isEmpty()){
            front=rear=t;
            rear->next=front;
        }else{
            rear->next=t;
            rear=t;
            rear->next=front;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front==rear){
            delete front;
            front=rear=NULL;
        }else{
            Node *t=front;
            front=front->next;
            rear->next=front;
            delete t;
        }
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:front->val;
    }
    
    int Rear() {
        return isEmpty()?-1:rear->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */