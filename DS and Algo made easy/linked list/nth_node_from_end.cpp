#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
};
struct node *start=NULL;
void nth_node_end(struct node *start);
struct node *create_ll(struct node *start);

int main(void)
{
  int n;
  cout<<"\n Enter the data in list: ";
  start = create_ll(start);
  nth_node_end(start);
}

struct node *create_ll(struct node *start)
{
  struct node *new_node, *ptr;
  int num;
  cout<<"\nEnter -1 to end:::";
  cout<<"\nEnter the data: ";
  cin>>num;
  while(num!=-1)
  {
      new_node=(struct node*)malloc(sizeof(struct node));
      new_node->data=num;
      if(start==NULL)
      {
        new_node->next=NULL;
        start=new_node;
      }
      else
      {
        ptr=start;
        while(ptr->next!=NULL) ptr=ptr->next;
        ptr->next=new_node;
        new_node->next=NULL;
      }
      cout<<"\nEnter the data:";
      cin>>num;
  }
  return start;
}

void nth_node_end(struct node *start)
{
  int n,k=0;
  cout<<"\n Enter the nth position : (from last) ";
  cin>>n;
  struct node *p,*pn;
  p = start;
  pn = p;
  while(k<n)
  {
    pn=pn->next;
    k++;
  }
  while(pn->next!=NULL)
  {
    p=p->next;
    pn=pn->next;
  }
  p=p->next;
  cout<<"\nData: "<<p->data;
}
