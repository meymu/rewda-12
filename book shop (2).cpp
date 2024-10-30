#include <iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
fstream filename,filename2,fileread;
class BOOK{

    private:
          int book_Id;
          char book_name[50];
          char book_category[30];
          char author_name[20];
          int book_price;
    public:

        string getbookname()
          {
              return book_name;
          }
        string getbookcategory()
            {
               return book_category;
            }
         string getbookauthor()
            {
               return author_name;
            }
          int getbookid()
          {
                   return book_Id;
          }
   void  chack_book(char bname[50],char bcategory[30],char bauthor[20],int &found)
       {

             BOOK book;
             fstream filename;
        filename.open("book.txt",ios::in|ios::app);
          if(!filename)
            {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(1);
            }
         while(filename.read((char*)&book,sizeof(BOOK))&&found==0)
          {
              if(book.getbookname()==bname)
                {
                    if(book.getbookcategory()==bcategory)
                    {
                            if(book.getbookauthor()==bauthor)
                              {
                             found=1;
                              }
                    }
               }
        }
          filename.close();
          if(found==0)
            {
           strcpy(book_name,bname);
           strcpy(book_category,bcategory);
           strcpy(author_name,bauthor);
            }

       }
       void chack_id(int &id)
          {
             BOOK book;
             fstream filename;
              bool boolchack=true;
            filename.open("book.txt",ios::in|ios::app);
          if(!filename)
            {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(1);
            }
            while(filename.read((char*)&book,sizeof(BOOK))&& boolchack==true)
                   {

                if(book.getbookid()==id)
                    {
                        cout<<"the entered id number is already exist please enter other id number"<<endl;
                        cin>>id;
                        chack_id(id);
                      boolchack=false;
                    }
                  }
                   book_Id=id ;
                   filename.close();
           }
       void set_book_details(int &found)
          {
               int id;
            char bname[50],bcategory[30],bauthor[20];
             cout<<"\nENTER DETAILS ABOUT BOOK U WANT TO ADD\n";
                    cout<<"\nEnter The Book id: ";
                    cin>>id;
                    chack_id(id);
                    cout<<"\nEnter The Book Name: ";
                    cin.ignore();
                    cin.getline(bname,50);
                    cout<<"\nEnter The Book Category: ";
                    cin.getline(bcategory,30);
                    cout<<"\nEnter The Author's Name: ";
                    cin.getline(bauthor,20);
                    cout<<"\nEnter The book price in USE dollar: ";
                    cin>>book_price;
                   chack_book(bname,bcategory,bauthor,found);

          }

           void show_book()
          {
                    cout<<"\nBook Id: "<<book_Id;
                    cout<<"\nBook Name: "<<book_name;
                    cout<<"\nBook category: "<<book_category;
                    cout<<"\nAuthor's Name: "<<author_name;
                    cout<<"\nBook price: "<<book_price;
          }
           void modify_book(int &found)
                {
              int id,choice;
           char bname[50],bcategory[30],bauthor[20];
                     cout<<"if you want to change book id enter 1/if you don't enter other number"<<endl;
                     cin>>choice ;
                     cout<<"\nEnter The New Details of book"<<endl;
                     if(choice==1)
                        {
                      cout<<"\nModify Book Id : ";
                      cin>>id;
                      chack_id(id);
                       }
                    cout<<"\nModify Book Name : ";
                    cin.ignore();
                    cin.getline(bname,50);
                    cout<<"\nModify Book Category : ";
                    cin.getline(bcategory,30);
                    cout<<"\nModify Author's Name: ";
                    cin.getline(bauthor,20);
                    cout<<"\nModify The book price: ";
                    cin>>book_price;
                   chack_book(bname,bcategory,bauthor,found);
          }


          void report()
              {
              cout<<book_Id<<setw(20)<<book_name<<setw(20)<<book_category<<setw(20)<<author_name<<setw(20)<<book_price<<endl;
              }

};
BOOK book;

void add_book()
{
         int found=0;
          system("cls");
          int more_or_main;
           filename.open("book.txt",ios::out|ios::app);
           if(!filename)
            {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(0);
            }

                    book.set_book_details(found);
                 if(found==0)
                    {
                filename.write((char*)&book,sizeof(BOOK));
                    }
                 else if(found==1)
                     {
                     cout<<"this book is already exist"<<endl;
                     }
                 filename.close();
                    cout<<"\nPress 1 to add more books.";
                    cout<<"\nPress 2 to return to main menu.\n";
                    cout<<"Enter: ";
                    cin>>more_or_main;
                    if(more_or_main==1){add_book(); }

}
void display_all_book()
{
          system("cls");
          int found=0;
          filename.open("book.txt",ios::in|ios::app);
          if(!filename)
            {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(1);
            }
              cout<<"\n\n\t\tALL Book LIST\n\n";
          cout<<"=========================================================================================================\n";
          cout<<"Book id"<<setw(20)<<"Book Name"<<setw(20)<<"Category"<<setw(20)<<"Author"<<setw(20)<<"Book price"<<endl;
          cout<<"=========================================================================================================\n";

         while(filename.read((char*)&book,sizeof(BOOK)))
          {

                    book.report();
                    found=1;
          }
          if(found==0)
             {
                 cout<<" NO DATA "<<endl;
             }
          system("pause");
          filename.close();

}
void modifybook()
{
          system("cls");
          int Id,num=0;
          int found=0;
          cout<<"\n\n\tMODIFY BOOK";
          cout<<"\n\n\tEnter The book Id you want to modify : ";
          cin>>Id;
          filename.open("book.txt",ios::in|ios::out|ios::app);
           if(!filename)
            {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(1);
            }
          while(filename.read((char*)&book,sizeof(BOOK)) && found==0)
          {
                    if(book.getbookid()==Id)
                    {
                               book.show_book();
                               cout<<"\n**************************************************************"<<endl;
                               book.modify_book(num);
                        if(num==0)
                              {
                                int pos=-1*sizeof(book);
                               filename.seekp(pos,ios::cur);
                               filename.write((char*)&book,sizeof(BOOK));
                               cout<<"\n\n\t Record Updated Successfully...";

                              }
                        else if(num==1)
                        {
                            cout<<"this book is already exist "<<endl;
                        }
                         found=1;
                    }
          }
          system("pause");
          filename.close();
          if(found==0)
                    cout<<"\n\n Record Not Found ";

}
void delete_book()
{

          int id,choice;
          int sure=0;
          int chack=0;
          int exist=0;
          bool Back=true;
          while(Back){
            system("cls");
          cout<<"\n\n\n\tDELETE BOOK";
          cout<<"\n\t\tPress 1 to DELETE ALL BOOKS";
          cout<<"\n\t\tPress 2 to DELETE SPECIFIC BOOKS";
          cout<<"\n\t\tPress 3 to EXIT";
          cout<<"\n\t\tPress 4 to BACK";
          cout<<"\n\t\tEnter...";
             cin>>choice;

    if(choice==1)
                {
           system("cls");
          cout<<"\n\n\t\t****************************************************\n";
          cout<<"\nare you sure to delete all book's data???"<<endl;
          cout<<"enter except 1 and 2 to delete the file "<<endl;
          cin>>sure;
          if(sure!=1&&sure!=2)
            {
             remove("book.txt");
                chack=1;
            }
                }
    else if(choice==2)
                {
                    system("cls");
                filename.open("book.txt",ios::in|ios::out);
            if(!filename)
                   {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(0);
                   }

                filename2.open("Temp.txt",ios::out|ios::app);
            if(!filename2)
                 {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(0);
                }
    cout<<"\n\nEnter The Book's id You Want To Delete: ";
                 cin>>id;
        fileread.open("book.txt",ios::in|ios::out);
           if(!fileread)
            {
                  cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(1);
                        }
          while(fileread.read((char*)&book,sizeof(BOOK)))
          {
                    if(book.getbookid()==id)
                    {          exist=1;
                               book.show_book();
                               }
          }
           fileread.close();
           if (exist==1){
    cout<<"\n\t\t****************************************************\n";
    cout<<"\n\n\nare you sure to delete this book data???"<<endl;
          cout<<"enter except 1 and 2 to delete the file "<<endl;
          cin>>sure;
          if(sure!=1&&sure!=2)
            {
          //fp.seekg(0,ios::beg);
          while(filename.read((char*)&book,sizeof(BOOK)))
                  {
                if(book.getbookid()!=id)
                    {
                        filename2.write((char*)&book,sizeof(BOOK));
                    }
                else {
                    chack=1;
                     }
                 }
          filename2.close();
          filename.close();
          remove("book.txt");
          rename("Temp.txt","book.txt");
            }}
                }
    else if(choice==3)
        {
        exit(1);
        }
    else if(choice==4)
        {
        Back=false;
        }

    else
        {
         cout << "\n\nINVALID CHOICE\n";
        }
    if(choice!=4){
        if(chack==1)
            {
              cout<<"\n\n\tRecord Deleted .."<<endl;
            }
        else if (sure==1||sure==2)
            {
             cout<<"\n\nRecord not deleted .."<<endl;
            }
          else if(exist==0)
            {
             cout<<"\n\nRecord not found .."<<endl;
            }
    }
        system("pause");
}
  }
  //customer choice
  void available_book(){
          system("cls");
          int found=0;
          int ID;
          int chack=0;
          filename.open("book.txt",ios::in|ios::app);
          if(!filename)
            {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(1);
            }
              cout<<"\n\n\t\tALL Book LIST\n\n";
          cout<<"=========================================================================================================\n";
          cout<<"Book id"<<setw(20)<<"Book Name"<<setw(20)<<"Category"<<setw(20)<<"Author"<<setw(20)<<"Book price"<<endl;
          cout<<"=========================================================================================================\n";

         while(filename.read((char*)&book,sizeof(BOOK)))
          {

                    book.report();
                    found=1;
          }
          filename.close();
          if(found==1){

                cout<<"\n\t\t****************************************************\n";
          cout<<"ENTER BOOK ID OF YOUR CHOICE BOOK TO BUY// ENTER 0 IF YOU ARE NOT WANT TO BUY ANY BOOK "<<endl;
          cin>>ID;
          if(ID!=0)
            {
                filename.open("book.txt",ios::in|ios::app);
             if(!filename)
                  {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(1);
                  }
          while(filename.read((char*)&book,sizeof(BOOK)))
              {
          if(book.getbookid()==ID)
              {
              cout<<"*******you purchase the book successfully*******"<<endl;
              cout<<"            *******thank you *******"<<endl;
              chack=1;
              }

              }
             filename.close();
          if(chack==0){
            cout<<"no books in this id "<<endl;
              }
             }
             if (ID==0){
                cout<<"thank you you don't purchase any book"<<endl;
             }

             }
          if(found==0)
             {
                 cout<<" NO BOOK DATA "<<endl;
             }
          system("pause");


}
void search_book()
  {   int found=0;
        int ID;
        int ch_ck;
        string chack;
        char bname[50];
        char bcategory[30];
        int choice;
        bool Back=true;
       while(Back){
       system("cls");

                cout<<"\n\t\tPress 1 to SEARCH BY BOOK NAME ";
                cout<<"\n\t\tPress 2 to SEARCH BY BOOK CATEGORY ";
                cout<<"\n\t\tPress 3 to BACK";
                cout<<"\n\t\tEnter...";
                cin>>choice;



    if(choice==1)
            {
              system("cls");
              cout<<"\n\nEnter The Book's name You Want To get: ";
                 cin.ignore();
                 cin.getline(bname,50);
                 filename.open("book.txt",ios::in|ios::app);
          if(!filename)
            {
                cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(0);
            }
            while(filename.read((char*)&book,sizeof(BOOK)))
              {
                if(book.getbookname()==bname)
                    {
                cout<<"\n\n\t\tBook LIST\n\n";
          cout<<"=========================================================================================================\n";
          cout<<"Book id"<<setw(20)<<"Book Name"<<setw(20)<<"Category"<<setw(20)<<"Author"<<setw(20)<<"Book price"<<endl;
          cout<<"=========================================================================================================\n";

                    book.report();

                    found=1;
                    }
              }
              filename.close();
           if(found==1){
          cout<<"\n****************************************************************************\n";
          cout<<"ENTER 'YES' TO BUY THIS BOOK  // 'NO' OR OTHER WORD IF YOU ARE NOT WANT TO BUY "<<endl;
          cin>>chack;
          if(chack=="yes")
          {
              cout<<"*******you purchase this book successfully*******"<<endl;
              cout<<"              *******thank you *******"<<endl;
          }
          else if(chack!="yes"){
            cout<<"thank you you don't purchase any book"<<endl;
          }}
          else if(found==0)
             {
                 cout<<" NO BOOK DATA "<<endl;
             }
           }
    else if(choice==2)
            {system("cls");
          cout<<"\n\nEnter The Book's category You Want To get: ";
                 cin.ignore();
                 cin.getline(bcategory,30);
               filename.open("book.txt",ios::in|ios::app);
            if(!filename)
            {
                cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(0);
            }
                   cout<<"\n\n\t\t Book LIST\n\n";
          cout<<"=========================================================================================================\n";
          cout<<"Book id"<<setw(20)<<"Book Name"<<setw(20)<<"Category"<<setw(20)<<"Author"<<setw(20)<<"Book price"<<endl;
          cout<<"=========================================================================================================\n";

            while(filename.read((char*)&book,sizeof(BOOK)))
              {

                if(book.getbookcategory()==bcategory)
                    {
                    book.report();
            found=1;
                    }
              }
               filename.close();
        if(found==0)
             {
                 cout<<" NO BOOK DATA IN THIS CATEGORY  "<<endl;
             }

        else if(found==1){

                cout<<"\n\t\t\t\t\t\t\t*****************************************\n";
          cout<<"ENTER BOOK ID OF YOUR CHOICE BOOK TO BUY// ENTER 0 IF YOU ARE NOT WANT TO BUY ANY BOOK "<<endl;
          cin>>ID;
          if(ID!=0)
            {
          filename.open("book.txt",ios::in|ios::app);
          if(!filename)
            {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                 exit(1);
            }
          while(filename.read((char*)&book,sizeof(BOOK)))
              {
          if(book.getbookid()==ID)
              {
              cout<<"*******you purchase the book successfully*******"<<endl;
              cout<<"            *******thank you *******"<<endl;
              ch_ck=1;
              }
              }
             filename.close();
          if(ch_ck==0){
            cout<<"no books in this id "<<endl;
              }
             }
             if(ID==0)
             {
                cout<<"thank you you don't purchase any book"<<endl;
             }
             }
             }


   else if(choice==3)
            {
                Back=false;
                found=1;
            }
    else
        {
         cout << "\n\nINVALID CHOICE\n";
        }


          system("pause");

       };
}

// customer choice
   void customer_control_panel()
{
    system("cls");
    cout<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout<<"\n\t\tPress 1 to SHOW ALL AVAILABLE BOOKS";
                cout<<"\n\t\tPress 2 to SEARCH BOOKS TO BUY";
                cout<<"\n\t\tPress 3 to Exit";
                cout<<"\n\t\tPress 4 to back";
    cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}
  void owner_control_panel()
{
    system("cls");
    cout<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout<<"\n\t\tPress 1 to ADD BOOKS";
                cout<<"\n\t\tPress 2 to SHOW ALL BOOKS";
                cout<<"\n\t\tPress 3 to MODIFY BOOKS";
                cout<<"\n\t\tPress 4 to DELETE BOOKS";
                cout<<"\n\t\tPress 5 to EXIT";
                cout<<"\n\t\tPress 6 to BACK";
    cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}
void bookShopRecord1()
  {
    int choice;
    bool Back=true;

    while (Back) {

        owner_control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
                add_book();
            break;

        case 2:
            display_all_book();
            break;

        case 3:
           modifybook();
            break;
        case 4:
            delete_book();
            break;
        case 5:
            exit(0);
            break;
        case 6:
            Back=false;
            break;
        default:
            cout << "\n\nINVALID CHOICE\n";
              break;
      }
   }
}
//customer
void bookShopRecord2()
  {
    int choice;
    bool Back=true;

   while (Back) {

        customer_control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            available_book();
            break;
        case 2:
            search_book();
            Back=true;
               break;
        case 3:
            exit(0);
            break;
        case 4:
            Back=false;
            break;
        default:
            cout << "\n\nINVALID CHOICE\n";
              break;}

 }
      }

int main(){
     BOOK book;
    int choice;
 system("color 06");

    while (1) {
system("cls");
     cout<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout << "\n\n\t\t\t\tCONTROL  PANEL";
                cout<<"\n\t\tPress 1 IF YOU ARE CUSTUMER ";
                cout<<"\n\t\tPress 2 IF YOU ARE OWNER";
                cout<<"\n\t\tPress 3 to Exit";
    cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice)
         {
             case 1:
                 bookShopRecord2();
                 break;
             case 2:
                 bookShopRecord1();
                 break;
             case 3:
                 exit(0);
                 break;
             default:
                 cout << "\n\nINVALID CHOICE\n";
              break;

        }
             }
             return 0;

}


