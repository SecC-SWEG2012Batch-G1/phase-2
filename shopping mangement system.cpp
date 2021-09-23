

/****************************************************************************************************************************************
****************************************  SHOPPING MANGMENT SYSTEM*************************************************************************
*******************************************************************************************************************************************
*/
#include<fstream>
#include<string>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;
int choice;
int option;
int num,i=0,quant;//quant used to denote the quantity entered  by customer
int j=0;//i and j for an array
char press;

template<class t1,class t2>
struct address{
	t1 city;
	t2 housenum;
	};

template<class t1,class t2,class t3>
struct Administrator
{
    t1 fullName,email,password1,password2;
	t2 phoneNo,admin_id;
    t3 gender;
    address<t1,t2>add;

};

template<class t1,class t2>
struct Cust{
	t1 name;
	t2 phone_number;
	address<t1,t2>add;
};

template<class t1,class t2,class t4>
struct product{
	t1 product_name, product_type;;
	t2 quantity, product_num;
	t4 price, total_price, difference, cost, discount_price,discount;// discout is by percent
	};
fstream fp;
Cust<string,int>cust;
product<string,int,float>produc;
Administrator<string,int ,char>admin_1;

void show_product()
	{
	cout<<"Product ID "<<setw(23)<<"Product Name"<<setw(23)<<"Quantity"<<setw(23)<<"Price"<<setw(23)<<"Discount\n";
	cout<<produc.product_num<<setw(28)<<produc.product_name<<setw(26)<<produc.price<<setw(23)<<produc.quantity<<setw(23)<<produc.discount<<endl;

	}

template<class t2>
t2 getProduct()
	{
		return produc.product_num;
	}


template<class t3>
t3 getPrice()
	{
		return produc.price;
	}

template<class t3>
t3 getQuantity()
	{
		return produc.quantity;
	}

template<class t1>
 t1 getName()
	{
		return produc.product_name;
	}
template<class t3>
t3 getDiscount()
	{
		return produc.discount;
	}

char getchoice();
 void customer_info();
 void Registration();
 void login();
 void admin_menu();
 void create_product();
 void show_all_product();
 void display_record(int num);
 void edit_product();
 void delete_product();
 void product_menu();
 void place_order();




int main()
{

    product<string,int,float>cloth_list[100];
	system("cls");
	char co= getchoice();


	switch(co)
		{
			case 'A':
			case 'a':
			{
			    system("cls");
					customer_info();
					place_order();
					getchar();
					break;
			}

			case 'B':
			case 'b':
			Registration();
					break;

			case 'C':
			case 'c':
					cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
					cout<<"\n\tGood Bye!";
					cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
					exit(0);

			default :cout<<"Invalid Input...\n";
		}


}


char getchoice()
 {
  char co;
  system("cls");
    cout<<"###########***************  WELCOME TO SHOPPING MANGMENT SYSTEM *********************########"<<endl;
  	cout<<"\t\t\t\t*\t\t*\n";
  	cout<<"\t\t\t\t**\t\t**\n";
   	cout<<"\t\t\t\t***\t\t***\n";
   	cout<<"\t\t\t\t****\t\t****\n";
   	cout<<"\t\t\t\t*****\t\t*****\n";
    cout<<"\t\t\t\t******\t\t******\t\t\t\t";cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
   	cout<<"\t\t\t\t*******\t\t*******\t\t\t\t";	cout<<"\tA. CUSTOMER\n";
   	cout<<"\t\t\t\t********\t********\t\t\t\t";	cout<<"B. ADMINISTRATOR\n";
   	cout<<"\t\t\t\t*******\t\t*******\t\t\t\t";	cout<<"\tC. EXIT\n";
   	cout<<"\t\t\t\t******\t\t******\t\t\t\t";cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
   	cout<<"\t\t\t\t*****\t\t*****\n";
   	cout<<"\t\t\t\t****\t\t****\n";
   	cout<<"\t\t\t\t***\t\t***\n";
   	cout<<"\t\t\t\t**\t\t**\n";
   	cout<<"\t\t\t\t*\t\t*\n";
	int option;
    cout<<"Enter your choice: "<<endl;
    cin>>co;
   return co;
	}
 void customer_info(){
 	cout<<"##############################################################################################\n";
	cout<<"######################## WELCOME TO SHOPPING MANAGMENT SYSTEM ###############################################\n";
	cout<<"Enter your Name: ";
	cin.ignore();
	getline(cin,cust.name);
	cout<<"Enter your Phone Number: ";
	cin>>cust.phone_number;
	cout<<"Enter your city that you live in : ";
	cin>>cust.add.city;
	cout<<"Enter your House Number: ";
	cin>>cust.add.housenum;
	cout<<"You can buy  ";
	show_all_product();
}

void Registration()
{
    cout<<"Please enter carefully admin's ID number which is \"12345678\": "<<endl;
    int admin_ID=12345678;
    cin>>admin_1.admin_id;
    while (admin_ID != admin_1.admin_id)
    {
        int count=0;
        cout<<"Yu are not approved to use this service!!! \nplease try again"<<endl;
        cin>> admin_1.admin_id;
        if( count==2)
        cout<<"failed";
        exit(0);
        count++;
    }
    fp.open("Administrator.dat",ios::out|ios::binary|ios::app);
    fp.write((char*)&admin_1,sizeof(admin_1));

     cout<<"Enter your full Name:"<<endl;
   cin>>admin_1.fullName;
     cout<<"Enter your city You live in :"<<endl;
   cin>>admin_1.add.city;
    cout<<"Enter your email:"<<endl;
    cin>>admin_1.email;
     cout<<"Enter your phone number:"<<endl;
    cin>>admin_1.phoneNo;
    cout<<"Enter your password:"<<endl;
    cin>>admin_1.password1;
    cout<<"Re-enter your password:"<<endl;
  cin>>admin_1.password2;
    if(admin_1.password1 != admin_1.password2)
    {
        cout<<"wrong password!!\nplease write your password again"<<endl;
        cin>>admin_1.password2;
    }
    cout<<"you have successfully Registered...."<<endl;
    cout<<"what do you want to do\n1.Login\n2.exit"<<endl;
    b:cin>>choice;
    switch(choice)
    {
        case 1:
        login();break;
        case 2:
        exit(1);
         default:
        {cout<<"enter correct value"<<endl;
        goto b;}
    }
    fp.close();

 }

void login()
{
    fp.open("Administrator.dat",ios::in|ios::binary);
    fp.read((char*)&admin_1,sizeof(admin_1));
    string password,fullname1;
    cout<<"enter your username:"<<endl;//user name refer to fullname
    cin>>fullname1;
    cout<<"password: "<<endl;
    cin>>password;
    while(fullname1 != admin_1.fullName)
    {
        int count=0;
        cout<<"wrong comcination!!\nplease enter your full Name"<<endl;
        cin>>fullname1;

        if( count==2)
        {cout<<"failed";
        exit(0);}
         count++;
    }
    while(password != admin_1.password2)
    {
        int count=0;
        cout<<"wrong password!!\nplease try again"<<endl;
        cin>>password;

         if( count==2)
        {cout<<"1.forgot password\n2.retry";
        int n;
        cin>>n;}

        if( count==3)
        {cout<<"failed";
        exit;}
        count++;

    }
    cout<<"you have successfully signed up...."<<endl;
    cout<<"what would you like to do"<<endl;
    admin_menu();
}

void admin_menu()
{
	int option;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\tPress 1 to CREATE PRODUCT";
	cout<<"\n\tPress 2 to DISPLAY ALL PRODUCTS";
	cout<<"\n\tPress 3 to DISPLAY SPECIFIC PRODUCTS";
	cout<<"\n\tPress 4 to MODIFY PRODUCT";
	cout<<"\n\tPress 5 to DELETE PRODUCT";
	cout<<"\n\tPress 6 to GO BACK TO MAIN MENU";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

	cout<<"\n\n\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1:
		{system("cls");
				create_product();
				admin_menu();
				break;}

		case 2:
		{show_all_product();
		        admin_menu();
				break;}

		case 3:
				{int num;
				system("cls");
				cout<<"\n\n\tPlease Enter The Product Number: ";
				cin>>num;
				display_record(num);
				break;}

		case 4: edit_product();
		break;

		case 5: delete_product();
		        break;

		case 6: system("cls");
				break;

		default:admin_menu();
	}
}


void create_product()
{
	fp.open("database.dat",ios::out|ios::app);
	fp.write((char*)&produc,sizeof(produc));


		cout<<endl<<"Please Enter The Product Number: ";
		cin>>produc.product_num;
		fp>>produc.product_num;
		cout<<endl<<"Please Enter The Name of The Product: ";
		cin>>produc.product_name;
		cin.ignore();
	    getline(fp, produc.product_name);
		cout<<endl<<"Please Enter The Price of The Product: ";
		cin>>produc.price;
		fp>>produc.price;
		cout<<"The quantity of your product :";
		cin>>produc.quantity;
	   	fp>>produc.quantity;
		cout<<endl<<"Please Enter The Discount (%): ";
		cin>>produc.discount;
		fp>>produc.discount;
	fp.close();
	cout<<endl<<endl<<"The Product Has Been Sucessfully Created...";
	getchar();
	system("cls");
}


void show_all_product()
{
	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<endl<<"\t\tRECORDS.";
	cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	fp.open("database.dat",ios::in);
	while(fp.read((char*)&produc,sizeof(produc)))
	{
		show_product();
		cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl;
		getchar();
	}
	fp.close();
}


void display_record(int num)
{
	bool found=false;
	fp.open("database.dat",ios::in);
	while(fp.read((char*)&produc,sizeof(produc)))
	{
		if(getProduct<int>()==num)
		{
			system("cls");
			show_product();
			found=true;
		}
	}

	fp.close();
	if(found == true)
	cout<<"\n\nNo record found";
	getchar();
}



void edit_product()
{
	int num;
	bool found=false;
	system("cls");
	cout<<endl<<endl<<"\tPlease Enter The Product number: ";
	cin>>num;

	fp.open("database.dat",ios::in|ios::out);
	while(fp.read((char*)&produc,sizeof(produc)) && found==false)
	{
		if(getProduct<int>()==num)
		{
			show_product();
			cout<<"\nPlease Enter The New Details of Product: "<<endl;
		    create_product();
			int pos=1*sizeof(produc);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&produc,sizeof(produc));
			cout<<endl<<endl<<"\t Record Successfully Updated...";
			found=true;
		}
	}
	fp.close();
	if(found==false)
		cout<<endl<<endl<<"Record Not Found...";
	getchar();
}


void delete_product()
{
	int num;
	system("cls");
	cout<<endl<<endl<<"Please Enter The product number: ";
	cin>>num;
	fp.open("database.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&produc,sizeof(produc)))
	{
		if(getProduct<int>()!=num)
		{
			fp2.write((char*)&produc,sizeof(produc));
		}
	}
	fp2.close();
	fp.close();
	remove("database.dat");
	rename("Temp.dat","database.dat");
	cout<<endl<<endl<<"\tRecord Deleted...";
	getchar();
}

template<class t1,class t2,class t3>
void product_menu()
{
	fp.open("database.dat",ios::out);


while(fp.read((char*)&produc,sizeof(product< t1,t2,t3>)))
	{
		cout<<getProduct<int>()<<"\t\t"<<getName<string>()<<"\t\t"<<getPrice<float>()<<"\t\t"<<getQuantity<float>()<<"\t\t"<<getDiscount<float>()<<endl;
	}
	fp.close();


	fp.open("database.dat",ios::in);
	cout<<endl<<endl<<"\t\tProduct MENU\n\n";
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"P.NO.\t\tNAME\t\tPRICE\t\tQUANTITY\t\tDISCOUNT\n";
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	while(fp.read((char*)&produc,sizeof(product< t1,t2,t3>)))
	{
		cout<<getProduct<int>()<<"\t\t"<<getName<string>()<<"\t\t"<<getPrice<float>()<<"\t\t"<<getQuantity<float>()<<"\t\t"<<getDiscount<float>()<<endl;
	}
	fp.close();
}



void place_order()
{
	int order_arr[50],quan[50],c=0;
	float amt,damt,total=0;
	char ch='Y';
 product_menu<string,int,float>();
	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n PLACE YOUR ORDER";
	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	do{
		cout<<"\n\nEnter The Product number: ";
		cin>>order_arr[c];
		if(order_arr[c]!=produc.product_num)
		{
		    cout<<"The object is not found..."<<endl;
		    exit(0);
		}
		cout<<"\nQuantity: ";
		cin>>quan[c];
		c++;
		cout<<"\nDo You Want To Order Another Product ? (y/n)";
		cin>>ch;
		}while(ch=='y' ||ch=='Y');
	cout<<"\n\nThank You...";
	getchar();
	system("cls");
	cout<<"\n\n********************************INVOICE************************\n";
	cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
for(int x=0;x<=c;x++)
	{
		fp.open("database.dat",ios::in);
		fp.read((char*)&produc,sizeof(produc));
		while(!fp.eof())
		{
			if(getProduct<int>()==order_arr[x])
			{
				amt=getPrice<float>()*quan[x];
				damt=amt-(amt*getDiscount<float>()/100);
				cout<<"\n"<<order_arr[x]<<"\t"<<getName<string>()<<"\t"<<quan[x]<<"\t\t"<<getPrice<float>()<<"\t"<<amt<<"\t\t"<<damt;
				total+=damt;
			}
			fp.read((char*)&produc,sizeof(produc));
		}
		fp.close();
	}
	cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
	getchar();
}








