#include"Stack.h"

template<typename E>
Stack<E>::Stack<E>()
{
  topOfStack=NULL;
  items=0;
}


template<typename E>
Stack<E>::~Stack<>()
{
  makeEmpty();
}


template<typename E>
const Stack<E>& Stack<E>::operator=(const Stack<E>& rhs)
{
    if(*this!=&rhs)
    {
        makeEmpty();
        if(rhs.isEmpty())
            return *this;
        ListNode* rptr= rhs.topOfStack;
        ListNode* ptr= new ListNode(rptr->element);
        topOfStack=ptr;
        for(rptr=rptr->next;rptr!=NULL;rptr=rptr->next)
        {
            ptr=ptr->next=new ListNode(rptr->element);
        }
    }

    return *this;
}


template<typename E>
Stack<E>::Stack<E>(const Stack<E>& rhs)
{
    topOfStack=NULL; // kyun kiye nhi samajh mein aaya.
   *this=rhs; // I THInk OVERLOADED ASSIGNMENT OPERATOR IS BEING INVOKED HERE
}


template<typename E>
bool Stack<E>::isEmpty() // my thinking notsure.
{
    return items==0;
}


template<typename E>
void Stack<E>::push(const E& e)
{
     topOfStack=new ListNode(e,topOfStack);
     items++;    // my thinking notsure.
}


template<typename E>
void Stack<E>::pop()
{
    if(isEmpty)
        throw UnderflowException();
    ListNode* oldTop= topOfStack;
    topofStack=topofStack->next;
    delete oldTop;
    items--;  // my thinking notsure.
}


template<typename E>
const E& Stack<E>::top() const
{
    if(isEmpty)
      throw UnderflowException();
    return topOfStack->element;
}


template<typename E>
void Stack<E>::makeEmpty()
{
    while(!isEmpty())
      pop();
}


template<typename E>
int Stack<E>::size() const
{
    return items;
}
