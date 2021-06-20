//FINAL PROGRAM FOR THE EDITOR
//WRITTEN BY GAUTHAM AND MANISH
//DATE 15.3.2016
#include"header.h"
int main()//main program
{ 
	extern char a[5][50];
	extern int an;
	int c_flag=1,var=1,i=0,i1=0,j1=0,j=0,k1=0,q1,y=1;
	char userid[30],passwd[45],c,*p;
	int g,oy=0,flag=1,ew=0;
	char aa='y';
	char *t1=NULL,temp[15],temp1[50],temp2[300],temp3[50],temp4[300];
	char word[50],mean[1000];
	FILE *ofp,*cfp;//openig and closing file pointers
	static int  pq=0;
	unsigned long start,stop;
	node *q=NULL,*pa=NULL,*cu=NULL;
	anode *av=NULL;
	
	ofp=fopen("words1.txt","r");
	system("clear");
	printf("                                  WELCOME TO EDITOR   \n\n");
	printf("\n\n\n                PLEASE WAIT WHILE THE EDITOR IS OPENING(loading the words)\n");
	
	if(ofp==NULL)
	{printf("error:no sufficient space to open the file %s\n","word1.txt");exit(-1);}
	
	start=clock();
	while(flag==1 && c!=EOF)
	{ c=fgetc(ofp);
		for(i=0;c!=' '&& c!='\n' && c!=-1;i++)
		word[i]=c;c=fgetc(ofp);
		    
	   word[i]='\0';
	   if(c==' ') 
	   {
		     while(c!=':')
		    { c=fgetc(ofp);
		     }flag=0; 
	   }
   		 if(c==':')
   		 {
   			 c=fgetc(ofp);
         		for(j=0;c!='\n';j++)
         		{
         		mean[j]=c; 
        		 c=fgetc(ofp);
        		 }mean[j]='\0';flag=1;
		}
     		q=insert_bst(q,word,mean);
    		 pq++;
   	}
	stop=clock();	
	system("clear");
	
printf("                                           Hello              \n                                     WELCOME TO Text Editor                        \n ");
printf("\n");
printf("   \n\n   IF YOU ARE ALREADY A USER PRESS 1 TO LOGIN.\n\n   TO REGISTER AS A NEW USER PRESS 2.\n\n   HELP PRESS 3.\n");
scanf("%d",&q1);//takes the choice of the user
getchar();
	
while(c_flag==1)
{	
	switch(q1)
	{
	case 1 :    printf("PLEASE GIVE YOUR USER ID\nUSER ID:\n");
         	   scanf("%[^\n]s",userid);getchar();
         	   printf("PLEASE ENTER YOUR PASSWORD\nPASSWORD:");
          	    p=input_passwd(p);
       		  //    printf("user id:%s\npassword:%s",userid,p);    
         	   printf("PLEASE WAIT WHILE CHECKING THE USER ID AND PASSWORD\n");
          	  flag=check(userid,p);//checking for the user id and the password in the user_id txt file
          	  
	  	   if(flag==1)//cheching for the flag if true then open the editor else give the other options
        	  {
	     		 printf("NO OF WORDS IN THE DICTIONARY ARE %d\n",pq);
             		 printf("THE TOME TAKEN FOR INSERTION IS %ld:secs\n",((long)(stop-start))/CLOCKS_PER_SEC);
	     		  printf("PLEASE WAIT OPENING THE SAIMAA'S EDITOR\n");
              		 editor(q);c_flag=0;
	      	 }
           	  else if(flag==2)
	    	   printf("SORRY INCORRECT PASSWORD PLEASE RE-ENTER THE PASSWORD.\n");
            	 else if (flag==3)
	     	  printf("SORRY INCORRECT USER-ID PLEASE RE-ENTER THE USER-ID.\n");
             	else if (flag==4)
	     	  printf("SORRY PLEASE REGISTER IN FOR LOGGING IN.\n");
	      	 break;
	      	 
	      	 
	case 2 :
            printf("PLEASE GIVE YOUR USER-ID FOR THIS PROGRAM\n");	       
            scanf("%[^\n]s",userid);getchar();
            while(var==1)
            { printf("PLEASE GIVE YOUR PASSWORD\nPASSWORD:");
            p=input_passwd(p);
	    system("clear");
	    j1=write_userid(userid,p);
	    if(j1==1)
	     {
	     printf("SUCCESSFULLY REGISTERED\n");
	     printf("PLEASE WAIT OPENING THE SAIMAA'S EDITOR\n");
             editor(q);
                var=0;
	    }   
            else {printf("SORRY REGISTRATION FAILED\n");c_flag=0;}
	    }break;
	    
	    
	case 3 : printf("YOU SELECTED FOR HELP OPTION\n");
     	    printf("FOLLOW THE INTERFACE.IF YOU ARE A NEW USER YOU PRESS 1.YOU THEN ENTER THE USER ID AND YOU PASSWORD \n");
		 printf("IF YOU ARE NOT A USER PRESS 2.AND YOU GIVE THE USER ID AND PASSWORD FOR THIS EDITOR\n");
		 printf("IT WILL BE GOOD READ 'READ ME' BEFORE USING THE SPELLCHECKER\n ");
		  c_flag=0;     break;
		  
		  
	default : printf("please select the in one of the above options");	    
}

}
fclose(ofp);
return 0;
}
