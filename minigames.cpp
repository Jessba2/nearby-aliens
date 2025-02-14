#include "tile.h"
bool hangman(char *answer_word)
{
  //inititalize an ascii image
  char display_list[15][15];
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      display_list[i][j]=' ';
    }
  }
  int length=strlen(answer_word);
  int wrong_count=0;
  char input_letter;
  int match_letter_count=0;

  char *display_string=new char[length+1];

  //initialize empty display
  for(int i=0;i<length;i++)
    display_string[i]='_';

  //while for game
  //either too many wrong words or answer matches current string
  while(wrong_count<6 && strcmp(display_string,answer_word)!=0){
    //display for hangman body
    for(int i=0;i<15;i++){
      for(int j=0;j<15;j++){
        cout<<display_list[i][j];
      }
      cout<<"\n";
    }
    cout<<"\n";
    //display for empty words
    for(int i=0;i<15;i++){
      cout<<display_string[i];
    }
    cout<<"\n";
    cout<<"This is a game of hangman. input the letter you wish to guess is ";
    cout<<"part of the solution";
    cin >> input_letter;
    cin.ignore(30, '\n');
    for(int i=0;i<length;i++){
      if(input_letter==answer_word[i]){
        match_letter_count++;
        //for displaying correct letter positions
        display_string[i]=answer_word[i];
      }
    }
    //check for wrong answer
    if(match_letter_count<=0)
      wrong_count++;
    match_letter_count=0;


    //change value based on wrongcount
    if(wrong_count==1)
      display_list[0][3]='0';
    if(wrong_count==2){
      display_list[1][3]='|';
      display_list[2][3]='|';
    }
    if(wrong_count==3)
      display_list[1][2]='/';
    if(wrong_count==4)
      display_list[1][4]='/';
    if(wrong_count==5)
      display_list[3][2]='/';
    if(wrong_count==6)
      display_list[3][4]='/';




  }
  if(strcmp(display_string,answer_word)==0)
    return true;
  else
    return false;
}
