#include<iostream>
using namespace std;


class CSingleton
{
    private:
        CSingleton(){}
        static CSingleton *only_instance;
    public:
    static CSingleton *get_instance()
    {
        if (only_instance == NULL)
        {
            only_instance = new CSingleton();

        }
        return only_instance;
    }
};
CSingleton *CSingleton::only_instance = NULL;

int main()
{
    CSingleton *s1 = CSingleton::get_instance();
    CSingleton *s2 = CSingleton::get_instance();
    cout<<s1<<"ddd"<<s2<<endl;
    return 0;
}
