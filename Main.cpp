
 //William Wong
 //4/12/2023
 //This program helps to implement the Heap data structure and contains numbers within this tree formation!

 #include <cstring>
 #include <iostream>
 #include <fstream>
 #include <cstdlib>
 #include <cmath>
 #include <vector>
 using namespace std;

 //Function prototypes below

 int identifyLeft(int * heap, int userInput);
 int identifyRight(int * heap, int userInput);
 void removeFunc(int * &heap);
 void add(int * &heap);
 void print(int * heap, int index, int surface);
 int findParent(int * &heap, int index);
 void insert(int * &heap, int num);
 void fileGenerator(int * &heap);
 void manualGenerator(int * & heap);

 int main() {

   char userInput[50];
   int * heap = new int [101];
   for (int i = 0; i < 101; i++) {
     heap[i] = 0;
   }

   int reply = 0;
   bool continues = false;

   cout << "----------------------" << endl;
   cout << "Hey user! This is Heap!" << endl;


   //Below here is the loop
   do {
     cout << "Type the num 1 to generate numbers with file or you can type 2 in order to generate them yourself: " << endl;
     cin >> reply;
     cin.get();

     if (reply == 1) {
       fileGenerator(heap); //here is generated through file input
       continues = true;
     } else if (reply == 2) { //here is generated through manual input

       manualGenerator(heap);
       continues = true;
       
     } else { //invlaid input here

       cout << "Invalid input! Please try again user!" << endl;
       
     }
   } while(!continues);

   cout << "------------------" << endl;
   cout << "Heap now!" << endl;
   print(heap, 1, 0);

   //Below asks users for commands of adding, printing, remove, removeAll
   // or quitting
   do {

     cout << "-------------------" << endl;
     cout << "Hey user please enter a command. You can either ADD --> PRINT --> REMOVE to remove root --> REMOVEALL --> delete everything in heap --> or QUIT!: " << endl;

     cin.get(userInput, 50);
     cin.get();

     if (strcmp(userInput, "ADD") == 0) { //add num to heap

       add(heap);
       cout << "Added!" << endl;
    
     }

     if (strcmp(userInput,"PRINT") == 0) { //print the heap
       if (heap[1] == 0) {

	 cout << "No numbers within heap!" << endl;
	 
       } else {

	 cout << "------------------" << endl;
	 print(heap, 1, 0);
	 
       }
     }

     if (strcmp(userInput, "REMOVE") == 0) { //remove root from heap

       removeFunc(heap);
       cout << "Root removed!" << endl;
       
     }

     if (strcmp(userInput, "REMOVEALL") == 0) { //removingall the nums in heap

       while (heap[1] != 0) {

	 removeFunc(heap);
	 
       }
       cout << "The whole heap has been removed" << endl;
       
     }

     if (strcmp(userInput, "QUIT") == 0) { //stop the program

       cout << "Thanks for using the Heap Program!" << endl;
       
     }
     
   } while (strcmp(userInput, "QUIT") != 0);
   
 }

 //looking for left child within index
 int identifyLeft(int * heap, int userInput) {

   int index = userInput * 2;

   if (heap[index] != 0 && index < 101) {
     return index;
   } else {
     return -1;
   }
   
 }
 //looking for right child within index thats inputted
 int identifyRight(int * heap, int userInput) {

   int index = (userInput * 2) + 1;

   if (heap[index] != 0 && index < 101) {
     return index;
   } else {
     return -1;
   }
   
 }

 //inserts num into heap
 void insert(int * &heap, int num) {

   int index = 0;

   if (heap[1] == 0) {
     heap[1] = num;
   } else {

     for(int i = 1; i < 101; i++) {

       if (heap[i] == 0) {
	 heap[i] = num;
	 index = i;
	 break;
       }
       
     }
     
   }

   int parentIndex = findParent(heap, index);

   while (parentIndex != -1 && heap[index] > heap[parentIndex]) {

     int temp = heap[index];
     heap[index] = heap[parentIndex];
     heap[parentIndex] = temp;
     index = parentIndex;
     parentIndex = findParent(heap, index);
     
   }
   
 }

 //looks for parent of the index which is inputted
 int findParent(int * &heap, int index) {

   if (index == 1) {
     return -1;
   } else {
     return floor(index / 2);
   }
  
 }

 //print function here implementing inorder tree algorithm
 void print(int * heap, int index, int surface) {

   if (index == -1 || heap[index] == 0) {
     return;
   }

   print(heap, identifyRight(heap, index), surface + 1);

   for (int i = 0; i < surface; i++) {
     cout << "    ";
   }
   cout << heap[index] << endl;

   print(heap, identifyLeft(heap, index), surface + 1);
  
 }

 //asking user for add input
 void add(int * &heap) {

   int inputs = 0;
   cout << "---------------" << endl;
   cout << "Please enter the num you want to add within the heap: " << endl;
   cin >> inputs;
   cin.get();
   insert(heap, inputs);
   
 }

 //removes root of heap, and further continusouly remove all elements as well
 //when called
 void removeFunc(int *&heap) {

   int index = 1;
   int rightChild = 0;
   int leftChild = 0;
   int swap = 0;
   int temp = 0;

   cout << "Removed: " << heap[1] << endl;

   while (index < 101) {

     leftChild = identifyLeft(heap, index);
     rightChild = identifyRight(heap, index);

     if (leftChild != - 1 && rightChild != - 1) {

       if(heap[leftChild] > heap[rightChild]) {
	 swap = leftChild;
       } else {
	 swap = rightChild;
       }
       
     } else if (rightChild != -1 && leftChild == -1) {
       swap = rightChild;
     } else if (leftChild != - 1 && rightChild == -1) {
       swap = leftChild;
     } else {
       heap[index] = 0;
       break;
     }

     temp = heap[index];
     heap[index] = heap[swap];
     heap[swap] = temp;
     index = swap;
     
   }
   
 }

 //Numbers generated randomly through file input
 void fileGenerator(int * &heap) {

   ifstream numbers("Numbers.txt");
   srand(time(NULL));
   int num = 0;
   vector<int> nums;

   while(!numbers.eof()) {
     numbers >> num;
     nums.push_back(num);
   }

   int number = 0;
   int randIndex = 0;
   int count = 0;

   while(count != 50) {
     randIndex = rand() % nums.size();
     number = nums.at(randIndex);
     insert(heap, number);
     count++;
   }
   
 }
 //nums generated through user input
 void manualGenerator(int * & heap) {
   
   int userInput = 0;
   int count = 0;

   cout << "---------------------" << endl;
   cout << "Enter -1 if you want to terminate the loop!" << endl;

   while (userInput != 0 || count < 50) {
     cout << "Please enter a num: " << endl;
     cin >> userInput;
     if (userInput == -1) {
       break;
     } else {
       insert(heap, userInput);
       cout << "Number entered!" << endl;
       count ++;
     }
   }

   cin.get();
   
 }
