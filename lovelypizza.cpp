//This Program Is Created By Mohd Mujtaba Section-K1613 Roll No-B47 Reg No-11608125

//*******************************PROGRAM STARTS FROM HERE*********************************************
#include<iostream> // can be remove when using fstream
#include<fstream>
#include<conio.h> // getch()
#include<stdio.h> // gets,puts, 
#include<stdlib.h> // system("cls") system("PAUSE") exit() remove() rename()
#include<string.h> // strcpy strlen strcmp etc..
#include<iomanip>
#include<windows.h>   //Sleep()
#include<bits/stdc++.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; 

void gotoxy(int x,int y)
{
	CursorPosition.X=x;
	CursorPosition.Y=y;
	SetConsoleCursorPosition(console,CursorPosition); 
	
}

using namespace std;
fstream f1;
fstream f2;
fstream f3;
fstream f4;


int i,temp,found=0,total=0;
char chop='y';
int i_code1;



class menu
{
	protected:
	float price;
	char p_name[20];
	public:
		int i_code;
	void get_menu();
	void show_menu();
	void delPizzaMenu();
};
class order: public menu
{
	protected:
	char name[30],add[80];
	int bill_no,i_code2;
	long long mbno;
	public:
	void modify();
		
	void get_order();
	void show_order();
	void gen_bill(int,int);
	void search();
	void del_rec();
	
};

class lovely_pizza:public order
{	
	public:
		
		
		
		
		void home_page()
		{
			
			int menuch=1;
			bool value=true;
			int x=7;
		//	MENU:
				
				
				
			while(value)
			{
				system("cls");
				gotoxy(14,x);
				cout<<"->";
				system("color 1A");	
				gotoxy(18,1);
				cout<<setw(30)<<"             ==================================================";
				gotoxy(18,2);
//				Sleep(150);
				cout<<setw(30)<<"                      WELCOME TO LOVELY PIZZA PVT. LTD. ";
				gotoxy(18,4);
//				Sleep(150);
				cout<<setw(30)<<"                               PHAGWARA PUNJAB";
				gotoxy(18,5);
//				Sleep(150);
				cout<<setw(30)<<"            ===================================================";
				gotoxy(18,6);
//				Sleep(100);
				gotoxy(18,7);
				cout<<"1. NEW ORDER:";
				gotoxy(18,8);
				cout<<"2. ALL ORDER DETAILS:";
				gotoxy(18,9);
				cout<<"3. SEARCH ORDER";
				gotoxy(18,10);
				cout<<"4. Modify ORDER:";
				gotoxy(18,11);
				cout<<"5. Delete ORDER :";
				gotoxy(18,12);
				cout<<"6. Enter Pizza Menu Details:";
				gotoxy(18,13);
				cout<<"7. Show Pizza  MENU:";
				gotoxy(18,14);
				cout<<"8. Delete Pizza Details:";
				gotoxy(18,15);
				cout<<"9. Exit (Sign Out):";
				gotoxy(18,16);
				cout<<"Choose One Option...... :";
				system("pause>nul"); // the >nul bit causes it the print no message
				
				if(GetAsyncKeyState(VK_DOWN) && x != 16)
				{
					gotoxy(14,x);
					cout<<"  ";
					x++;
					cout<<"->";
					menuch++;
					continue;
				}
				if(GetAsyncKeyState(VK_UP)&&x!=7)
				{
					gotoxy(14,x);
					cout<<"  ";
					x--;
					cout<<"->";
					menuch--;
					continue;
				}
				if(GetAsyncKeyState(VK_RETURN))
				{
						
		switch(menuch)
		{
			case 1:
				system("cls");
			
				get_order();
			//	goto MENU; // REDIRECTED TO MENU LABEL
				break;
			case 2:
				system("cls");
				f2.open("D:\\get_order.txt",ios::in|ios::out|ios::app);
				show_order();
			//	goto MENU; // REDIRECTED TO MENU LABEL
				break;
			case 3:
				search();
				cout<<"Press Again Any Key...#BACK #TO #MENU:";
				getch();
			//	goto MENU; // REDIRECTED TO MENU LABEL
				break;				
			case 4:
				system("cls");	
				modify();
			//	goto MENU; // REDIRECTED TO MENU LABEL
				break;
		    case 5:
		    	del_rec();
			//	goto MENU; // REDIRECTED TO MENU LABEL
				break;
		     	
			case 6:
				
	        	f1.open("D:\\menu.txt",ios::out|ios::app);
			   	get_menu();	
				f1.close();
			//	goto MENU; // REDIRECTED TO MENU LABEL
				break;
			case 7:
				system("cls");
		    	f1.open("D:\\menu.txt");
		 	    show_menu();
	    	 	f1.close();
		    	getch();
		    //	goto MENU; // REDIRECTED TO MENU LABEL
		 	    break;
		 	case 8:
		 		delPizzaMenu();
		 	//	goto MENU; // REDIRECTED TO MENU LABEL
		 		break;
			case 9:
				system("cls");
				
				for(i=0;i<50;i++)
				{
					
					cout<<"/";
					if(i==26)
						cout<<"Saving And Exiting.....:";
					Sleep(30);
				}
								
				exit(42);
				value=false;
		//	default:
		//		cout<<"Invalid Choice ...........Enter Again........\n";
		//		Sleep(300);
				//goto MENU; // REDIRECTED TO MENU LABEL
		//		break;
		}
	}
}
gotoxy(18,19);
}
	
				
			
			
		
			
		
}pizza;
	
void menu::get_menu()
{
	system("color 2F");
	do
	{
		system("cls");
		cout<<setw(30)<<"Enter All Pizza DETAILS With PRICES:\n\n";
		cout<<"Enter Item Code:";
		fflush(stdin);
	    
		cin>>i_code;
		cout<<"Pizza Name;";
		fflush(stdin);
		gets(p_name);
		cout<<"Price:";
		cin>>price;
		f1.write((char*)&pizza,sizeof(pizza));
		system("cls");
		cout<<"Record Entered.......\n"<<setw(15)<<"Want To Enter Any More (Y/N):";
		cin>>chop;
		
	}while(chop=='y'||chop=='Y');
}

void menu::show_menu()
{
	system("color 1A");
	cout<<"Item_Code"<<setw(18)<<"Name"<<setw(25)<<"Price"<<"\n";
	while(f1.read((char*)&pizza,sizeof(pizza)))
	cout<<i_code<<setw(25)<<p_name<<setw(20)<<price<<"\n";
}
	
void order::modify()
{
	 MODIFY:
	found=0;
	int mbno1,x;
	char cnfModify;
	cout<<"Enter Mobile_No:";
	cin>>mbno1;
	f2.open("D:\\get_order.txt",ios::in|ios::out|ios::app);
	f3.open("D:\\get_order1.txt",ios::in|ios::out|ios::app);
	
			
	cout<<"Bill_No:"<<setw(10)<<"Name"<<setw(20)<<"Address"<<setw(20)<<"Mobile No"<<setw(20)<<"Pizza Code"<<"\n";
	while(f2.read((char*)&pizza,sizeof(pizza)))
	{
		if(mbno1==mbno)
		{
			cout<<bill_no<<setw(20)<<name<<setw(20)<<add<<setw(15)<<mbno<<setw(20)<<i_code2<<"\n";
			//
			//
			cout<<"\nWant To Modify This:(Y/y):";
			fflush(stdin);
			cin>>cnfModify;
			fflush(stdin);
			if(cnfModify=='y'||cnfModify=='Y')
			{
				cout<<"\nEnter New Pizza Code:";
				cin>>i_code2;
					
			}
			f3.write((char*)&pizza,sizeof(pizza));
			found=1;
		}
			
	
	}
	if(found==0)
	{
		cout<<"File Not Found!!! ENTER AGAIN::";
		system("PAUSE");
		f2.close();
	   	f3.close();
		goto MODIFY;
	}
		
	f2.close();
	f3.close();
		
	
		
	f2.open("D:\\get_order.txt",ios::in|ios::out|ios::app);
	f3.open("D:\\get_order1.txt",ios::in|ios::out|ios::app);
	while(f2.read((char*)&pizza,sizeof(pizza)))
	{
		if(mbno1==mbno)
			continue;
		else
			f3.write((char*)&pizza,sizeof(pizza));
	}
	f2.close();
	f3.close();
	remove("D://get_order.txt");
	rename("D://get_order1.txt","D://get_order.txt");
		
	cout<<"\n\n Record Updated!! Press Any Key For MENU";
	getch();
}
	
void order::get_order()
{
    int x,tempBillCount=0;
	char ch;
	f2.open("D:\\get_order.txt",ios::out|ios::in|ios::app);
	while(f2.read((char*)&pizza,sizeof(pizza)))
	{
		tempBillCount++;
		
	}
	f2.close();
	f2.open("D:\\get_order.txt",ios::out|ios::in|ios::app);
	bill_no=tempBillCount+1;
	cout<<"Enter Name:";
	fflush(stdin);
	gets(name);
	cout<<"Enter Address:";
	fflush(stdin);
	gets(add);
	cout<<"Enter Mobile Number:";
	cin>>mbno;
	fflush(stdin);
	
	AGAIN:                   //GOTO STATEMENT
		
	cout<<"Enter Pizza(ITEM) Code:";
	fflush(stdin);
	cin>>i_code2;  
	//	x=i_code2;
				
		
				        //not working with Item_code2 Variable which Is char Variable in Class and I_code1 is global Variable
			
	f2.write((char*)&pizza,sizeof(pizza));    //storing The Data of Only Pizza Menu And That is also of last menu
 	cout<<"Do You Want To Enter More:";
	 cin>>ch;
	if(ch=='y'||ch=='Y')
	goto AGAIN; // goto to again LABEL
	f2.close();
	gen_bill(mbno,bill_no);
		getch();                 //its just like printing the bill after order;
		
		       /*"Name Is" and "Address" is Showing Two Time One for Above Mobile Number and One time for Item Code in Get Order Detail Function
		        I think am Using Fwrite Fuction Two Times That's y output Is coming Like This 
		
		         have To ask mam about this problem*/
		        
	}
void order::show_order()
{
	system("Color 5F");
	int x;
//	f1.open("D:\\menu.txt",ios::in|ios::out|ios::app);
	cout<<"Bill_No:"<<setw(10)<<"Name"<<setw(20)<<"Address"<<setw(20)<<"Mobile No"<<setw(20)<<"Pizza Code"<<"\n\n";
	while(f2.read((char*)&pizza,sizeof(pizza)))
	{
		cout<<bill_no<<setw(20)<<name<<setw(20)<<add<<setw(15)<<mbno<<setw(20)<<i_code2<<"\n";
		x=i_code2;
		fflush(stdin);
		//cout<<"\nItem_Code"<<setw(18)<<"Pizza Name"<<setw(25)<<"Price"<<"\n\n";
			//	cout<<i_code2<<setw(25)<<p_name<<setw(20)<<price<<"\n";
			
		
	}
	getch();	
		
	f2.close();
	
/*	while(f1.read((char*)&pizza,sizeof(pizza)));
	{
		if(x==i_code)
		{
				
			cout<<"\nItem_Code"<<setw(18)<<"Pizza Name"<<setw(25)<<"Price"<<"\n\n";
			cout<<i_code<<setw(25)<<p_name<<setw(20)<<price<<"\n";
			cout<<"\n\n\n\n\n\n\n"<<setw(50)<<"Amount-->RS "<<total;
		}
		f1.close();
		
		
	} */
	
}
	
void order::gen_bill(int a, int tempBillNo)
{
	system("color 1A");
	int i_bill;
	float total=0;
				
	system("cls");
	cout<<setw(80)<<"_______________________________________\n";
	cout<<setw(80)<<"|=====================================|\n";
	cout<<setw(80)<<"|          LOVELY PIZZA PVT. LTD      |\n";
	cout<<setw(80)<<"|                                     |\n";
	cout<<setw(80)<<"|       Jalandhar-Phagwara Highway    |\n";
	cout<<setw(80)<<"|             Chehru -Punjab          |\n";
	cout<<setw(82)<<"|=====================================|\n\n\n";
						
	cout<<"Customer Name:"<<name<<"\t\tBill No:"<<tempBillNo;
	cout<<"\nAddress:"<<add;
	cout<<"\nContact No:"<<mbno;
	//f1.open("D:\\menu.txt",ios::in|ios::out|ios::app);
	f2.open("D:\\get_order.txt",ios::in|ios::out|ios::app);
	cout<<"\n===================================================================\n";
	cout<<"\n===================================================================\n";
	cout<<"\n\nItem_Code"<<setw(18)<<"Pizza Name"<<setw(25)<<"Price"<<"\n\n";
	while(f2.read((char*)&pizza,sizeof(pizza)))
	{
		if(a==mbno)
		{
			i_bill=i_code2;
			
			f1.open("D:\\menu.txt",ios::in|ios::out|ios::app);
					while(f1.read((char*)&pizza,sizeof(pizza)))
					{	
						if(i_bill==i_code)
						{
							cout<<i_code<<setw(25)<<p_name<<setw(20)<<price<<"\n";
							total+=price;
							break;
						}
	
					}
					f1.close();		
		}
    }
    cout<<"\n\n"<<setw(40)<<"TOTAL COST FOR ORDER IS RS:"<<total<<"\n";
    cout<<setw(50)<<"THANK YOU! AND VISIT AGAIN:\n";
	//f1.close();
	f2.close();
}
	
void order::search()
{
 	system("Color 2F");
	 
	long b;
 	float total=0;

 	Back: //goto function to move back and search again.....

 	system("cls");
 	found=0;
	cout<<"Enter Mobile_No To Be Searched: \n"<<setw(10)<<"Enter 99 Any time When You Wish To go Back(MENU): ";
	cin>>b;
	f2.open("D:\\get_order.txt",ios::in|ios::out|ios::app);
	while(f2.read((char*)&pizza,sizeof(pizza)))
	{
		if(b==mbno)
		{
			cout<<"\n\nCustomer Name:"<<name;
			cout<<"\nAddress:"<<add;
			cout<<"\nContact No:"<<mbno;
			found=1;
			break;
		}
	}
	f2.close();
	if(found==1)
		{
			cout<<"\n\nItem_Code"<<setw(18)<<"Pizza Name"<<setw(25)<<"Price"<<"\n\n";
			f2.open("D:\\get_order.txt",ios::in|ios::out|ios::app);
		//	f2.seekp(0,ios::beg);
			while(f2.read((char*)&pizza,sizeof(pizza)))
			{
				if(b==mbno)
				{
					temp=i_code2;
				
					f1.open("D:\\menu.txt",ios::in|ios::out|ios::app);
					while(f1.read((char*)&pizza,sizeof(pizza)))
					{	
						if(temp==i_code)
						{
							cout<<i_code<<setw(25)<<p_name<<setw(20)<<price<<"\n";
							total+=price;
							break;
						}
	
					}
					f1.close();			
				}
			}
			cout<<"\n\n"<<setw(20)<<"TOTAL COST FOR PIZZA IZZ RS:"<<total<<"\n";
		}
	
		
		if (found==0)
		{
		    if(b==99)
		    goto MENU;
			system("cls");
			cout<<"File/Record Not Found!!\n Press any key to enter again.....";
			getch();
			goto Back;
		}
		
		MENU:
		f1.close();
		f2.close();
}


void order::del_rec()
{
	system("color 7C");
	searchAgain:             //GOTO STATEMENT 
	found=0;
	long long x;
	char ch;
	
	cout<<"Enter Mobile Number:"<<setw(10)<<"(ENTER 99 ANY TIME #TO #GO #BACK::)";
	cin>>x;
	f2.open("D://get_order.txt",ios::in|ios::out|ios::app);
	while(f2.read((char*)&pizza,sizeof(pizza)))
	{
		if(x==mbno)
		{
			cout<<"\n\nCustomer Name:"<<name;
			cout<<"\nAddress:"<<add;
			cout<<"\nContact No:"<<mbno;
			temp=i_code2;
			found=1;
		}
	}
	f2.close();
	if (found==0)
	{
	    if(x==99)
		    goto MENU;
		system("cls");
		cout<<"File/Record Not Found!!\n Press any key to enter again.....";
		getch();
		goto searchAgain;
	}
	
	if(found==1)
		cout<<"\n\nItem_Code"<<setw(18)<<"Pizza Name"<<setw(25)<<"Price"<<"\n\n";
	f1.open("D:\\menu.txt",ios::in|ios::out|ios::app);
		
	while(f1.read((char*)&pizza,sizeof(pizza)))
	{
		if(temp==i_code)
		{
			cout<<i_code<<setw(25)<<p_name<<setw(20)<<price<<"\n";
				
		}
		
		
	}
	     // MENU LOCAL GOTO Object;
		
	f1.close();
	MENU:  
	
	f2.open("D://get_order.txt",ios::in);
	f3.open("D://get_order1.txt",ios::in|ios::out|ios::app);
	while(f2.read((char*)&pizza,sizeof(pizza)))
	{
		if(x==mbno)
		continue;
		f3.write((char*)&pizza,sizeof(pizza));
	}
	f2.close();
	f3.close();
	remove("D://get_order.txt");
	rename("D://get_order1.txt","D://get_order.txt");
	
	
	
		
		
		
}

void menu::delPizzaMenu()
{
	system("color 5F");
	int tempIcode;
	found=0;
	f1.open("D://menu.txt",ios::in|ios::out|ios::app);
	delPizzaMenu:
	cout<<"Enter Pizza Code:";
	cin>>tempIcode;
	while(f1.read((char*)&pizza,sizeof(pizza)))
	{
		if(tempIcode==i_code)
		{
			cout<<i_code<<setw(25)<<p_name<<setw(20)<<price<<"\n";
			found=1;	
		}
	}
	f1.close();
	if(found!=1)
	{
		if(tempIcode==99)
		goto delPizzaMenu1;
		cout<<"Required Data Is Not Found!!!,\n   PRESS ANY KEY TO ENTER AGAIN(ENTER 99 To GO BACK):\n";
		getch();
		goto delPizzaMenu;
	}
	
	
	f1.open("D://menu.txt",ios::in);
	f4.open("D://menu1.txt",ios::in|ios::out|ios::app);
	delPizzaMenu1: // goto function
	while(f1.read((char*)&pizza,sizeof(pizza)))
	{
		if(tempIcode==i_code)
		continue;
		f4.write((char*)&pizza,sizeof(pizza));
	}
	f1.close();
	f4.close();
	remove("D://menu.txt");
	rename("D://menu1.txt","D://menu.txt");
	
		
}
	
	
	
	
main()
{
	system("Color 6B");
	char pass[256] = {0},c;
    char pass1[] = "mujtaba1@";
    int pos = 0,count=0;
    Sleep(300);
    cout<<setw(30)<<"               ============================================\n";
    Sleep(300);
    cout<<setw(45)<<"                           PIZZA MANAGEMENT SYSTEM\n";
    Sleep(300);
    cout<<setw(45)<<"                         CREATED BY- MOHAMMAD MUJTABA\n";
    Sleep(300);
    cout<<setw(45)<<"                               SECTION - K1613\n";
    Sleep(300);
    cout<<setw(45)<<"                                ROLL NO- B47\n";
    Sleep(300);
    cout<<setw(30)<<"               =============================================\n";
    Sleep(300);
    cout<<setw(30)<<"               =============================================\n";
    Sleep(300);
    cout<<setw(30)<<"                          LOGIN INTERFACE (AUTHORIZED)\n";
    Sleep(300);
    cout<<setw(30)<<"               =============================================\n\n";
    Sleep(300);
    login:  // GOTO FUNCTION
    
    cout<<"\nEnter Password (Max 3 attempts) : ";
    
    do {
        c = getch();

        if( isprint(c) ) 
        {
            pass[ pos++ ] = c;
            cout<<'*';
        }
        else if( c == 8 && pos )
        {
            pass[ pos-- ] = '\0';
            cout<<"\b\b";
            
        }
    } while( c != 13 );
    
    system("cls");
    cout<<"Please Wait System Is Verifing data";
    for(i=0;i<40;i++)
    {
    	Sleep(59);
    cout<<"_";
}

    if( !strcmp(pass,pass1) )
        {
        	system("cls");
        	cout<<setw(40)<<"                  PLEASE WAIT WHILE PROGRAM IS LOADING>>\n";
            for(i=0;i<40;i++)
		     {
			cout<<"/\\";
			Sleep(50);
			
            	}
	
        }
    else
        {
  cout<<"\n Wrong Password!!!\n PRESS ANY KEY & TRY AGAIN";
  getch();
  count++;
  if(count==3)
  exit(42);
  else 
  goto login;
 }	
		
	pizza.home_page();	
			

}
	
