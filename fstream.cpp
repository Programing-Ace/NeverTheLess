/* FEATURES OF C++ USED
   1. CONCEPT OF CLASS AND OBJECTS
   2. DEFINING A FUNCTION OUTSIDE CLASS USING SCOPE RESOLUTION OPERATOR
   3. MANIPULATORS
   4. INITIALIZER LIST
   5. SLEEP FXN 
   6. FILE HANDLING
   7. INHERITANCE
   8. STRING
   9. ARRAYS
   10.STATIC DATA MEMBER
   11.CONSTRUCTORS
   12.DESTRUCTOR
   13.INLINE FUNCTION
   14.FRIEND FUNCTION
   15.CALL BY REFERENCE
   16.CALL BY ADDRESS
   17.FUNCTION OVERLOADING
   18.OPERATOR OVERLOADING
   19.GETLINE 
   20.TYPE CONVERSION
   21.POINTERS 
   22.POINTER TO OBJECT
   23.LOOPS
   24.DECISION MAKING USING CONDITIONS
   25.SWITCH CASE
   26.DIFFERENT INBUILT FUNCTIONS OF STRING CLASS
*/
#include<windows.h>		//sleep fxn
#include<iostream>
#include<iomanip>		// for manipulators
#include<string>
#include<fstream>	//File handling 
using namespace std;
class store
{//public:
    char a[20];int s,c,b,choice;
	static int q;    //static int
public:
    store ()  //default constructor
    {
        string pass,password="coding@c++";   //password
        for(q=0;;)
        {
        cout<<"\n enter correct password :- ";
        cin>>a;
        int i=password.compare(a);         //compare of string
        if (i==0)
        {
            cout<<"\npassword matched\n";
            break;
        }
        else
        {
            cout<<"\npassword not matched\n\a";
            ++q;
            cout<<"\n"<<q<<" number of times entered wrong password\n\n\n";
        }
        }
    }
    store (const int h1,int y=20);    //parametrised constructor
    inline friend void welcome();     //inline friend function
   void welcome(int *xu)              //call by adress
   {string t3=" TO ";
   string t4="THE "; 
   t4.swap(t3);                    //swap of string
   	cout<<t4<<t3;
   }
   void welcome(int &pu)         //call by reference along overloading
   {
   	cout<<"STORE"<<setw(50)<<setfill('=');//  manipulator
   }
    
};
int store::q=0;    //for static int
void welcome()
	   {
	   	string t1="WEL";
	   	string t2="COME";
        	cout<<setw(50)<<setfill('=')<<t1+t2;
			}
store::store (int h1,int y):c(h1)   //parametreised constructor,intializer list
   {						//similar to c=h1 and b=y;
Sleep(c);
cout<<"\n \n *******************************";
        Sleep(c);
          cout<<"DEPARTMENTAL STORE";
        Sleep(c);
          cout<<"******************************* \n";
Sleep(c);
cout<<"                                 MADE BY- ABHISHIKA AGARWAL                         \n";Sleep(600);
cout<<"                                   K18AP (11811468)                           \n";
cout<<"   ";   
 }

class store1:public store  //single inheritance
{//public:
	int mfgdd,mfgmm,mfgyyyy,expdd,expmm,expyyyy,n,i,price,pname,x;
    char name[25];
    char comp;
    public:
    void detail();
    void totalitems();
    void additems();
    void modify();
    void searchproduct();
    void format();
    void deleteitems();
    void operator+(int);
    ~store1()                 //destructor
    {
        cout<<"\t\tprogramm execution completed";
    }
};
void store1::operator +(int d) //operator overloading
{
	x=70;
	x=x+d;
	//cout<<x;
}
void store1::additems()   //to add items
{
	cout<<"for how many products u want to enter data -";
	cin>>n;
	for(i=0;i<n;i++)
	{
	ofstream outf("store.txt",ios::out|ios::app);
    cout<<"enter product name : ";
    cin>>name;
    outf<<"name-"<<name<<"\t\t";
    cout<<"enter product price : ";
    cin>>price;
    outf<<"price-"<<price<<"\t\t";
    cout<<"enter mfg date(dd,mm,yyyy)-";
    cin>>mfgdd;cout<<"                          -";
	cin>>mfgmm;cout<<"                          -";
	cin>>mfgyyyy;
    outf<<"mfg-"<<mfgdd<<"-"<<mfgmm<<"-"<<mfgyyyy;
    cout<<"enter exp date(dd,mm,yyyy)-";
    cin>>expdd;cout<<"                          -";
	cin>>expmm;cout<<"                          -";
	cin>>expyyyy;
    outf<<"\t\texp-"<<expdd<<"-"<<expmm<<"-"<<expyyyy<<"\n";
    outf.close();
    detail();
   }
}
void store1::totalitems()    //shows list of total items with discription
{
	string line;
	cout<<"the items available in store are following\n";
	ifstream f;
	f.open("store.txt");
	cout<<"\t\t\t\tDEPARTMENTAL STORE RECORD\n";
	cout<<setw(x)<<setfill('*')<<"\n";
	cout<<"prod.name                 price                 mfg-date                 exp-date\n";
	cout<<setw(100)<<setfill('*')<<"\n";
	while(getline(f,line))
	{
		cout<<line<<"\n";
    }
	f.close();
}
void store1::detail()
{
	 cout<<"entered details are following\n name:"<<name;
	 cout<<"   price -"<<price;
    cout<<"    mfg date:"<<mfgdd<<"-"<<mfgmm<<"-"<<mfgyyyy;
    cout<<"  exp date:"<<expdd<<"-"<<expmm<<"-"<<expyyyy<<"\n";
}
void store1::deleteitems()   //delete a particular record
{
	ofstream fi("temp.txt");
	string search;
    int o;
    string line;
    ifstream f;
	f.open("store.txt");
	cout<<"enter product name to be deleted\n";
	cin>>search;
	if(f.is_open())
    {
	while(!f.eof())
        {
getline(f,line);		//getline fxn is used to read the data line by line
if((o= line.find(search)) != string::npos)		//string::npos means -1
{//cout<<line<<endl;
        }
        else
        {
        fi<<line<<endl;
		}
        }}
      f.close();
      fi.close();
      remove("store.txt");
	rename("temp.txt","store.txt");
		cout<<"performed sucessfully";

}
void store1::modify()   // modification in a record
{
ofstream fi("temp.txt");
	string search;
    int o;
    string line;
    ifstream f;
	f.open("store.txt");
	cout<<"enter product name to be deleted\n";
	cin>>search;
	if(f.is_open())
    {while(!f.eof())
        {
getline(f,line);
if((o= line.find(search)) != string::npos)
{
cout<<"enter product name : ";
    cin>>name;
    fi<<"name-"<<name<<"\t\t";
    cout<<"enter product price : ";
    cin>>price;
    fi<<"price-"<<price<<"\t\t";
    cout<<"enter mfg date(dd,mm,yyyy)-";
    cin>>mfgdd;cout<<"                          -";
	cin>>mfgmm;cout<<"                          -";
	cin>>mfgyyyy;
    fi<<"mfg-"<<mfgdd<<"-"<<mfgmm<<"-"<<mfgyyyy;
    cout<<"enter exp date(dd,mm,yyyy)-";
    cin>>expdd;cout<<"                          -";
	cin>>expmm;cout<<"                          -";
	cin>>expyyyy;
    fi<<"\t\texp-"<<expdd<<"-"<<expmm<<"-"<<expyyyy<<"\n";

        }
        else
        {
        fi<<line<<endl;
		}
        }}
      f.close();
      fi.close();
      remove("store.txt");
	rename("temp.txt","store.txt");
		cout<<"performed sucessfully";	
}
void store1::format()   // all records will be reset
{
   // cout<<"are you sure to format all records press y for yes otherwise press any other key\a\n";
    //cin>>comp;
   // if(comp == 'y')
    //{
   //ofstream outf("store.txt",ios::out|ios::trunc);
   //cout<<" all records are deleted\n";
    //}
    //else
    //{
      //  cout<<" all records are still as it is\n";
    //}
    cout<<"ARE YOU SURE YOU WANT TO DELETE ?"<<endl;
string aa;
cin>>aa;string b="yes";
if(aa.compare(b)==0)
{
ofstream u("store.txt",ios::trunc);
u.close();
}
}
/*void recursion(int kjh)  //recursion
{
	kjh++;
	cout<<"-";
	if(kjh==83)
	{
		cout<<"-";
	}
	else
	{
			return recursion(kjh);
	}

}*/
void store1::searchproduct()    //product is searched by name
{
    string search;
    int o;
    string line;
    ifstream f;
	f.open("store.txt");
	cout<<"enter product name to be searched\n";
	cin>>search;
	if(f.is_open())
    {while(!f.eof())
        {
getline(f,line);
if((o= line.find(search)) != string::npos)
{cout<<line<<endl;
        }
        }}
      f.close();
      cout<<"searching performed successfuly\n";
}
int main()
{
	int x,e;
	char hgf='z';
	   int t,w,h1=hgf;
    //store s1;
    store s2=h1;   /*basic to class*/
    //recursion(0);
    store1 *p;
    store1 d;
	p=&d;   //pointer to object
    welcome();
    d.welcome(&x);
    d.welcome(e);
    d+30;
        do{
        cout<<"\nenter choice";Sleep(100);
        cout<<"\n 1.add item";Sleep(100);
        cout<<"\n 2.total item";Sleep(100);
        cout<<"\n 3.show all detail of latest item";Sleep(100);
        cout<<"\n 4.edit item";Sleep(100);
        cout<<"\n 5.searchproduct";Sleep(100);
        cout<<"\n 6.format all records";Sleep(100);
        cout<<"\n 7.modify record";Sleep(100);
        cout<<"\n 8.quit\n";Sleep(100);
        //cout<<"enter your number you want to search\n";
        cin>>w;
        system("cls");
        switch(w)
          {
		    case 1: (*p).additems();break;
            case 2: (*p).totalitems();break;
            case 3: (*p).detail();break;
            case 4: (*p).deleteitems();break;
            case 5: (*p).searchproduct();break;
            case 6: (*p).format();break;
            case 7: (*p).modify();break;
            case 8:break;
        }
    }while(w!=8);
    return 0;
}