/**************************************************************************

Copyright: SenseTime

Author: Peng Liu

Date:2021-01-09

Description:Provide class details  about string in STL. 

**************************************************************************/

#include<iostream>
#include "string.h"
using namespace std;
class String{
    public:
        String(const char *str= NULL);
        String(const String &other); //constructor
        ~String();
        String &operator +(const String &other);
        String &operator =(const String & other);
        bool operator ==(const String &other);
        int getLength() const; // if we use const , it just into local file
        void display();
    private:
        char *m_data;
};
String::String(const char *str){
    if(str == NULL){
        m_data = new char[1]; // allocate memory for string
    }
    else{
        int length = strlen(str);
        m_data = new char[length+1];
        strcpy(m_data, str);
    }
}

String::String(const String &other){
    if(!other.m_data){
        m_data = 0;
    }

    m_data = new char[strlen(other.m_data)+1];
    strcpy(m_data , other.m_data);
}

String::~String(){
    if(m_data != NULL){
        delete[] m_data;
        m_data = NULL;
    }
}

String &String::operator=(const String &other){
    if(this != &other){
        delete[] m_data;
        if(!other.m_data){
            m_data = NULL;
        }
        else{
            m_data = new char[strlen(other.m_data+1)];
            strcpy(m_data,other.m_data);
        }

    }
    return *this;
}

String &String::operator +(const String &other){
    String newString;
    if(!other.m_data){
        newString = *this;
    }
    else if(!m_data){
        newString = other;
    }
    else{
        newString.m_data = new char[strlen(m_data)+ strlen(other.m_data)+1];
        strcpy(newString.m_data, m_data);
        strcat(newString.m_data , other.m_data);
    }
    return newString;
}

/* this function first judge whether it is same sapce, if not return flase, if true go next procss.*/
bool String::operator==(const String &other){
    if(strlen(other.m_data) != strlen(other.m_data)){
        return false;
    }
    else{
        return strcmp(m_data , other.m_data)?false:true;
    }
}

int String::getLength() const{
    return strlen(m_data);
}


void String::display(){
    cout<<*m_data<<endl;
}

int main (){
    String s1("hello");
    String s2(s1);
    String s3 = s1;
    cout<<s1.getLength()<<endl;
    s3.display();


}