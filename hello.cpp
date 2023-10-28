#include <iostream>
#include <conio.h> 
#include <string.h>
#include <time.h>
#include <cstdlib>
using namespace std; 
int rr=0,rankk=1;
void welcome()
{
    cout<<"=============================================================="<<endl;
    cout<<"                         !CHIT GAME!                          "<<endl;
    cout<<"==============================================================\n"<<endl;
}
class Player
{
    string chit[5]={"none","none","none","none","none"};
    
    public:
    string name;
    void distribution(string* arr)
    {   cout<<"Enter the name of "<<(rr/4)+1<<"th player : ";
        cin>>name;
        for(int j=0;j<4;j++)
        {chit[j]=*(arr+rr);
        rr++;
        }
    }
    void display()
    {
        cout<<name<<"\'s chits are : "<<"\n"<<chit[0]<<"\n"<<chit[1]<<"\n"<<chit[2]<<"\n"<<chit[3]<<"\n"<<chit[4]<<endl;
    }
    friend void play(Player*,Player*);
};

void play(Player* first,Player* second)
{  if(first->chit[4]=="none")
    {if((first->chit[0]==first->chit[1])&&(first->chit[1]==first->chit[2])&&(first->chit[2]==first->chit[3]))
    {cout<<first->name<<" comes on rank "<<rankk<<" with chit "<<first->chit[0]<<endl;
    rankk++;
    cout<<second->name<<" It's your turn because "<<first->name<<" was the first player .\n";
    return;
    }
    }
    int choice;
    cout<<"Hello "<<first->name<<"\nIf you want to see your chits press 1 else press 0  : ";
    cin>>choice;
    if(choice==1)
    first->display();
    int temp;
    if(first->chit[4]=="none")
    cout<<"which chit you want to suffle 1,2,3 or 4 !"<<endl;
    else 
    cout<<"which chit you want to suffle 1,2,3,4 or 5 !"<<endl;
    cin>>temp;
    
    try
    {  
        
        while(first->chit[temp-1]=="none")
        throw(temp);
    } 
    catch(int)
    {cout<<"Enter the valid chit number  :\n";
     cin>>temp;
    }
    int i=temp-1;
    if(second->chit[3]=="none")
    second->chit[3]=first->chit[i];
    else
    second->chit[4]=first->chit[i];
    
    string a=first->chit[i];
    while(i<4)
    {
        first->chit[i]=first->chit[i+1];
        i++;
            
    }
    system("cls"); 
    welcome(); 
    first->chit[4]="none";
    if((first->chit[0]==first->chit[1])&&(first->chit[1]==first->chit[2])&&(first->chit[2]==first->chit[3]))
    {cout<<first->name<<" comes on rank "<<rankk<<" with chit "<<first->chit[0]<<endl;
    rankk++;
    }
    cout<<second->name<<" You got "<<a<<" from "<<first->name<<endl;
    
   
}

int main()
{   system("cls");
    welcome();
    int nop,noc,i;
    
    cout<<" Hello players! \n Do let me know how many you are ";
    cin>>nop;
    noc=nop*4;
    string arr[noc];
    cout<<"Every player will have 4 chits!"<<endl; 
    cout<<"There will be "<<nop<<" type of chits "<<endl;
    for(i=1;i<=nop;i++)
    {
        cout<<"Enter what will be in the "<<i<<"th type of chit :";
        cin>>arr[(i-1)*4];
        // getline(cin,arr[(i-1)*4]);
        arr[((i-1)*4)+3]=arr[((i-1)*4)+2]=arr[((i-1)*4)+1]=arr[(i-1)*4];
    }
    srand(time(0));
    string tchit[noc];
    noc--;
    int f=0,a;
    while(noc!=1)
    {
       a=rand()%noc; 
       tchit[f]=arr[a];
       f++;
       if(a!=noc)

       arr[a]=arr[noc];

       noc--; 
    }
    noc=nop*4; 
    tchit[noc-2]=arr[0];
    tchit[noc-1]=arr[1];

    Player ob[nop];
    for(i=0;i<nop;i++)
    {
        ob[i].distribution(tchit);
    } 
    system("cls"); 
    welcome(); 
    cout<<"Now, let\'s begin! "<<endl; 

    int x,y,rankk2=1,pl=nop;
    x=0;y=1;
    while(rankk<nop)
    {
        play(&ob[x],&ob[y]);
        if(rankk!=rankk2)
        {   Player temp=ob[x];
            int index=x;
            while(index<nop)
            {   ob[index]=ob[index+1];
                index++;
            }
            pl--;
            ob[nop-1]=temp;
            rankk2++;
             if(y==0)
                y=(y+1)%pl; 
            else
                y=y%pl;
            x=x%pl;
        }
        else{
        x=(x+1)%pl;
        y=(y+1)%pl;
        }
    }
    system("cls"); 
    welcome(); 
    for(i=1;i<nop;i++)
    {
        cout<<ob[i].name<<" Won with rank "<<i<<endl;
    }
    cout<<ob[0].name<<" Lost the game "<<endl;
    getch();
    return 0;
}