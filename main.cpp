//90b. POSTFIX , PREFIX all in one

#include<iostream>
using namespace std;
class Marks{
    int mark;
public:
    Marks(){
        mark=0;
    }
    Marks(int mark){
        this->mark=mark;
    }
    void disp(){
        cout<<"Ur mark is "<<mark<<endl;
    }
    Marks operator ++(){  //Prefix Increment operator
        mark+=1;
        cout<<"\nPrefix increment operation done thru MEMBER FTN with return"<<endl;
        return *this;
    }
    friend void operator --(Marks &m); //Prefix Decrement operator
    //Postfix Increment operator thru member ftn
    Marks operator++(int){  //argument 'int' specifies its POSTFIX
        Marks temp;
        mark+=1; //this change will be reflected only in the next iteration
        cout<<"\nPOSTFIX increment operation done thru MEMBER FTN with void return"<<endl;
        return temp;
    }
    //Postfix Decrement operator thru friend ftn
    friend Marks operator--(Marks &m, int);
};
//Friend ftn defined outside the class
void operator --(Marks &m){
    m.mark-=1;
    cout<<"\nPrefix decrement operation done thru FRIEND FTN with void return"<<endl;
}
//Friend ftn defined outside the class
Marks operator--(Marks &m, int){
    Marks temp=m;
    m.mark-=1;
    cout<<"\nPOSTFIX decrement operation done thru FRIEND FTN with return"<<endl;
    return temp;
}
int main(){
    Marks m1(100);
    m1.disp();
    (++m1).disp(); //Prefix Increment 
    --m1;          //Postfix Decrement
    m1.disp();
    m1++;  //Postfix Increment operator thru member ftn
    m1.disp();
    m1--;  //Postfix Decrement operator thru friend ftn
    m1.disp();
    return 0;
}
