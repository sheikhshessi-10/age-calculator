/*Programmers name : Muhammad Sches & Subhan Ahmad ( mini project )
* 
* DATE: 25 January 2024

* program : calculate the Age in days, months and years and Take today’s date (particularly the day of the week).
Calculate what was the day on 14th August 1947 (On the day Pakistan came into being).
Then ask any date and tell what was the day of the week on that day.
*/

#include <iostream>
using namespace std;

bool IsValidYearInDate(int year);
bool  IsValidMonthInDate(int month);
bool  IsValidDayInDate(int day);
bool isValidDateOfDeath(int dob, int mob, int yob, int dod, int mod, int yod);
bool IsLeapYear(int year);
bool isDateValid(int, int, int);
bool isGreaterEqual(int du, int mu, int yu, int dd, int md, int yd);
int daysInAMonth(int month, int year);
void ageCalculator(int, int, int, int, int, int);



int ageInDays(int dob, int mob, int yob, int dor, int mor, int yor);
string outputDay(int ageInDays, string day, bool past);
int maina();
int mainb();


void menu()
{
    cout << "Enter 1 to : Find the Age in days, months and years." << endl;
    cout << "Enter 2 to : Find what was the day on a specific date" << endl;
    cout << "0. Exit" << endl;

}
int main()
{
    int choice;
    while (true)
    {
        cout << "__________________________\n" << endl;
        menu();
        cout << "__________________________\n" << endl;
        cout << "Enter Choice:";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            maina();
            break;
        case 2:           
            mainb();

            break;
        default:
            break;
        }
    }
    return 0;
}






/*
calculate the Age in days, months and years.
*/
int maina()
{
    int dob, mob, yob, dod, mod, yod;


    bool validate = true;

    do
    {
        if (!validate)

            cout << "Enter a valid Date Of Birth: ";

        else

            cout << "Enter Date Of Birth: ";

        cin >> dob >> mob >> yob;
        validate = isDateValid(dob, mob, yob);
    } while (!validate);

    do
    {
        cout << "Expected Date of Death: ";
        cin >> dod >> mod >> yod;

    } while (!(isGreaterEqual(dod, mod, yod, dob, mob, yob)) || !(isDateValid(dod, mod, yod)));

    ageCalculator(dob, mob, yob, dod, mod, yod);

    return 0;
}

bool isDateValid(int day, int month, int year)
{
    if (day >= 1 && day <= daysInAMonth(month, year))
        return true;
    if (month >= 1 && month <= 12)
        return true;
    if (year > 0)
        return true;

    return false;
}

bool isGreaterEqual(int du, int mu, int yu, int dd, int md, int yd)
{
    if (yu > yd)
        return true;
    if (yu < yd)
        return false;
    if (mu > md)
        return true;
    if (mu < md)
        return false;
    return du >= dd;
}


int daysInAMonth(int month, int year)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    if (month == 2)
    {
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                    return 29;
                else
                    return 28;
            }
            else
                return 29;
        }
        else
            return 28;
    }

    else
        return 30;
}

void ageCalculator(int bday, int bmonth, int byear, int dday, int dmonth, int dyear)
{
    int ageday, agemonth, ageyear;

    ageday = dday - bday;
    if (ageday < 0)
    {
        ageday = ageday + daysInAMonth(dmonth - 1, dyear);
        dmonth--;
    }

    agemonth = dmonth - bmonth;
    if (agemonth < 0)
    {
        agemonth = agemonth + 12;
        dyear--;
    }

    ageyear = dyear - byear;

    cout << "Age is " << ageyear << " years " << agemonth << " months " << ageday << " days." << endl;
}



bool IsLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}



bool isValidDateOfDeath(int dob, int mob, int yob, int dod, int mod, int yod)
{
    if (yod >= yob)
    {

        if (yod == yob)
        {
            if (mod >= mob)
                if (mod == mob)
                {
                    if (dod >= dob)
                        return true;

                }

        }

    }



    return false;
}

bool IsValidYearInDate(int year)
{
    int count = 0;
    if (year > 0)
    {
        while (year > 0)
        {
            year /= 10;
            count++;
        }
        if (count == 4)
        {
            return true;
        }
        else
            return false;
    }
    return false;


}
bool  IsValidMonthInDate(int month)
{
    if (month < 1 || month > 12)
        return false;

}

bool  IsValidDayInDate(int day)
{
    if (day < 1 || day > 31)
        return false;

}


//Mainb
/*
Take today’s date (particularly the day of the week).
Calculate what was the day on 14th August 1947 (On the day Pakistan came into being).
Then ask any date and tell what was the day of the week on that day.
*/

int mainb()
{
    bool past = false;
    int dor, mor, yor, dob, mob, yob;
    string day;
    cout << "Enter a refrence date: ";
    cin >> dor >> mor >> yor;
    cout << "Enter the day on this day: ";
    cin >> day;
    cout << "Enter another date: ";
    cin >> dob >> mob >> yob;


    int temp;

    if ((yor > yob) || (yor == yob && mor > mob) || (yor == yob && mor == mob && dor > dob))
    {
        past = true;

    }


    int ageindays = ageInDays(dob, mob, yob, dor, mor, yor);
    string output = outputDay(ageindays, day, past);
    cout << output;

    return 0;
}




int ageInDays(int dob, int mob, int yob, int dor, int mor, int yor)
{
    int days = 0;
    int temp;
    if (yob > yor || (yob == yor && (mob > mor || (mob == mor && dob > dor))))
    {

        temp = dob;
        dob = dor;
        dor = temp;

        temp = mob;
        mob = mor;
        mor = temp;


        temp = yob;
        yob = yor;
        yor = temp;
    }



    while (dob != dor || mob != mor || yob != yor)
    {

        days++;
        dob++;
        if (dob > daysInAMonth(mob, yob))
        {
            dob = 1;
            mob++;
            if (mob > 12)
            {
                mob = 1;
                yob++;
            }
        }
    }


    return days;
}


string outputDay(int ageInDays, string day, bool past)
{
    string dayout;
    int rem, char1 = 0;
    int td;

    rem = ageInDays % 7;


    if (day == "Monday")
    {
        char1 = 1;
    }
    else if (day == "Tuesday")
    {
        char1 = 2;
    }
    else if (day == "Wednesday")
    {
        char1 = 3;
    }
    else if (day == "Thursday")
    {
        char1 = 4;
    }
    else if (day == "Friday")
    {
        char1 = 5;
    }
    else if (day == "Saturday")
    {
        char1 = 6;
    }
    else if (day == "Sunday")
    {
        char1 = 7;
    }



    if (past)
    {


        switch (rem)
        {
        case 0:
            return day;
            break;
        case 1:
            td = char1 + (7 - 1);
            break;
        case 2:
            td = char1 + (7 - 2);
            break;
        case 3:
            td = char1 + (7 - 3);
            break;
        case 4:
            td = char1 + (7 - 4);
            break;
        case 5:
            td = char1 + (7 - 5);
            break;
        case 6:
            td = char1 + (7 - 6);

            break;
        default:
            break;
        }
    }


    else
    {
        switch (rem)
        {
        case 0:
            return day;
            break;
        case 1:
            td = char1 + 1;
            break;
        case 2:
            td = char1 + 2;
            break;
        case 3:
            td = char1 + 3;
            break;
        case 4:
            td = char1 + 4;
            break;
        case 5:
            td = char1 + 5;
            break;
        case 6:
            td = char1 + 6;

            break;
        default:
            break;
        }

    }

    if (td > 7)
    {
        td = td % 7;
    }

    if (td == 1)
    {
        dayout = "Monday";
    }
    else if (td == 2)
    {
        dayout = "Tuesday";
    }
    else if (td == 3)
    {
        dayout = "Wednesday";
    }
    else if (td == 4)
    {
        dayout = "Thursday";
    }
    else if (td == 5)
    {
        dayout = "Friday";
    }
    else if (td == 6)
    {
        dayout = "Saturday";
    }
    else if (td == 7)
    {
        dayout = "Sunday";
    }
    return dayout;
}