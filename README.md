# Text-Editor-Using-C

This code implements text editor in c which used dictionary in background 
to check and correct spelling mistakes of user.
 
 Instructions
1. Compile the code using makefile.
2. and run the executable file.

THE NAME OF OUR PROGRAM IS TEXT EDITOR
THE PROGRAM IS A SMALLER VERSION OF A WORD EDITOR.

by   Manish                  &             Gautam
       |                                      |
      \|/                                    \|/ 
manish21295@yahoo.com,                 gauthamdasu@gmail.com
2manish12kumar95@gmail.com

This program provides the features of searching for a word in dictoinary,inserting,deletion of a word in a dictonary.It provides with a tab feature,which when pressed gives suggestions about the word pressed and allows you to write from where you left in the word.

It then searches for the word once the word is given.
It is provided with a option of writing on to a file by checking each entered word with the word that present in the dictionary.

It has help command in it which gives the user while using for some help in how to use the editor.
It also has feature for knowing of analysis of the trees
The different types of algorithms used in the program are                 

1.Binary search tree(successful)	  
2.Avl tree(successful)		  
3.red black tree(successful)		 
4.radix tree(incomplete)

This program takes input from the file which is already parsed accordingly and dictionary is built accordingly
The limitations of this program are
               
1.Backspace cannot be used while entering any words.	       

                                                                 PROGRAM DESCRIPTION

This program is divided into 4 parts:

1.Searching a word in dictionary.
2.Insert a new word in dictionary.
3.Delete a word from the dictionary.
4.Open text editor.

 

                                                                PROJECT FILE DESCRIPTION
 
  1.checker.c :This file contains main() function,dictionary,and editor function call,which
                                                                       runs trees in the background to search words from dictionary.
  
  2.functions.c            :This file contains all the function definitions for trees(bst,
                                         AVL,RBT,RADIX),password feature,tab feature.
  
  3.header.h               :This file contains prototype of all the functions in functions.c

  4.dictionary.txt       :This file contains data for dictionary which consist of word and its meaning in the formate:
                                            word:meaning\n
 
  5.makefile                :This file contains the commands for compiling all the files(GAUMANS_SPELLCHECKER.C,
                                            and functions.c ) together.
 
  6.user_id.txt             :This file contains all the user id and passwords.

  7.editor_finalee.c     :This file contains the code for the editor part.




                                                                         INPUT/OUTPUT

1.In dictionary search user can enter a word,but cannot use backspace to erase a mistake.
2.In Insert word user can give any kind of input.
3.In Delete word user can give any kind of input.
4.In editor user can write like normal text editor(wordpad),but cannot use backspace to erase a mistake.
    User can erase his mistake by back arrow.

                                                

                                                                  ALGORITHM USED

The different types of algorithms used in the program are
                  

1.Binary search tree(successful)
		  
2.Avl tree(successful)
		  
3.red black tree(successful)
		 
 4.radix tree


 

                                                               LIMITATIONS

User cannot use backspace in editor to erase the mistake.



                                                            FUTURE WORK

a.It can be made more interactive using special functions and graphics.
b.Backspace can be improved.



                                                          REFERENCE

1.ANSCI C,by Dennis Richie
2.Data structure and algotrithm using c,by allen weiss
3.web



                                                      AKNOWLEDGEMENT

First of all I thank my inspirational soul SWAMI.
Our computer lab team,and its head Mr Satya Narayan sir.
Our teacher Mr.Darshan Gera sir.
Our alumini  Naveen brother,Sai kumar brother,Prasad brother.



                                                                   CONTRIBUTIONS

Gautam 
gauthamdasu@gmail.com
bst tree,red black tree ,tab feature,password.

Manish 
manish21295@yahoo.com, 2manish12kumar95@gmail.com
avl tree ,radix tree, text editor.
