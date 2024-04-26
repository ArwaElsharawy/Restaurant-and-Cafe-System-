#include <iostream>
#include <fstream>
#include <string>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

using namespace std;
#define size 100000
#define items 150
int o = 0, id, edit, de, t = 0;    //t:total el deals  

void welcome();
void signin(fstream& account);
void create(fstream& account);
void view_menu();

struct resit {
    string name;
    float  price;
    int id;

}list[items];

struct customers {
    int id;
    string name;
    string orders;
    int phone;
    string address;
    string email;
    string pass;

}cust[size];

struct food {
    string  name;
    int id;
    string category;
    float price;
}arr[items];

void view_menu() {
    int press, order, deals, sum = 0;
    char ch,close,show;  //ch:continue,
    cout << "----------------------------- Menu --------------------------------\n";
start:
    arr[0] = { "(1)Milk Tea  ",20201,"drinks",10 };
    arr[1] = { "(2)Lemonade",20202,"drinks",12 };
    arr[2] = { "(3)orange juice",20203,"drinks",15 };
    arr[3] = { "(4)Mango Juice",20204,"drinks",18 };
    arr[4] = { "(5)Ice Coffee" ,20205,"drinks",20 };

    arr[5] = { "(6)Pizza  ",20206,"main dish",50 };
    arr[6] = { "(7)Burger",20207,"main dish",50 };
    arr[7] = { "(8)Pasta",20208,"main dish",45 };
    arr[8] = { "(9)Sea Food",20209,"main dish",80 };
    arr[9] = { "(10)Molo5ia" ,20210,"main dish",30 };

    arr[10] = { "(11)CheeseCake ",20211,"Dessert",25 };
    arr[11] = { "(12)Crepe",20212,"Dessert",20 };
    arr[12] = { "(13)Waffle",20213,"Dessert",20 };
    arr[13] = { "(14)Cookies",20214,"Dessert",15 };
    arr[14] = { "(15)Konafa" ,20215,"Dessert",25 };

    cout << "(1) Drinks \n";
    cout << "(2) Main Dish \n";
    cout << "(3) Desserts \n";
    cout << "(4) Exit \n";
    cin >> press;
    
    switch (press) {
    case 1:
        cout << "\n Name \t\t\t\t Price \t\t\t Id \n";
        cout << "--------------------------------------------------------------------\n";
        for (int i = 0; i < 5; i++) {
            cout << arr[i].name << "\t \t \t  " << arr[i].price << "$ \t\t\t" << arr[i].id << endl;
        }
        cout << "\nIf You Want To See The Photos Press (S) : \t";
        cin >> show;
        if (show == 's' || show == 'S') {

        initwindow(520, 400);

        readimagefile("milkTea.jpg", 10, 10, 150, 150);     
        readimagefile("lemonade.jpg", 170, 10, 320, 150);
        readimagefile("Orange-Juice.jpeg", 340, 10, 500, 150);
        readimagefile("mango.jpg", 80, 180,250, 320);
        readimagefile("coffee.jpg", 290, 180, 460, 320);
        cout << "Press (C) To Close The Window : \t";
        cin >> close;
                
        closegraph();
        
        }

        cout << "--------------------------------------------------------------------\n";
        cout << "Please select the order number :\t";
        cin >> order;
        cout << "\nPlease enter the number of deals :\t";
        cin >> deals;
        t += deals;      //total el deals

        
        for (int i = 1; i <= deals; ++i) {  

            list[o].name = arr[order - 1].name;
            list[o].price = arr[order - 1].price;
            list[o].id = arr[order - 1].id;
            o++;
        }
        sum += arr[order - 1].price * deals;
        
        cout << "\n\t\t\tTotal Price :   " << sum << "$" << endl;
        cout << "\nDo you want to continue? \t";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
            goto start;


        else
        cout << "\n\n\t\t\tYour Order Is" << endl;
        for (int i = 0; i < o; ++i) {
            cout << list[i].name << "  ";
            cout << list[i].price << "$" << "  ";
            cout << list[i].id << endl<<endl;

        }
        
        cout << "\t\t Total Price :  \t" << sum << "$" << endl;

        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
        cout << "(1) Add To Your Order\n(2) Delete\n(3) Receipt\n\t";
        cin >> edit;

        

        if (edit == 1) {   
            cout << endl;
            goto start;
            cout << "\nPlease Select The Order Number :\t";
            cin >> order;
            cout << "\nPlease Enter The Number Of Deals :\t";
            cin >> deals;
            for (int i = 1; i <= deals; ++i) {

                list[o].name = arr[order - 1].name;
                list[o].price = arr[order - 1].price;
                list[o].id = arr[order - 1].id;
                o++;
            }
            sum += arr[order - 1].price * deals;
            cout << "__________\n";
            cout << "\t\tThe Price After Editing Is\t" << sum << "$" << endl;


        }

        


        else if (edit == 2) {

            

            int s_id = 0, n_delete;
            cout << "Enter ID :   ";
            cin >> s_id;
            cout << "Enter The Number Of Element Do You Want To Delete :   ";
            cin >> n_delete; cout << endl;
            int z = 0;
            cout << "\t\t\tYOUR ORDER AFTER EDIT IS\n\n";
            for (int j = 0; j < t; j++) {
                if (list[j].id == s_id && z < n_delete) {

                    sum -= list[j].price;
                    z++;

                }


                else {
                    cout << list[j].name << "\t" << list[j].price << "$" << "\t" << list[j].id << endl;
                }

            }
            cout << "\n\t\t\t\t\t Total Price " << sum << "$" << endl;
            break;
        }

        else if (edit == 3) 
        {
            cout << "\t\t\t\t\tRECEIPT\t\t" << endl;
            for (int i = 0; i < o; ++i) {
                cout << list[i].name << "  ";
                cout << list[i].price << "$" << "\t" << list[i].id << endl;

            }
            cout << "\n\t\t Total Price : \t" << sum << "$" << endl;
            break;
        }
        break;

        //...............................................................

    case 2: 
        cout << "\n Name \t\t\t\t Price \t\t\t Id \n";
        cout << "--------------------------------------------------------------------\n";
        for (int i = 5; i < 10; i++) {
            cout << arr[i].name << "\t \t \t  " << arr[i].price << "$ \t\t\t" << arr[i].id << endl;
        }
        cout << "\nIf you want to see the photos press S : \t";
        cin >> show;
        if (show == 's' || show == 'S') {
        initwindow(520, 400);

        readimagefile("pizza.jpg", 10, 10, 150, 150);     
        readimagefile("Burger.jpg", 170, 10, 320, 150);
        readimagefile("pasta.jpg", 340, 10, 500, 150);
        readimagefile("seaFood.jpg", 80, 180, 250, 320);
        readimagefile("Molokhia.jpg", 290, 180, 460, 320);
        cout << "Press c to close the window : \t";
        cin >> close;
       
        
        closegraph();
        }
        
        cout << "--------------------------------------------------------------------\n";
        cout << "Please select the order number :\t";
        cin >> order;
        cout << "\nPlease enter the number of deals :\t";
        cin >> deals;
        t += deals;
        for (int i = 1; i <= deals; ++i) {
            list[o].name = arr[order - 1].name;
            list[o].price = arr[order - 1].price;
            list[o].id = arr[order - 1].id;
            o++;
        }
        sum += arr[order - 1].price * deals;
        cout << "\n\t\t\tTotal Price :   " << sum << "$" << endl;
        cout << "\nDo you want to continue? \t\n";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
            goto start;


        else
            cout << "\t\t\tYour Order Is" << endl;
        for (int i = 0; i < o; ++i) {
            cout << list[i].name << "  ";
            cout << list[i].price << "$" << "  ";
            cout << list[i].id << endl << endl;

        }
        cout << "\t\t Total Price :  \t" << sum << "$" << endl;

        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
        cout << "(1) Add To Your Order\n(2) Delete\n(3) Receipt\n\t" << endl;
        cin >> edit;
        if (edit == 1) {
            cout << endl;
            goto start;
            cout << "Please Select The Order Number :\t";
            cin >> order;
            cout << "\nPlease Enter The Number Of Deals :\t";
            cin >> deals;
            for (int i = 1; i <= deals; ++i) {

                list[o].name = arr[order - 1].name;
                list[o].price = arr[order - 1].price;
                list[o].id = arr[order - 1].id;
                o++;
            }
            sum += arr[order - 1].price * deals;
            cout << "__________\n";
            cout << "\t\tThe Price After Editing Is\t" << sum << "$" << endl;


        }
        else if (edit == 2) {



            int s_id = 0, n_delete;
            cout << "Enter ID :   ";
            cin >> s_id;
            cout << "Enter The Number Of Element Do You Want To Delete :   ";
            cin >> n_delete; cout << endl;
            int z = 0;
            cout << "\t\t\tYOUR ORDER AFTER EDIT IS\n\n";
            for (int j = 0; j < t; j++) {
                if (list[j].id == s_id && z < n_delete) {

                    sum -= list[j].price;
                    z++;

                }


                else {
                    cout << list[j].name << "\t" << list[j].price << "$" << "\t" << list[j].id << endl;
                }

            }
            cout << "\n\t\t\t\t\t Total Price " << sum << "$" << endl;
            break;
        }

        else if (edit == 3)
        {
            cout << "\t\t\t\t\tRECEIPT\t\t" << endl;
            for (int i = 0; i < o; ++i) {
                cout << list[i].name << "  ";
                cout << list[i].price << "$" << "\t" << list[i].id << endl;

            }
            cout << "\n\t\t Total Price : \t" << sum << "$" << endl;
            break;
        }
        break;
        //...............................................................
    case 3:
        cout << "\n Name \t\t\t\t Price \t\t\t Id \n";
        cout << "--------------------------------------------------------------------\n";
        for (int i = 10; i < 15; i++) {
            cout << arr[i].name << "\t \t \t  " << arr[i].price << "$ \t\t\t" << arr[i].id << endl;
        }
        cout << "If you want to see the photos press S : \t";
        cin >> show;
        if (show == 's' || show == 'S') {

            initwindow(520, 400);

            readimagefile("cheesecake.jpg", 10, 10, 150, 150);     
            readimagefile("crepe.jpg", 170, 10, 320, 150);
            readimagefile("waffle.jpg", 340, 10, 500, 150);
            readimagefile("cookies.jpg", 80, 180, 250, 320);
            readimagefile("konafa.jpg", 290, 180, 460, 320);
            cout << "Press c to close the window : \t";
            cin >> close;
           
            closegraph();
        }
        
       
        cout << "--------------------------------------------------------------------\n";
        cout << "Please select the order number :\t";
        cin >> order;
        cout << "\nPlease enter the number of deals :\t";
        cin >> deals;
        t += deals;
        for (int i = 1; i <= deals; ++i) {
            list[o].name = arr[order - 1].name;
            list[o].price = arr[order - 1].price;
            list[o].id = arr[order - 1].id;
            o++;
        }
        sum += arr[order - 1].price * deals;
        cout << "\n\t\t\tTotal Price :   " << sum << "$" << endl;
        cout << "\nDo you want to continue? \t\n";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
            goto start;


        else
            cout << "\t\t\tYour Order Is" << endl;
        for (int i = 0; i < o; ++i) {
            cout << list[i].name << "  ";
            cout << list[i].price << "$" << "  ";
            cout << list[i].id << endl << endl;

        }
        cout << "\t\t Total Price :  \t" << sum << "$" << endl;

        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
        cout << "(1) Add To Your Order\n(2) Delete\n(3) Receipt\n\t" << endl;
        cin >> edit;
        if (edit == 1) {
            cout << endl;
            goto start;
            cout << "Please Select The Order Number :\t";
            cin >> order;
            cout << "\nPlease Enter The Number Of Deals :\t";
            cin >> deals;
            for (int i = 1; i <= deals; ++i) {

                list[o].name = arr[order - 1].name;
                list[o].price = arr[order - 1].price;
                list[o].id = arr[order - 1].id;
                o++;
            }
            sum += arr[order - 1].price * deals;
            cout << "__________\n";
            cout << "\t\tThe Price After Editing Is\t" << sum << "$" << endl;


        }
        else if (edit == 2) {



            int s_id = 0, n_delete;
            cout << "Enter ID :   ";
            cin >> s_id;
            cout << "Enter The Number Of Element Do You Want To Delete :   ";
            cin >> n_delete; cout << endl;
            int z = 0;
            cout << "\t\t\tYOUR ORDER AFTER EDIT IS\n\n";
            for (int j = 0; j < t; j++) {
                if (list[j].id == s_id && z < n_delete) {

                    sum -= list[j].price;
                    z++;

                }


                else {
                    cout << list[j].name << "\t" << list[j].price << "$" << "\t" << list[j].id << endl;
                }

            }
            cout << "\n\t\t\t\t\t Total Price " << sum << "$" << endl;
            break;
        }

        else if (edit == 3)
        {
            cout << "\t\t\t\t\tRECEIPT\t\t" << endl;
            for (int i = 0; i < o; ++i) {
                cout << list[i].name << "  ";
                cout << list[i].price << "$" << "\t" << list[i].id << endl;

            }
            cout << "\n\t\t Total Price : \t" << sum << "$" << endl;
            break;
        }
        break;
    case 4:

        break;
    }

}


void signin(fstream& account) {
    ifstream data;
    data.open("customer.txt", ios::in);
    string mail, pas;
    cout << "\n Enter your E_mail:\n";
    cin >> mail;
    cout << " Enter your Password:\n";
    cin >> pas;
    string line1, line2;
    while (!data.eof())
    {
        getline(data, line1);
        getline(data, line2);

        for (int i = 0; i < size; i++) {
            {

                if (mail == line1 && pas == line2) {


                    welcome();
                    break;


                }
                else
                    break;
            }


        }
    }

    account.close();
    data.close();

}
void create(fstream& account) {
    char stat = 'C';
    account.open("customer.txt ", ios::app);



    while (stat != 'D' && stat != 'd') {
        int i = 0;
        cout << "\t\t\t\t    Creat your Account \n";
        cout << "\t\t\t\t    -------------------\n";

        cout << "\n Enter your ID:\n";
        cin >> cust[i].id;
        account << "ID:";
        account << cust[i].id << endl;
        cout << " Enter your Name:\n";
        cin >> cust[i].name;
        account << "Name:";
        account << cust[i].name << endl;
        cout << " Enter your Phone: \n";
        cin >> cust[i].phone;
        account << " Phone:";
        account << cust[i].phone << endl;
        cout << " Enter your Address:\n";
        cin >> cust[i].address;
        account << "Adress:";
        account << cust[i].address << endl;
        
        cout << " Enter your E_mail:\n";
        cin >> cust[i].email;
       
        account << cust[i].email << endl;
        cout << " Enter your Password :\n";
        cin >> cust[i].pass;
        
        account << cust[i].pass << endl;
        cout << "IF YOU'RE DONE , PLEASE CLICK D:" << " ";
        cin >> stat;

        i++;

    }
    cout << "\n\t\t\t\t You singedd up Successfully\n\t\t\t\t----------------------------- \n ";
    welcome();
}
void welcome() {
    cout << "\t\t\t\t WELCOME OUR DEAR CUSTOMER \n";
    cout << "\t\t\t\t --------------------------\n";
    cout << "(1) View Menu \n";
    cout << "(2) Search \n";
    cout << "(3) Exit \n";

    int press;
    cin >> press;
    switch (press) {
    case 1:
        view_menu();
        break;
    case 2:
        arr[0] = { "(1)Milk Tea  ",20201,"drinks",10 };
        arr[1] = { "(2)Lemonade",20202,"drinks",12 };
        arr[2] = { "(3)orange juice",20203,"drinks",15 };
        arr[3] = { "(4)Mango Juice",20204,"drinks",18 };
        arr[4] = { "(5)Ice Coffee" ,20205,"drinks",20 };

        arr[5] = { "(6)Pizza  ",20206,"main dish",50 };
        arr[6] = { "(7)Burger",20207,"main dish",50 };
        arr[7] = { "(8)Pasta",20208,"main dish",45 };
        arr[8] = { "(9)Sea Food",20209,"main dish",80 };
        arr[9] = { "(10)Molo5ia" ,20210,"main dish",30 };

        arr[10] = { "(11)CheeseCake ",20211,"Dessert",25 };
        arr[11] = { "(12)Crepe",20212,"Dessert",20 };
        arr[12] = { "(13)Waffle",20213,"Dessert",20 };
        arr[13] = { "(14)Cookies",20214,"Dessert",15 };
        arr[14] = { "(15)Konafa" ,20215,"Dessert",25 };

       
            cout << "\nEnter ID \n";      
            
            cin >> id;
            
            for (int i = 0; i < 15; i++)
            {
                if (id == arr[i].id) {
                    cout <<"\n" << arr[i].name<<'\t' << arr[i].id << '\t' << arr[i].category << "\t" << arr[i].price << "$" << endl<<endl;
                }
            }
        
        view_menu();
        break;
    case 3:
        break;
    }
}

int main()
{
    fstream account;
    cout << "\t\t\t\t WELCOME OUR DEAR CUSTOMER \n";
    cout << "\t\t\t\t --------------------------\n";
    int click;
    cout << "(1) Creat an Account.\n(2) Log In.\n(3) Exit.\n";
    
    cin >> click;
    switch (click) {
    case 1:
        create(account);
        break;

    case 2:
        signin(account);
        break;
    case 3:
        break;
    case 4:
        view_menu();
        break;
    case 5:
        welcome();
        break;
   
    }
    return 0;
}
