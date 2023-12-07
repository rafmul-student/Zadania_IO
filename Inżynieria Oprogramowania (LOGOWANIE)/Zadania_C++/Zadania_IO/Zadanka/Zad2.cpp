#include <iostream>

using namespace std;
int main()
{
    int AA[10];  
    int uj;
    for (int i=0;i<10;i++)
    {
        cout<<"Podaj "<<i+1<<" liczbe w tablicy"<<endl;
        
        cin>>AA[i];
        
        if (AA[i] < 0) 
        {
            uj++;
        }
    }
    
    int* BB = new int[uj];
    int id = 0;
    
    for (int i=0;i<10;i++)
    {
        if (AA[i]<0)
        {
            BB[id] = AA[i];
            id++;
        }  
    }

    cout<<"Liczby w tablicy BB to:"<<endl;
    
    for (int i=0;i<uj;i++)
    {
        cout<<BB[i]<<endl;
    }

    cout<<"Ilosc liczb w tablicy : "<<uj<<endl;
    cout<<"Ilosc liczb pominietych : "<<10 - uj<<endl;

    delete[] BB;

    return 0;
}

