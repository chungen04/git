#include <iostream>
using namespace std;

class Node{

public:
    Node(){
        next = NULL;
    }//constructor
    Node(int _element){
        element = _element;
        next = NULL;
    }//also constructor: function overload: decided by datatype

protected:
    int element;
    Node* next;

};

class List{

public:
    List(){
        first = NULL;
    }//constructer: no returning type
    //constructor is only called when calling list for the first time(by compiler; no need to be coded)
    ~List(){//destructor: release memory
        while(first != NULL){
            erase();
        }
    }
    void insert(int element){
        if(first == NULL){//the list is empty
            /*
            first = new Node;//allocate memory: first is already declared as a pointer
            first->element = element;//the first element is type of Node and the _element is argument of insert
            */
            first = new Node(element);//first is a Node* :create the first
        }else{
            Node* p = new Node(element);// element and next is not assigned
            //first pointed to p, p point to the next
            //(*p).next = first;
            p->next = first;//is equivalent to the above statement but much as an expert(?)
            first = p;
        }
    }
    void printOut(){
        Node* p = first;
        //loop time is unknown
        while( p != NULL){
            //end condition p=NULL
            cout << p->element << "->";
            p = p->next;//next p
        }
        cout << "NULL" << endl;
    }
    void erase(){
        // dont erase if there's nothing
        if(first == NULL){
            return;
        }else{
            //1. assign next to first's next. 2. release.
            Node* p = first;
            first = p->next;
            //once p's next is NULL then first = NULL, then if erase again, first = NULL is detected and nothing would be done.
            delete p;
        }
    }

protected:
    Node* first;

};

int main(){
    /*-
    Node a;
    a.element = 3;*/
    List list;
    list.insert(3);
    list.insert(4);
    list.insert(1);
    list.insert(5);
    list.insert(45);

    list.printOut();

    list.erase();

    /*
    when calling class ends
    class automatically calls destructor(can't overload, no return)
    here we want to release the memory which is newed in new Node(element)
    that is, ~List(){}
    */

    system("pause");
    return 0;
}
