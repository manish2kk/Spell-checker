//THIS FILE CONTAINS ALL THE FUNCTIONS USED IN THE PROGRAM
//FUNCTIONS WRITTEN BY GAUTHAM AND MANISH
#include"header.h"
/******************************************************************************************************/
//BST FUNCTIONS FOR INSERT DELETE SEARCH
node* insert_bst(node *q,char *a,char *b)
{
node *t;t=q;
a=toLower(a);
if(t==NULL)
{
  t=(node*)calloc(1,sizeof(node));
  if(t==NULL)
  {
  printf("error:no sufficient space to create node\n");
  exit(-1);
  }
   else
   {
   strcpy(t->word,a);
   strcpy(t->mean,b);
   t->l=t->r=NULL;
   }
}   
  else
    if(strcmp(t->word,a)==-1)
     t->l=insert_bst(t->l,a,b);
  else
    if(strcmp(t->word,a)==1)
    t->r=insert_bst((t->r),a,b);
  return t;
}
                                       
void display(node *u)
{
if(u==NULL)
{}
else
{
display(u->r);
printf("%s:%s\n",u->word,u->mean);
display(u->l);
}
}

node* delete_bst(char *a,node *t)
{
node *tcell;
if(t==NULL)
{printf("error word not found\n");exit(0);}
else
  if(strcmp(t->word,a)==-1)
    {t->l=delete_bst(a,t->l);}
else
  if(strcmp(t->word,a)==1)
    {t->r=delete_bst(a,t->r);}
else
if(t->l && t->r)
  {
   tcell=findmin(t->r);
   strcpy(t->word,tcell->word);
   strcpy(t->mean,tcell->mean);
   t->r=delete_bst(t->word,t->r);
  }
  else
   {
   tcell=t;
  if(t->l == NULL)
   t=t->r;
   else if (t->r == NULL)
   t=t->l;
   free(tcell);
   }
return t;
}



node *findmin(node * t1)
{
if(t1==NULL)
return NULL;
else
if(t1->l==NULL)
return t1;
else return findmin(t1->l);
}


node * search(node *t,char *w,char *m)
{
int r;
 if(t==NULL)
{printf("\nSORRY THE WORD %s IS NOT THERE IN THE DICTIONARY\n",w);
exit(0);
}
 if(t!=NULL)
{ r=strcmp(toLower(t->word),toLower(w));
if(r==0)
    strcpy(m,t->mean);
 if(r==-1)
       t->l=search(t->l,toLower(w),m);
 if(r==1)
       t->r=search(t->r,toLower(w),m);
}          return t;
}

char *toLower( char article[])
  {
    int i=0;
        for( i; article[i] != 0; i++)
	{
	  if ( article[i] >= 'A' && article[i] <='Z')
	article[i] = article[i] + 32;
         }
 return article;
 }



//***********************************************************************************************************************
//FUNCTIONS FOR TAKING WORD FOR TAB FEATURE
 int take_word(node *q,char *mean)
  {
  int flag=1,i=0;
   char *temp,c;
   temp=(char *)calloc(26,sizeof(char));
   if(temp==NULL)
   {
   printf("error");
   exit(0);
    }
printf("ENTER THE WORD\n");
while(flag==1)
{
  c=getch();
 while(c!='\n' && c!='\t')
  {
   temp[i]=c; 
   printf("%c",c);
   i++;
   c=getch();
    }
   if(c=='\n')
   {
   temp[i]='\0';
   flag=0;
   q=search(q,temp,mean); 
   break;}
  else if(c=='\t')
    {
    temp[i]='\0';
    flag=1;
    q=tab_search(q,temp);
    }
    printf("\n%s",temp);flag=1;
    }
return 0;
}

node *tab_search(node *w,char *a)//for searching the dictionary for the words begining with the word befor tab is used
{//if()
static int j=0;
a=toLower(a);
 // printf("\n%s\n",w->word);
int r;
 if(w==NULL)
{//printf("sorry no word in the dictonary");
return NULL;}
 if(w!=NULL)
  {     w->r=tab_search(w->r,a);
 if(strsub(w->word,a,strlen(a))==1)
  {printf("\n%s",w->word);j++;}
if(j<10)
       w->l=tab_search(w->l,a);
}          return w;
}




int strsub(char *a,char *b,int i)//here a is the input string in which b is checked 
{
int k=0,j=0,flag=1;
for(j=0;j<i && b[j]!='\0';j++)
 {
if(a[j]!=b[j]) 
 return 0;
}
return 1;
}





void editor(node *rq)
{
    int i=1,j=0,flag=0,v,y;
      char temp[15],temp1[1000],c,d;
        node *r=NULL;
       system("clear");
        printf("                          \n\n                                     WELCOME TO Text Editor                             ");
	  while(i==1)
	    {
	     printf("\nSELECT ANY ONE OF THE FOLLOWIG OPTIONS\n    1.SEARCHING THE WORD IN A DICTOARY\n    2.TO INSERT A WORD AND ITS MEANING TO     THE DICTONARY\n    3.TO REMOVE ANY WORD IN THE DICTONARY\n    4.TO WRITE ONTO A FILE\n    5.TO DISPLAY ALL WORDS IN THE DICTIONARY\n    6.TO EXIT PRESS '0'\n    YOUR CHOICE ::  ");
	     scanf("%d",&v);
	               switch(v)
	           {
	               case 1 : printf("YOU SELECTED 1.TO LOOKUP FOR A WORD\nPLEASE ENTER THE WORD FOR THE MEANING\n");
			//if(y!=0)
			getchar();
                        y=take_word(rq,temp1);
			printf("\nTHE MEANING OF THE IS %s\n",temp1);
		                                                     break;
		       case 2 :printf("YOU SELECTED 2.TO INSERT A WORD AND ITS MEANING\nPLEASE ENTER THE WORD\n ");
		                            scanf("%s",temp);getchar();
		                printf("PLEASE GIVE THE MEANING OF THE WORD\n");
		                            scanf("%[^\n]s",temp1);
		                               rq=insert_bst(rq,temp,temp1); 
						break;
		       case 3 :printf("YOU SELECTED 3.TO DELETE A WORD\nPLEASE ENTER THE WORD TO BE DELETED\n");
		                           scanf("%[^\n]s",temp1);
		                                rq=delete_bst(temp1,rq);
						break;
		       case 4 :printf("YOU SELECTED 4.TO WRITE ON A FILE \n");
		                        printf("OPENING EDITOR\n");
					manish_edi();
					break;
		       case 5 :printf("YOU SELECTED 5.TO DISPLAY ALL THE WORDS IN THE DICTIONARY\n");
		                        display(rq);     
					break;
		       case 6 :
		                  exit(0);
					break;
		       default : printf("ERROR--PLEASE SELECT ANY ONE OF THE ABOVE OPTIONS\n");
 } 
 //printf("PRESS '1' TO CONTINUE\n");scanf("%d",&i); 
 }

}


int write_userid(char *a,char*b)//function for user id to be written in a file
{
int flg;
user p;
FILE *ofp=fopen("user_id.txt","a+");
   if(ofp==NULL)
     { flg=0;return flg;exit(0);}//fputs(a,ofp);fprintf(ofp,":");fputs(b,ofp);
strcpy(p.username,a);
printf("%s",p.username);
strcpy(p.passwd,b);
fwrite(&p,sizeof(p),1,ofp);
flg=1;
fclose(ofp);
return flg;
}


int check(char *usr,char *pswd)//function for checking the user-id and password in for the user name entered
{
int k,i=0,j=0,tru=0,p;//flag for returning
char c,temp1[50],temp2[50],temp[2];
user u;
FILE *fp1=fopen("user_id.txt","r");
 if(fp1==NULL)
  { printf("SORRY NO SPACE TO OPEN FILE");
    exit(0);     }
 while(fread(&u,sizeof(u),1,fp1)==1)
  {                
       k=strcmp(u.username,usr);//k has the value of the comparission btw givenid and userid
	if(k==0)
          {
	  if((p=strcmp(u.passwd,pswd))==0)
            { tru=1;break;}
	  else 
	  if((p=strcmp(u.passwd,pswd))!=0)
             {tru=2;
	  //printf("passwd not match%d %s",p,u.passwd);
	     break;}
	  }
        else 
	{if(k!=0)
             tru=3;
	 else  tru=4; }
     }
fclose(fp1);
return tru;
}




char * input_passwd(char *a)//for taking the password from the user
{
int i=0;
char c;
a=(char*)calloc(20,sizeof(char));
printf("ENTER THE PASSWD\n");
while((c=getch())!='\n')
{
  a[i]=c;
  printf("*");
  i++;
}a[i]='\0';
return a;
}




//************************************************************************************************
//FUNCTIONS IN CONOI.H USED FOR OUR PROJECT
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/* reads from keypress, echoes */
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void clrscr()
{
       printf("\x1b[2J");
}


 
