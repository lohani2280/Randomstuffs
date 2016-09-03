#include<iostream>
#include"String.h"
//using std::cout;
//using std::cin;
//using std::endl;
int main()
{
    String ayush,lohani;
    std::cin>>ayush;
    std::cout<<ayush<<std::endl;
    std::cin>>lohani;
    std::cout<<lohani<<std::endl;
    ayush+=lohani;
    std::cout<<ayush;
    return 0;
}
