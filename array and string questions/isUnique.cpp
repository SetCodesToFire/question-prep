#include<iostream>
#include<string>

using namespace std;

void bruteforce();

int main(void)
{
  bruteforce();
}

void bruteforce(){
  int flag=0;
  string str;
  cout<<"\nEnter the string: ";
  getline(cin,str);
  for(int i=0;i<str.size();i++)
  {
    for(int j=i+1;j<str.size();j++)
    {
      if(str[i]==str[j])
      {
        flag=1;
        goto pos;
      }
    }
  }
  pos:
  if(flag==1)
    cout<<"\nThe string does not have unique characters";
  else
    cout<<"\nThe string has unique characters :"<<str;
}
