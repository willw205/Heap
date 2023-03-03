
 #include <cstring>
 #include <iostream>
 #include <fstream>
 using namespace std;

 void printFunction(int* heap, int area, int indent);
 void deleteFunction(int* heap, int deletor);
 void heapSort(int* heap, int size);

 int main() {

   char input;
   int length = 0;
   int* heap = new int[100];

   for(int i = 0; i < 100; i++) {

     heap[i] = 0;
     
   }

   cout << "Please choose how you want to enter your numbers" << endl;
   cout << "Type 1 for a file input or Type 2 for a user input!" << endl;
   cin >> input;

   if(input == 1) {

     char theFile[100];
     int count = 0;
     cout << "Please enter your file name" << endl;
     cin >> theFile;
     ifstream theFile;
     numFile.open(theFile);

     while(theFile >> heap[count]) {

       cout << heap[count] << endl;
       length++;
       count++;
       
     }
     theFile.close();
     //Enter heapSort here
   } else if (input == 2) {

     int inputs = 0;

     for(int i = 0; i < 100; i++) {

       cout << "Please enter a number between 1 and 1000 and you can input -1 to terminate the loop" << endl;
       cin >> inputs;
       if(inputs = -1) {

	 break;
       } else {

	 heap[i] = inputs;
	 length++;
       }
     }
     //Enter heapsport hear
     
   } else {

     cout << "Not Valid!" << endl;
     
   }

   for(int i = 0; i < 100; i++) {

     cout << heap[i] << " ";
     
   }

   
  }

//void printFunction(int* heap, int area, int indent);

 void printFunction(int* heap, int area, int indent) {

   if(heap[area] == 0) {
     return;
   }
   indent +=10;

   printFunction(heap, area*2+1, indent);

   cout << "\n" << endl;

   for(int i = 10; i < indent; i++) {

     cout << " ";
     
   }

   cout << heap[area] << "\n";

   print func(heap, location*2+2, space);
  
 }

 void deleteFunction(int* heap, int deletor) {

   for(int = 0; i < 100; i++) {

     if(heap[i] == deletor) {

       heap[i] = 0;
       break;
       
     }
     
   }

   //heap sort here
  
 }

 
