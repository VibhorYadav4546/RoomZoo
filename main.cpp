#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <direct.h>
#include <iomanip>
#include <ctype.h>
#include <cstdio>
#include <direct.h>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <wincon.h>
#include <ctime>
using namespace std;

int WHITE = 15;
int RED = 12;
int GREEN = 10;
int BLUE = 9;
int YELLOW = 14;
int CYAN = 11;

void textcolor(int color)
{
    static int __BACKGROUND;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute(h, color + (__BACKGROUND << 7));
}

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void drawBox(int x, int y, int w, int h)
{

    gotoxy(x, y);
    cout << char(201);
    for (int i = 1; i < w - 1; i++)
    {
        cout << char(205);
    }
    cout << char(187) << endl;

    for (int i = y + 1; i < y + h - 1; i++)
    {
        gotoxy(x, i);
        cout << char(186);
        gotoxy(x + w - 1, i);
        cout << char(186) << endl;
    }

    gotoxy(x, y + h - 1);
    cout << char(200);
    for (int i = 1; i < w - 1; i++)
    {
        cout << char(205);
    }
    cout << char(188) << endl;
}

struct dosdate_t
{
public:
    int day;
    int month;
    int year;
};

void _dos_getdate(dosdate_t &date)
{
    time_t t = time(NULL);
    tm tm = *localtime(&t);
    date.day = tm.tm_mday;
    date.month = tm.tm_mon + 1;
    date.year = tm.tm_year + 1900;
}
class Customer_PresonalDetails
{
public:
    char name[30];
    char address[30];
};
class Customer_RoomDetails
{
public:
    int ROOM;
    long Phone;
    int member;
    char date[15];
    int noOfDays;
    float roomCost;
};

class Customer : public Customer_PresonalDetails, public Customer_RoomDetails
{

} c;

class BILL : public Customer_PresonalDetails, public Customer_RoomDetails
{
public:
    float total;
} b;

class RoomClass
{
public:
    int ROOMno;
    int priceOfBed;
    int priceOfPillow;
    int priceOfBlancket;
    int priceOfTowel;
    char bed[15];
    char ROOMtype[30];
    float ROOMcst;
    int avl;
} r;

void CURRENT()
{
    system("cls");
    RoomClass r1;
    ofstream fout("record.dat", ios::app);
    fstream fin("ROOMtype.txt", ios::in);
    cout << "\nRoom AVAILIBILTY: ";
    textcolor(WHITE);
    _cprintf(" ");
    textcolor(RED);
    _cprintf("RED: ");
    cout << "Room ALREADY BOOKED | ";
    textcolor(GREEN);
    _cprintf("GREEN: ");
    cout << "Room AVAILABLE)";
    textcolor(WHITE);
    cout << endl;
    cout << "\tRoom NUMBER\t  Room TYPE\t   BED TYPE\t      PRICE\n";
    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }
    int rr = 6;

    map<int, int> roomDetal;
    int rnc = 0;
    while (fin.read((char *)&r1, sizeof(r1)))
    {
        if (r1.avl == 1)
        {
            textcolor(GREEN);
            gotoxy(8, rr);
            _cprintf("%d ", r1.ROOMno);
            gotoxy(28, rr);
            _cprintf("%s ", r1.ROOMtype);
            gotoxy(45, rr);
            _cprintf("%s ", r1.bed);
            gotoxy(61, rr);
            _cprintf("%f ", r1.ROOMcst);
            cout << endl;

            roomDetal[r1.ROOMno] = r1.ROOMcst;
            rnc++;
        }
        else
        {
            textcolor(RED);
            gotoxy(8, rr);
            _cprintf("%d ", r1.ROOMno);
            gotoxy(28, rr);
            _cprintf("%s ", r1.ROOMtype);
            gotoxy(45, rr);
            _cprintf("%s ", r1.bed);
            gotoxy(61, rr);
            _cprintf("%f ", r1.ROOMcst);
            cout << endl;
        }
        rr++;
    }
    fin.close();
    cout << endl;
    textcolor(WHITE);
    if (rnc == 0)
        cout << "Room NOT AVAILABLE.\n";
    else
    {
        struct dosdate_t d;
        _dos_getdate(d);
        cout << "THE CURRENT DATE IS: " << d.day << "/" << d.month << "/" << d.year << endl;

        cout << "\n**********************";
        cout << "\nENTER CUSTOMER DETAILS";
        cout << "\n**********************";
        int flg = 0, i;

        while (1)
        {
            while (true)
            {
                try
                {
                    cout << "\nENTER ROOM NUMBER (Or PRESS 0 TO EXIT): ";
                    cin >> c.ROOM;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw runtime_error("Invalid input. Please enter an integer.");
                    }
                    else
                    {
                        break;
                    }
                }
                catch (exception &e)
                {
                    cerr << "Error: " << e.what() << endl;
                }
            }
            if (c.ROOM == 0)
            {
                break;
            }
            else
            {

                if (roomDetal.find(c.ROOM) != roomDetal.end())
                {
                    flg = 1;
                }

                if (flg == 1)
                {
                    c.roomCost = roomDetal[c.ROOM];

                    printf("\nNAME: ");
                    scanf("%s", &c.name);
                    fflush(stdin);
                    printf("\nNO.OF FAMILY MEMBERS: ");
                    scanf("%d", &c.member);
                    printf("\nADDRESS: ");
                    scanf("%s", &c.address);
                    fflush(stdin);
                    printf("\nNUMBER OF DAYS: ");
                    scanf("%d", &c.noOfDays);
                    printf("\nPHONE NUMBER: ");
                    scanf("%ld", &c.Phone);
                    fflush(stdin);
                    printf("\n");
                    break;
                }
                else
                {
                    cout << "INVALID ROOM NUMBER.\nPRESS ANY KEY TO ENTER CORRECT ROOM NUMBER:";
                    getch();
                }
            }
        }
        if (c.ROOM > 0)
        {
            cout << "DO YOU WANT TO SAVE(Y/N) :";
            char ch;
            cin >> ch;
            if (toupper(ch) == 'Y')
            {
                cout << "\nHAVE A NICE DAY";
                fout.write((char *)&c, sizeof(c));
                fstream fin("ROOMtype.txt", ios::in | ios::out);
                while (fin.read((char *)&r1, sizeof(r1)))
                {
                    if (r1.ROOMno == c.ROOM)
                    {
                        int pos = fin.tellg();
                        fin.seekp(pos - sizeof(r1));
                        r1.avl = 0;
                        fin.write((char *)&r1, sizeof(r1));
                        break;
                    }
                }
                fin.close();
            }
        }
    }
    fout.close();
}

void ADVANCE()
{
    system("cls");
    RoomClass r2;
    ofstream fout("record1.dat", ios::app);
    fstream fin("ROOMtype.txt", ios::in);
    cout << "\nROOM AVAILIBILTY: ";
    textcolor(WHITE);
    cout << "\n\n";
    cout << "\tROOM NUMBER\t  ROOM TYPE\t   BED TYPE\t      PRICE\n";
    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }
    int rr = 6;
    while (fin.read((char *)&r2, sizeof(r2)))
    {
        gotoxy(8, rr);
        cout << r2.ROOMno;
        gotoxy(28, rr);
        cout << r2.ROOMtype;
        gotoxy(45, rr);
        cout << r2.bed;
        gotoxy(61, rr);
        cout << r2.ROOMcst;
        cout << endl;
        rr++;
    }
    fin.close();
    cout << endl;
    textcolor(WHITE);
    struct dosdate_t d;
    _dos_getdate(d);
    cout << "THE CURRENT DATE IS: " << d.day << "/" << d.month << "/" << d.year << endl;
    cout << "\n**********************";
    cout << "\nENTER CUSTOMER DETAILS";
    cout << "\n**********************";
    cout << "\nNAME: ";
    cin >> c.name;

    while (true)
    {
        try
        {
            cout << "\nNO.OF FAMILY MEMBERS: ";
            cin >> c.member;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input. Please enter an integer.");
            }
            else
            {
                break;
            }
        }
        catch (exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
    cout << "\nENTER CHECKIN DATE: ";
    cin >> c.date;
    cout << "\nADDRESS: ";
    cin >> c.address;

    while (true)
    {
        cout << "\nPHONE NUMBER: ";
        if (cin >> c.Phone)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid phone number. Please enter a valid phone number." << endl;
        }
    }
    cout << "DO YOU WANT TO SAVE(Y/N) :";
    char ch;
    cin >> ch;
    if (toupper(ch) == 'Y')
    {
        cout << "\nHAVE A NICE DAY";
        fout.write((char *)&c, sizeof(c));
        fstream fin("ROOMtype.txt", ios::in | ios::out);
        while (fin.read((char *)&r2, sizeof(r2)))
        {
            if (r2.ROOMno == c.ROOM)
            {
                int pos = fin.tellg();
                fin.seekp(pos - sizeof(r2));
                r2.avl = 0;
                fin.write((char *)&r2, sizeof(r2));
                break;
            }
        }
        fin.close();
    }
    fout.close();
}

void CHECKIN_MENU()
{
    system("cls");
    char ch;
    while (1)
    {
        system("cls");
        int width = 50;
        int height = 9;
        int startX = 25;
        int startY = 3;
        int menuTitleWidth = 22;
        int menuTitleX = startX + (width - menuTitleWidth) / 2;
        int menuTitleY = startY + 1;
        int borderColour = 9;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), borderColour);
        gotoxy(startX, startY);
        cout << char(201);
        for (int i = 0; i < width; i++)
            cout << char(205);
        cout << char(187) << endl;

        gotoxy(menuTitleX, menuTitleY + 1);
        cout << char(179) << " SELECT TYPE OF BOOKING " << char(179);
        gotoxy(menuTitleX, menuTitleY + 2);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        gotoxy(startX + 2, startY + 4);
        cout << "1. CURRENT BOOKING";
        gotoxy(startX + 2, startY + 5);
        cout << "2. ADVANCE BOOKING";
        gotoxy(startX + 2, startY + 6);
        cout << "3. RETURN";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), borderColour);
        gotoxy(startX, startY + height - 1);
        cout << char(200);
        for (int i = 0; i < width; i++)
            cout << char(205);
        cout << char(188);

        for (int i = startY + 1; i < startY + height - 1; i++)
        {
            gotoxy(startX, i);
            cout << char(186);
            gotoxy(startX + width + 1, i);
            cout << char(186);
        }

        gotoxy(startX + width / 2 - 8, startY + height);
        cout << "ENTER YOUR CHOICE:";
        ch = getche();
        switch (ch)
        {
        case '1':
            system("cls");
            CURRENT();
            getch();
            break;
        case '2':
            system("cls");
            ADVANCE();
            getch();
            break;
        case '3':
            return;
        }
    }
}

void R_MODIFY_FORAVL(int);
void C_DELETE(int);

void CHECKOUT()
{
    fstream fout("bill.txt", ios::app);
    fstream fin("record.dat", ios::in);
    fin.read((char *)&c, sizeof(c));
    for (int i = 0; i < 80; i++)
    {
        cout << "\033[1;35m-\033[0m";
    }
    cout << "\n";
    gotoxy(33, 2);
    cout << "\033[1;32mRoomZoo HOTEL\033[0m";
    cout << "\n";
    for (int i = 0; i < 80; i++)
    {
        cout << "\033[1;35m-\033[0m";
    }
    cout << "\n";
    cout << "\n";
    int rno;

    while (true)
    {
        try
        {
            cout << "\n\033[1;34mENTER ROOM NUMBER TO GENERATE BILL FOR:\033[0m ";
            cin >> rno;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input. Please enter an integer.");
            }
            else
            {
                break;
            }
        }
        catch (exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
    if (rno == c.ROOM)
    {
        float btotal;
        cout << "\n\033[1;34mROOM NUMBER:\033[0m " << c.ROOM;
        cout << "\n\033[1;34mNAME:\033[0m " << c.name;
        cout << "\n\033[1;34mNO.OF FAMILY MEMBERS:\033[0m " << c.member;
        cout << "\n\033[1;34mADDRESS:\033[0m " << c.address;
        cout << "\n\033[1;34mPHONE NUMBER:\033[0m " << c.Phone;
        cout << "\n\033[1;34mNUMBER OF DAYS:\033[0m " << c.noOfDays;
        cout << "\n\033[1;34mPER DAY COST:\033[0m " << c.roomCost;
        btotal = c.noOfDays * c.roomCost;
        cout << "\n\033[1;34mROOM COST FOR " << c.noOfDays << " DAYS:\033[0m " << btotal;
        float gtotal = btotal;
        cout << "\n\033[1;34mGRAND TOTAL COST:\033[0m " << gtotal;
        cout << "\n\033[1;34mAMOUNT TO BE PAID (Y/N):\033[0m ";
        fflush(stdin);
        char ch;
        cin >> ch;
        if (toupper(ch) == 'Y')
        {
            b.ROOM = c.ROOM;
            strcpy(b.name, c.name);
            strcpy(b.address, c.address);
            b.Phone = c.Phone;
            b.member = c.member;
            strcpy(b.date, c.date);
            b.noOfDays = c.noOfDays;
            b.roomCost = c.roomCost;
            b.total = gtotal;
            fout.write((char *)&b, sizeof(b));
            R_MODIFY_FORAVL(c.ROOM);
            fin.close();
            C_DELETE(c.ROOM);

            cout << "\n\033[1;32mTHANK YOU FOR VISITING US.\033[0m";
        }
    }
    fout.close();
    fin.close();
    getch();
}

void R_ADD()
{
    system("cls");
    fstream fout("ROOMtype.txt", ios::out | ios::app | ios::binary);
    ofstream ROOMs("ROOMs.txt", ios::out | ios::app);
    cout << "\n**********************";
    cout << "\nENTER Room DETAILS";
    cout << "\n**********************";
    fflush(stdin);
    cout << "\nRoom TYPE: ";
    cin >> r.ROOMtype;
    fflush(stdin);
    cout << "\nTYPE OF BED: ";
    gets(r.bed);
    cout << "\nRoom COST: ";
    cin >> r.ROOMcst;

    bool isValidROOM = false;
    do
    {

        while (true)
        {
            try
            {
                cout << "\nRoom NUMBER: ";
                cin >> r.ROOMno;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Invalid input. Please enter an integer.");
                }
                else
                {
                    break;
                }
            }
            catch (exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }

        ifstream ROOMsCheck("ROOMs.txt");
        int ROOM;
        while (ROOMsCheck >> ROOM)
        {
            if (ROOM == r.ROOMno)
            {
                cout << "\nRoom ID already exists. Please enter a unique Room ID.";
                break;
            }
        }
        ROOMsCheck.close();
        if (ROOMsCheck.eof())
        {
            isValidROOM = true;

            ROOMs << r.ROOMno << endl;
        }
    } while (!isValidROOM);

    r.avl = 1;
    cout << "DO YOU WANT TO SAVE(Y/N): ";
    char ch;
    cin >> ch;
    if (toupper(ch) == 'Y')
    {
        fout.write((char *)&r, sizeof(r));
        cout << "\nROOM ADDED.";
    }
    fout.close();
    ROOMs.close();
}

void R_MODIFY()
{
    system("cls");
    ifstream fin("ROOMtype.txt", ios::in | ios::binary);
    ofstream fout("rtype.tmp", ios::out | ios::binary);

    if (!fin)
    {
        cout << "NO ROOM FOUND.";
        return;
    }

    int rno;

    while (true)
    {
        try
        {
            cout << "\nEnter ROOM Number to Modify Cost: ";
            cin >> rno;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input. Please enter an integer.");
            }
            else
            {
                break;
            }
        }
        catch (exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    bool ROOMFound = false;
    while (fin.read((char *)&r, sizeof(r)))
    {
        if (rno == r.ROOMno)
        {
            ROOMFound = true;
            cout << "\n***********************";
            cout << "\nCurrent Details:";
            cout << "\nRoom Number: " << r.ROOMno;
            cout << "\nRoom Type: " << r.ROOMtype;
            cout << "\nRoom Cost: " << r.ROOMcst;

            cout << "\n\n***********************";
            cout << "\nEnter new ROOM Cost: ";
            cin >> r.ROOMcst;

            char ch;
            cout << "Do you want to save (Y/N): ";
            cin >> ch;

            if (toupper(ch) == 'Y')
            {
                fout.write((char *)&r, sizeof(r));
                cout << "\nRecord Modified.";
            }
            else
            {
                cout << "\nRecord not Modified.";
            }
        }
        else
        {
            fout.write((char *)&r, sizeof(r));
        }
    }

    if (!ROOMFound)
    {
        cout << "\nROOM with ROOM Number " << rno << " not found.";
    }

    fin.close();
    fout.close();
    remove("ROOMtype.txt");
    rename("rtype.tmp", "ROOMtype.txt");
}

void R_MODIFY_FORAVL(int rno)
{
    ofstream fout("rtype.tmp", ios::out | ios::binary);
    ifstream fin("ROOMtype.txt", ios::in | ios::binary);
    if (!fin)
    {
        cout << "NO ROOM FOUND.";
    }
    else
    {
        while (fin.read((char *)&r, sizeof(r)))
        {
            if (rno == r.ROOMno)
            {
                r.avl = 1;
                fout.write((char *)&r, sizeof(r));
            }
            else
                fout.write((char *)&r, sizeof(r));
        }
        fout.close();
        fin.close();
        remove("ROOMtype.txt");
        rename("rtype.tmp", "ROOMtype.txt");
    }
}

void R_DISPLAY()
{
    system("cls");
    ifstream fin("ROOMtype.txt", ios::in | ios::binary);
    if (!fin)
    {
        cout << "NO ROOM FOUND.";
    }
    else
    {
        for (int i = 0; i < 80; i++)
        {
            cout << "*";
        }
        gotoxy(30, 2);
        cout << "ROOM DETAIL INFORMATION\n";
        for (int i = 0; i < 80; i++)
        {
            cout << "*";
        }
        cout << "\n";
        cout << "\tROOM NUMBER\t    ROOM TYPE\t      ROOM COST\t\tBED TYPE\n";
        for (int i = 0; i < 80; i++)
        {
            cout << "-";
        }
        int rr = 7;
        while (fin.read((char *)&r, sizeof(r)))
        {
            gotoxy(12, rr);
            cout << r.ROOMno;
            gotoxy(31, rr);
            cout << r.ROOMtype;
            gotoxy(46, rr);
            cout << r.ROOMcst;
            gotoxy(67, rr);
            cout << r.bed;
            cout << "\n";
            rr++;
        }
        cout << "\nPRICE OF EXTRA BED: ";
        r.priceOfBed = 200;
        cout << r.priceOfBed;
        cout << "\nPRICE OF EXTRA PILLOW: ";
        r.priceOfPillow = 40;
        cout << r.priceOfPillow;
        cout << "\nPRICE OF EXTRA BLANKET: ";
        r.priceOfBlancket = 80;
        cout << r.priceOfBlancket;
        cout << "\nPRICE OF EXTRA TOWEL: ";
        r.priceOfTowel = 20;
        cout << r.priceOfTowel;
    }
    fin.close();
}

void R_DELETE()
{
    system("cls");
    ofstream fout("rtype.tmp", ios::out | ios::binary);
    ifstream fin("ROOMtype.txt", ios::in | ios::binary);
    if (!fin)
    {
        cout << "NO ROOM FOUND.";
    }
    else
    {
        int rno;

        while (true)
        {
            try
            {
                cout << "\nENTER ROOM NUMBER TO DELETE: ";
                cin >> rno;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Invalid input. Please enter an integer.");
                }
                else
                {
                    break;
                }
            }
            catch (exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }

        int flg = 0;
        while (fin.read((char *)&r, sizeof(r)))
        {
            if (rno == r.ROOMno)
                flg = 1;
            else
                fout.write((char *)&r, sizeof(r));
        }
        if (flg == 1)
            cout << "ROOM DELETED.";
        else
            cout << "ROOM NOT AVAILABLE TO DELETE.";
    }

    fout.close();
    fin.close();
    remove("ROOMtype.txt");
    rename("rtype.tmp", "ROOMtype.txt");
}

void M_ROOMTYPE_MENU()
{
    system("cls");
    int ch;
    while (1)
    {
        system("cls");
        drawBox(33, 4, 30, 10);
        gotoxy(38, 5);
        cout << " ROOM OPTIONS";
        gotoxy(35, 8);
        cout << "1. ADD";
        gotoxy(35, 9);
        cout << "2. MODIFY";
        gotoxy(35, 10);
        cout << "3. DISPLAY";
        gotoxy(35, 11);
        cout << "4. DELETE";
        gotoxy(35, 12);
        cout << "5. RETURN";
        gotoxy(35, 14);
        cout << "ENTER YOUR CHOICE:";
        ch = getche();
        switch (ch)
        {
        case '1':
            system("cls");
            R_ADD();
            getch();
            break;
        case '2':
            system("cls");
            R_MODIFY();
            getch();
            break;
        case '3':
            system("cls");
            R_DISPLAY();
            getch();
            break;
        case '4':
            system("cls");
            R_DELETE();
            getch();
            break;
        case '5':
            return;
        }
    }
}

void C_MODIFY()
{
    system("cls");
    ofstream fout("ctype.tmp", ios::out | ios::binary);
    ifstream fin("record.dat", ios::in | ios::binary);
    if (!fin)
    {
        cout << "NO RECORD FOUND.";
    }
    else
    {
        int rno;
        Customer
            c1;

        while (true)
        {
            try
            {
                cout << "\nENTER ROOM ID TO MODIFY: ";
                cin >> rno;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Invalid input. Please enter an integer.");
                }
                else
                {
                    break;
                }
            }
            catch (exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        while (fin.read((char *)&c, sizeof(c)))
        {
            if (rno == c.ROOM)
            {
                cout << "\n***********************";
                cout << "\nENTER DETAILS TO MODIFY";
                cout << "\n***********************";
                cout << "\nENTER ROOM ID TO MODIFY: " << rno;
                cout << "\nNAME: ";
                cin >> c1.name;
                fflush(stdin);

                while (true)
                {
                    try
                    {
                        cout << "\nNO.OF FAMILY MEMBERS: ";
                        cin >> c1.member;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw runtime_error("Invalid input. Please enter an integer.");
                        }
                        else
                        {
                            break;
                        }
                    }
                    catch (exception &e)
                    {
                        cerr << "Error: " << e.what() << endl;
                    }
                }
                cout << "\nADDRESS: ";
                cin >> c1.address;
                fflush(stdin);

                while (true)
                {
                    try
                    {
                        cout << "\nNUMBER OF DAYS: ";
                        cin >> c1.noOfDays;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw runtime_error("Invalid input. Please enter an integer.");
                        }
                        else
                        {
                            break;
                        }
                    }
                    catch (exception &e)
                    {
                        cerr << "Error: " << e.what() << endl;
                    }
                }
                cout << "\nPHONE NUMBER: ";
                cin >> c1.Phone;
                fflush(stdin);
                cout << "\n\n";
                char ch;
                cout << "DO YOU WANT TO SAVE(Y/N): ";
                cin >> ch;
                if (toupper(ch) == 'Y')
                {
                    c1.ROOM = c.ROOM;
                    c1.roomCost = c.roomCost;
                    fout.write((char *)&c1, sizeof(c1));
                    cout << "RECORD MODIFIED.";
                }
                else
                    fout.write((char *)&c, sizeof(c));
            }
            else
                fout.write((char *)&c, sizeof(c));
        }
        fout.close();
        fin.close();
        remove("record.dat");
        rename("ctype.tmp", "record.dat");
    }
}

void C_DISPLAY()
{
    system("cls");
    ifstream fin("record.dat", ios::in | ios::binary);
    if (!fin)
    {
        cout << "NO RECORD FOUND.";
    }
    else
    {
        for (int i = 0; i < 80; i++)
        {
            cout << "*";
        }
        gotoxy(33, 2);
        cout << "CUSTOMER DETAIL INFORMATION\n";
        for (int i = 0; i < 80; i++)
        {
            cout << "*";
        }
        cout << endl;
        gotoxy(2, 5);
        cout << "R.NO";
        gotoxy(15, 5);
        cout << "CUSTOMER NAME";
        gotoxy(35, 5);
        cout << "ADDRESS";
        gotoxy(50, 5);
        cout << "PHONE";
        gotoxy(60, 5);
        cout << "DAYS";
        gotoxy(70, 5);
        cout << "COST";
        cout << endl;
        for (int i = 0; i < 80; i++)
        {
            cout << "-";
        }
        cout << endl;
        int rr = 7;
        while (fin.read((char *)&c, sizeof(c)))
        {
            gotoxy(3, rr);
            cout << c.ROOM;
            gotoxy(17, rr);
            cout << c.name;
            gotoxy(37, rr);
            cout << c.address;
            gotoxy(50, rr);
            cout << c.Phone;
            gotoxy(62, rr);
            cout << c.noOfDays;
            gotoxy(70, rr);
            cout << c.roomCost;
            rr++;
        }
        fin.close();
    }
}

void BILL_DISPLAY()
{
    system("cls");
    ifstream fin("bill.txt", ios::in | ios::binary);
    if (!fin)
    {
        cout << "NO RECORD FOUND.";
    }
    else
    {
        for (int i = 0; i < 80; i++)
        {
            cout << "*";
        }
        gotoxy(25, 2);
        cout << "CUSTOMER WISE BILL DETAIL INFORMATION\n";
        for (int i = 0; i < 80; i++)
        {
            cout << "*";
        }
        gotoxy(2, 5);
        cout << "R.NO";
        gotoxy(10, 5);
        cout << "CUSTOMER NAME";
        gotoxy(25, 5);
        cout << "ADDRESS";
        gotoxy(36, 5);
        cout << "PHONE";
        gotoxy(47, 5);
        cout << "DAYS";
        gotoxy(56, 5);
        cout << "COST";
        gotoxy(69, 5);
        cout << "T.COST";
        cout << endl;
        for (int i = 0; i < 80; i++)
        {
            cout << "-";
        }
        cout << endl;
        int rr = 7;
        while (fin.read((char *)&b, sizeof(b)))
        {
            gotoxy(2, rr);
            cout << b.ROOM;
            gotoxy(13, rr);
            cout << b.name;
            gotoxy(27, rr);
            cout << b.address;
            gotoxy(35, rr);
            cout << b.Phone;
            gotoxy(48, rr);
            cout << b.noOfDays;
            gotoxy(54, rr);
            cout << b.roomCost;
            gotoxy(68, rr);
            cout << b.total;
            rr++;
        }
        fin.close();
    }
}

void C_DELETE(int rno)
{
    system("cls");
    ofstream fout("ctype.tmp", ios::out | ios::binary);
    ifstream fin("record.dat", ios::in | ios::binary);
    if (!fin)
    {
        cout << "NO RECORD FOUND.";
    }

    else
    {
        while (fin.read((char *)&c, sizeof(c)))
        {
            if (rno != c.ROOM)
                fout.write((char *)&c, sizeof(c));
        }
    }
    fout.close();
    fin.close();
    remove("record.dat");
    rename("ctype.tmp", "record.dat");
}

#include <windows.h>

void CUSTOMER_MENU()
{
    int ch;
    while (1)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        cout << "--------------------------------------------------\n";
        cout << "|                   CUSTOMER OPTIONS              |\n";
        cout << "--------------------------------------------------\n";
        cout << "|                       MENU                     |\n";
        cout << "--------------------------------------------------\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "| 1. DISPLAY                                       |\n";
        cout << "| 2. BILL DISPLAY                                  |\n";
        cout << "| 3. RETURN                                        |\n";
        cout << "--------------------------------------------------\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "ENTER YOUR CHOICE: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        ch = getche() - '0';
        switch (ch)
        {
        case 1:
            system("cls");
            C_DISPLAY();
            getch();
            break;
        case 2:
            system("cls");
            BILL_DISPLAY();
            getch();
            break;
        case 3:
            return;
        default:
            cout << "\nINVALID CHOICE! PLEASE TRY AGAIN.";
            getch();
            break;
        }
    }
}

void MASTER_MENU()
{
    system("cls");
    int ch;
    while (1)
    {
        system("cls");
        drawBox(28, 2, 44, 11);
        gotoxy(36, 3);
        cout << "MENU";
        gotoxy(30, 5);
        cout << "1. Register Room";
        gotoxy(30, 7);
        cout << "2. RETURN";
        gotoxy(30, 9);
        cout << "ENTER YOUR CHOICE: ";
        ch = getche();
        switch (ch)
        {
        case '1':
            system("cls");
            M_ROOMTYPE_MENU();
            break;
        case '2':
            return;
        }
    }
}

void intoMenuMain()
{
    system("cls");
    system("color 0A");
    cout << "\n\n\n\n\n\t\t\t\t                               RRRRR         *\n"
         << "\t\t\t\t                               R    R       ***\n"
         << "\t\t\t\t                               R    R        *\n"
         << "\t\t\t\t                               RRRR       \n"
         << "\t\t\t\t                               R    R         \n"
         << "\t\t\t\t                               R     R      \n"
         << "\t\t\t\t                               R      R   \n\n\n\n\n"
         << "\t\t\t\t RoomZoo - Where every booking is a safari of comfort and convenience.";
    getch();
}
int loading1()
{
    int i, j, k, a;

    std::cout << "Loading ";

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 1 * 100000000; j++)
        {
            k = 1000 * j;
            if (k == j)
                std::cout << "....";
        }
    }

    system("cls");
    return 0;
}
int loading()
{
    system("cls");
    system("color 07");
    int i, j, k, a;

    std::cout << "\n\n\n\n\n                                Please wait loading program\n";
    std::cout << "\n                                Loading ";

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4 * 100000000; j++)
        {
            k = 100000 * j;
            if (k == j)
                std::cout << ".";
        }
    }

    system("cls");
    return 0;
}

int thankYouMessage()
{
    char f;

    cout << "\033[1;32m";
    cout << "___________ .__                         __        _____.___.                     \n";
    cout << "\\__    ___/ |  |__   _____      ____   |  | __    \\__  |   |   ____    __ __      \n";
    cout << "  |    |    |  |  \\  \\__  \\    /    \\  |  |/ /     /   |   |  /  _ \\  |  |  \\      \n";
    cout << "  |    |    |   Y  \\  / __ \\_ |   |  \\ |    <      \\____   | (  <_> ) |  |  /         \n";
    cout << "  |____|    |___|  / (____  / |___|  / |__|_ \\     / ______|  \\____/  |____/ \n";
    cout << "                 \\/       \\/       \\/       \\/     \\/                        \n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\n";
    }

    cout << "\033[0m";
    cout << "Enter any key to continue\n";
    getch();
    system("cls");

    return 0;
}

int main()
{
    system("cls");

    intoMenuMain();
    loading();
    system("color 02");
    char choice;
    while (1)
    {
        system("cls");
        int width = 40;
        int height = 11;
        int startX = 30;
        int startY = 3;
        int menuTitleWidth = 16;
        int menuTitleX = startX + (width - menuTitleWidth) / 2;
        int menuTitleY = startY + 1;
        int borderColour = 9;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), borderColour);
        gotoxy(startX, startY);
        cout << char(201);
        for (int i = 0; i < width; i++)
            cout << char(205);
        cout << char(187) << endl;

        gotoxy(menuTitleX, menuTitleY + 1);
        cout << char(179) << "  MAIN MENU  " << char(179);
        gotoxy(menuTitleX, menuTitleY + 2);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        gotoxy(startX, startY + 3);
        cout << " 1.CHECK-IN";
        gotoxy(startX, startY + 4);
        cout << " 2.CHECK-OUT";
        gotoxy(startX, startY + 5);
        cout << " 3.CUSTOMER INFO";
        gotoxy(startX, startY + 6);
        cout << " 4.ADMIN";
        gotoxy(startX, startY + 7);
        cout << " 5.EXIT";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), borderColour);
        gotoxy(startX, startY + height - 1);
        cout << char(200);
        for (int i = 0; i < width; i++)
            cout << char(205);
        cout << char(188);

        for (int i = startY + 1; i < startY + height - 1; i++)
        {
            gotoxy(startX, i);
            cout << char(186);
            gotoxy(startX + width + 1, i);
            cout << char(186);
        }

        gotoxy(startX + width / 2 - 8, startY + height);
        cout << "ENTER YOUR CHOICE ";
        choice = getche();

        switch (choice)
        {
        case '1':
            system("cls");
            loading1();
            CHECKIN_MENU();
            break;
        case '2':
            system("cls");
            loading1();
            CHECKOUT();
            break;
        case '3':
            system("cls");
            loading1();
            CUSTOMER_MENU();
            break;
        case '4':
            system("cls");
            loading1();
            MASTER_MENU();
            break;
        case '5':
            system("cls");
            loading1();
            system("cls");
            thankYouMessage();
            exit(0);
        }
    }
    return 0;
}
