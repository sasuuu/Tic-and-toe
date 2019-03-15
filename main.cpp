#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int wybor;
bool wygral=false;
bool remis=true;
int player=1;
char tab[9];
int runda=1;
int dupa=0;

void wyswietl()
{
    system("cls");
    cout<<"Player 1 <X> - Player 2 <O>"<<" Runda: "<<runda<<endl<<endl;
    for(int i=3;i<12;i++){
        for(int j=1;j<18;j++){
            if(j%6 == 0) cout<<"|";
            else if(i%3 == 2 && i != 11) cout<<"_";
            else if(i%3 == 1 && (j+3)%6 == 0) cout<<tab[dupa++];
            else cout<<" ";
        }
        cout<<endl;
    }
    dupa=0;
    cout<<endl<<endl<<endl;
}
void czy_wygral()
{
    for(int i=0;i<3;i++){
        if((tab[i]==tab[i+3])&&(tab[i+3]==tab[i+6]))
    {
        wygral=true;
        tab[i]='|';
        tab[i+3]='|';
        tab[i+6]='|';
        remis=false;
        i=3;
    }
        else if((tab[3*i]==tab[3*i+1])&&(tab[3*i+1]==tab[3*i+2]))
    {
        wygral=true;
        tab[3*i]='-';
        tab[3*i+1]='-';
        tab[3*i+2]='-';
        remis=false;
        i=3;
    }
        else if((tab[i]==tab[i+4])&&(tab[i+4]==tab[i+8]))
    {
        wygral=true;
        tab[i]='\\';
        tab[i+4]='\\';
        tab[i+8]='\\';
        remis=false;
        i=3;
    }
        else if((tab[i+2]==tab[i+4])&&(tab[i+4]==tab[i+6]))
    {
        wygral=true;
        tab[i+2]='/';
        tab[i+4]='/';
        tab[i+6]='/';
        remis=false;
        i=3;
    }
        else {
            remis = true;
        }
    }


}


int main()
{
    for(int i=0;i<9;i++)
    {
        tab[i]=i+49;
    }
    do
    {
        wyswietl();
        if(player==1)
        {
            cout<<"Player 1, enter a number: ";
            wybor=getch();
            if((wybor<'1')||(wybor>'9'))
            {
                cout<<endl<<"Nie ma takiego pola!!!";
                Sleep(2000);
            }
            else if((tab[wybor-49]=='X')||(tab[wybor-49]=='O'))
            {
                cout<<endl<<"To pole jest juz zajete!!!";
                Sleep(2000);
            }
            else
            {
                tab[wybor-49]='X';
                player++;
                runda++;
                czy_wygral();
                if(runda==10) wygral=true;
            }
        }
        else
        {
            cout<<"Player 2, enter a number: ";
            wybor=getch();
            if((wybor<'1')||(wybor>'9'))
            {
                cout<<endl<<"Nie ma takiego pola!!!";
                Sleep(2000);
            }
            else if((tab[wybor-49]=='X')||(tab[wybor-49]=='O'))
            {
                cout<<endl<<"To pole jest juz zajete!!!";
                Sleep(2000);
            }
            else
            {
                tab[wybor-49]='O';
                player--;
                runda++;
                czy_wygral();
                if(runda==10) wygral=true;
            }

        }

    }while(wygral==false);
    if(remis==true)
    {
        wyswietl();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<endl<<"Remis !!!";
    }
    else
    {
        wyswietl();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        if(player==2) cout<<endl<<"Wygral player 1 w "<<runda<<" rundzie !!!";
        else cout<<endl<<"Wygral player 2 w "<<runda<<" rundzie !!!";
    }
    Sleep(5000);
    cout<<endl<<"Jesli chcesz zagrac jeszcze raz kliknij Y, jesli nie kliknij esc";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    wybor=getch();
    if(wybor=='y')
    {
        wygral=false;
        remis=true;
        player=1;
        runda=1;
        main();
    }
    else return 0;
}
