#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;

static string baza_login[100],baza_haslo[100],listatestow[100][60]; 
static bool baza_uprawnien[100]; 
static int baza_id[100],baza_tests[100];

void Komunikat(string tekst)
{
    unsigned char znak;
    int kod;
    cout<<tekst<<endl;
    cout<<endl<<"Klinkij [ENTER] aby kontynuowac... ";
    
    do
    {
    znak = getch();
    kod = static_cast < int >( znak );
    } while (kod!=13);
    
    system("cls");
}

class Konto
{
private:
string login, haslo;
bool czy_nauczyciel;
int id,tests;

public:
static int status;
static int count;

Konto(string x, string y, bool z)
{
    login = x;
    baza_login[count] = x;
    
    haslo = y;
    baza_haslo[count] = y;
    
    czy_nauczyciel = z;
    baza_uprawnien[count] = z;
    
    id = count;
    baza_id[id]=id;
    
    tests = 0;
    count++;
}

void logowanie() 
{
    system("cls");
    do
    {
    cout<<"Podaj nick: ";
    cin>>login;
    cout<<endl<<"Podaj haslo: ";
    cin>>haslo;
    
    for (int i = 0;i<count;i++)
    {
        if (login==baza_login[i] && haslo==baza_haslo[i])
        {
            system("cls");
            Komunikat("Pomyslnie zalogowano!");
            status = 1;
            czy_nauczyciel = baza_uprawnien[i];
            id = baza_id[i];
            tests = baza_tests[i];
        }

    }
    if (status!=1)
    {
    system("cls");
    Komunikat("Nie udalo sie zalogowac.\nProsze sprobowac ponownie.");    
    }
    } while (status!=1);
    

}
void wyloguj()
{

    system("cls");
    login = "";
    haslo = "";
    czy_nauczyciel = false;
    status = 0;
    Komunikat("Nastapilo wylogowanie.");
   
}
void wyswietl_konto()
{
    string czy_haslo,status_nauczyciela;
    cout<<"---Twoje konto---"<<endl;
    cout<<"Twoj nick: "<<login<<endl;
    
    if (czy_nauczyciel==true)
    {
        status_nauczyciela = "aktywny";
    }
    else
    {
        status_nauczyciela = "nieaktywny";
    }
    
    cout<<"Status nauczyciela: "<<status_nauczyciela<<endl; 
    cout<<"Ilosc twoich testow: "<<tests<<endl<<endl;
    cout<<"Haslo to dane wrazliwa.\nCzy chcesz zeby zostalo ono wyswietlone?\n(y/n): ";
    cin>>czy_haslo;
    
    system("cls");
    
    cout<<"---Twoje konto---"<<endl;
    cout<<"Twoj nick: "<<login<<endl;
    cout<<"Status nauczyciela: "<<status_nauczyciela<<endl; 
    cout<<"Ilosc twoich testow: "<<tests<<endl;
    
    if (czy_haslo=="y")
    {
        cout<<"Twoje haslo: "<<haslo<<endl<<endl;
    }
    Komunikat("To wszystie twoje dane.");
    
}


int get_status()
{
    return(status);
}
bool get_uprawnienia()
{
    return(czy_nauczyciel);
}
string get_login()
{
    return(login);
}
int get_id()
{
    return(id);
}
int get_tests()
{
    return(tests);
}
void tests_up()
{
    tests++;
    baza_tests[id]=tests;
}
};

int Konto::count=0;
int Konto::status=0;

int main()
{
    
    Konto user("","",false);
    Konto uczen1("DamianXi","radwan321",false);
    Konto uczen2("Alicja123","zi3lony",false);
   
    Konto admin("admin","root",true);
    Konto nauczyciel("P_ania42","mruczus",true);
    Konto testowe("d","d",true);

    string komunikat_nienauczyciel = "Pomyslnie zalogowano z konta ucznia.\nNastapi teraz przelogowanie do innego systemu.";
    string komunikat_nauczyciel = "Pomyslnie zalogowano z konta nauczycielskiego.\nNastapi teraz otwarcie listy testow.";
    string MENU = "---SYSTEM NAUCZANIA I TESTOW---\n-----------MAIN MENU-----------";
    
    bool status;
    int decision;
    
    while(true)
    {
    system("cls");
    cout<<MENU<<endl;
        
        switch(user.get_status())
        {
    
    
    case 0:
    
    cout<<"(1) Zaloguj"<<endl<<"(2) Wyjdz"<<endl;
    cin >> decision;
    if (decision==1)
    {
        user.logowanie();
        if(user.get_uprawnienia()==false)
        {
            Komunikat(komunikat_nienauczyciel);
            return(0);
        }
        else
        {
            Komunikat(komunikat_nauczyciel);
            status = 1;
        }
    }
    
    else if (decision==2)
    {
        system("cls");
        cout<<"Do zobaczenia!"<<endl;
        Sleep(2000);
        system("cls");
        return(0);    
    }
    break;
    case 1:
    cout<<"(1) Pokaz liste testow"<<endl<<"(2) Utworz nowy test"<<endl<<"(3) Pokaz dane konta"<<endl<<"(4) Wyloguj"<<endl;
    cin >> decision;
    if (decision==1)
    {
        if(listatestow[user.get_id()][0]=="") 
        {
            system("cls");
            Komunikat("Nie posiadasz zadnych utworzonych testow.");
        }
        else
        
        {
            system("cls");
            int x;
            string nazwa;
            cout<<"---LISTA TESTOW---"<<endl;
            for (int i=0;i<user.get_tests();i++)
            {
                cout<<"("<<i+1<<")"<<" "<<listatestow[user.get_id()][i]<<endl;
            }
            
            cout<<endl<<"---WYBIERZ TEST---"<<endl;
            cin>>x;
            x--;
            
            nazwa = "start " + user.get_login() + listatestow[user.get_id()][x] +".txt";
            const char* command = nazwa.c_str(); 

            system("cls");
            Komunikat("UWAGA!\nPo nacisnieciu klawisza [ENTER] zostanie otworzony wybrany test.\nPrzed zamknieciem testu upewnij sie, aby zapisac zmiany uzywajac skrotu [CTRL + S]");
            cout<<"Prosze czekac.\nTrwa otwieranie pliku..."<<endl;
            Sleep(3000);
            
            system(command);
            system("cls");
        }
    
    
    }      
    else if (decision==2)
    {
        string nazwa,user_log;
        
        system("cls");
        cout<<"Podaj nazwe testu: ";
        cin>>nazwa;
        
        listatestow[user.get_id()][user.get_tests()] = nazwa;

        nazwa = "type nul >" + user.get_login() + nazwa + ".txt";
        const char* name = nazwa.c_str(); 
        system(name);
      
        user.tests_up();
        Komunikat("Pomyslnie utworzono nowy test.");
    }   
    
    else if (decision==3)
    {
        system("cls");
        user.wyswietl_konto();
    }
    
    
    else if (decision==4)
    {
        user.wyloguj();
    }
        
        };


    }
    
}