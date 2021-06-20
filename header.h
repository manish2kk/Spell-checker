//THIS HEADER CONTAINS ALL THE DEFINITIONS OF THE FUNCTIONS
//WRITTEN BY DASU GAUTHAM SREERAM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <termios.h>
#include <unistd.h>
#include<time.h>
struct node    //for binary search tree node
{
char word[50],mean[1000];
struct node *l,*r;
};
typedef struct node node;
struct anode   //for avl tree node
{char word[26];
  char mean[950];
  int h;
 struct anode *l,*r;
};
typedef struct anode anode;
typedef struct//for password and user id
{
char username[50],passwd[50];
}user;
struct node_avl
{char word[26];
  char mean[950];
  int h;
 struct node_avl *l,*r;
};
typedef struct node_avl node_avl;


node *insert_bst(node *q,char *a,char*b); //for insertion in a binary search tree
node* delete_bst(char *x,node *t); //for deletion in a binary search tree
node *findmin(node *t1);// to find min in a binary search tree
void display(node *u);//displays the node
node *search(node *t,char *w,char *m);//searching in a bst
char *toLower( char article[]);//to convert a uppercase letter to lower case
int Max(int a,int b);// ''
node * tab_search(node *w,char *a);//tab feature of searching in tree
int strsub(char *a,char *b,int i);//function for checking asubstring in a string
int write_userid(char *a,char*b);//to write in a file the userid and password
int check(char *usr,char *pswd);//fun to verify the entered password
char *input_passwd(char *a);//fun to take password from the user
void editor(node *rq);//to invoke the editor developed
int getch(void);
int getche(void);
void clrscr();
void editor_final(void);
node_avl * findmin_avl(node_avl *root);
node_avl * findmin_avl(node_avl *root);
int height(node_avl *p);
void m_editor(void);
node_avl * singlerotatewithleft(node_avl *k2);
node_avl * singlerotatewithright(node_avl *k1);
node_avl * doublerotatewithleft(node_avl *k3);
node_avl * doublerotatewithright(node_avl *k3);
node_avl * insert_avl(node_avl *root,char *x,char *m);
node_avl * delete_avl(node_avl *root,char *x);
int  search_avl(node_avl *t,char *w);
void print_avl(node_avl *root);




