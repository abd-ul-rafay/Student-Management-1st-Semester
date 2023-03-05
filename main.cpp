#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string line[5][8]; 
void fileReader();
void menu();
void selection(string [],string [],string [],string [],string [],string [],string [],string []);
void others(string [],string [],string [],string [],string [],string [],string [],string []);
void loginPortal(string [],string [],string [],string [],string []);
void student_Login(string [],string [],string [],string [],string [],int);
void registeration(string [],string [],string [],string [],string [],int);
void register_inFile(string [],string [],string [],int);
void feeDefaulter(string [],string [],string [],string [],string [],int);
void cgpa(string [],string [],string [],string [],string [],int);
void preRequisite(string [],string [],string [],string [],string [],int);

int main()
{
	
	fileReader();
	
	string student_Name[5];
	string student_ID[5];
	string student_Password[5];
	string student_Fee[5];
	string student_pReq[5];
	string student_CGPA[5];
	string student_Address[5];
	string student_Number[5];
	
	int i,j;
	/* Data of Students */
	for(i = 0; i < 5; i++)
	{
		j=0;
		student_Name[i]     = line[i][j];
		j=1;
		student_ID[i]       = line[i][j];
		j=2;
		student_Password[i] = line[i][j];
		j=3;
		student_Fee[i]      = line[i][j];
		j=4;
		student_pReq[i]     = line[i][j];
		j=5;
		student_CGPA[i]     = line[i][j];
		j=6;
		student_Address[i]  = line[i][j];
		j=7;
		student_Number[i]   = line[i][j];
	}

	
	
	/* Calling menu function */
	menu();
	
	/* Calling selection function */
	selection(student_Name, student_ID, student_Password, student_Fee, student_pReq, student_CGPA, student_Address, student_Number); 
	
	return 0;
}
	
void fileReader()
{
	
	fstream AnyFile;
	AnyFile.open("Student_Data.txt", ios::in);  //  read mode
	
	if(AnyFile.is_open())
	{
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				getline(AnyFile, line[i][j]);
			}
		}
		AnyFile.close();
	}
	
}
	
void menu()
{
	system("cls");

	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout<<"- - - - - - - - - - U M T    R E G I S T E R A T I O N    S Y S T E M - - - - - - - - - -"<<endl;
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout<<"- - - | Press 1 to  Login." <<endl;	
	cout<<"- - - | Press 2 for Other." <<endl;	
	cout<<"- - - | Press other to  exit the System." <<endl;	
}	

void selection(string student_Name[],string student_ID[],string student_Password[],string student_Fee[],string student_pReq[],string student_CGPA[],string student_Address[],string student_Number[])
{
	int menuKey;
	cout << "- - - - - > ";

	cin >> menuKey;  // Taking a value for next action
	
	switch(menuKey)
	{
		case 1:
		    loginPortal(student_Name, student_ID, student_Password, student_Fee, student_CGPA);
			break;
		case 2:
			others(student_Name, student_ID, student_Password, student_Fee, student_pReq, student_CGPA, student_Address, student_Number);
		default:
			cout<<endl;
			cout<<"- - - - - - E X I T E D - - - - - -"<<endl;
			cout<<"- - - - - - ThankYou :) - - - - - -"<<endl;
			
			exit (3);
			break;
	}
}

void loginPortal(string student_Name[],string student_ID[],string student_Password[],string student_Fee[],string student_CGPA[])
{
	system("cls");

	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout << "- - - - - - - - L o g i n     P o r t a l - - - - - - - -"<<endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	
	string userID, password;
	bool a=1;

	while(a==1)
	{
		cout<<"- - - - Enter Your ID and Password"<<endl;
		cout<<"- - - - - - > User ID (-1 to exit): ";

		cin>>userID;
		if(userID=="-1")
		{
			cout<<endl;
			cout<<"- - - - - - E X I T E D - - - - - -"<<endl;
			cout<<"- - - - - - ThankYou :) - - - - - -"<<endl;
			
			exit (3);
	    }

		cout<<"- - - - - - - - - - - - > Password: ";
		cin>>password;
		
		int b=0;    // used so that it can take value of "i" inside loop and giving to its sub-function
		
		
		for(int i = 0; i < 5; i++)
		{
			if(userID==student_ID[i] && password==student_Password[i])
			{
				a=0;
				b=i;  // here value of b is value of i
				
				system("cls");
							
				student_Login(student_Name, student_ID, student_Password, student_Fee, student_CGPA, b);
				break;
			}		
		}
		
		if(a==1)
		{
			cout<<endl<<"- - - - Invalid ID or Password, Try again"<<endl;
		}
	}
}

void others(string student_Name[],string student_ID[],string student_Password[],string student_Fee[],string student_pReq[],string student_CGPA[],string student_Address[],string student_Number[])
{
	system("cls");

	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout<<"- - - - - - - - - - U M T    R E G I S T E R A T I O N    S Y S T E M - - - - - - - - - -"<<endl;
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	
	cout<<"- - - - Enter 1 to search a Student."<<endl;
	cout<<"- - - - Enter 2 to delete a Record."<<endl;
	cout<<"- - - - Enter other to Exit"<<endl;
	
	int give;
	cout<<"- - - - - > ";
	cin>>give;
	
		if(give==1)
		{
			system("cls");

			cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
			cout<<"- - - - U n i v e r s i t y   o f   M a n a g m e n t   a n d   T e c h n o l o g y - - - -"<<endl;
			cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
			
			cout<<"- - - - Enter the ID of the student to search"<<endl;
			
			string Idee;
			cout<<"- - - - - > ";

			cin>>Idee;
			
			int q=1;
			for(int i=0;i<5;++i)
			{	
				if(Idee==student_ID[i])
					{
						q=0;
						cout<<"- - - | Name:     "<<student_Name[i]<<endl;
						cout<<"- - - | ID:       "<<student_ID[i]<<endl;
						cout<<"- - - | Password: "<<student_Password[i]<<endl;
						cout<<"- - - | CGPA:     "<<student_CGPA[i]<<endl;
						cout<<"- - - | Pre-Req:  "<<student_pReq[i]<<endl;
						cout<<"- - - | Fees:     "<<student_Fee[i]<<endl;
						cout<<"- - - | Address:  "<<student_Address[i]<<endl;
						cout<<"- - - | Number:   "<<student_Number[i]<<endl;	
						
						system("pause");
						menu();
						selection(student_Name, student_ID, student_Password, student_Fee, student_pReq, student_CGPA, student_Address, student_Number); 

					}
			}
					
			if(q==1)
				{
					cout<<"- - - - Not found"<<endl;
					system("pause");
					menu();
					selection(student_Name, student_ID, student_Password, student_Fee, student_pReq, student_CGPA, student_Address, student_Number); 

				}
		}
			
		else if (give==2)
		{
			system("cls");

			cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
			cout<<"- - - - U n i v e r s i t y   o f   M a n a g m e n t   a n d   T e c h n o l o g y - - - -"<<endl;
			cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
			
			cout<<"- - - - Press 1 to delete a Record"<<endl;
			cout<<"- - - - Press other to Exit"<<endl;

			int deleter;
			cout<<"- - - - - >";
			cin>>deleter;
			
			switch(deleter)
			{
				case 1:
					cout<<"Are you sure, You want to delete te Record"<<endl;
					cout<<"- - - - Press 1 for Yes"<<endl;
					cout<<"- - - - Press 0 for No"<<endl;
					
					bool y_n;
					cin>>y_n;
					
					if(y_n==1)
					{
						cout<<"You will not Able to run program After clearing Data"<<endl;
						system("pause");
						fstream qFile;
						qFile.open("Student_Data.txt", ios::trunc);
						if(qFile.is_open())
						{
//							file will delete
							qFile.close();
						}
					}		
					break;
					
				default:
					menu();
					selection(student_Name, student_ID, student_Password, student_Fee, student_pReq, student_CGPA, student_Address, student_Number); 

			}
		}
			
		else
		{
			menu();
			selection(student_Name, student_ID, student_Password, student_Fee, student_pReq, student_CGPA, student_Address, student_Number); 
		}
}

void student_Login(string student_Name[],string student_ID[],string student_Password[],string student_Fee[],string student_CGPA[],int b)
{
	
	system("cls");
	
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout<<"- - - - U n i v e r s i t y   o f   M a n a g m e n t   a n d   T e c h n o l o g y - - - -"<<endl;
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	
	cout<<"- - - - - "<<student_Name[b]<<endl<<"- - - - - - ID: "<<student_ID[b]<<endl;
	cout<<"- - - - - - - - - - -"<<endl;
	cout<<"- - - | Press 2 to Register." <<endl;	
	cout<<"- - - | Press 3 to See the List of Fee defaulters." <<endl;	
	cout<<"- - - | Press 4 to see the CGPA of a student." <<endl;	
	cout<<"- - - | Press 5 to see the Pre requisite of a Course." <<endl;	
	cout<<"- - - | Press other to exit."<<endl;
				
	string afterLogin;
	cout<<"- - - - - > ";
	cin>>afterLogin;
			
	if(afterLogin=="2")
		registeration(student_Name,student_ID,student_Password,student_Fee,student_CGPA,b);
		
	else if(afterLogin=="3")
		feeDefaulter(student_Name,student_ID,student_Password,student_Fee,student_CGPA,b);
		
	else if(afterLogin=="4")
		cgpa(student_Name,student_ID,student_Password,student_Fee,student_CGPA,b);
		
	else if(afterLogin=="5")		
		preRequisite(student_Name,student_ID,student_Password,student_Fee,student_CGPA,b);
		
	else	
		loginPortal(student_Name, student_ID, student_Password, student_Fee, student_CGPA);
							
}

void registeration(string student_Name[],string student_ID[],string student_Password[],string student_Fee[],string student_CGPA[],int b)
{
	system("cls");
	
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout << "- - - - - - - - R e g i s t e r a t i o n - - - - - - - -"<<endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	
	cout << "- - - - "<<student_Name[b]<<endl;
	
	if(student_Fee[b]=="0")
	{
		cout<<"- - - Sorry, can't Register"<<endl;
		cout<<"- - - - - Your Dues are not clear"<<endl;
		cout<<"- - - - - - - Please clear your Fees"<<endl;
		
		system("pause");
		student_Login(student_Name, student_ID, student_Password, student_Fee, student_CGPA, b);
	}
	else
	{
		if(student_CGPA[b] > ("3.0"))
		{
			cout<<"- - - - CGPA is - - - - > "<< student_CGPA[b] <<endl;
			cout<<"- - - - - So registering all Courses"<<endl;
			cout<<"- - - - - - - - - - -"<<endl;

			cout<<"- - - - - 2nd Semester Courses"<<endl;
			cout<<"- - - | Object Oriented Programming"<<endl;
			cout<<"- - - | Discrete Structures"<<endl;
			cout<<"- - - | Applied Physics"<<endl;
			cout<<"- - - | Object Oriented Programming Lab"<<endl;
			cout<<"- - - | Composition & Communication"<<endl;
			cout<<"- - - | Applied Physics Lab"<<endl;
			cout<<"- - - | Pakistan Studies"<<endl;
			
		}
		else if(student_CGPA[b] > ("2.0"))
		{
			cout<<"- - - - CGPA is - - - - > "<< student_CGPA[b] <<endl;
			cout<<"- - - - - So registering Three Courses"<<endl;
			cout<<"- - - - - - - - - - -"<<endl;
			
			cout<<"- - - - - 2nd Semester Courses"<<endl;
			cout<<"- - - | Object Oriented Programming"<<endl;
			cout<<"- - - | Discrete Structures"<<endl;
			cout<<"- - - | Applied Physics"<<endl;
		}
		else if(student_CGPA[b] <= ("2.0"))
		{
			cout<<"- - - - CGPA is - - - - > "<< student_CGPA[b] <<endl;
			cout<<"- - - - - So registering Two Courses"<<endl;
			cout<<"- - - - - - But with Warning!"<<endl;
			cout<<"- - - - - - - - - - -"<<endl;
			
			cout<<"- - - - - 2nd Semester Courses"<<endl;
			cout<<"- - - | Object Oriented Programming"<<endl;
			cout<<"- - - | Discrete Structures"<<endl;
		}
		
		register_inFile(student_Name,student_ID,student_CGPA,b);
		
		cout<<"To exit, ";
		system("pause");
		student_Login(student_Name, student_ID, student_Password, student_Fee, student_CGPA, b);
	}
}

void register_inFile(string student_Name[],string student_ID[],string student_CGPA[],int b)
{
	string subj[7]={"OOP","Discrete Structures","Applied Physics","OOP LAB","Composition & Communication","Applied Physics Lab","Pakistan Studies"};
	
	fstream jFile;
	jFile.open("For_Register.txt", ios::app);
	if(jFile.is_open())
	{
		jFile<<"Registration of Courses"<<endl;
		jFile<<student_Name[b]<<endl;
		jFile<<"ID: "<<student_ID[b]<<endl;
		jFile<<"CGPA: "<<student_CGPA[b]<<endl;
		
		if(student_CGPA[b] > ("3.0"))
		{
			for(int i = 0; i < 7; i++)
			{
				jFile<<i+1<<"."<<subj[i]<<endl;
			}
		}
		else if(student_CGPA[b] > ("2.0"))
		{
			for(int i = 0; i < 3; i++)
			{
				jFile<<i+1<<"."<<subj[i]<<endl;
			}
		}
		else if(student_CGPA[b] <= ("2.0"))
		{
			for(int i = 0; i < 2; i++)
			{
				jFile<<i+1<<"."<<subj[i]<<endl;
			}
		}
		
		jFile<<"----------------------------------------------"<<endl;
		jFile.close();
	}
	
}

void feeDefaulter(string student_Name[],string student_ID[],string student_Password[],string student_Fee[],string student_CGPA[],int b)
{
	system("cls");
	
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout << "- - - - - - - - F e e    D e f a u l t e r s  - - - - - - - -"<<endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	
	cout<<"- - - - - Following are the Fee defaulter Students:"<<endl;
	
	for(int i = 0; i < 5; i++)
	{
		if(student_Fee[i]=="0")
		{
			cout<<"- - - | Name:     "<<student_Name[i]<<endl;
			cout<<"- - - | ID:       "<<student_ID[i]<<endl;
			cout<<"- - - | Password: "<<student_Password[i]<<endl;
			cout<<"- - - | CGPA:     "<<student_CGPA[i]<<endl;
			cout<<"- - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		}
	}
	
	cout<<"To exit, ";
	system("pause");
	student_Login(student_Name, student_ID, student_Password, student_Fee, student_CGPA, b);
}

void cgpa(string student_Name[],string student_ID[],string student_Password[],string student_Fee[],string student_CGPA[],int b)
{
	system("cls");
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout << "- - - - - - - - C G P A   o f   a   S t u d e n t - - - - - - - -"<<endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	
	cout << "- - - - "<<student_Name[b]<<endl;
	cout << "- - - - "<<"Your CGPA is - - - > "<<student_CGPA[b]<<endl;
	
	cout<<"To exit, ";
	system("pause");
	student_Login(student_Name, student_ID, student_Password, student_Fee, student_CGPA, b);
}

void preRequisite(string student_Name[],string student_ID[],string student_Password[],string student_Fee[],string student_CGPA[],int b)
{
	system("cls");
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout << "- - - - - - - - P r e    R e q u i s i t e  - - - - - - - -"<<endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	cout << "- - - - - - - - - -"<<endl;
	
	string reader;
	fstream aFile;
	aFile.open("For_PreRequisite.txt", ios::in);

	if(aFile.is_open())
	{
		while(getline(aFile, reader))
		{
			cout<<reader<<endl;
		}
		aFile.close();
	}
	
	cout<<"To exit, ";
	system("pause");

	student_Login(student_Name, student_ID, student_Password, student_Fee, student_CGPA, b);
}
