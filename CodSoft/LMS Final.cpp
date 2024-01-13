#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstring>
#include <cstdlib>  
#include <cstring>  

using namespace std;

class lib
{
	private:
	int bookid;
	char title[20];
	char author[20];
	char category[20];
	float edition;
	int pages;
	string dueDate;
	bool checkedOut;
	bool available;
	public:
		//accessing functions
	int getid()
	{
		return bookid;
	}
	char *gettitle()
	{
	return title;	
	}
	char *getauthor()
	{
		return author;
	}
	char *getcategory()
	{
		return category;
	}
	float getedition()
	{
		return edition;
	}
	string getdueDate()
	{
		return dueDate;
	}
	bool isCheckedOut()
	{
		return checkedOut;
	}
	 void setCheckedOut(bool status) {
        checkedOut = status;
    }
     bool isAvailable() const {
        return available;
    }

    
    void setAvailability(bool status) {
        available = status;
    }
	lib()
	{
		bookid=0;
		strcpy(title,"");
		strcpy(author,"");
		strcpy(category,"");
		pages=0;
		edition=0;
	}
	void getbook()
	{
		bool status,status1;
		cout<<"\tEnter Book ID:";
		cin>>bookid;
		cout<<"\tEnter Book Title:";
		cin.get();
		cin.getline(title,20);
		cout<<"\tEnter Book Author: ";
		cin.getline(author,20);
		cout<<"\tEnter Book Category: ";
		cin.getline(category,20);
		cout<<"\tEnter No. of Pages: ";
		cin>>pages;
		cout<<"\t Enter Date of Editon of Book: ";
		cin>>edition;
		 cout << "\tEnter Due Date (YYYY-MM-DD): ";
    cin >> dueDate;
    cout<<"\t CheckedOut (1 for true, 0 for false):";
	cin>>status;
	setCheckedOut(status);
	cout<<"\t Change it's availability status:";
	cin>>status1;
	setAvailability(status1);
		cout<<endl;
	}
	//To display book details in individualistic format
	void showbook()
	{
		cout<<endl;
		cout<<"Book ID        :"<<bookid<<endl;
		cout<<"Book Title     :"<<title<<endl;
		cout<<"Author Name    :"<<author<<endl;
		cout<<"Category       :"<<category<<endl;
		cout<<"No. of Pages   :"<<pages<<endl;
		cout<<"Editon         :"<<edition<<endl;
		cout <<"Due Date      :" << dueDate << endl;
		 cout<< "Checked Out  :" << (checkedOut ? "Yes" : "No") << endl;
	}
	void header()
	{
		cout.setf(ios::left);
		cout<<setw(5)<<"I.D."
		<<setw(20)<<"Book Title"
		<<setw(20)<<"Book Author"
		<<setw(15)<<"Category"
		<<setw(6)<<"Pages"
		<<setw(6)<<"Editon"
		<<setw(15)<<" Due Date"
		<<setw(10)<<"Checkout Out"
		<<setw(15)<<"Availabilty"<<endl;
		for(int i=1;i<=120;i++)
		{
			cout<<"=";
		}
		cout<<endl;
		
	}
	void listshow()
	{
		cout.setf(ios::left);
		cout<<setw(5)<<bookid
		<<setw(20)<<title
		<<setw(20)<<author
		<<setw(15)<<category
		<<setw(6)<<pages
		<<setw(6)<<edition
		 <<setw(6)<<dueDate
		 <<setw(10)<<"  "<<boolalpha<<checkedOut
		 <<setw(15)<<"  "<<boolalpha<<available<<endl;
	}
	
}obj1;

//functions for project declared outside of class lib
int fineAmount;
void bookReturn() {
    int n, flag = 0;

    ifstream sin("books.dat");
    ofstream fout("temp.dat", ios::out | ios::binary);

    cout << "Enter Book ID for return: ";
    cin >> n;

    while (sin.read((char*)&obj1, sizeof(obj1))) {
        if (n == obj1.getid()) {
            obj1.showbook();
            obj1.setAvailability(true);  // set availability status to true (returned)
            flag++;
        }
        fout.write((char*)&obj1, sizeof(obj1));
    }

    sin.close();
    fout.close();

    if (flag == 0) {
        cout << "Book with ID " << n << " not found...\n";
    } else {
        remove("books.dat");
        rename("temp.dat", "books.dat");
        cout << "Book returned successfully.\n";
    }
}

void checkoutBook() {
    int n, flag = 0;
    ifstream sin("books.dat");
    ofstream fout("temp.dat", ios::out);

    cout << "Enter Book ID for checkout: ";
    cin >> n;

    while (sin.read((char*)&obj1, sizeof(obj1))) {
        if (n == obj1.getid()) {
            obj1.showbook();
            obj1.setCheckedOut(true); // Set the book as checked out
            flag++;
        }
        fout.write((char*)&obj1, sizeof(obj1));
    }

    sin.close();
    fout.close();

    if (flag == 0) {
        cout << "Book Number with ID: " << n << " not available...\n";
    } else {
        remove("books.dat");
        rename("temp.dat", "books.dat");
        cout << "Book checked out successfully.\n";
    }
}

void calculateFine() {
    // Get the current date (manually input for demonstration purposes)
    string currentDate = "2024-01-13"; // replace with the actual current date

    ifstream r("books.dat");
    while (r.read(reinterpret_cast<char*>(&obj1), sizeof(obj1))) {
       
        // Convert the due date string to a date object (manually input for demonstration purposes)
        string dueDate = obj1.getdueDate();

        // Compare the current date with the due date
        if (currentDate > dueDate) {
            // Calculate and display the fine (you can replace this with your own fine calculation logic)
            cout << "Book ID: " << obj1.getid() << " is overdue.\n";
            // Replace 10 with your fine rate per day
             fineAmount = (currentDate[8] - dueDate[8]) * 10;

            cout << "Fine amount: Rs " << fineAmount << "\n";
        }
    }
    r.close();
}
void drawline(char ch)
{
	for(int i=1;i<=80;i++)
	cout<<ch;
	cout<<endl;
	
}
void heading()
{
	drawline('|');
	cout<<"\t\tLIBRARY MANAGEMENT SYSTEM\n";
	drawline('|');
}
void addbook()
{
	ofstream f;
	f.open("books.dat",ios::app);
	obj1.getbook();
	obj1.setCheckedOut(false);
	obj1.setAvailability(true);
	f.write(reinterpret_cast<char*>(&obj1),sizeof(obj1));
	cout<<"Book data saved in file...\n";
	f.close();
}
void displaybooks()
{
	ifstream r("books.dat");
	int rec=0;
	while(r.read(reinterpret_cast<char*>(&obj1), sizeof(obj1))) 
	{
		if(rec<1)
		obj1.header();
		obj1.listshow();
		rec++;
	}
	r.close();
	cout<<"\nTotal "<<rec<<" Records in file...\n";
	
}
void searchbyid()
{
	int n,flag=0;
	ifstream sin("books.dat");
	cout<<"Enter Book Id:  ";
	cin>>n;
	while(sin.read((char *)&obj1,sizeof(obj1)))
	{
		if(n==obj1.getid())
		{
			obj1.showbook();
			flag++;
			
		}
	}
	sin.close();
	if(flag==0)
	{
		cout<<"Book Number with ID: "<<n<<" not available...\n";
		
	}
}
void searchbytitle()
{
	int flag=0;
	char title[20];
	ifstream sin("books.dat");
	cout<<"Enter Book Title :";
	cin.ignore();
	cin.getline(title,20);
	while(sin.read((char *)&obj1,sizeof(obj1)))
	{
		if(strcmpi(title,obj1.gettitle())==0)
		{
			obj1.showbook();
			flag++;
		}
		
	}
	sin.close();
	if(flag==0)
	cout<<"Book with title: "<<title<<" not available...\n";
}
void searchbycategory()
{
	int flag=0,rec=0;
	char catg[20];
	ifstream sin("books.dat");
	cout<<"Enter Book Category :";
	cin.ignore();
	cin.getline(catg,20);
	while(sin.read((char *)&obj1,sizeof(obj1)))
	{
		if(strcmpi(catg,obj1.getcategory())==0)
		{
			if(rec<1)
			obj1.header();
			obj1.listshow();
			flag++;
			rec++;
		}
		
	}
	sin.close();
	if(flag==0)
	cout<<"Book with Category: "<<catg<<" not available...\n";
}
void searchbyauthor()
{
	int flag=0,rec=0;
	char auth[20];
	ifstream sin("books.dat");
	cout<<"Enter Book Author :";
	cin.ignore();
	cin.getline(auth,20);
	while(sin.read((char *)&obj1,sizeof(obj1)))
	{
		if(strcmpi(auth,obj1.getauthor())==0)
		{
			if(rec<1)
			obj1.header();
			obj1.listshow();
			flag++;
			rec++;
		}
		
	}
	sin.close();
	if(flag==0)
	cout<<"Book with Author: "<<auth<<" not available...\n";
}
void dispose()
{
	int n,flag=0;
	ifstream sin("books.dat");
	ofstream fin("dispose.dat",ios::out|ios::binary);
	cout<<"Enter Book ID: ";
	cin>>n;
	while(sin.read((char *)&obj1,sizeof(obj1)))
	{
		if(n==obj1.getid())
		{
			obj1.showbook();
			flag++;
		}
		else
		{
			fin.write((char*)&obj1,sizeof(obj1));
		}
	
	
	}
		sin.close();
		fin.close();
			if(flag==0)
		{
			cout<<"Book Number with Id :"<<n<<" not available...\n";
			
		}
		else
		{
			cout<<"Book Transferred to dispose.dat successfully.\n";
		}
}
void modify()
{
	int n,flag=0, pos;
	fstream sin("books.dat",ios::in|ios::out);
	cout<<"Enter Book Id: ";
	cin>>n;
	while(sin.read((char*)&obj1,sizeof(obj1)))
	{
		if(n==obj1.getid())
		{
			pos=sin.tellg();
			cout<<"Following data will be edited....\n";
			obj1.showbook();
			flag++;
			sin.seekg(pos-sizeof(obj1));
			obj1.getbook();
			sin.write((char*)&obj1,sizeof(obj1));
			cout<<"\nData Modified Successfully...\n";
			
		}
	}
	sin.close();
	if(flag==0)
	cout<<"Book Number with ID: "<<n<<" not available...\n";
}
void displaydisposed()
{
	ifstream sin("dispose.dat");
	int rec=0;
	while(sin.read((char*)&obj1,sizeof(obj1)))
	{
	 if(rec<1)
	 	obj1.header();
	 obj1.listshow();
	 rec++;	
	}
	sin.close();
	cout<<"\nTotal "<<rec<<" Records in disposed off file...\n";
	
}

//function for displaying program options
void searchmenu()
{
	int ch;
	do
	{
		system("cls");
		heading();
		cout<<"Book Search Options\n";
		cout<<"0. Back\n";
		cout<<"1.By ID\n";
		cout<<"2.By title\n";
		cout<<"3. By Category\n";
		cout<<"4. By Author\n";
		
		cout<<"Enter your choice: ";
		cin>>ch;
		system("cls");
		heading();
		switch(ch)
		{
		 	case 1:
				searchbyid();
				break;
			case 2:
				searchbytitle();
				break;
			case 3:
				searchbycategory();
				break;
			case 4:
			searchbyauthor();
			break;
			
			default:
				cout<<"\a";
				
		}
		system("pause");
		
	}
	while(ch!=0);
}
void menu()
{
	int ch;
	do 
	{
		system("cls");
		heading();
		cout<<"0.Exit.\n";
		cout<<"1.Add new book\n";
		cout<<"2.Display All books\n";
		cout<<"3.Search all books\n";
		cout<<"4.Disposed off books\n";
		cout<<"5.Modify Details\n";
		cout<<"6.List of Disposed Books\n";
		
		cout << "7. Calculate Fines\n";
		cout<<"8.To Mark A book Checkedout\n";
		cout << "9. Return a Book\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		system("cls");
		heading();
		switch(ch)
		{
			case 1:
				addbook();
				break;
			case 2:
				displaybooks();
				break;
			case 3:
				searchmenu();
				break;
			case 4:
			dispose();
			break;
			case 5:
			modify();
			break;
			case 6:
			displaydisposed();
			break;	
			case 7:
			calculateFine();
			break;
			case 8:
			checkoutBook();
			break;
			 case 9:
            bookReturn();
            break;
		}
		system("pause");
		
	}
	while(ch!=0);
	
}

int main()
{
	menu();
	return 0;
}