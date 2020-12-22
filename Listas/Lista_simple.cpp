#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

// Point structure
struct Point{
	int coordinateX;
	int coordinateY;
	Point *next;
};

// Function prototype
void menu(Point *head);
Point* createNode(Point *head);
Point* insertStart(Point *head);
void insertEnd(Point *head);
void print(Point *head);
void originDistance(Point *head);
void insertMiddle(Point *head ,int coordinateX, int coordinateY);
Point* deleteFirst(Point *head);
void deleteMiddle(Point *head, int coordinateX, int coordinateY);
bool validateExistence(Point *head, int coordinateX, int coordinateY);

int main(){
	
	// Inicizlitation head list
	Point *head=NULL;	
	
	// Call menu list
	menu(head);
}

// Menu list 
void menu(Point *head){
	
	int option;
	
	do{
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"||||                  MENU                    ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cout<<"|||| 1.create first node into list            ||||"<<endl;
		cout<<"|||| 2.insert node to start of list           ||||"<<endl;
		cout<<"|||| 3.insert node to end of list             ||||"<<endl;
		cout<<"|||| 4.insert node to middle of list          ||||"<<endl;
		cout<<"|||| 5.delete first node into list            ||||"<<endl;
		cout<<"|||| 6.delete middle node into list           ||||"<<endl;
		cout<<"|||| 9.print list                             ||||"<<endl;
		cout<<"|||| 0.exit                                   ||||"<<endl;
		cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
		cin>>option;
		system("cls");
		switch (option){
			
			case 1:
				head = createNode(head);
				system("cls");
				break;
				
			case 2:
				head = insertStart(head);
				system("cls");
				break;
				
			case 3:
				insertEnd(head);
				system("cls");
				break;
				
			case 4:
				int coordinateX;
				int coordinateY;
				bool validation;
				cout<<"Set coordinate X: "; 
				cin>>coordinateX;
				cout<<"Set coodinate Y: "; 
				cin>>coordinateY;
				validation = validateExistence(head,coordinateX,coordinateY);
				if(validation == true){
					insertMiddle(head,coordinateX,coordinateY);
				}else{
					cout<<"List does not exist"<<endl;
				}
				system("cls");	
				break;	
				
			case 5:
				head = deleteFirst(head);	
				system("cls");
				break;
				
			case 6:
				int searchCoordinateX;
				int searchCoordinateY;
				bool validation1;
				cout<<"Put coordinate X to delete: "; 
				cin>>searchCoordinateX;
				cout<<"Put coordinate X to delete: "; 
				cin>>searchCoordinateX;
				validation1 = validateExistence(head,searchCoordinateX,searchCoordinateY);
				if(validation1 == true){
					deleteMiddle(head,searchCoordinateX,searchCoordinateY);
				}else{
					cout<<"Node does not exist"<<endl;
				}
				system("cls");
				break;
					
			case 9:
				print(head);
				system("cls"); 
				break;
				
			default :
				cout<<"Thanks"<<endl;
				system("Pause");	
		}
	}while(option != 0);
}
Point* createNode (Point *head){
	head = new Point;
	cout<<"Set coordinate X: "; 
	cin>>head->coordinateX;
	cout<<"Set coordiante Y: "; 
	cin>>head->coordinateY;
	head->next = NULL;
	cout<<"Node created successfully"<<endl;
	return head;
}
Point* insertStart(Point *head){
	if(head != NULL){
		Point *newNode = NULL;
		newNode=new Point;
		cout<<"Set coordinate X: "; 
		cin>>newNode->coordinateX;
		cout<<"Set coordiante Y: "; 
		cin>>newNode->coordinateY;
		newNode->next=head;
		head = newNode;
		return head;
	}else{
		cout<<"Create a list"<<endl;
	}
	system("PAUSE");	
}
void insertEnd(Point *head){
	if(head != NULL){
		Point *newNode = new Point;
		Point *auxiliar = head;
		cout<<"Set coordinate X: "; 
		cin>>newNode->coordinateX;
		cout<<"Set coordiante Y: "; 
		cin>>newNode->coordinateY;
		newNode->next = NULL;
		while(auxiliar->next != NULL){
			auxiliar = auxiliar->next;
		}
		auxiliar->next = newNode;
		cout<<"Node created successfully"<<endl;
	}else{
		cout<<"Create a list"<<endl;
	}
	system("PAUSE");
}
void print (Point *head){
	while(head != NULL){
		cout<<head->coordinateX<<" - "<<head->coordinateY<<endl;
		originDistance(head);
		head = head->next;
	}
	system("PAUSE");
}
void originDistance(Point *head){
	if(head != NULL){
		double distance;
		int coordinateX;
		int coordinateY;
		coordinateX = head->coordinateX;
		coordinateY = head->coordinateY;
		distance = sqrt(pow(coordinateX,2)+pow(coordinateY,2));
		cout<<"Origin distance is: "<<distance<<endl;
	}else{
		cout<<"Coordinate does not load."<<endl;
	}
}
void insertMiddle(Point *head,int coordinateX, int coordinateY){
	
	if(head != NULL){
		Point *auxiliar = head;
		Point *newNode = new Point;
		cout<<"Set coordinate X: ";
		cin>>newNode->coordinateX;
		cout<<"Set coordinate Y: ";
		cin>>newNode->coordinateY;
		bool ban = false;
		while(ban == false){
			if(auxiliar->coordinateX == coordinateX && auxiliar->coordinateY == coordinateY){
				ban=true;
			}else{
				ban=false;
				auxiliar = auxiliar->next;
			}
		}
		newNode->next = auxiliar->next;
		auxiliar->next = newNode;
	}else{
		cout<<"Create a list";
	}
	system("PAUSE");
}
Point* deleteFirst(Point *head){
	Point *auxiliar = head;
	head = head->next;
	delete auxiliar;
	cout<<"Node deleted succesfully"<<endl;
	system("Pause");
	return head;
}
void deleteMiddle(Point *head,int coordinateX, int coordinateY){
	if(head){
		Point *auxiliar = head;
		Point *auxiliar1 = NULL;
		bool ban = false;
		while(ban == false){
			if(auxiliar->coordinateX != coordinateX && auxiliar->coordinateY != coordinateY){
				auxiliar1 = auxiliar;
				auxiliar = auxiliar->next;
			}else{
				ban = true;
			}
		}
		auxiliar1->next = auxiliar->next;
		delete auxiliar;
		cout<<"Node deleted succesfully"<<endl;
	}else{
		cout<<"Create a list";
	}
	system("PAUSE");
}
bool validateExistence(Point *head, int coordinateX, int coordinateY){
	while(head != NULL){
		if(head->coordinateX == coordinateX && head->coordinateY == coordinateY){
			cout<<"The node exist"<<endl;
			return true;
		}
		head = head->next;
	}
	cout<<"The node does not exist"<<endl;
	system("PAUSE");
	return false;
}
