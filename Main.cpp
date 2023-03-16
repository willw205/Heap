
 //William Wong
 //3/03/2023
 //This program helps to implement the Heap data structure and contains numbers within this tree formation!

 #include <cstring>
 #include <iostream>
 #include <fstream>
 using namespace std;

 //Function prototypes below

 void printFunction(int* heap, int area, int indent);
 void deleteFunction(int* heap, int deletor);
 void heapSort(int* heap, int length);
 void heapify(int* heap, int length, int node);

 int main() {

   //Initializing variables
   
   int input;
   int length = 0;
   int* heap = new int[100];

   for(int i = 0; i < 100; i++) {

     heap[i] = 0;
     
   }

   cout << "Please choose how you want to enter your numbers" << endl;
   cout << "Type 1 for a file input or Type 2 for a user input!" << endl;
   cin >> input;

   //Getting input from the file
   
   if(input == 1) {

     char theFile[100];
     int count = 0;
     cout << "Please enter your file name" << endl;
     cin >> theFile;
     ifstream numFile;
     numFile.open(theFile);
     
     while(numFile >> heap[count]) {

       cout << heap[count] << endl;
       length++;
       count++;
       
     }
     numFile.close();
     heapSort(heap, 100);

   //Getting input from user
     
   } else if (input == 2) {

     int inputs = 0;

     for(int i = 0; i < 100; i++) {

       cout << "Please enter a number between 1 and 1000 and you can input -1 to terminate the loop" << endl;
       cin >> inputs;
       if(inputs == -1) {
	 break;
       } else {

	 heap[i] = inputs;
	 length++;
       }
     }
     heapSort(heap, 100);
     
   } else {

     cout << "Not Valid!" << endl;
     
   }

   for(int i = 0; i < 100; i++) {

     cout << heap[i] << " ";
     
   }

   //Asking the user to either add, delete, print or quit

   char askUser[100] = "occur";

   while(strcmp(askUser, "QUIT") != 0) {

     cout << "Please enter what you want to do --> ADD or DELETE or PRINT or QUIT" << endl;
     cin >> askUser;
     if(strcmp(askUser, "ADD") == 0) {

       if(length >=100) {

	 cout << "Exceeding numbers, not allowed!" << endl;
	 
       } else {

	 cin >> heap[length];
	 length++;
	 heapSort(heap, 100);
	 
       }
       
     } else if (strcmp(askUser, "DELETE") == 0) {

        int deleteNum = 0;
	cin >> deleteNum;
	deleteFunction(heap, deleteNum);
       
       
     } else if (strcmp(askUser, "PRINT") == 0) {

       printFunction(heap, 0, 0);
       
     } else if(strcmp(askUser, "QUIT") == 0) {
       
     } else {

       cout << "Invalid!" << endl;
       
     }
     
   }

   
  }

 //Print function to create tree structure

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

   printFunction(heap, area*2+2, indent);
  
 }

 //helps to delete a number

void deleteFunction(int* heap, int deletor) {

   for(int i = 0; i < 100; i++) {

     if(heap[i] == deletor) {

       heap[i] = 0;
       break;
       
     }
     
   }

   heapSort(heap, 100);
 
 }

 //heapify function/heapsort function code was given through https://www.programiz.com/dsa/heap-data-structure
 //here we are swapping the nodes if its bigger than the parent

 void heapify(int* heap, int length, int node) {

   int largest = node;
   int leftChild = 2*node+1;
   int rightChild = 2*node+2;

   if(leftChild < length && heap[leftChild] > heap[largest]) {

     largest = leftChild;
 
   }

   if(rightChild < length && heap[rightChild] > heap[largest]) {

     largest = rightChild;
     
   }

   if(largest != node) {

     swap(heap[node], heap[largest]);
     heapify(heap, length, largest);
     
   }
   
 }

 //Helps to ensure that nodes are not smaller than children

 void heapSort(int* heap, int length) {

   for(int i = length/2 - 1; i >= 0; i--) {

     heapify(heap, length, i);
     
   }

   for(int i = length-1; i > 0; i--) {

     heapify(heap, i, 0);
     
   }
   
 }

 
