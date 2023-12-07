#include <iostream>

using namespace std;

int main()
{
    for (int i=300;i<1201;i++)
    {
        if(i%400==0)
        {
            cout<<endl;
        }
        
        else if (i%100==0)
        {
            cout<<" *** ";   
        }
        
        else if (i%2==1)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
