/* Easy Implementation of Circular Queue Data-Structure, Just go through the code you will find it very simple and easy to understand. It is implemented in C++ 
   programming language.
   
   Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and 
   the last position is connected back to the first position to make a circle. It is also called 'Ring Buffer'.
    
   
   1. Circular Queue is a Linear DataStructure which operates in a FIFO(first in first out) or LILO(Last in last out).
   2. Circular Queue is an abstract Data type.
   3. Elements are added from the rear/back side of the Circular queue - Enqueue operation
   4. Elements are removed from the head/front side of the Circular queue - Dequeue operation
   5. Operations on Queue:
      a) Enqueue: to add an element in Circular queue.
      b) Dequeue: to delete an element from the Circular queue.
      c) isFull: to check if the Circular queue is full or not.
      d) isEmpty: to check if the Circular queue is empty or not.
      e) Count: to count the number of elements in the Circular queue.
   
    4. I have implemented Circular Queue using Arrays. In this i have taken the fixed array size that is 5, you can dynamically take the array size from the user.
  
  Let's go ahead and implement it..!   */
  
  
  
#include <iostream>
using namespace std;

class CircularQueueImplementation{
    
    private:
    int front,rear;
    int arr[5];
    int count;
    
    public:
    CircularQueueImplementation(){
        count = 0;
        front = -1;
        rear = -1;
        for(int i=0; i<5; i++){
            arr[i] = 0;
        }
    }
    
    bool isEmpty(){
        if(front==-1 && rear==-1)
            return true;
        else
            return false;
    }
    
    bool isFull(){
        if((rear+1)%5==front)                                   
            return true;
        else
            return false;
    }
    
    void Enqueue(int val){
        if(isFull()){
            cout<<"Queue is full";
            return;
        }else if(isEmpty()){
            front=0;
            rear=0;
            arr[rear] = val;
        }else{
            rear = (rear+1)%5;;
            arr[rear] = val;
        }
        count++;
    }
    
    int Dequeue(){
        int x;
        if(isEmpty()){
            cout<<"Queue is Empty "<<endl;
            return 0;
        }
        else if(front==rear){
            x = arr[front];
            arr[front] = 0;
            rear = -1;
            front = -1;
            count--;
            return x;
            
        }else{
            x = arr[front];
            arr[front] = 0;
            front = (front+1)%5;
            count--;
            return x;
        }
    }
    int countElement(){
        return (count);
    }
    
    void Display(){
        cout<<" Elements in the Queue are :";
        int i;
        for(i=0;i<5;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};


int main()
{
    CircularQueueImplementation obj;
    int option,value;
    do{
        cout<<"What operation you want to perform? Select from the options below. Enter 0 to exit"<<endl;
        cout<<"1.Enqueue()"<<endl;
        cout<<"2.Dequeue()"<<endl;
        cout<<"3.isEmpty()"<<endl;
        cout<<"4.isFull()"<<endl;
        cout<<"5.count()"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Clear screen"<<endl<<endl;
        cin>>option;
        
        switch(option){
            case 0:
            break;
            
            case 1:
                cout<<"Enqueue operation \n Enter the value to add in Queue "<<endl;
                cin>>value;
                obj.Enqueue(value);
                break;
            
            case 2:
                cout<<"Dequeue operation is performed"<<endl;
                cout<<"Dequeued value is : "<<obj.Dequeue()<<endl;
                break;
            
            case 3:
                if(obj.isEmpty())
                    cout<<"Queue is Empty"<<endl;
                else
                    cout<<"Queue is not Empty"<<endl;
                break;
            
            case 4:
                if(obj.isFull())
                    cout<<"Queue is Full"<<endl;
                else
                    cout<<"Queue is not Full"<<endl;
                break;
            
            case 5:
                cout<<"Total values in the Queue are : "<<obj.countElement()<<endl;
                break;
            
            case 6:
                cout<<"All Elements in Queue are :";
                obj.Display();
                cout<<endl;
                break;
            
            case 7:
                system("cls");
                break;
            default:
                cout<<"Enter the correct option..!"<<endl;
            
        }
        
    }while(option!=0);

    return 0;
}
