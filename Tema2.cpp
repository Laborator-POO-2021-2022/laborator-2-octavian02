#include <iostream>
#include <cstring>
using namespace std;

class Biblioteca
{
    int an_construire;
    char adresa[20];
    char *nume;
    char *bibliotecar;

public:
    Biblioteca();                            // constructor fara parametri
    Biblioteca(char[], char *, char *, int); // constructor cu parametri
    Biblioteca(const Biblioteca &);          // constructor de copiere
    ~Biblioteca();                           // destructorul

    void afisare() const;                    // afiseaza atributele clasei
    void modif(char *, char *, char[], int); // modifica atributele clasei

    char *getBibliotecar() const;

    friend void minAn(Biblioteca *, int l);
    friend void sortare(Biblioteca *, int l);
    friend int getAn(const Biblioteca &);                   // returneaza vechimea obiectului apelat
    friend void interschimbare(Biblioteca &, Biblioteca &); // interschimba valorile dintre 2 obiecte de tip Biblioteca
};

Biblioteca::Biblioteca()
{
    nume = NULL;
    bibliotecar = NULL;
    an_construire = 0;
    strcpy(adresa, "");
}

Biblioteca::Biblioteca(char ad[], char *n, char *bl, int an)
{
    nume = new char[strlen(n) + 1];
    bibliotecar = new char[strlen(bl) + 1];

    strcpy(nume, n);
    strcpy(bibliotecar, bl);
    strcpy(adresa, ad);

    an_construire = an;
}

Biblioteca::Biblioteca(const Biblioteca &obj)
{
    if (obj.nume != NULL)
    {
        nume = new char[strlen(obj.nume) + 1];
        strcpy(nume, obj.nume);
    }
    else
        nume = NULL;

    if (obj.bibliotecar != NULL)
    {
        bibliotecar = new char[strlen(obj.bibliotecar) + 1];
        strcpy(bibliotecar, obj.bibliotecar);
    }
    else
        bibliotecar = NULL;

    strcpy(adresa, obj.adresa);
    an_construire = obj.an_construire;
}

Biblioteca::~Biblioteca()
{
    // cout << "Destructor. " << nume << endl;
    delete[] nume;
    delete[] bibliotecar;
}

void Biblioteca::afisare() const
{
    cout << "Anul in care s-a construit biblioteca este " << an_construire << endl;
    cout << "Adresa este " << adresa << endl;

    if (nume != NULL)
    {
        cout << "Numele bibliotecii este " << nume << endl;
    }
    else
    {
        cout << "Numele bibliotecii este necompletat." << endl;
    }

    if (bibliotecar != NULL)
    {
        cout << "Numele blibliotecarului este " << bibliotecar << endl;
    }
    else
    {
        cout << "Numele blibliotecarului este necompletat." << endl;
    }
}

void Biblioteca::modif(char ad[], char *n, char *bl, int an)
{
    strcpy(adresa, ad);
    if (nume != NULL)
        delete[] nume;
    nume = new char[strlen(n) + 1];
    strcpy(nume, n);
    if (bibliotecar != NULL)
        delete[] bibliotecar;
    bibliotecar = new char[strlen(n) + 1];
    strcpy(bibliotecar, bl);
    an_construire = an;
}

char *Biblioteca::getBibliotecar() const
{
    return bibliotecar;
}

int getAn(const Biblioteca &obj)
{
    return obj.an_construire;
}

void interschimbare(Biblioteca &obj1, Biblioteca &obj2)
{
    Biblioteca obj3(obj1);

    if (obj1.nume != NULL)
        delete[] obj1.nume;
    if (obj2.nume != NULL)
    {
        obj1.nume = new char[strlen(obj2.nume) + 1];
        strcpy(obj1.nume, obj2.nume);
    }
    else
        obj1.nume = NULL;

    if (obj2.nume != NULL)
        delete[] obj2.nume;
    if (obj3.nume != NULL)
    {
        obj2.nume = new char[strlen(obj3.nume) + 1];
        strcpy(obj2.nume, obj3.nume);
    }
    else
        obj2.nume = NULL;

    if (obj1.bibliotecar != NULL)
        delete[] obj1.bibliotecar;
    if (obj2.bibliotecar != NULL)
    {
        obj1.bibliotecar = new char[strlen(obj2.bibliotecar) + 1];
        strcpy(obj1.bibliotecar, obj2.bibliotecar);
    }
    else
        obj1.bibliotecar = NULL;

    if (obj2.bibliotecar != NULL)
        delete[] obj2.bibliotecar;
    if (obj3.bibliotecar != NULL)
    {
        obj2.bibliotecar = new char[strlen(obj3.bibliotecar) + 1];
        strcpy(obj2.bibliotecar, obj3.bibliotecar);
    }
    else
        obj2.bibliotecar = NULL;

    strcpy(obj1.adresa, obj2.adresa);
    strcpy(obj2.adresa, obj3.adresa);

    obj1.an_construire = obj2.an_construire;
    obj2.an_construire = obj3.an_construire;

}
void sortare(Biblioteca *obj, int l)
{
    for(int i=0 ; i < l-1 ; i++ )
        for(int j=i+1 ; j < l ; j++ )
            if(strcmp(obj[i].nume, obj[j].nume) > 0)
                interschimbare(obj[i], obj[j]);

}

void minAn(Biblioteca *obj, int l)
{
         int mn=getAn(obj[0]);
        for(int i=1 ; i < l ; i++ )
            if( obj[i].an_construire < mn )
               {
                    mn=obj[i].an_construire;
               }
        for(int i=0 ; i < l ; i++ )
            if( mn==obj[i].an_construire)
                obj[i].afisare();

}

int main()
{
    Biblioteca obj1;
    /*char adresa[20] = "ST";
    char nume[20] = "DC";
    char bibliotecar[20] = "Mo";
    int an = 1970;*/
    Biblioteca obj2("ST", "DC", "MO", 1980);

    obj1.afisare();
    obj2.afisare();

    Biblioteca obj3(obj1);
            obj3.afisare();

    interschimbare(obj1, obj2);
    obj1.afisare();
    obj2.afisare();
    obj3.afisare();

    Biblioteca *v = new Biblioteca[3];

    v[0].modif("AA", "BN", "AC", 1969);
    v[1].modif("BA", "AM", "BC", 1996);
    v[2].modif("CA", "AE", "CC", 1969);

    for(int i = 0; i < 3; i ++)
		v[i].afisare();
    
    sortare(v, 3);
    for(int i = 0; i < 3; i ++)
		v[i].afisare();

    cout << "-----------------------------" << endl;
    minAn(v, 3);

    delete[] v;
    return 0;
}
