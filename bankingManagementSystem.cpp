/*
NAME: MOUNBAGNA ABDELLA ABASSE
STUDENT ID: 200041261
NATIONALITY: CAMEROONIAN
DEPARTMENT: CSE
PROGRAM: BscEngg
Project start: 16/06/2022
Project end: 19/06/2022
*/

#include<iostream> //use for input & output i.e cin and cout
#include<cstring> //
#include<fstream> //opening and closing file, read and write from file
#include<iomanip> //used for setting the with i.e setw()
#include<conio.h> //getch() is use to wait for a key press from the user
#include<stdlib.h> //syt=stem("cls") is use for clearing the screen
#include<stdio.h> //use for clearing the buffer i.e fflush(stdin)
using namespace std;


class bankRecord
{
    int passeword;
    long long accountNumber;
    char name[100];
    double balance;
public:
    void setPasseword(int p){passeword=p;}
    void setName(char *n){strcpy(name,n); }
    void setAccountNumber(long long an){accountNumber=an; }
    void setBalance(double b){balance=b;}
    int getPasseword(){return passeword;}
    char *getName(){return name;}
    long long getAccountNumber(){return accountNumber;}
    double getBalance(){return balance;}
    void showInfo()
    {
        cout<< "              ->ACCOUNT NUMBER: "<<accountNumber<<endl;
        cout<< "              ->ACCOUNT NAME: "<<name<<endl;
        cout<< "              ->BALANCE: $"<<balance<<endl<<endl;
    }
    void showBalance(){cout<< "->BALANCE: $"<<balance; };
    void setWBalance(double nb){balance=balance-nb;}
    void setDBalance(double nb){balance=balance+nb;}
};

void printStars(int);
void printSpace(int);
void addAccount();
void showAllAccounts();
void searchAccount();
void deleteAccount();
void deleteAllAccounts();
void updateAccount();
void balanceQuery();
void withdrawal();
void deposit();
void changePassword();

bankRecord b;
fstream file;
int main()
{
    int choice,p;

    printStars(10);
    cout<< "WELCOME TO MY BANK MANAGEMENT SYSTEM";
    printStars(10);
    cout<< "\n\n";
    printSpace(5);
    cout<< "1.MANAGER"<<endl;
    printSpace(5);
    cout<< "2.CUSTOMER"<<endl<<endl;
    cout<< "choice an option:"<<endl;
    cin>>p;
    if(p==1)
    {
        char pw[20];
        fflush(stdin);
        cout<< "Enter your password: ";
        cin.get(pw,20);
        fflush(stdin);
        if(strcmp(pw,"manager")==0){
        while(1){
     system("cls");
    printStars(10);
    cout<< "WELCOME MANAGER";
    printStars(10);
cout<< "\n\n";
cout<< "select an option below"<<endl;
    printSpace(5);
    cout<< "1.Add an account"<<endl;
    printSpace(5);
    cout<< "2.Show the list of accounts"<<endl;
    printSpace(5);
    cout<< "3.Search an account"<<endl;
    printSpace(5);
    cout<< "4.Delete an account"<<endl;
    printSpace(5);
    cout<< "5.Delete all accounts"<<endl;
    printSpace(5);
    cout<< "6.Update or modify an account"<<endl;
    printSpace(5);
    cout<< "7.Exit from the application ???"<<endl<<endl;
    cout<< "make a choice: ";
    cin>>choice;
    cout<< "\n\n";
    switch(choice){
case 1:
    addAccount();
    cout<< "\n\nNew account added successfully..."<<endl<<endl;
    cout<< "Press any key to get to the main menu"<<endl;
    getch();
    break;
case 2:
    showAllAccounts();
    cout<< "\n";
    cout<< "Press any key to get to the main menu"<<endl;
    getch();
    break;
case 3:
    searchAccount();
    cout<< "\n";
    cout<< "Press any key to get to the main menu"<<endl;
    getch();
    break;
case 4:
    deleteAccount();
    cout<< "Account deleted successfully..."<<endl;
    cout<< "\n";
    cout<< "Press any key to get back to the main menu"<<endl;
    getch();
    break;
case 5:
    deleteAllAccounts();
    cout<< "All accounts deleted successfully..."<<endl;
    cout<< "\n";
    cout<< "Press any key to get back to the main menu"<<endl;
    getch();
    break;
case 6:
    updateAccount();
    cout<< "\n";
    cout<< "Press any key to get back to the main menu"<<endl;
    getch();
    break;
case 7:
    printSpace(5);
    printStars(10);
    cout<< "Thanks for using my application, see you later";
    printStars(10);
    exit(0);
    break;
default:
    cout<< "You have pressed the wrong key, try again";
    getch();
    }}}
    else
        {
    cout<< "Oops, wrong password";
    getch();
        }
    }
   else if(p==2)
    {
        while(1){
        system("cls");
    printStars(10);
    cout<< "WELCOME DEAR CUSTOMER";
    printStars(10);
cout<< "\n\n";
cout<< "select an option below"<<endl;
    printSpace(5);
    cout<< "1.Balance query"<<endl;
    printSpace(5);
    cout<< "2.Change password"<<endl;
    printSpace(5);
    cout<< "3.Withdrawal"<<endl;
    printSpace(5);
    cout<< "4.Deposit"<<endl;
    printSpace(5);
    cout<< "5.Exit from the application ???"<<endl<<endl;
    cout<< "make a choice: ";
    cin>>choice;
    cout<< "\n\n";
    switch(choice){
case 1:
    balanceQuery();
    cout<< "Press any key to get back to the main menu"<<endl;
    getch();
    break;
case 2:
    changePassword();
    cout<< "Password changed successfully"<<endl;
    cout<< "Press any key to get back to the main menu"<<endl;
    getch();
    break;
case 3:
    withdrawal();
    cout<< "Press any key to get back to the main menu"<<endl;
    getch();
    break;
case 4:
    deposit();
    cout<< "Press any key to get back to the main menu"<<endl;
    getch();
    break;
case 5:
    printSpace(5);
    printStars(10);
    cout<< "Thanks for using my application, see you later";
    printStars(10);
    exit(0);
    break;
default:
    cout<< "You have pressed the wrong key, try again";
    getch();
    }}}
return 0;
}

void printSpace(int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<< " ";
}
void printStars(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<< "*";
    }
}
void addAccount()
{
    char ch='y';
    long long a;
    char n[100];
    int p;
    double ba;
    file.open("myBankRecord.txt",ios::app);
    while(ch=='y'||ch=='Y')
    {
        //putting records to the object
        fflush(stdin);
        cout<< "Enter a password: "<<endl;
        cin>>p;
        b.setPasseword(p);
        b.getPasseword();
        fflush(stdin);
        cout<< "Enter your account number: "<<endl;
        cin>>a;
        b.setAccountNumber(a);
        b.getAccountNumber();
        fflush(stdin);
        cout<< "Enter your account's name: "<<endl;
        cin.get(n,100);
        b.setName(n);
        b.getName();
        fflush(stdin);
        cout<< "Enter your balance: "<<endl;
        cin>>ba;
        b.setBalance(ba);
        b.getBalance();
        fflush(stdin);
        file.write((char*)&b,sizeof(b)); //write object into the file
        cout<< "Do you want to enter another record? ";
        cin>>ch;
    }
    file.close();
}
void showAllAccounts()
{
    file.open("myBankRecord.txt",ios::in);

    if(!file)
    {
        cout<< "Oops error occured while opening the file!!!"<<endl;
        exit(0);
    }
    else
    {

        file.read((char*)&b,sizeof(b)); //read records from file into object
        while(!file.eof())
        {
            //records displayed to object(b) so that it can be displayed on the screen
            b.showInfo();
            file.read((char*)&b,sizeof(b));
        }
    }
    file.close();
}
void searchAccount()
{
    int flag=0;
    double n;
    file.open("myBankRecord.txt",ios::in);
    if(!file)
    {
        cout<< "Oops error occured while opening the file!!!"<<endl;
        exit(0);
    }
    else
    {
        cout<< "\n";
        cout<<"Enter the account number to be search: "<<endl;
        cin>>n;
        file.read((char*)&b,sizeof(b));
        while(!file.eof())
        {
            if(n==b.getAccountNumber())
            {
                flag=1;
                b.showInfo();
                break;
            }
            file.read((char*)&b,sizeof(b));
        }
        if(flag==0)
        {
            cout<< "Account not found!!!"<<endl;
        }
    }
    file.close();
}
void deleteAccount()
{
    double n;
    cout<< "Enter the account number to be deleted: ";
    cin>>n;
    ofstream file2;

    file2.open("tempFile.txt",ios::out);
     file.open("myBankRecord.txt",ios::in);
    if(!file)
    {
        cout<< "Error occured while opening the file!!!";
        exit(0);
    }
    else
    {
        file.read((char*)&b,sizeof(b)); //reading records of file to object so that it can be copied to the new file
        while(!file.eof())
        {
            if(n!=b.getAccountNumber())
            {
                file2.write((char*)&b,sizeof(b));
            }
            file.read((char*)&b,sizeof(b));
        }

    }

    file2.close();
    file.close();
    remove("myBankRecord.txt");
    rename("tempfile.txt","myBankRecord.txt");
}
void deleteAllAccounts()
{
    ofstream file3;
    file.open("myBankRecord.txt",ios::in);
    file3.open("myBankRecord.txt",ios::out);
    if(!file)
    {
        cout<< "Error occured while opening the file";
        exit(0);
    }
    else
    {
        file.read((char*)&b,sizeof(b));
        while(!file.eof())
        {
            file3.write((char*)&b,sizeof(b));
        }
        file.read((char*)&b,sizeof(b));
    }
    file.close();
    file3.close();
    remove("file3.txt");
}
void updateAccount()
{
    double n,ba;
    char nn[20];
    long long na;
    cout<< "Enter the account number to be updated: ";
    cin>>n;
    file.open("myBankRecord.txt",ios::in|ios::out);
    if(n!=b.getAccountNumber())
            {
                cout<< "\nSorry, but the account number that you just entered is not found"<<endl;
                cout<< "Press any key to go to the main menu";
                getch();
            }

    if(!file)
    {
        cout<< "Error occured while opening the file!!!"<<endl;
        exit(0);
    }
        while(file.read((char*)&b,sizeof(b))) //This is another way to check END OF FILE(eof)
        {
            if(b.getAccountNumber()==n)
            {
                cout<< "\nEnter new records:"<<endl;
                cout<< "Enter new account number: ";
                cin>>na;
                b.setAccountNumber(na);
                b.getAccountNumber();
                fflush(stdin);
                cout<< "\nEnter new account name: "<<endl;
                cin.get(nn,20);
                b.setName(nn);
                b.getName();
                fflush(stdin);
                cout<< "\nEnter new balance: "<<endl;
                cin>>ba;
                b.setBalance(ba);
                b.getBalance();
                //move put pointer(seekp) to the current position-1
                int pos=sizeof(b);
                file.seekp(-pos,ios::cur);
                file.write((char*)&b,sizeof(b));//write object to file
                cout<< "Account updated sucessfully...";
            }
    }
    file.close();
}
void balanceQuery()
{
    int n,flag=0;
    file.open("myBankRecord.txt",ios::in);
    if(!file)
    {
        cout<< "Oops error occured while opening the file!!!"<<endl;
        exit(0);
    }
    else
    {
        cout<< "\n";
        cout<<"Enter your password: "<<endl;
        cin>>n;
        file.read((char*)&b,sizeof(b));
        while(!file.eof())
        {
            if(n==b.getPasseword())
            {
                flag=1;
                printSpace(5);
                cout<< "\n";
                b.showBalance();
                cout<< "\n";
                break;
            }
            file.read((char*)&b,sizeof(b));
        }
            if(flag==0)
            {
                cout<< "\nWrong password,try again!!!"<<endl;
            }
    }
    file.close();
}
void withdrawal()
{
    double ba;
    int pw;
    cout<< "Enter your password: ";
    cin>>pw;
    file.open("myBankRecord.txt",ios::in|ios::out);
    if(!file)
    {
        cout<< "Error occured while opening the file!!!"<<endl;
        exit(0);
    }
        while(file.read((char*)&b,sizeof(b))) //This is another way to check END OF FILE(eof)
        {
            if(b.getPasseword()==pw)
            {
                cout<< "Enter the amount to be withdrawn: ";
                cin>>ba;
                b.setWBalance(ba);
                b.getBalance();
                fflush(stdin);
                //move put pointer(seekp) to the current position-1
                int pos=sizeof(b);
                file.seekp(-pos,ios::cur);
                file.write((char*)&b,sizeof(b));//write object to file
                cout<< '\a';
                cout<< "\n";
                printStars(5);
                cout<<" Dear customer, BENDO BOSS Bank cash transaction of $"<<ba<<" debited from "<<b.getAccountNumber()<< " sucessfully";
                printStars(5);
                cout<< "\nThanks for using my banking system..."<<endl;
            }
    }
    file.close();
}
void deposit()
{
    double ba;
    int pw;
    cout<< "Enter your password: ";
    cin>>pw;
    file.open("myBankRecord.txt",ios::in|ios::out);
    if(!file)
    {
        cout<< "Error occured while opening the file!!!"<<endl;
        exit(0);
    }
        while(file.read((char*)&b,sizeof(b))) //This is another way to check END OF FILE(eof)
        {
            if(b.getPasseword()==pw)
            {
                cout<< "Enter the amount to be deposited: ";
                cin>>ba;
                b.setDBalance(ba);
                b.getBalance();
                fflush(stdin);
                //move put pointer(seekp) to the current position-1
                int pos=sizeof(b);
                file.seekp(-pos,ios::cur);
                file.write((char*)&b,sizeof(b));//write object to file
                cout<< '\a';
                cout<< "\n";
                printStars(5);
                cout<<" Dear customer, an amount of $"<<ba<<" has been credited to "<<b.getAccountNumber()<< " sucessfully";
                printStars(5);
                cout<< "\nThanks for using my banking system..."<<endl;
            }
    }
    file.close();
}
void changePassword()
{
    int op,np;
    cout<< "Enter old password: ";
    cin>>op;
    file.open("myBankRecord.txt",ios::in|ios::out);
    if(op!=b.getPasseword())
            {
                cout<< "\nSorry, but the account number that you just entered is not found"<<endl;
                cout<< "Press any key to go to the main menu";
                getch();
            }

    if(!file)
    {
        cout<< "Error occured while opening the file!!!"<<endl;
        exit(0);
    }
        while(file.read((char*)&b,sizeof(b))) //This is another way to check END OF FILE(eof)
        {
            if(b.getPasseword()==op)
            {
                fflush(stdin);
                cout<< "Enter new password: ";
                cin>>np;
                b.setPasseword(np);
                b.getPasseword();
                fflush(stdin);
                //move put pointer(seekp) to the current position-1
                int pos=sizeof(b);
                file.seekp(-pos,ios::cur);
                file.write((char*)&b,sizeof(b));//write object to file
            }
    }
    file.close();
}
