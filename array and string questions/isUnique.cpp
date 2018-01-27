#include<iostream>
#include<string>

using namespace std;

void bruteforce();
void optimal1();
void merge(string &str, int l, int m, int r);
void mergeSort(string &str, int l, int r);

int main(void)
{
  bruteforce();
  optimal1();
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

void merge(string &str, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[20], R[20];

    for (i = 0; i < n1; i++)
        L[i] = str[l + i];
    for (j = 0; j < n2; j++)
        R[j] = str[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            str[k] = L[i];
            i++;
        }
        else
        {
            str[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        str[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        str[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(string &str, int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSort(str, l, m);
        mergeSort(str, m+1, r);
        merge(str, l, m, r);
    }
}

void optimal1()
{
  int flag=0;
  string str;
  cout<<"\nEnter the string: ";
  getline(cin,str);
  mergeSort(str,1,str.size()-1);
  for(int i=0;i<str.size();i+=2)
  {
    if(str[i]==str[i+1])
    {
      flag=1;
      goto pos;
    }
  }
  pos:
  if(flag==1)
    cout<<"\nThe string does not have unique characters";
  else
    cout<<"\nThe string has unique characters :"<<str;
}
