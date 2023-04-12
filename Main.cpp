
 //William Wong
 //3/03/2023
 //This program helps to implement the Heap data structure and contains numbers within this tree formation!

 #include <cstring>
 #include <iostream>
 #include <fstream>
 #include <cstdlib>
 #include <cmath>
 #include <vector>
 using namespace std;

 //Function prototypes below

 int main() {

   char userInput[50];
   int * heap = new int [101];
   for (int i = 0; i < 101; i++) {
     heap[i] = 0;
   }

   int reply = 0;
   bool continue = false;

   cout << "----------------------" << endl;
   cout << "Hey user! This is Heap!" << endl;

   do {
     cout << "Type the num 1 to gerate numbers with file or you can type 2 in order to generate them yourself: " << endl
     cin >> reply;
     cin.get();

     if (reply == 1) {
       //Function of file inserted  here
       continue = true;
     } else if (answer == 2) {

       //Function of manual inserted here
       continue = true;
       
     } else {

       cout << "Invalid input! Please try again user!" << endl;
       
     }
   } while(!continue);

   cout << "------------------" << endl;
   cout << "Heap now!" << endl;
   //print function

   do {

     cout << "-------------------" << endl;
     cout << "Hey user please enter a command. You can either ADD --> PRINT --> REMOVE to remove root --> REMOVEALL --> delete everything in heap --> or QUIT!: " << endl;

     cin.get(userInput, 50);
     cin.get();

     if (strcmp(userInput, "ADD") == 0) {

       //add function here
       cout << "Added!" << endl;
    
     }

     if (strcmp(userInput,"PRINT") == 0) {
       if (heap[1] == 0) {

	 cout << "No numbers within heap!" << endl;
	 
       } else {

	 cout << "------------------" << endl;
	 //print function here
	 
       }
     }

     if (strcmp(userInput, "REMOVE") == 0) {

       //remove function here;
       cout << "Root removed!" << endl;
       
     }

     if (strcmp(userInput, "REMOVEALL") == 0) {

       while (heap[1] != 0) {

	 //remove function here
	 
       }
       cout << "The whole heap has been removed" << endl;
       
     }

     if (strcmp(userInput, "QUIT") == 0) {

       cout << "Thanks for using the Heap Program!" << endl;
       
     }
     
   } while (strcmp(userInput, "QUIT") != 0);
   
 }
