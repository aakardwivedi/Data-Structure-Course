////Program to solve tower of hanoi using recursion.

#include<iostream>
using namespace std;

void TOH(int num,char x, char y, char z);

int main()
{

    int n;
    cin>>n;
    TOH(n,'L','C','R');
    return 0;
}

void TOH(int num,char x, char y, char z)
{

    if(num>=1)
    {
        TOH(num-1,x,z,y);
        cout<<"    "<<x<< "->"<<z;
        TOH(num-1,y,x,z);
    }
}

