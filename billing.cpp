#include<iostream>
#include<fstream>

using namespace std;

class market
{
    private:
    int pcode,price,pdis;
    string pname;

    public:
    void main_menu();
    void administrator();
    void buyer();
    void add();
    void modify();
    void delete_product();
    void buy_product();
    void receipt();
};

void market::main_menu()
{
    n:
    int choice,pw;
    string email;
    cout<<"\t\t\t\t\t __________________________________ \n";
    cout<<"\t\t\t\t\t|                                  |\n";
    cout<<"\t\t\t\t\t|           SUPERMARKET            |\n";
    cout<<"\t\t\t\t\t|__________________________________|\n\n\n";
    cout<< "\t\t\t\t\t1)Administrator\n"<<endl;
    cout<< "\t\t\t\t\t2)Buyer\n"<<endl;
    cout<< "\t\t\t\t\t3)Exit\n" <<endl;
    cout<<"\t\t\t\t\tEnter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:
        cout<<"\n\n";
        log:
        cout<<"\n\t\t\t\tPlease login :"<<endl;
        cout<<"\n\t\t\t\tEnter your email id: ";
        cin>>email;
        cout<<"\n\t\t\t\tEnter your password: ";
        cin>>pw;
        
        if ((email== "maitri123@gmail.com") && (pw == 12345678) || (email== "siddesh@gmail.com") && (pw == 12345678))
        {
            administrator();
        }
        else
        {
            cout<<"\n\t\t\t\tWrong credentials !!\n"<<endl;
            goto log;
        }
        break;

        case 2:
        buyer();
        break;

        case 3:
        exit(0);
        break;

        default:
        cout<<"Please select from the given choice."<<endl;
        goto n;
        break;
    }
}
void market::administrator()
{
    a:
    int choice;
    cout<<"\t\t\t\t\t __________________________________ "<<endl;
    cout<<"\t\t\t\t\t|        Administrator menu        |"<<endl;
    cout<<"\t\t\t\t\t|__________________________________|"<<endl;
    cout<<"\t\t\t\t\t|                                  |"<<endl;
    cout<<"\t\t\t\t\t|_______ 1)Add the product.________|\n"<<endl;
    cout<<"\t\t\t\t\t|_______ 2)Modify the product._____|\n"<<endl;
    cout<<"\t\t\t\t\t|_______ 3)Delete the product._____|\n"<<endl;
    cout<<"\t\t\t\t\t|_______ 4)Back to main menu.______|\n"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        add();
        break;

        case 2:
        modify();
        break;

        case 3:
        delete_product();
        break;

        case 4:
        main_menu();
        break;

        default:
        cout<<"Invalid choice.";
        goto a;
        break;
    }
}
void market::buyer()
{
    p:
    int choice;
    cout<<"\n\n_____________________________________________________________________\n\n";
    cout<<"                                BUYER                                     "<<endl;
    cout<<"\n_____________________________________________________________________\n\n";
    cout<<"\n\t\t1)Buy Product"<<endl;
    cout<<"\n\t\t2)Go back"<<endl;
    cout<<"\n\t\t3)Exit"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        receipt();
        break;

        case 2:
        main_menu();
        break;

        case 3:
        exit(0);
        break;
        
        default:
        cout<<"Invalid choice"<<endl;
    }
    goto p; 
}
void market::add()
{
    // ofstream data;
    m:
    fstream MyFile;
    int c,tokens=0;
    float p,d;
    string n;
    cout<<"\t\t\t\t\t __________________________________ "<<endl;
    cout<<"\t\t\t\t\t                                    "<<endl;
    cout<<"\t\t\t\t\t          ADDING A PRODUCT          "<<endl;
    cout<<"\t\t\t\t\t __________________________________ "<<endl;
    cout<<"\nProduct code of the product:   "<<endl<<" ";
    cin>>pcode;
    cout<<"\nProduct name of the product:"<<endl<<" ";
    cin>>pname;
    cout<<"\nPrice of the product:"<<endl<<" ";
    cin>>price;
    cout<<"\nDiscount on product:"<<endl<<" ";
    cin>>pdis;
   
    MyFile.open("database.txt", ios::in);//reading mode
    if(!MyFile)
    {
        //if the file doesn't exist
        //will enter if there is no file which contains data that can be readed.
        MyFile.open("database.txt",ios::app|ios::out);//write mode
        MyFile<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<pdis<<"\n";
        MyFile.close();
    }
    else
    {  
        //if the file exists
        MyFile>>c>>n>>p>>d;
        while(!MyFile.eof())//end of file operation it will make sure to check every content of file by iterating it
        {
            if(c == pcode)
            {
                tokens++;
            }
            MyFile>>c>>n>>p>>d;
        }
        MyFile.close();
        if(tokens==1)
        {
            goto m;
        }
        else
        {
            MyFile.open("database.txt",ios::app|ios::out);//write mode
            MyFile<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<pdis<<"\n";
            MyFile.close();
        }
    }
    cout<<"\nRecord inserted successfully !!!\n\n";
    administrator();
}
void market::modify()
{
    //edit function
    fstream data,data1;//objects of fstream class
    int c,tokens=0;
    float p,d;
    string n;
    int pkey;
    cout<<"\n\n\nModify the record"<<endl;
    cout<<"\n\nProduct code:"<<endl;
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"No files exist"<<endl;
    }
    else{
            data1.open("database1.txt",ios::app|ios::out);//write mode
            data>>pcode>>pname>>price>>pdis;
            while(!data.eof())//end of file operation it will make sure to check every content of file by iterating it
            {
                if(pkey == pcode)
                {
                    cout<<"\n\nProduct new code :"<<endl;
                    cin>>c;
                    cout<<"\n\nName of the product:"<<endl;
                    cin>>n;
                    cout<<"\n\nPrice of the product:"<<endl;
                    cin>>p;
                    cout<<"\n\nDiscount on product:"<<endl;
                    cin>>d;    
                    data<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                    cout<<"\n\nRECORD EDITED !! :) "<<endl;
                    tokens++;
                    break;
                }
                else
                {
                    data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<pdis<<"\n";
                }
                data>>pcode>>pname>>price>>pdis;
            }
            data.close();
            data1.close();

            remove("database.txt");
            rename("database1.txt", "database.txt");
            if (tokens == 0)
            {
                cout<<"Record not found."<<endl;
            }
            
    }
    administrator();
}
void market::delete_product()
{
    fstream data,data1;//objects of fstream class
    int pkey,tokens=0;
    cout<<"Delete Product"<<endl;
    cout<<"Product code"<<endl;
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exist"<<endl;
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data1>>pcode>>pname>>price>>pdis;
        while(!data1.eof())//end of file operation it will make sure to check every content of file by iterating it
        {
            if(pcode == pkey)
            {
                cout<<"Product deleted successfully";
                tokens++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<pdis<<endl;
            }
            data>>pcode>>pname>>price>>pdis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if (tokens == 0)
        {
            cout<<"Record not found."<<endl;
        }
    }
}
void market::buy_product()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n_____________________________________________________________________\n\n";
    cout<<"ProNo\t\tName\t\tPrice"<<endl;
    cout<<"\n_____________________________________________________________________\n\n";
    //cout<<endl<<endl;
    data>>pcode>>pname>>price>>pdis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<endl;
        data>>pcode>>pname>>price>>pdis;
    }
    data.close();
}
void market::receipt()
{
    fstream data;
    int c=0;
    int arrc[100],arrq[100];
    char choice;
    float amt=0,pdis=0,total=0;

    //cout<<"\n\n\t\t\t\tRECEIPT ";
    data.open("database.txt",ios::in);
    if(!data){
    cout<<"Empty file"<<endl;
    }
    else
    {
        data.close();
        buy_product();
        cout<<"\n_____________________________________________________________\n";
        cout<<"|                                                             |\n";
        cout<<"|                Please place the order                       |\n";
        cout<<"|                                                             |\n";
        cout<<"|_____________________________________________________________|\n";

        do
        {
            m:
            cout<<"\n\nEnter Your product code:"<<endl;
            cin>>arrc[c];
            cout<<"\n\nEnter Your product quantity:"<<endl;
            cin>>arrq[c]; 
            /*for(int i =0;i<c;i++)
            {
                if (arrc[c]==arrc[i])
                {
                    cout<<"Duplicate product code. Please try again.";
                    goto m;
                }
            } 
            */  
            c++;  
            cout<<"\n\n Do you want to buy another product? if yes then enter y else n: ";
            cin>>choice;
        }while(choice == 'y');

        
        cout<<"\n\n_________________________________________RECEIPT___________________________________________\n";
        cout<<"\nProduct No\tProduct name\tProduct quantity\t  Price\t  Amount\t  Amount with discount\n";

        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>pdis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amt = price*arrq[i];
                    pdis = amt - (amt*pdis/100);
                    total = total+pdis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amt<<"\t\t"<<pdis;
                }
                data>>pcode>>pname>>price>>pdis;
                //data<<pcode<<pname<<price<<pdis;
            }
            data.close();
        }

        cout<<"\n\n _____________________________________________________________\n";
        cout<<"Total Amount : "<<total;
    }
}
int main()
{
    market m;
    m.main_menu();
    return 0;
}