#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class List{
	private:
		struct node {
			int data;
			node* next;
		};
		typedef struct node* nodePtr;
		nodePtr head; //Head node
		nodePtr curr; //Curent node
		nodePtr tail; //Tail temp
	public:
		List();                                        //constructor
		bool empty();                                  //Checks if list is empty
		void PushQueue (int pushInt);                  //Append to list
		void PushStack (int pushInt);                  //Prepend to list
		void PrintQueue (List & someList, int size);   //Print queue
		void PrintStack (List & someList, int size);   //Print stack
		void PopQueue ();
		void PopStack ();
};

List::List() {  //defining the constructor. For defining the private data.
	head = NULL;
	curr = NULL;
	tail = NULL;
}

bool List::empty() {
	if (head == NULL){
		return true;
	}
	return false;
}

//Push int to list
void List::PushQueue(int addInt){
	nodePtr n = new node;
	n->next = NULL;
	n->data = addInt;
	if(head != NULL){
		curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = n;
    }
	else{
		head = n;
    }
}

void List::PushStack(int addInt){
	//Since it's a stack, push it to the front of the list...basically prepend it
	nodePtr n = new node;
	n->next = head;
	n->data = addInt;
	head = n;
}

//Pop function for queues
void List::PopQueue (){
	head = head->next;
}

//Pop function for stacks
void List::PopStack (){
	head = head->next;
	}


//Following function prints queue
void List::PrintQueue(List & someList, int size){
	cout << "Your list is a QUEUE" << endl;
	//Iterates through queue, printing out the data and then poping the value from list
	for (; !(someList.empty()); someList.PopQueue()){
		int count = 0;
		cout << someList.head->data;
		if (count < size){
			cout << " ";
		}
		count++;
	}
	cout << endl;
}

//Following function prints stack
void List::PrintStack(List & someList, int size){
	//Iterates through stack, printing out the data and then poping the value from list
	cout << "Your list is a STACK" << endl;
	//Iterates through queue, printing out the data and then poping the value from list
	for (; !(someList.empty()); someList.PopStack()){
		int count = 0;
		cout << someList.head->data;
		if (count < size){
			cout << " ";
		}
		count++;
	}
	cout << endl;
}

int main(){
	List uStack, uQueue;
	int input, counter = 0; //Store user's input
	char continueQ = 'Y', method; //Char used to store user's input
	cout << "Enter number: "; //Prompt user for number and store it
	cin >> input; //Store user's input
	uStack.PushStack(input); //Add to input to list
	uQueue.PushQueue(input);
	cout << endl << "Continue Y or N?: "; //Checks if the user wants to add more numbers
	cin >> continueQ;                     //Records user's input
	//Following loop will always prompt for more numbers unless user decides not to continue
	while (continueQ == 'Y' || continueQ == 'y'){
		cout << endl << "Enter number: ";
		cin >> input;
		uStack.PushStack(input);
		uQueue.PushQueue(input);
		counter++;
		cout << endl << "Continue Y or N: ";
		cin >> continueQ;
	}
	cout << endl << "Method S or Q?: "; //Ask user if (s)he wants to make a stack or a queue
	cin >> method;                      //Record user's answer (q or s)
	//Showtime! Time to print either a queue or stack
	cout << endl << "*******Your Program Prints Out******" << endl << endl;
	//Print determine on method
	if (method == 'S' || method == 's'){
		uStack.PrintStack(uStack, counter); //Call PrintStack function to print out items in stack
	}
	if (method == 'Q' || method == 'q'){
		uQueue.PrintQueue(uQueue, counter); //Call PrintQueue function to print out items in queue
	}
}