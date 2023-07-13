#include "Cmplx_class.h"

void insert(char op, const Cmplx_number &c)
{
    Stack *temp = new Stack();
    temp->op_name = op;
    temp->stackObject=c;
    temp->right = NULL;
    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        top->right=temp;
        top=temp;
    }
}

void display_stack()
{
 if(top==NULL)
 {
    cout<<"Stck underflow";
    return;
 } 
  Stack *temp = new Stack();
  temp=top;
    do{
        cout<<"Operation :- "<<temp->op_name<<endl;
        cout<<temp->stackObject<<endl;
        temp=temp->right;
    }while(temp!=NULL);
}

Cmplx_number return_object()
{
    if(top == NULL)
    {
        Cmplx_number temp;
        return (temp);
    }
    return (top->stackObject);
}