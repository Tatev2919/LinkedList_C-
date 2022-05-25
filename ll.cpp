#include <iostream>
using namespace std;
class Node {
    public:
        int value;
        Node* prev = nullptr;
        Node* next = nullptr;
        Node (int x) {
            value = x;
            prev = nullptr;
            next = nullptr;
        }
};
class Linkedlist{
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
        int length = 0;
    public:
        void push_back(int x) {
            Node* temp = new Node(x);
            if (head == nullptr) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
            ++length;
        }
        void push_front(int x) {
            Node* temp = new Node(x);
            Node* h = head;
            if (is_empty()) {
                head = temp;
                tail = temp;
            } else {
                temp->next = head;
                head-> prev = temp;
                head = temp;
            }
            ++length;
        }
        int pop_back(){
            if (is_empty()){
                return -1;
            }
            Node* t = tail;
            tail = tail-> prev;
            tail-> next = nullptr;
            --length;
            return t-> value;
        }
        int pop_front(){
            if (is_empty()){
                return -1;
            }
            Node* h = head;
            head = head-> next;
            head-> prev = nullptr;
            --length;
            return h->value;
        }
        
        void print () {
            for( Node* tmp = head;tmp!= nullptr;tmp = tmp->next){
                cout<<tmp->value << endl;
            }
        }

        int get_node(int i){
            Node* tmp = head;
            if (i > length){
                return -1;
            }
            for(int j = 0;tmp!= nullptr && j != i; j++){
                tmp = tmp->next;
            }
            return tmp->value;
        }

        int pop(int i){
            Node* tmp = head;
            cout << length << " : length is " << endl;
            if (is_empty() || i > (length-1)){
                return -1;
            } 
            if (head == tail){
                head=tail=nullptr;
                return tmp->value;
            } 
            for(int j = 0;tmp!= nullptr && j != i; ++j){
                tmp = tmp->next;
            }
            if(tmp != tail){
                if (tmp!=head){
                    tmp->next->prev=tmp->prev;
                    tmp->prev->next = tmp->next;
                    cout<< tmp->value << endl;
                    --length;
                    return tmp->value;
                } else {
                    return pop_front();
                }
            } else {
                return pop_back();
            }
        }

        void insert(int value,int i) {
            Node* tmp = head;
            Node* add = new Node(value);
            if (is_empty()){
                head = tail = add;
            }
            if (i == 0) {
                cout << "test1" << endl; 
                push_front(value);
            }
            if (i == length){
                push_back(value);
            } else {

                cout << "test2: " << i << endl; 
                for(int j = 0; j != i; ++j){
                    tmp = tmp->next;
                }            
                tmp->prev->next = add;
                add->next = tmp;
                add->prev = tmp->prev;
                tmp->prev = add;
            }
        }
        
        void print_reverse () {
            for (Node* tmp = tail;tmp!= nullptr; tmp = tmp->prev){
                cout<<tmp->value << endl;
            }
        }
        bool is_empty() {
            return head == nullptr;
        }
};
int main () {
    Linkedlist ll;
    ll.push_back(4);
    ll.push_back(15);
    ll.push_back(17);
    ll.push_back(1);
    ll.push_back(6);
    ll.push_front(2);
    ll.print();
    cout << "Print reverse" << endl;
    ll.print_reverse();
    cout << "Pop_back" << endl;
    cout << ll.pop_back() << endl;
    cout << "Print" << endl;
    ll.print();
    cout << "Pop_front" << endl;
    cout << ll.pop_front() << endl;
    cout << "Print" << endl;
    ll.print();
    cout<< "get_node" << endl;
    cout << ll.get_node(5)<<endl;
    cout << ll.get_node(3)<<endl;
    cout << ll.get_node(0)<<endl;
    cout << "ll before pop by index"<<endl;
    ll.print();
    ll.pop(0);
    cout << "ll after pop by index"<<endl;
    cout << "ll before pop by index 1"<<endl;
    ll.print();
    ll.pop(3);
    
    cout << "add value from the middle"<<endl;
    ll.print();
    ll.insert(47,0);
    cout << "after adding value from the middle"<<endl;
    ll.print();

    cout << "after adding value from the middle"<<endl;
    ll.print();


    return 0;
}
