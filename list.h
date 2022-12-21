#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

using namespace std;

template <typename T>
class list
{
public:
    virtual T pop() = 0;
    virtual T getfront() const = 0;
    virtual bool is_empty() const = 0;
    virtual T size() const = 0;
    virtual void empty() = 0;

    friend ostream& operator<< (ostream &out, list& f){
        f.print(out);
        return out;
        };
    friend istream& operator>> (istream &in, list &f){
        T data;
        in>>data;
        f.push(data);
        return in;
        };
    virtual ~list () {};
protected:
    virtual ostream& print (ostream &out) const = 0;
    virtual void push(T data) = 0;
    struct node {
    T data;
    list<T> :: node *next;
};
};

#endif // LIST_H_INCLUDED
