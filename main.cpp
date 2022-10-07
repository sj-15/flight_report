#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <cmath>
using namespace std;
class Date
{
public:
    int dayOfMonth;
    int monthOfYear;
    int year;
};
class FlightOperation
{
public:
    string flightType;
    string arrivalDeparture;
    string domesticIntl;
    int flightOpsCount;
    Date date;
};
int total_flights = 0;
vector<FlightOperation> flight_details;

void read_record()
{
    fstream fin;
    fin.open("data.csv", ios::in);
    vector<string> row;
    string word, line;
    int i = 0;
    while (getline(fin, line))
    {
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        flight_details.push_back({row[3], row[4], row[5], stoi(row[6]), stoi(row[0]), stoi(row[1]), stoi(row[2])});
        total_flights += stoll(row[6]);
        row.clear();
    }
    fin.close();
}



void calculate(int val)
{
    cout << val << '/' << total_flights << " (" << fixed << setprecision(1) << (val * 100 * 0.1f) / (total_flights * 0.1f) << "%)\n";
}

int main()
{
    read_record();
    int choice;
    cout << "Welcome to the Larv Flight Operations Data Analysis Program. Please make a selection from the menu options below regarding the information you would like to see:\n\n";

    cout << "\t1. Percentage and count of Arrival vs Departure flights.\n"
         << "\t2. Percentage and count of Domestic vs International flights.\n"
         << "\t3. Percentage and count of Charter vs Scheduled flights.\n"
         << "\t4. Split of flights by above criteria for a specified date.\n"
         << "\t5. Percentage and count of International Scheduled Departures.\n"
         << "\t6. Percentage and count of Domestical Charter Arrivals.\n"
         << "\t7. Exit the program.\n\n"

         << "Please enter your choice:  ";

    cin >> choice;
    int x, y;
    switch (choice)
    {
    case 1:
        system("cls");
        x = 0;
        y = 0;
        for (auto it : flight_details)
        {
            if (it.arrivalDeparture == "Arrival")
            {
                x += it.flightOpsCount;
            }
            else if (it.arrivalDeparture == "Departure")
            {
                y += it.flightOpsCount;
            }
        }
        cout << "Departure Flights: ";
        calculate(y);
        cout << "Arrival Flights: ";
        calculate(x);
        break;
    case 2:
        system("cls");
        x = 0;
        y = 0;
        for (auto it : flight_details)
        {
            if (it.domesticIntl == "Domestic")
            {
                x += it.flightOpsCount;
            }
            else if (it.domesticIntl == "International")
            {
                y += it.flightOpsCount;
            }
        }
        cout << "Domestic Flights: ";
        calculate(x);
        cout << "International Flights: ";
        calculate(y);
        break;
    case 3:
        system("cls");
        x = 0;
        y = 0;
        for (auto it : flight_details)
        {
            if (it.flightType == "Charter")
            {
                x += it.flightOpsCount;
            }
            else if (it.flightType == "Scheduled")
                y += it.flightOpsCount;
        }

        cout << "Charter Flights: ";
        calculate(x);
        cout << "Scheduled Flights: ";
        calculate(y);
        break;
    case 4:
        system("cls");
        int d, m, ye;
        cout << "Enter a Day: ";
        cin >> d;
        cout << "\nEnter a Month: ";
        cin >> m;
        cout << "\nEnter a Year: ";
        cin >> ye;
        x = 0;
        y = 0;
        for (auto it : flight_details)
        {
            if (it.date.dayOfMonth == d && it.date.monthOfYear == m && it.date.year == ye)
            {
                if (it.arrivalDeparture == "Arrival")
                {
                    x += it.flightOpsCount;
                }
                else if (it.arrivalDeparture == "Departure")
                {
                    y += it.flightOpsCount;
                }
            }
        }
        cout << "Departure Flights: ";
        calculate(y);
        cout << "Arrival Flights: ";
        calculate(x);
        cout << "\n";
        x = 0;
        y = 0;
        for (auto it : flight_details)
        {
            if (it.date.dayOfMonth == d && it.date.monthOfYear == m && it.date.year == ye)
            {
                if (it.domesticIntl == "Domestic")
                {
                    x += it.flightOpsCount;
                }
                else if (it.domesticIntl == "International")
                {
                    y += it.flightOpsCount;
                }
            }
        }
        cout << "Domestic Flights: ";
        calculate(x);
        cout << "International Flights: ";
        calculate(y);
        cout << "\n";
        x = 0;
        y = 0;
        for (auto it : flight_details)
        {
            if (it.date.dayOfMonth == d && it.date.monthOfYear == m && it.date.year == ye)
            {
                if (it.flightType == "Charter")
                {
                    x += it.flightOpsCount;
                }
                else if (it.flightType == "Scheduled")
                {
                    y += it.flightOpsCount;
                }
            }
        }
        cout << "Charter Flights: ";
        calculate(x);
        cout << "Scheduled Flights: ";
        calculate(y);
        break;
    case 5:
        system("cls");
        x = 0;
        for (auto it : flight_details)
        {
            if (it.arrivalDeparture == "Departure" && it.domesticIntl == "International" && it.flightType == "Scheduled")
                x += it.flightOpsCount;
        }
        cout << "International Scheduled Departures: ";
        calculate(x);
        break;
    case 6:
        system("cls");
        x = 0;
        for (auto it : flight_details)
        {
            if (it.flightType == "Charter" && it.domesticIntl == "Domestic" && it.arrivalDeparture == "Arrival")
            {
                x += it.flightOpsCount;
            }
        }
        cout << "Domestical Charter Arrivals: ";
        calculate(x);
        break;
    case 7:
        exit(0);
    }
}