#include<iostream>
#include<cstring>
#include"String.h"

String::String()
{
    len=0;
    str=new char[1];
    str[0]='\0';
}

String::String(const char* st)
{
    len=std::strlen(st);
    str=new char[len+1];
    std::strcpy(str,st);
}

String::String(const String &st)
{
    len=st.len;
    str=new char[len+1];
    std::strcpy(str,st.str);
}

int String::length()
{
    len=std::strlen(str);
    return len;
}

String::~String()
{
    delete [] str;
}

const char* String::c_str() const
{
    return str;
}

String& String::operator=(const String& st)
{
    if(this==&st)
       return *this;
    delete [] str;
    len=st.len;
    str=new char[len+1];
    std::strcpy(str,st.str);
    return *this;//returns a refernce to yoursself(i.e, return refence of the invoking object)
}

String& String::operator=(const char* st)//LHS waala object String object hoga while RHS waala const char* type ka hoga!!!
{
    delete [] str;
    len=std::strlen(st);
    str=new char[len+1];
    std::strcpy(str,st);
    return *this; //returns a refernce to yoursself(i.e, return refence of the invoking object)
                  // yahan NOTICE karo ki hum (return *this) kar rahe h naa ki (return str) coz former m ek pointer string
                  // return hoga while latter m String object return hoga ...an humaare prototyppe k accoording hume return
                  // invoking String object hi karna h jo ki sirf (*this) se hi ho sakta h.
}

const String& String::operator+=(const String& st)
{
    int templen;
    templen=st.len+len;
    char *temp=new char[templen+1];
    std::strcpy(temp,str);
    std::strcat(temp,st.str);
    *this=temp; //  this is operator overloading of = operator of (const char* type)[L.H.S is a str.ing objeect and R.H.S is cons char* type].
    return *this;
    /*
    U can also think this way which is a wrong path
     str=temp; // ye nhi ho sakta coz isme str and temp dono ho string pointer h const char* type waale.
                  Thus, ye dono hi ek hi string ko point karenge.
                  temp ek temprory variable h and therefore jab iss function ka execution khatm hoga then the block of memory pointed by
                  temp will get deleted and so str pointer would be pointing smwhere undefined.
                  *this=temp will invoke const char* type of = overloaded operator which wii work fine.

     return str; //ye nhi hoga coz hume ek string object return karna h na ki ek string pointer.

    */
}

bool operator==(const String& st1,const String& st2)
{
    return (std::strcmp(st1.str,st2.str)==0);
}

bool operator<(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str,st2.str)<0);
}

bool operator>(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str,st2.str)>0);
}

char& String::operator[](int i)
{
    return str[i];
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
    os<<st.str;
    return os;
}

std::istream& operator>>(std::istream& is, String& st)//NHI CLEAR HAI!!!!!!!
{
    char temp[String::CINMAX];
    is.get(temp,String::CINMAX);// why didnt we used getline function  here??...if u use getline function here then after input of the string u have to ENTER two times to see the output.
    if(is)
        st=temp; // shouldnt it be st.str=temp?//this is operator overloading of = operator of (const char* type).[L.H.S is a str.ing objeect and R.H.S is cons char* type
    while(is&&is.get()!='\n')// couldnt understand this loop.This loop is basically to remove the strays of character from the input streaam.
    continue;
    return is;
}

std::istream& getline(std::istream& in, String& st)// NHI CLEAR HAI!!!!
{
    char ch;
    while(in.get(ch)&&ch!='\n')
        st.str+=ch;
    return in;
}
