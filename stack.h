#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "list.h"
using namespace std;

template <typename T>
class stack : public list<T>
{
private :
    typename list<T> :: node *head;
public:
    stack () {
        head = NULL;
    }
    bool is_empty () const {
        if ( head == NULL )
            return true;
        else
            return false;
    }
    stack (const stack& s)  {
        typename list<T> :: node *p1;
        typename list<T> :: node *p2;
        typename list<T> :: node *p3;
        head = NULL; p3 = NULL;
        p1 = s.head;
        while ( p1 != NULL ) {
            p2 = new typename list<T> :: node;
            p2->data = p1->data;
            p2->next = NULL;
            if ( head == NULL ) {
                head = p2;
                p3 = p2;
            }
            else {
                p3->next = p2;
                p3 = p3->next;
            }
            p1 = p1->next;
        }
    }
    stack<T>& operator = (const stack<T>& s) {
        if ( head != NULL ) empty();
        typename list<T> :: node *p1;
        typename list<T> :: node *p2;
        typename list<T> :: node *p3;
        head = NULL; p3 = NULL;
        p1 = s.head;
        while ( p1 != NULL ) {
            p2 = new typename list<T> :: node;
            p2->data = p1->data;
            p2->next = NULL;
            if ( head == NULL ) {
                head = p2;
                p3 = p2;
            }
            else {
                p3->next = p2;
                p3 = p3->next;
            }
            p1 = p1->next;
        }
        return *this;
    }
    stack (stack &&s) {
        head = s.head;
        s.head = NULL;
    }
    T size() const {
        if (head == NULL)
            return 0;
        else {
            typename list<T> :: node *p;
            p = head;
            int num = 0;
            while (p != NULL) {
                num++;
                p = p->next;
            }
            return num;
        }
    }
    void push(T data) {
        typename list<T> :: node *p;
        p = new typename list<T> :: node;
        p->data = data;
        p->next = head;
        head = p;
    }
     T pop() {
        if ( is_empty() ) {
            throw "Error";
            return 0;
            }
        typename list<T> :: node *p2;
        T data;
        data = head->data;
        p2 = head;
        head = head->next;
        delete p2;
        return data;
    }
    void empty() {
        typename list<T> :: node *p1;
        typename list<T> :: node *p2;
        p1 = head;
        while ( p1 != NULL ) {
            p2 = p1;
            p1 = p1->next;
            delete p2;
        }
        head = NULL;
    }
    ostream& print(ostream& out) const {
        if ( head == NULL )
            out << "Стек пуст";
        else {
            typename list<T> :: node *p;
            p = head;
            while ( p != NULL ) {
                out << p->data << " ";
                p = p->next;
            }
        }
        return out;
    }

    ~stack() { empty(); }

    T getfront () const {
        if ( is_empty() ) {
            throw "Error";
            return 0;
        }
        return head->data;
    }
};

#endif // STACK_H_INCLUDED

