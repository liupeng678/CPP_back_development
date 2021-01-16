/**************************************************************************

Copyright: Sensetime

Author: Peng Liu

Date:2021-01-09

Description:Provide class about string in STL. 

**************************************************************************/

#include<iostream>
using namespace std;
class String{
    public:
        String(const char *str= NULL);
        String(const char &other);
        ~String();
        String &operator +(const String &other);
        String &operator =(const String & other);
        bool operator ==(const String &other);
        int getLength() const;
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
    m_data[0] = other.m_data[0 = new char[strlen(other.m_data)+1];
    strcpy(m_data , other.m_data);
}

String::~String(){
    if(m_data != NULL){
        delete[] m_data;
        m_data = NULL;
    }
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

