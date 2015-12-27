#include <iostream>
#include "sdt.h"
using namespace std;
void To_Hex(int value)
{
    switch(value)
    {
    case 15:
        cout<<"F";
        break;
    case 14:
        cout<<"E";
        break;
    case 13:
        cout<<"D";
        break;
    case 12:
        cout<<"C";
        break;
    case 11:
        cout<<"B";
        break;
    case 10:
        cout<<"A";
        break;
    case 9:
        cout<<"9";
        break;
    case 8:
        cout<<"8";
        break;
    case 7:
        cout<<"7";
        break;
    case 6:
        cout<<"6";
        break;
    case 5:
        cout<<"5";
        break;
    case 4:
        cout<<"4";
        break;
    case 3:
        cout<<"3";
        break;
    case 2:
        cout<<"2";
        break;
    case 1:
        cout<<"1";
        break;
    case 0:
        cout<<"0";
        break;
    }
}
void In_hex(uint8_t byte)
{
    uint8_t del=byte/16;
    uint8_t ost=byte%16;
    To_Hex(del);
    To_Hex(ost);
}
void In_Binary(uint8_t byte)
{
    int i=128;
    uint8_t j=0;
    while(true)
    {
        ++j;
        if(i==0)
            break;
        if(i&byte)
            cout<<"1";
        else
            cout<<"0";

        i=i>>1;
        if(j==4)
        {
            cout<<" ";
            j=0;
        }
    }
}
void print_in_binary(const void* data, size_t size)
{
    uint8_t* bytes=(uint8_t*) data;
    for(uint8_t i=0; i<size; i++)
    {
        uint8_t byte=*(bytes+i);
        In_Binary(byte);
    }
}
void print_in_hex(const void* data, size_t size)
{
    uint8_t* bytes=(uint8_t*) data;
    for(int i=0; i<size; i++)
    {
        uint8_t byte=*(bytes+i);
        In_hex(byte);
    }
}
int main()
{
    const uint8_t size=2;
    uint16_t val1,val2;
    char oper;
    cout<<"Enter values and operand:"<< endl;
    cin>>val1>>oper>>val2;
    uint16_t answer;
    switch(oper)
    {
    case '&':
        answer=val1&val2;
        break;
    case '^':
        answer=val1^val2;
        break;
    case '|':
        answer=val1|val2;
        break;
    }
    print_in_hex(&val1,size);
    cout << oper;
    print_in_hex(&val2,size);
    cout << "=" ;
    print_in_hex(&answer,size);
    cout << endl;
    print_in_binary(&val1,size);
    cout<<oper;
    print_in_binary(&val2,size);
    cout<< "=" << endl;
    print_in_binary(&answer,size);
    return 0;
}
