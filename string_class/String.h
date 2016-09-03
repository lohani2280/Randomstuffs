#ifndef STRING_H_
#define STRING_H_

class String
{
    char *str;
    int len;

public:
    static const int CINMAX=80;
    String();// default constructor
    String(const char *); //construct string from c string
    String(const String &); //copy constructor
    int length();//member function to calculate the length of a String object.
    const char* c_str() const; // return c-style string from a String object.
    ~String();

    //overloaded operator
    String& operator=(const String&);
    String& operator=(const char*);
    const String& operator+=(const String& );// thoda chaap h!!!..why do we used const??
    friend bool operator==(const String&,const String&);
    friend bool operator<(const String&,const String&);
    friend bool operator>(const String&,const String&);
    char& operator[](int i);
    friend std::ostream& operator<<(std::ostream& os, const String&);
    friend std::istream& operator>>(std::istream& is, String&);
    friend std::istream& getline(std::istream& in, String& st);
};
#endif // STRING_H_
