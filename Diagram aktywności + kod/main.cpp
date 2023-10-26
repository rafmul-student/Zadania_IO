#include <iostream>
using namespace std;

class Konto
{
private:
string login, haslo, listatestow[60];
bool czy_nauczyciel;

static string baza_imion[100],baza_nazwisk[100]; 
static bool baza_uprawnien[100]; 

static int count;

public:
Konto(string x, string y, bool z)
{
    login = x;
    baza_imion[count] = x;
    haslo = y;
    baza_nazwisk[count] = y;
    czy_nauczyciel = z;
    baza_uprawnien[count] = z;


}






};





int main()
{
    
    
    cout<<"-----Logowanie------"<<endl;
    return(0);
}