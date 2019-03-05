//
//  main.cpp
//  CSE - 202 Project By Mujib Ahamad
//
//  Created by Mujib Vaa on 24/03/18.
//  Copyright © 2018 Mujibs Mac. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;


class medicineType	//base class
{
public:

    void take_order();
    void delete_order();
    void modify();
	void order_list();
	void daily_summary();
	void exit();
	medicineType();//constuctor

};

 medicineType::medicineType ()
{

}		//constructor for class CarType


struct node //constract node
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
	"Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;

	node *prev;
	node *next;
	node *link;

}*q, *temp;				//pointer declaration


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

int main()
{



	system("COLOR 61");
	medicineType medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t==================================================\n";
		cout<<"\t\t\t UNI Pharmacy Management System - MUJIB\n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. delete latest Medicine order\t\t ||\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.take_order();
				break;
			}


		case 2:
			{
				medicine.delete_order();
				system("PAUSE");
				break;
			}

		case 3:
			{
				medicine.modify();
				system("PAUSE");
				break;
			}

		case 4:
			{
				medicine.order_list();
				system("PAUSE");
				break;
			}
		case 5:
			{
				medicine.daily_summary();
				system("PAUSE");
				break;
			}
        case 6:
			{
				medicine.exit();
				goto a;
				break;
			}


		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}
		}
	}while(menu!=6);
	a://goto
	cout<<"thank you"<<endl;
	system ("PAUSE");
	return 0;
}


void medicineType::take_order()
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";

	node *temp;
	temp=new node;

				cout <<"**************************************************************************\n";
				cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"   \t\tDRUGS NAME"<<"           DRUGS PRICE(Rupe)"<<endl;
				cout <<"**************************************************************************\n";
                cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Probiotics"<<"			Rupe 2.00"<<endl;
                cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin C(500mg)"<<"		Rupe 3.00"<<endl;
                cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Acid Free C(500mg)"<<"		Rupe 1.00"<<endl;
                cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Women'S Multivate"<<"		Rupe 4.00"<<endl;
                cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Marino Tablet"<<"	 	Rupe 1.00"<<endl;
                cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maxi Cal Tablet"<<" 		Rupe 5.00"<<endl;
                cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amino Zinc Tablet"<<"		Rupe 7.00"<<endl;
                cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Burnex"<<"			Rupe 4.00"<<endl;
                cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Fabuloss 5"<<"			Rupe 3.00"<<endl;
                cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Royal Propollen"<<"		Rupe 5.00"<<endl;
                cout<<" "<<endl;

	temp = new node;
	cout << "Type Order no: ";
    cin >> temp->reciept_number;
	cout<< "Enter Customer Name: ";
	cin>> temp->customerName;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout << "Please enter your selection : "<<endl;
		cin>> temp->menu2[i];
        cout<< "Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay is: " << temp->amount[i]<<" Rupe"<<endl;
        system("PAUSE");

	}
	cout<<"==========================================================================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"==========================================================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}


void medicineType::order_list()

{

	int i, num, num2;
	bool found;
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;

	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\t\tHere is the Order list\n";
	cout<<"==========================================================================="<<endl;


	if(temp == NULL)
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)
        {
		cout <<"Reciept Number : "<<temp->reciept_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;

		cout<<"Order Date : "<<temp->date<<endl;

		cout<<"_____________________________________________________________________________"<<endl;

		cout << "===============================================================================" << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" Rupe"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}

		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}


}
}


void medicineType::delete_order()
{
	system("cls");
	int i, num, count;
    cout<<"Enter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->reciept_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"The Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;

		while((!found) && (q != NULL))
		{
  			if(q->reciept_number != num)
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q)
				last = temp;
				delete q;
				cout<<"The Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		}
}



void medicineType::modify()
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"Enter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->reciept_number;
	cout<< "Change Customer Name: ";
	cin>> temp->customerName;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout << "Please enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "Change Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" Rupe"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");

	}

 cout<<"RECORD MODIFIED....!"<<endl;
 }
 else
 {
 	if(temp != NULL && temp->reciept_number != sid)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}



void medicineType::daily_summary()
{
	int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL)
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL)

		{


		    	ofstream fout;
	char fname[20];
	char rec[80];

	cout<<"Enter a unique file name: ";
	cin>>fname;

	fout.open(fname, ios::app);






				cout <<"Reciept Number : "<<temp->reciept_number;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->customerName<<endl;

				cout<<"Order Date : "<<temp->date<<endl;

				cout<<"____________________________________________________________________________"<<endl;

				cout << "==========================================================================" << endl;
				cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" Rupe"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}

			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"Total Bill is : "<<temp->total;

			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";


			fout <<"Reciept Number : "<<temp->reciept_number;
				fout <<"\n";
				fout<<"Customer Name: "<<temp->customerName<<endl;

				fout<<"Order Date : "<<temp->date<<endl;
				fout <<"\n";
				fout<<"Total Bill is : "<<temp->total;
				temp=temp->next;
                cout<<"Data inserted successfully..!!";
                fout.close();
		}

	}
}
void medicineType::exit()
{
	cout<<"\nYou choose to exit.\n"<<endl;
}


////////////////////////////Thank You @ Mujib Ahamad //////////////////////////////////////////
