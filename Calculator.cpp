#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
class Calculator{
    private:
    float a,b;
    public:
    float addition(float a, float b){
        return a+b;
    }
    float subtraction(float a, float b){
        return a-b;
    }
    float multiplication(float a, float b){
        return a*b;
    }
    float division(float a, float b){
        return a/b;
    }
};

int main()
{
   Calculator c;
    float a,b;
    char ch;
    cout<<"Welcome to Calci - your Personal Calculator!"<<endl;
    
    while(1){
        cout<<"Enter number 1: ";
        cin>>a;
        cout<<"Enter number 2: ";
        cin>>b;
        cout<<"Enter your choice of operation"<<endl;
        cout<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl<<"4. Division"<<endl<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case '1':
            cout<<"Addition: "<<c.addition(a,b)<<endl;
            break;
            
            case '2':
            cout<<"Subtraction: "<<c.subtraction(a,b)<<endl;
            break;
            
            case '3':
            cout<<"Multiplication: "<<c.multiplication(a,b)<<endl;
            break;
            
            case '4':
            cout<<"Division: "<<c.division(a,b)<<endl;
            break;
            
            case '5':
            cout<<"Thank you for using Calci! See you again! :)"<<endl;
            exit(0);
            break;
            
            default:
            cout<<"Invalid choice! Please enter a valid one.";
        }
    }
    
    return 0;
}