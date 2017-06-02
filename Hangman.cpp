#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;
//Variables-----------------------------
bool WordTaken(0);
string Word, WordGuesser;
int WordLength, Lives, MenuChoise, Status, RevieledLetters;
//Functions-----------------------------
void TakeWord(){
    ifstream fd("words.txt");
    WordTaken=1;
    Status=0;
    RevieledLetters=0;
    srand(time(NULL));
    int WordNumber=0;
    while(!fd.eof()) {
        fd>>Word;
        WordNumber++;
    }
    fd.clear();
    fd.seekg(0, ios::beg);
    int RandomWord=rand()%WordNumber;
    for(int i=1; i<=RandomWord; i++)
        fd>>Word;
    WordLength=Word.length();
    fd.close();
    Lives=6;
}
void Display(){
 system("CLS");
 cout<<"|   ----"<<endl;
 cout<<"|  |    |"<<endl;
 cout<<"|  |    ";
 if(Lives<=5) cout<<"O";
 cout<<endl<<"|  |   ";
 if(Lives<=2) cout<<"/|\\";
  else if(Lives<=3) cout<<"/|";
  else if(Lives<=4) cout<<" |";
  cout<<endl<<"|  |   ";
  if(Lives<=0) cout<<"/ \\";
  else if(Lives==1) cout<<"/";
  cout<<endl<<"| /|\\"<<endl<<endl;
  cout<<"| Lives:"<<Lives<<endl;
  cout<<"| "<<WordGuesser<<endl<<"|"<<endl;
  cout<<"| If you want to guess entire word at once, type \"1\""<<endl;

}
void WordGuesserFormer(){
    WordGuesser=Word;
    for(int i=0; i<=WordLength; i++){
        WordGuesser[i]='_';
    }
}
void Gameplay(){
    char Letter;
    string Guess;
    bool Found=0;
    cin>>Letter;
    if(Letter!='1'){
        for(int i=0; i<WordLength; i++){
            if(Word[i]==Letter){
                WordGuesser[i]=Word[i];
                RevieledLetters++;
                Found=true;
            }
        }
        if(RevieledLetters==WordLength) Status=1;
        if(Found==0) Lives--;
    }
    else{
        string WordGuesser2;
        cin>>WordGuesser2;
        if(WordGuesser2==Word){
            WordGuesser=WordGuesser2;
            Status=1;
        }
        else Lives--;
    }
    if(Lives<=0) {
        Status=-1;
        WordGuesser=Word;
    }
}
int main(){
    while(1){
        if(!WordTaken){
            TakeWord();
            WordGuesserFormer();
        }
        Display();
        Gameplay();
        if(Status!=0){
            Display();
            if(Status==1) cout<<"YOU WON!!!\n \n";
            else cout<<"YOU LOST!!!\n \n";
            system("PAUSE");
            WordTaken=false;
        }
    }
    return 0;
}
