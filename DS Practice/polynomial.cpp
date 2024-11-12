#include<iostream>
using namespace std;

struct Term
{
    /* data */
    int coeff;
    int exp;
};

class Polynomial{
    private:
        Term terms[100];
        int termCount;

    public:
        Polynomial(){
            termCount = 0;
        }
        void readPoly();
        void displayPoly();
};

void Polynomial::readPoly(){
    cout<<"Enter the number of terms in the polynomial: ";
    cin>>termCount;
    for(int i = 0; i < termCount; i++){
        cout<<"Enter coeff and exp for term "<<(i+1)<<": ";
        cin>>terms[i].coeff >> terms[i].exp;
    }
}

void Polynomial::displayPoly(){
    for(int i = 0; i < termCount; i++){
        cout<<terms[i].coeff<<"x^"<<terms[i].exp;
        if(i < termCount - 1){
            cout<<" + ";
        }
        //cout<<endl;
    }
    cout<<endl;
}

int main(){
    Polynomial p;
    p.readPoly();
    p.displayPoly();
}