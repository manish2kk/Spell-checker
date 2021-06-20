#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//#include"avl.h"
#include <termios.h>
#include <unistd.h>
char a[5][30]; /*list of 5 most closer word to w[30]*/
 int  an=0;      /*no of words in a[5][30]*/
/******************************************   B       S        T *******************************************/
/*************************   A      V      L   ***************************************/

struct node_avl
{char word[26];
  char mean[950];
  int h;
 struct node_avl *l,*r;
};
typedef struct node_avl node_avl;

int Max(int a,int b)
{if(a>b)
 return a;
 else  
 return b;
}


node_avl * findmin_avl(node_avl *root)
{
if(root==NULL)
return NULL;
else
if(root->l == NULL)
return root;
else return findmin_avl(root->l);
}

int height(node_avl *p)
{if(p==NULL)
 return -1;
 else
 return p->h;
}
/*int Max(int a,int b)
{if(a>b)
 return a;
 else  
 return b;
}*/

node_avl * singlerotatewithleft(node_avl *k2)
{node_avl *k1=0x0;
 k1=k2->l;
 k2->l=k1->r;
 k1->r=k2;
 k2->h=Max(height(k2->l),height(k2->r))+1;
 k1->h=Max(height(k1->l),k2->h)+1;
 return k1;
}
node_avl * singlerotatewithright(node_avl *k1)
{node_avl *k2=0x0;
 k2=k1->r;
 k1->r=k2->l;
 k2->l=k1;
 k1->h=Max(height(k1->l),height(k1->r))+1;
 k2->h=Max(height(k1->r),k1->h)+1;
 return k2;

}

node_avl * doublerotatewithleft(node_avl *k3)
{k3->l=singlerotatewithright(k3->l);
 return singlerotatewithleft(k3);
}

node_avl * doublerotatewithright(node_avl *k3)
{k3->r=singlerotatewithleft(k3->r);
 return singlerotatewithright(k3);
}

node_avl * insert_avl(node_avl *root,char *x,char *m)
{if(root==NULL)
 {root=(node_avl *)calloc(1,sizeof(node_avl));
  if(root==NULL)
  {printf("\nno space");
   exit(1);
  }
  else
  { strcpy(root->word,x);
    strcpy(root->mean,m);
  }
  return root;
 }
 else
 if(strcmp(x,root->word)<0)
  
  {root->l=insert_avl(root->l,x,m);
     if(height(root->l)-height(root->r)==2)
      if(strcmp(x,(root->l)->word)<0)
       root=singlerotatewithleft(root);
       else
       root=doublerotatewithleft(root);
  }
 else
   if(strcmp(x,root->word)>0)
    {root->r=insert_avl(root->r,x,m);
       if(height(root->r)-height(root->l)==2)
       if(strcmp(x,(root->r)->word)>0)
       root=singlerotatewithright(root);
       else
       root=doublerotatewithright(root);
    }

 root->h=Max(height(root->l),height(root->r))+1;
 return root;  
}


node_avl * delete_avl(node_avl *root,char *x)
{node_avl *tcell;
if(root==NULL)
{printf("\nerror! element not found\n");exit(0);}
else
if(strcmp(x,root->word)<0)
root->l=delete_avl(root->l,x);
else
if(strcmp(x,root->word)>0)
root->r=delete_avl(root->r,x);
else
if(root->l && root->r)
{
tcell=findmin_avl(root->r);
strcpy(root->word,tcell->word);
root->r=delete_avl(root->r,x);
}
else
{
tcell=root;
if(root->l == NULL)
root=root->r;
else if (root->r == NULL)
root=root->l;
free(tcell);
}
return root;
}





int  search_avl(node_avl *t,char *w)
{if(t==0x0)
   return 0;
 else 
 if(strcmp(w,t->word)<0)
        return search_avl(t->l,w);
 else 
 if(strcmp(w,t->word)>0)
        return search_avl(t->r,w);
 else{//printf("%s",t->mean);
 return 1;}
}



void print_avl(node_avl *root)
{

if(root!=NULL) 
 {if(root->l==NULL&&root->r==NULL)
   {printf("\n\n%s\n%s",root->word,root->mean);
   }
  else
   { print_avl(root->l);
     printf("\n\n%s\n%s",root->word,root->mean);
     print_avl(root->r);
   }
 }
}





































/************************    R      B      T   **************************************/

//A Red-Black tree node_rbt structure
struct node_rbt
{
    char word[50],mean[1150];     // for data part
    char color;  // for color property
      
   //links for left, right children and parent
   struct node_rbt *left, *right, *parent;
};
typedef struct node_rbt node_rbt; 
// Left Rotation




void LeftRotate(struct node_rbt **root,struct node_rbt *x)
{
//y stored pointer of right child of x
    struct node_rbt *y = x->right;
 
//store y's left subtree's pointer as x's right child
    x->right = y->left;
 
//update parent pointer of x's right
    if (x->right != NULL)
        x->right->parent = x;
  // update y's parent pointer
    y->parent = x->parent;
 
    // if x's parent is null make y as root of tree
    if (x->parent == NULL)
        (*root) = y;
 
    // store y at the place of x
    else if (x == x->parent->left)
        x->parent->left = y;
    else    x->parent->right = y;
 
     //make x as left child of y
    y->left = x;
 
    //update parent pointer of x
    x->parent = y;
}
 
 



//Right Rotation (Similar to LeftRotate)
void rightRotate(struct node_rbt **root,struct node_rbt *y)
{
    struct node_rbt *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent =y->parent;
    if (x->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}
  //Utility function to fixup the Red-Black tree after standard BST insertion




void insertFixUp(struct node_rbt **root,struct node_rbt *z)
{
    // iterate until z is not the root and z's parent color is red
    while (z != *root && z->parent->color == 'R')
    {
        struct node_rbt *y;
 
        // Find uncle and store uncle in y
        if (z->parent == z->parent->parent->left)
            y = z->parent->parent->left;
        else
            y = z->parent->parent->right;
 
       //If uncle is RED, do following
       //(i)  Change color of parent and uncle as BLACK
       //  (ii) Change color of grandparent as RED
       //  (iii) Move z to grandparent
        if (y->color == 'R')
        {
            y->color = 'B';
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
        }
 
         //Uncle is BLACK, there are four cases (LL, LR, RL and RR)
        else
        {
            // Left-Left (LL) case, do following
           // (i)  Swap color of parent and grandparent
           // (ii) Right Rotate Grandparent
            if (z->parent == z->parent->parent->left &&
                z == z->parent->left)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent->parent);
            }
 
           // Left-Right (LR) case, do following
           //  (i)  Swap color of current node_rbt  and grandparent
           //  (ii) Left Rotate Parent
           // (iii) Right Rotate Grand Parent
            if (z->parent == z->parent->parent->left &&
                z == z->parent->right)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent);
                rightRotate(root,z->parent->parent);
            }
 
            //Right-Right (RR) case, do following
            // (i)  Swap color of parent and grandparent
            // (ii) Left Rotate Grandparent
            if (z->parent == z->parent->parent->right &&
                z == z->parent->right)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent->parent);
            }
 
            // Right-Left (RL) case, do following
            //(i)  Swap color of current node_rbt  and grandparent
            // (ii) Right Rotate Parent
            // (iii) Left Rotate Grand Parent
            if (z->parent == z->parent->parent->right &&
                z == z->parent->left)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent);
                LeftRotate(root,z->parent->parent);
            }
        }
    }
    (*root)->color = 'B'; //keep root always black
}
 



//Utility function to insert newly node_rbt in RedBlack tree
void insert_rbt(struct node_rbt **root, char w[],char meaning[])
{
    // Allocate memory for new node_rbt
    struct node_rbt *z;
	z = (struct node_rbt*)calloc(1,sizeof(struct node_rbt));

	if(z==NULL)
			{printf("\nError");exit(1);}
    strcpy(z->word,w);
	strcpy(z->mean,meaning);
    z->left = z->right = z->parent = NULL;
 
     //if root is null make z as root
    if (*root == NULL)
    {
        z->color = 'B';
        (*root) = z;
    }
    else
    {
        struct node_rbt *y = NULL;
        struct node_rbt *x = (*root);
 
        // Follow standard BST insert steps to first insert the node_rbt
        while (x != NULL)
        {
            y = x;
            if (strcmp(z->word,x->word)<0)
                x = x->left;
            else
			if (strcmp(z->word,x->word)>0)
                x = x->right;
			else return;
        }
        z->parent = y;
        if (strcmp(z->word,y->word)>0)
            y->right = z;
        else
            y->left = z;
        z->color = 'R';
 
         //call insertFixUp to fix reb-black tree's property if it
        //is voilated due to insertion.
        insertFixUp(root,z);
    }
}
 



// A utility function to traverse Red-Black tree in inorder fashion
void inorder(struct node_rbt *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("\n%s", root->word);
    inorder(root->right);
}
 

int  search_rbt(node_rbt *t,char *w)
{if(t==0x0)
   return 0;
 else 
 if(strcmp(w,t->word)<0)
        return search_rbt(t->left,w);
 else 
 if(strcmp(w,t->word)>0)
        return search_rbt(t->right,w);
 else{printf("%s",t->mean);
 return 1;}
}





































/************************    R     A     D    I    X**********************************/

struct node_radix
{char w,color,*mean;
 struct node_radix *sibling,*child;
};
typedef struct node_radix node_radix;

/*----------------------------------------------------------------------------------------------*/
int search_radix(node_radix *root,char key[],int pos)
{node_radix *t=root;
 while(1)
 if(t==NULL)
 return 0;
 else
 if((t->w)==key[pos])
 {  if(pos==(strlen(key)-1))
    {  printf("\n");
       puts(t->mean);
       return 1;
    }
    else
    { t=t->child;
      pos++;
    }
 }
 else
 t=t->sibling;
 
}
/*----------------------------------------------------------------------------------------------*/
node_radix * createnode_radix(void)
{node_radix *t=(node_radix *)malloc(sizeof(node_radix));
 if(t==NULL)
 {printf("\nNo space to insert.Aborting!");
  exit(1);
 }
 else
 {t->w=0;
  t->color='r';
  t->mean=0x0;
  t->sibling=0x0;
  t->child=NULL;
  t->child=0x0; 
  return t;
 }
}
/*----------------------------------------------------------------------------------------------*/
node_radix * insert_radix(node_radix *root,int pos,char word[],char meaning[])
{node_radix *t;
 if(root==NULL)
 {  if(pos<strlen(word))
    {  t=createnode_radix();
       t->w=word[pos];
       t->color='r';
       if(pos==(strlen(word)-1))
       {  t->mean=(char *)calloc(strlen(meaning),sizeof(char));
          strcpy(t->mean,meaning);
          t->color='b';
          return t;
       }
       t->child=insert_radix(t->child,pos+1,word,meaning);
       return t;
    } 
 }
 else
 if(word[pos]==root->w)
 {  if(pos<(strlen(word)-1))
    {  root->child=insert_radix(root->child,pos+1,word,meaning);
       return root;
    }  
    else
    {  root->mean=(char *)calloc(strlen(meaning),sizeof(char));
       strcpy(root->mean,meaning);
       root->color='b';
       return root;
    }
 }
 else
 if(word[pos]<root->w)
 {  t=createnode_radix();
    t->sibling=root;
    root=t;
    if(pos==strlen(word)-1)
    {root->color='b';
     root->mean=(char *)calloc(strlen(meaning),sizeof(char));
     strcpy(root->mean,meaning);
    }
    else
    root->color='r';

    root->w=word[pos];
    if(root->color=='b')
    return root;
    else
    root->child=insert_radix(root->child,pos+1,word,meaning);

    return root;
 }
 else
 {  root->sibling=insert_radix(root->sibling,pos,word,meaning);
    return root;
 }

}       
/*----------------------------------------------------------------------------------------------*/
char word[30];

void display_dict(node_radix *root,int lim)
{node_radix *t=root;int j,i;
 if(root!=NULL)
 {  if(root->color=='b')
    {  word[lim]=root->w;
       word[lim+1]='\0';
       printf("%s\n",word);
       printf("            :");
       puts(root->mean);
    }
    if(root->child!=0x0){word[lim]=root->w;
    display_dict(root->child,lim+1);}
    if(root->sibling!=0x0){word[lim]=root->w;
    display_dict(root->sibling,lim);}
 }
}
/*----------------------------------------------------------------------------------------------*/
void display_tree(node_radix *root,int depth)
{if(root!=NULL)
 {printf("%c ",root->w);
  if(root->sibling!=NULL)
  display_tree(root->sibling,depth);
  if(root->child!=NULL)
  display_tree(root->child,depth+1);
 }
}
/*----------------------------------------------------------------------------------------------*/
void delete_tree(node_radix *root)
{node_radix *t,*s;
 if(root!=NULL)
 {t=root->child;
  s=root->sibling;
  if(root->color=='b')
  free(root->mean);
  free(root);
  delete_tree(t);
  delete_tree(s);
 }
}
/*----------------------------------------------------------------------------------------------*/
void delete_node_radix(node_radix *root,char g[])/*deletes a particular node_radix(by iteration)*/
{node_radix *t=root;int lim=0;
 while(t!=NULL)
 if(g[lim]<root->w)
 {printf("not in tree\n");
  break;
 }
 else
 if((g[lim]>root->w))
 t=t->sibling;
 else
 {t=t->child;
  lim++;
 }
 if(t==NULL)
 printf("word not in dictionary\n");
}





































/************************************************************************************/
void * set(int n)
{node_avl *root_avl=NULL;
 node_radix *root_radix=NULL;
// node *root_bst=NULL;
 node_rbt *root_rbt=NULL;

 int ll=0;
 int j,i,ch,a_count=0;
 char a[50],c='h',b[1000];
 

 FILE *ifp;
 ifp=fopen("dictionary.txt","r");
 while(c!=EOF)/*reads word and meaning from a file*/
 {   c=fgetc(ifp);
	for(a_count=0;c!=':';a_count++)
     { 
        c=fgetc(ifp);
		if(isalpha(c))
		a[a_count]=c;
        
     }a[a_count-1]='\0';ll++;
     
     for(j=0;;j++)
     { if(c=='\n'||c==EOF)
	   break;
       else{
        c=fgetc(ifp);
			 b[j]=c;
		   }
        
     }
     b[j]='\0';
	 if(c!=EOF)
      c=fgetc(ifp);
   if(!islower(a[0])) 
	{
	 if(n==1)
			root_avl=insert_avl(root_avl,a,b);
	 else
	 if(n==2)
			root_radix=insert_radix(root_radix,0,a,b);
	 else
//	 if(n==3)
//			root_bst=insert(root_bst,a,b);
 //    else
	 if(n==4)
			insert_rbt(&root_rbt,a,b);
	 
	}
  }
 fclose(ifp);

 if(n==1)
 return root_avl;
 else
 if(n==2)
 return root_radix;
// else
 //if(n==3)
// return root_bst;
 else
 return root_rbt;

}







FILE *ofp;
void del_char_file(void)  //erase a character from between a file
{char c='a';
		while((c=fgetc(ofp))!=EOF)
		{fseek(ofp,-2,1);          //going back by 2
		 fputc(c,ofp); fseek(ofp,1,1); //going front by 1
		}fseek(ofp,-2,1); fputc(EOF,ofp);
}



void insertinfile(char c) //put a character in between a file
{char temp1,temp2=c;
 //fseek(ofp,-1,1);
  if(fgetc(ofp)!=-1)
  {fseek(ofp,-1,1);		 
  do{
		 temp1=fgetc(ofp);fseek(ofp,-1,1);fputc(temp2,ofp);//fseek(ofp,1,1);printf("%d",ftell(ofp));
		 temp2=fgetc(ofp);fseek(ofp,-1,1);fputc(temp1,ofp);
   }while(temp2!=-1);
  }
 // fseek(ofp,-1,1);
  fputc(temp2,ofp);
}

int abss(int a,int b)
{if(a<b)
 return b-a;
 else 
 return a-b;
}

int iscloser(char orig_word[],char user_word[])
{int replacement=0,i,o,u,b=0,c=0;
 /*this code decides whether a given word is close to an original word either by one (1)deletion,(2)replacement,or*/
 /* (3)addition of a letter */
 
 /*count the no of replacement to get the original word*/
  if(strlen(orig_word)==strlen(user_word))
  {    for(i=0;i<strlen(user_word);i++)
         if(orig_word[i]!=user_word[i])
         replacement++;
    
         if(replacement<=1)
         return 1;
         else
         return 0;
  }
  else /*we need deletion or addition*/
  {     o=strlen(orig_word);
        u=strlen(user_word);
        if(abss(o,u)!=1)  /*we need more than one deletion or addition*/
        return 0;
        else          /*we need exactly one deletion or addition*/
        { if(strlen(orig_word)<strlen(user_word)) /*original word is smaller than user's word(delete)*/
          {   for(i=0;i<strlen(user_word);i++)
              if(orig_word[b]==user_word[c])
              {b++;c++;}
              else
              c++;
         
              if(c==strlen(user_word)&&b==strlen(orig_word))/*only one letter deleted*/
              return 1;
              else
              return 0;
          }
          else   /*original word is bigger than user's word.(add)*/
          {   for(i=0;i<strlen(orig_word);i++)
              if(orig_word[b]==user_word[c])
              {b++;c++;}
              else
              b++;

              if(c==strlen(user_word)&&b==strlen(orig_word))/*only one letter deleted*/
              return 1;
              else
              return 0;

          }
        }
   }
}
/*
void send(node_radix *root,int lim,char ww[])
{printf("\n in send");
		node_radix *t=root;int j,i;
 if(root!=NULL)
 {  if(root->color=='b')
    {  word[lim]=root->w;
       word[lim+1]='\0';
	   printf("\n%s",word);
        if(iscloser(word,ww))
	    {if(an<5)
		 strcpy(a[an++],word);	   
		 printf("%s",word);
		}
       //printf("%s\n",word);
       //printf("            :");
       //puts(root->mean);
    }
    if(root->child!=0x0){word[lim]=root->w;
    display_dict(root->child,lim+1);}
    if(root->sibling!=0x0){word[lim]=root->w;
    display_dict(root->sibling,lim);}
 }
}*/

void check_a(node_avl *root,char ww[])
{
if(root!=NULL) 
 {if(root->l==NULL&&root->r==NULL)
   {//printf("\n\n%s\n%s",root->word,root->mean);
        if(iscloser(root->word,ww))
	    {if(an<5)
		 strcpy(a[an++],word);	   
		 //printf("%s",word);
		}
   }
  else
   { check_a(root->l,ww);
     
        if(iscloser(root->word,ww))
	    {if(an<5)
		 strcpy(a[an++],root->word);	   
		 //printf("%s",root->word);
		}
	 //printf("\n\n%s\n%s",root->word,root->mean);
     check_a(root->r,ww);
   }
 }
}



void m_editor(void)

{//node_radix *root_radix=NULL;
 node_avl *root_avl=NULL;
 
 FILE *ifp,*ofp;
 
 char c='a',file[30],ww[30],arr,cc;
 int i,wc=0,bit=1,tmp,mistake=0,tab=0,z,wwn=0,init=0;
 root_avl=(node_avl *)set(1);
 //root_radix=(node_radix *)set(2);
 //display_dict(root_radix,0); 
//printf("%d",search_avl(root_avl,"night")); 
 //system("clear");
   printf("\n give file name:\n");getchar();
   scanf("%[^\n]s",file);

   ifp=fopen(file,"r+");
   if(ifp==NULL)
   {printf("file doesnt exist");
    ifp=fopen(file,"w+");
	}


start1:
system("clear");
    
 printf("\n|-------------------------------------------------------------------------------------------------------------------------|");
 printf("\n                                         welcome to our editor");
 
   {printf("\nDo you mean ");
		   for(i=0;i<an;i++)
			   printf("\"%s\",",a[i]);}
			   
 printf("\n|------------------------------------------------------------------------------------------------------------press ~ to exit ---|\n"); 
 
 fseek(ifp,0,0);
 while((c=fgetc(ifp))!=EOF)
 {printf("%c",c);//printf("1");
 }
 while(1)
 {  c=getch();
     
    putchar(c);
   
   if(c=='~') break;
	if(c==' '||c=='.'||c=='\n')
            {ww[wwn]='\0';wwn=0;
			 
			    if(islower(ww[0]))
		        ww[0]=toupper(ww[0]);
			 
			   fputc(c,ifp);
			  if(search_avl(root_avl,ww)==0) 
				{
				 an=0;
				 check_a(root_avl,ww);
				 goto start1;
			     for(i=0;i<an;i++)
			     printf(" %s ",a[i]);
				 
				}
			}
	 else
	 if(c>=32&&c<=126)
     	 {
			ww[wwn++]=c;
			fputc(c,ifp);

		 }
	 else
	 if(iscntrl(c))
		{ofp=fopen("copy.txt","w");
                   z=ftell(ifp);
                    rewind(ifp);
                   for(i=0;i<(z-1);i++)
                     {cc=fgetc(ifp);
                       fputc(cc,ofp);
                      }              
                   delete(ifp);
                   rename("copy.txt",file);
                   fclose(ofp);    
                }

 }
 
    fclose(ifp);
}



int manish_edi()
{int choice=1,choice2;char a[30],b[500];
// node * root=set(3);
 node_avl * root_avl=set(1);
 node_rbt * root_rbt=set(4);
 //node_radix * root_radix=set(2);
 
  while(choice!=0)
  {		system("clear");
		printf("\n\n\n\n\n\n\n\n\n                                 Enter your choice:");
		printf("\n\n                                1.Open Text Editor");
		printf("\n\n                                0.Exit\n\n\n                                 ");
        scanf("%d",&choice);
 switch(choice)
 {
        /*printf("\n\n\n\n      Enter a word:\n\n     ");
		scanf("%[^\n]s",a);
		printf("\n\n\n\n      Enter the meaning:\n\n     ");
		scanf("%[^\n]s",b);*/
	 case 1:system("clear");
	        m_editor();
	        break;
	 case 0:break;
	 default:printf("\n\n   wronrg choice");
	}
   }
	//	editor();
	system("clear");
 printf("\n\n");
 return 0;
}



