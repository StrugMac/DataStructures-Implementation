/* Easy Implementation of Stack Data-Structure, Just go through the code you will find it very simple and easy to understand. It is implemented in C++ programming
    language.
   
   1. Stack is a Linear DataStructure which operates in a LIFO(last in first out) or FILO(first in last out).
   2. Stack is an abstract Data type.
   3. Operations on Stack:
      a) Push: to add an element in stack from the top of the stack.
      b) Pop: to delete an element from the top of the stack
      c) Peek: to access the particular element at i'th location.
      d) count: to count the elements in a stack.
      e) change: to change the item with another item in a particular loaction.
   
    4. In this i have taken the fixed array size that is 5, you can dynamically take the array size.
  
  Let's go ahead and implement it..!   */


#include <iostream> 
using namespace std; 

  class StackImplementation
  { 
      private: 
      int top; 
      int arr[5]; 
     public:
  StackImplementation()
  { 
    top=-1;
    for(int i=0;i<5;i++)
    { 
    arr[i]=0; 
    } 
  }
  bool isEmpty()
    { 
    if(top==-1)
    return true; 
    else
    return false; 
    } 
  bool isFull()
  { 
   if(top==4)
    return true; 
    else
   return false; 
  } 
 void push(int val)
  {
  if(isFull())
  { 
  cout<<"cannot insert element stack overflow..!"; 
  } 
  else 
  { 
  top++; 
  arr[top]=val; 
  } 
  } 
  
 int pop()
  { 
  if(isEmpty())
  { 
  cout<<"cannot pop element stack is empty..!"; 
  return 0; 
  } 
  else
  {
 int popvalue=arr[top]; 
  arr[top] = 0;
  top--;
  return popvalue; 
  } 
  } 
int count()
{ 
return(top+1); 
} 
int peek(int pos)
{ 
if(isEmpty())
{ 
cout<<"stack underflow..!"; 
} 
else
{
return arr[pos]; 
} 
} 
void change(int pos,int val)
{ 
arr[pos]=val; 
cout<<"value changed at location "<<pos<<endl; 
} 
void display()
{
cout<<"All values in the Stack are : "; 
for(int i=4;i>=0;i--)
{ 
cout<<arr[i]<<endl; 
}
} 
};

int main() 
{ 
StackImplementation s1;
int option,position,value; 
do
{ 
  cout<<"What operation you want to perform? Select from the options below. Enter 0 to exit"<<endl; 
  cout<<"1.Push()"<<endl;
  cout<<"2.Pop()"<<endl;
  cout<<"3.isEmpty()"<<endl;
  cout<<"4.isFull()"<<endl;
  cout<<"5.Peek()"<<endl;
  cout<<"6.count()"<<endl;
  cout<<"7.change()"<<endl;
  cout<<"8.display"<<endl;
  cout<<"9.Clear the screen"<<endl<<endl;
  cin>>option; 
  
switch(option)
   {
    case 1: 
        cout<<"enter an item to push in stack"<<endl; 
        cin>>value;
        s1.push(value);
        cout<<"item pushed"; 
        break; 
    case 2:
        cout<<"value is popped"<<s1.pop()<<endl; 
        break; 
    case 3: 
        if(s1.isEmpty())
        cout<<"stack is empty"; 
        else 
        cout<<"stack is not empty";  
        break; 
    case 4: 
        if(s1.isFull())
        cout<<"stack is full"; 
        else
        cout<<"stack is not full"; 
        break; 
    case 5: 
        cout<<"enter the position to fetch the value "; 
        cin>>position;
        cout<<"value at position "<<position<<" is "<<s1.peek(position)<<endl; 
        break;
    case 6:
        cout<<" total elements in stack are "<<s1.count(); 
        break; 
    case 7:
        cout<<" enter the position where you want to change element"; 
        cin>>position; 
        cout<<endl;
        cout<<"enter the value to be entered at "<<endl; 
        cin>>value;
        s1.change(position,value);
        break; 
    case 8: 
        cout<<"display function is called "<<endl; 
        s1.display();
        break; 
    case 9: 
        system("cls"); 
        break; 
    default:
         cout<<" enter the correct option..!"<<endl; 
} 
}
   while(option!=0); 
return 0; 
}
