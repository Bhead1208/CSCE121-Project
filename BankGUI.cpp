/*
Aadhav Chandran
Brian Head
Abraham Hinojosa
*/
// Example code from Chapter 16.5 from textbook (chapter.16.7.cpp)
// with additional annotations.
// This code constructs a GUI that interacts with the user through
// buttons, boxes, and menus to draw an open polyline defined by
// points given by the user.
#include <iostream>    // for i/o
#include <sstream>     // for string streams
#include "Graph.h"     // next 3 are for graphics library
#include "GUI.h"
#include "Window.h"
#include "Economy.h"
using namespace Graph_lib;
using namespace std;

//----------------------------------------------------------
// define a struct that is a window in which lines can be
// entered via a GUI

struct Lines_window : Graph_lib::Window {       // inherits from Window
    
    // constructor
    Lines_window(Point xy,             // top lefthand corner
                 int w,                // width
                 int h,                // height
                 const string& title); // label
    
private:
    // data members
    Open_polyline lines;               // shape to hold the lines themselves
    BankIntl myBank;
    string choice = "None";
    int option = 0;
    
    // widgets:
    Button withdrawal_button;
    Button deposit_button;
    Button next_button;                // button indicating next point is ready
    Button quit_button;                // end program
    In_box input_a;                     // box for entering x coord of next point
    In_box input_b;                     // box for entering y coord of next point
    In_box input_c;
    In_box input_d;
    In_box input_e;
    Out_box xy_out;                    // box for displaying last point entered
    Out_box out1;
    Out_box out2;
    Out_box out3;
    Out_box out4;
    Out_box out5;
    Out_box out6;
    Out_box out7;
    Out_box out8;
    Out_box usO;
    Out_box gbpO;
    Out_box eurO;
    Out_box jpyO;
    Out_box rubO;
    Vector<Out_box*> outbs;
    Menu menu;                   // menu of color choices for the lines
    Button menu_button;                // button to display the color menu
    
    // function members
    
    void change(Color c) {             // change the color of the lines
        lines.set_color(c);
    }
    
    void hide_menu() {
        // hides the color menu and shows the button to display the color menu
        menu.hide();
        menu_button.show();
    }
    
    void menu_pressed() {
        // when menu button is pressed, hide the menu button and show the
        // actual menu of colors
        menu_button.hide();
        menu.show();
    }
    
    void next();   // defined below
    
    void quit();   // defined below
    
    void withdrawal();
    void deposit();
    void showPatron();
    void showTransaction();
    void isPatron();
    void add();
    void remove();
    void newPatron();
    void newPatronID();
    
    // callback functions; declared here and defined below.
    
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
    static void cb_withdrawal(Address, Address);
    static void cb_deposit(Address, Address);
    static void cb_showPatron(Address, Address);
    static void cb_showTransaction(Address, Address);
    static void cb_isPatron(Address, Address);
    static void cb_add(Address, Address);
    static void cb_remove(Address, Address);
    static void cb_newPatron(Address, Address);
    static void cb_newPatronID(Address, Address);
};

// ----------------------------------------------------------
// now define the parts of Lines_window that were only declared
// inside the class

// constructor:

Lines_window::Lines_window(Point xy, int w, int h, const string& title) :

// initialization - start by calling constructor of base class
Window(xy,w,h,title),

// initialize "Next point" button
next_button(
            Point(x_max()-150,0),   // location of button
            70, 20,                 // dimensions of button
            "Next",          // label of button
            cb_next),               // callback function for button
// initialize quit button
quit_button(
            Point(x_max()-70,0),    // location of button
            70, 20,                 // dimensions of button
            "Quit",                 // label of button
            cb_quit),               // callback function for button
// initialize the input_a inbox
input_a(
        Point(x_max()-410,0),       // location of box
        50, 20,                     // dimensions of box
        "I1:"),                 // label of box
// initialize the input_b inbox
input_b(
        Point(x_max()-310,0),       // location of box
        50, 20,                     // dimensions of box
        "I2:"),                 // label of box
// initialize the outbox
input_c(
        Point(x_max()-210,0),       // location of box
        50, 20,                     // dimensions of box
        "I3:"),                 // label of box
input_d(
        Point(x_max()-410,30),       // location of box
        50, 20,                     // dimensions of box
        "I2:"),                 // label of box
// initialize the outbox
input_e(
        Point(x_max()-310,30),       // location of box
        50, 20,                     // dimensions of box
        "I3:"),                 // label of box
// initialize the outbox
xy_out(
       Point(50,0),               // location of box
       200, 20,                    // dimensions of box
       "Option:"),          // label of box
out1(Point(60,30), 450, 20, "Output 1"),
out2(Point(60,60), 450, 20, "Output 2"),
out3(Point(60,90), 450, 20, "Output 3"),
out4(Point(60,120), 450, 20, "Output 4"),
out5(Point(60,150), 450, 20, "Output 5"),
out6(Point(60,180), 450, 20, "Output 6"),
out7(Point(60,210), 450, 20, "Output 7"),
out8(Point(60,240), 450, 20, "Output 8"),
// initialize the color menu
menu(
     Point(x_max()-100,30),   // location of menu
     100, 20,                 // dimensions of menu
     Menu::vertical,         // list menu items vertically
     "Menu"),               // label of menu
// initialize the menu button
menu_button(
            Point(x_max()-80,30),  // location of menu button
            80, 20,                // dimensions of button
            "Menu",          // label of button
            cb_menu),               // callback for button

withdrawal_button(
                  Point(x_max()-80,70),  // location of menu button
                  80, 20,                // dimensions of button
                  "withdrawal",          // label of button
                  cb_withdrawal),
deposit_button(
               Point(x_max()-80,70),  // location of menu button
               80, 20,                // dimensions of button
               "deposit",          // label of button
               cb_deposit),
usO(Point(40,y_max()-20), 100, 20, "USD"),
gbpO(Point(180,y_max()-20), 100, 20, "GBP"),
eurO(Point(320,y_max()-20), 100, 20, "EUR"),
jpyO(Point(460,y_max()-20), 100, 20, "JPY"),
rubO(Point(600,y_max()-20), 100, 20, "RUB")
// body of constructor follows
{
    // attach buttons and boxes to window
    attach(next_button);
    attach(quit_button);
    attach(input_a);
    attach(input_b);
    attach(input_c);
    attach(xy_out);
    attach(out1);
    attach(out2);
    attach(out3);
    attach(out4);
    attach(out5);
    attach(out6);
    attach(out7);
    attach(out8);
    attach(usO);
    attach(gbpO);
    attach(rubO);
    attach(eurO);
    attach(jpyO);
    xy_out.put("None");        // output to out box
    
    //format the doubles first
    stringstream ss;
    string me;
    
    sprintf((char*)me.c_str(), "%.2f", myBank.getTotalMoney("USD"));
    usO.put(me);
    
    sprintf((char*)me.c_str(), "%.2f", myBank.getTotalMoney("GBP"));
    gbpO.put(me);
    
    sprintf((char*)me.c_str(), "%.2f", myBank.getTotalMoney("EUR"));
    eurO.put(me);
    
    sprintf((char*)me.c_str(), "%.2f", myBank.getTotalMoney("JPY"));
    jpyO.put(me);
    
    sprintf((char*)me.c_str(), "%.2f", myBank.getTotalMoney("RUB"));
    rubO.put(me);
    
    // First make 3 buttons for color menu, one for each color, and
    // attach them to the menu: the attach function of the Menu struct
    // adjusts the size and location of the buttons; note callback functions).
    // Then attach menu to window but hide it (initially, the menu button
    // is displayed, not the actual menu of color choices).
    
    menu.attach(new Button(Point(0,0),0,0,"Withdrawal",cb_withdrawal));
    menu.attach(new Button(Point(0,0),0,0,"Deposit",cb_deposit));
    menu.attach(new Button(Point(0,0),0,0,"New Patron 1",cb_newPatron));
    menu.attach(new Button(Point(0,0),0,0,"New Patron 2",cb_newPatronID));
    menu.attach(new Button(Point(0,0),0,0,"Transactions",cb_showTransaction));
    menu.attach(new Button(Point(0,0),0,0,"Patrons",cb_showPatron));
    //menu.attach(new Button(Point(0,0),0,0,"Total Money",cb_deposit));
    menu.attach(new Button(Point(0,0),0,0,"Add Money",cb_add));
    menu.attach(new Button(Point(0,0),0,0,"Remove Money",cb_remove));
    menu.attach(new Button(Point(0,0),0,0,"Find Patron",cb_isPatron));
    attach(menu);
    menu.hide();
    
    // attach menu button
    attach(menu_button);
    
    // attach shape that holds the lines to be displayed
    attach(lines);
}

// ----------------------------
// callback function for quit button - boilerplate:
// When the button is pressed, the system invokes the
// specified callback function.  First argument is address of the
// button (which we won't use, so we don't bother to name it).  Second
// argument, named pw, is address of the window containing the pressed
// button, i.e., address of our Lines_window object.  reference_to
// converts the address pw into a reference to a Lines_window object,
// so we can call the quit() function.  Objective is to call function
// quit() which does the real work specific to this button.

void Lines_window::cb_quit(Address, Address pw) {
    reference_to<Lines_window>(pw).quit();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::quit() {
    hide();                   // FLTK idiom for delete window
    myBank.save_file();
}

// ----------------------------
// callback function for next button - boilerplate:

void Lines_window::cb_next(Address, Address pw) {
    reference_to<Lines_window>(pw).next();  // next is defined next
}

// -------------------------------
// what to do when "next point" button is pressed

void Lines_window::next() {
    // get input data from the inboxes - x and y coordinates
    // of next point
    string x = input_a.get_string();
    string y = input_b.get_string();
    string z = input_c.get_string();
    
    switch(option)
    {
        case 1: {
            
            myBank.withdrawal(stoi(x),y,stod(z));
        } break;
        case 2: {
            myBank.deposit(stoi(x),y,stod(z));
        } break;
        case 3: {
            Vector<Patron> pats = myBank.getPats();
            stringstream sst;
            if (pats.size()>0)
            {
                sst << pats.at(0);
                
                out1.put(sst.str());
                sst.str("");
            }
            if (pats.size()>1)
            {
                sst << pats.at(1);
                
                out2.put(sst.str());
                sst.str("");
            }
            if (pats.size()>2)
            {
                sst << pats.at(2);
                
                out3.put(sst.str());
                sst.str("");
            }
            if (pats.size()>3)
            {
                sst << pats.at(3);
                
                out4.put(sst.str());
                sst.str("");
            }
            if (pats.size()>4)
            {
                sst << pats.at(4);
                
                out5.put(sst.str());
                sst.str("");
            }
            if (pats.size()>5)
            {
                sst << pats.at(5);
                
                out6.put(sst.str());
                sst.str("");
            }
            if (pats.size()>6)
            {
                sst << pats.at(6);
                
                out7.put(sst.str());
                sst.str("");
            }
            if (pats.size()>7)
            {
                sst << pats.at(7);
                
                out8.put(sst.str());
                sst.str("");
            }
        } break;
        case 4: {
            Vector<Transaction> pats = myBank.getTrans();
            stringstream sst;
            if (pats.size()>0)
            {
                sst << pats.at(0);
                
                out1.put(sst.str());
                sst.str("");
            }
            if (pats.size()>1)
            {
                sst << pats.at(1);
                
                out2.put(sst.str());
                sst.str("");
            }
            if (pats.size()>2)
            {
                sst << pats.at(2);
                
                out3.put(sst.str());
                sst.str("");
            }
            if (pats.size()>3)
            {
                sst << pats.at(3);
                
                out4.put(sst.str());
                sst.str("");
            }
            if (pats.size()>4)
            {
                sst << pats.at(4);
                
                out5.put(sst.str());
                sst.str("");
            }
            if (pats.size()>5)
            {
                sst << pats.at(5);
                
                out6.put(sst.str());
                sst.str("");
            }
            if (pats.size()>6)
            {
                sst << pats.at(6);
                
                out7.put(sst.str());
                sst.str("");
            }
            if (pats.size()>7)
            {
                sst << pats.at(7);
                
                out8.put(sst.str());
                sst.str("");
            }
        } break;
        case 5:
        {
            if (myBank.findPatron(stoi(x)))
            {
                out1.put("Patron found!");
            }
            else
            {
                out1.put("Patron not found!");
            }
        }break;
        case 6:
        {
            myBank.add(x,stod(y));
        }break;
        case 7:
        {
            myBank.remove(x,stod(y));
        }break;
        case 8:
        {
            myBank.newPatron(x,y);
        }break;
        case 9:
        {
            myBank.newPatron(x,y,stoi(z));
        }break;
    }
    
    choice = "None";
    xy_out.put(choice);
    option = 0;
    redraw();  // function inherited from Window to redraw the window
}

// -------------------------------
// callback for when menu button is pressed - boilerplate

void Lines_window::cb_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
    // menu_pressed defined in Lines_window class as part of declaration
}

// ---------------------------------------------------

void Lines_window::cb_withdrawal(Address, Address pw) {
    reference_to<Lines_window>(pw).withdrawal();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::withdrawal() {
    choice = "withdrawal num,cur,amt";
    xy_out.put(choice);
    option = 1;
    hide_menu();
    redraw();
}

// ----------------------------

void Lines_window::cb_deposit(Address, Address pw) {
    reference_to<Lines_window>(pw).deposit();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::deposit() {
    choice = "deposit num,cur,amt";
    xy_out.put(choice);
    option = 2;
    hide_menu();
    redraw();
}

// ----------------------------

void Lines_window::cb_showPatron(Address, Address pw) {
    reference_to<Lines_window>(pw).showPatron();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::showPatron() {
    choice = "Patrons";
    xy_out.put(choice);
    option = 3;
    hide_menu();
    redraw();
}

// ----------------------------

void Lines_window::cb_showTransaction(Address, Address pw) {
    reference_to<Lines_window>(pw).showTransaction();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::showTransaction() {
    choice = "Transactions";
    xy_out.put(choice);
    option = 4;
    hide_menu();
    redraw();
}

// ----------------------------

void Lines_window::cb_isPatron(Address, Address pw) {
    reference_to<Lines_window>(pw).isPatron();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::isPatron() {
    choice = "Find Patron num";
    xy_out.put(choice);
    option = 5;
    hide_menu();
    redraw();
}

// ----------------------------

void Lines_window::cb_add(Address, Address pw) {
    reference_to<Lines_window>(pw).add();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::add() {
    choice = "Add Money Cur,amt";
    xy_out.put(choice);
    option = 6;
    hide_menu();
    redraw();
}

// ----------------------------

void Lines_window::cb_remove(Address, Address pw) {
    reference_to<Lines_window>(pw).remove();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::remove() {
    choice = "Remove Money Cur,amt";
    xy_out.put(choice);
    option = 7;
    hide_menu();
    redraw();
}

// ----------------------------

void Lines_window::cb_newPatron(Address, Address pw) {
    reference_to<Lines_window>(pw).newPatron();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::newPatron() {
    choice = "New Patron 1 str1,str2";
    xy_out.put(choice);
    option = 8;
    hide_menu();
    redraw();
}

// ----------------------------

void Lines_window::cb_newPatronID(Address, Address pw) {
    reference_to<Lines_window>(pw).newPatronID();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::newPatronID() {
    choice = "New Patron 2 str1,str2,num";
    xy_out.put(choice);
    option = 9;
    hide_menu();
    redraw();
}

// ----------------------------
// main - just creates window and invokes gui_main

int main() 
try {
    // construct the GUI windows
    Lines_window win1(Point(100,100),800,600,"lines1");
    // Lines_window win2(Point(200,200),800,600,"lines2");
    // Lines_window win3(Point(300,300),800,600,"lines3");
    // Lines_window win4(Point(400,400),800,600,"lines4");
    // Lines_window win5(Point(500,500),800,600,"lines5");
    return gui_main();  // inherited from Window; calls FLTK's run
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
    }
    catch(...) {
        cerr << "some exception\n";
        return 2;
    }
