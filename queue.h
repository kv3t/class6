#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "list.h"
using namespace std;

template <typename T>
class queue : public list<T>
{
public:
    queue () {
        head = NULL;
        tail = NULL;
    }
    queue (const queue& q)  {
        typename list<T>::node *curr = q.head;
        this->head = new typename list<T>::node;
        typename list<T>::node *p = this->head;
        p->data = curr->data;
        while (curr->next != NULL) {
            p->next = new typename list<T>::node;
            p->data = curr->data;
            curr = curr->next;
            p = p->next;
        }
        p->data = curr->data;
        p ->next = NULL;
        this->tail = p;
    }
    queue<T>& operator = ( const queue<T>& q ) {
        if ( head != NULL ){
            empty();
        }
        typename list<T>::node *curr = q.head;
        this->head = new typename list<T>::node;
        typename list<T>::node *p = this->head;
        p->data = curr->data;
        while ( curr->next != NULL ) {
            p->next = new typename list<T>::node;
            p->data = curr->data;
            curr = curr->next;
            p = p->next;
        }
        p->data = curr->data;
        p->next = NULL;
        this->tail = p;
        return *this;
    }
    queue (queue&& q) {
        if ( head != NULL ) {
        head = q.head;
        q.head = NULL; }
    }
    queue<T>& operator = (queue<T>&& q) {
        if ( head != NULL ) {
            empty();
        }
        head = q.head;
        q.head = NULL;
        return *this;
    }
    bool is_empty () const {
        if ( head == NULL )
            return true;
        else
            return false;
    }
    void push(T data) {
        typename list<T> :: node *p;
        p = new typename list<T> :: node;
        p->data = data;
        if ( head == NULL ) {
            head = p;
            tail = p;
            tail->next = NULL;
        }
        else {
            tail->next = p;
            tail = p;
            tail->next = NULL;
        }
    }
    T pop () {
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
    T getfront () const {
        if ( is_empty() ) {
            throw "Error";
            return 0;
        }
        return head->data;
    }
    ostream& print(ostream& out) const {
        if (head == NULL)
            out << "Очередь пуста";
        else {
            typename list<T> :: node *p;
            p = head;
            while (p != NULL) {
                out << p->data << " ";
                p = p->next;
            }
        }
        return out;
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
        tail = NULL;
    }
    ~queue() { empty(); }
    private:
    typename list<T> :: node *head;
    typename list<T> :: node *tail;
};

#endif // QUEUE_H_INCLUDED

