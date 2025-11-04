#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    int start, end, num, guess;
    cout<<"Welcome to the Number Guessing Game!"<<endl<<"Just enter your guessing range and trust your intuition!"<<endl;
    cout<<"Enter your start range: ";
    cin>>start;
    cout<<"Enter your end range: ";
    cin>>end;
    srand(time(0));
    num=(rand()%(end-start)+1);
    
    //Logic
    do{
        cout<<"Enter your guess: ";
        cin>>guess;
        if(num>guess){
            cout<<"Too low! Try again!";
        }
        else if(num<guess){
            cout<<"Too high! Try again!";
        }
        else{
            cout<<"You guessed it right! Great job! :)";
        }
    }while(num!=guess);
    
    return 0;
}