#ifndef STACK_H_
#define STACK_H_

template<typename E>
class Stack
{
public:
    Stack();
    Stack(const Stack& rhs);
    ~Stack();
    const Stack& operator=(const Stack& rhs);
    int size() const;
    bool isEmpty() const;
    void makeEmpty();
    void push(const E& e);
    void pop();
    const E& top() const;

private:
    struct ListNode
    {
        E element;
        ListNod* next;

        ListNode(const &E theElement, ListNode* n=NULL): element(theElement), next(n) {} // EK TYPE KA CONSTRUCTOR WITH DEFAULT
                                                        // ARGUMENTS AND THIS **INTIALIZES** THE STRUCTURE OBJECT AS SOON AS IT IS CREATED
                                                        //AS HAPPENEND IN CASE OF CONSTRUCTORS.PG-613 C++ PRIMER.
    };

    ListNode* topOfStack;
    items;
};
#endif // STACH_H_
