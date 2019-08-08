#include "orbit_functions.h"

message::message()
{
  next=NULL;
  content=NULL;
}
message::~message()
{
  if(next!=NULL)
    delete next;
  if(content!=NULL)
    delete content;
}
message_inbox::message_inbox()
{
  head=NULL;
}
message_inbox::~message_inbox()
{
  if(head!=NULL)
    delete head;
}
int message_inbox::add_message(char *content, message **h)
{
  if(*h==NULL){
    *h = new message;//make new
    (*h)->content = new char[strlen(content)+1];
    strcpy((*h)->content, content);//assign content
    (*h)->next=NULL;
    return 0;
  }
  return add_message(content,&(*h)->next);//reurse if not working
}
void message_inbox::display(message *h)
{
  if(h==NULL){
    cout<<"\n";
    cout<<"end of list of messages";
    cout<<"\n";
    return;
  }
  else{
    cout<<h->content;
    cout<<"\n";
    display(h->next);
  }
}
int message_inbox::broadcast()
{
  cout<<"A request for communication has been broadcasted to any possible available species";
  return 0;
}
//listen to messages
int message_inbox::message_inbox_listen(char planetCode, int broadcast)
{
  //THIS is where planet code could be used to get a hard coded message
  if(planetCode=='1' && broadcast==0){
    cout<<"sasdfdasdfas;lkjfkdla Decode this message to see what item to bring";
    return 0;
  }

  //This is for no intelligent life

  cout<<"There is no communication being recieved";
  return 1;

}

int message_inbox::decode_message(char planetCode, int recieved_message)
{
  //if statements for matching planetcode for what we want

  //IF STATEMENT SUCCESS JUST FOR TESTING


  //MINIGAME GO HERE
  if(planetCode=='1'){
    char test[] = "hello";
    if(hangman(test)){
      cout<<"message is decoded: bring a rock for gift exchange to be allowed to land. Rock is recorded in the inbox with the planet code in front of it..";
      char content[] = "1rock";
      int result=add_message(content,&head);
      cout<<result;
      return 0;
    }
    else{
      cout<<"message decoding failed";
      return 1;
    }
  }

  cout<<"There is no message to decode";
  return 1;
}

int message_inbox::gift_exchange(char planetCode, int decoded)
{
  char input[30];
  cout<<"input the type of gift needed to talk to the aliens";
  cin.get(input,29,'\n');
  cin.ignore(1000,'\n');

  if(planetCode=='1' && decoded==0){
    if(strcmp(input,"rock")==0){
      cout<<"successful communication. you may land";
      return 0;
    }
    else{
      cout<<"failed communication. retry";
      return 1;
    }
  }
  cout<<"error";
  return 1;

}

int probe_mine_fuel(char planetCode, int communicated, char inhabited)
{
  if(communicated!=0 && inhabited=='y'){
    cout<<"you were blown up by the locals! you should have communicated first..";
    return -1;//for blown up
  }
  else if(planetCode=='1'){
    cout<<"you gained 4 fuel";
    return 4;
  }
  else{
    cout<<"this planet has no fuel";
    return 0;
  }
  cout<<"error should not have reached this";
  return 0;
}
