#include <bits/stdc++.h>

using namespace std;

class RMS
{
private:
    string fname, lname, password, email, mobile, key;
    int SC;

public:
    void checkInfo()
    {
        string traininfo;
        ifstream in;
        in.open("trains.txt");
        while (!in.eof())
        {
            getline(in, traininfo);
            cout << traininfo << endl;
        }
        in.close();
    }

    void createID()
    {
        cout << "\tPlease enter the mandatory details!" << endl;
        cout << "\nEnter first name - ";
        cin >> fname;
        cout << "\nEnter last name - ";
        cin >> lname;
        cout << "\nEnter mobile number - ";
        cin >> password;
        cout << "\nEnter email - ";
        cin >> email;
        cout << "\nCreate a strong password - ";
        cin >> password;

        key = email + password;
        srand(time(0));
        SC = rand();

        ofstream create;
        create.open("secure.txt", ios::app);
        create << key << endl;
        create << SC;
        create << "\n";
        create.close();

        cout << "\t\nID & Password created....." << endl;
        cout << "\t\nPlease note this secret code - " << SC << endl;
    }

    void seatAvailable(vector<pair<string, int>> v)
    {
        string t_num;
        cout << "\n\tEnter Train number - ";
        cin >> t_num;
        for (auto it : v)
        {
            if (it.first == t_num)
            {
                cout << "\n\tAvailable seats for train number " << it.first << " is " << it.second << endl;

                return;
            }
        }
        cout << "\n\tInvalid Train number!!" << endl;
    }

    bool check()
    {
        string email, password;
        bool confirm;
        cout << "\nEnter your email - " << endl;
        cin >> email;
        cout << "\nEnter your password - " << endl;
        cin >> password;
        string key;
        string str;
        key = email + password;
        ifstream in;
        in.open("secure.txt");
        while (!in.eof())
        {
            getline(in, str);
            if (str == key)
            {
                return true;
            }
        }
        return false;
    }

    void structure(string p_name, string age, string Gen, string tN, string date, string s1, string s2, string pnr, string *N, string *A, string *G, vector<int> st, int price)
    {
        cout << "|********************************************TICKET-CONFIRMED************************************************" << endl;
        cout << "          Train NO.              Boarding               Destination              Date" << endl;
        cout << "          " << tN << "                  " << s1 << "               " << s2 << "                 " << date << endl;

        cout << "------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "                  Name                        Age                Gender    " << endl;
        cout << "                  " << N[0] << "                    " << A[0] << "                   " << G[0] << endl;
        cout << "                  " << N[1] << "                    " << A[1] << "                   " << G[1] << endl;
        cout << "                  " << N[2] << "                    " << A[2] << "                   " << G[2] << endl;
        cout << "                  " << N[3] << "                    " << A[3] << "                   " << G[3] << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "PNR NO. - " << pnr << endl;
        cout << "Price - " << price << endl;
        cout << "Coach - D1" << endl;
        cout << "Seat No. - ";

        for (auto value : st)
        {
            cout << value << " ";
        }
        cout << endl;
        cout << "(Please note!!) File Name - " << pnr << ".txt" << endl;
        cout << "|********************************************************************************************************************" << endl;
    }

    void bookTicket(vector<pair<string, int>> v1)
    {
        vector<pair<string, int>> cl;
        string Name[4];
        string age[4];
        string gender[4];
        vector<int> st;
        cl.push_back(make_pair("2S", 120));
        cl.push_back(make_pair("Sleeper", 320));
        cl.push_back(make_pair("1AC", 720));
        cl.push_back(make_pair("2AC", 560));
        string passenger_name, Age, G;
        int seat, price;
        string Class;
        string train_number;
        string date, station1, station2;
        string pnr;
        string file;
        int number;

        cout << "Enter Train Number - " << endl;
        cin >> train_number;

        cout << "How many passengers(Maximum 4) - ";
        cin >> number;
        cin.ignore();
        for (int i = 1; i <= number; i++)
        {
            cout << "\nEnter passenger number " << i << " name - " << endl;
            getline(cin, passenger_name);
            Name[i] = passenger_name;

            cout << "\nEnter passenger number " << i << " age - " << endl;
            cin >> Age;
            age[i] = Age;

            cout << "\nEnter passenger number " << i << " gender(M/F) - " << endl;
            cin >> G;
            gender[i] = G;
            cin.ignore();
        }
        cout << endl;
        for (auto it2 : cl)
        {
            cout << it2.first << " " << it2.second << "/-" << endl;
        }
        cout << "\nEnter class - " << endl;
        cin >> Class;

        for (auto it3 : cl)
        {
            if (it3.first == Class)
            {
                price = number * it3.second;
            }
        }

        cout << "\nEnter boarding station - \n"
             << endl;
        cin >> station1;
        cout << "\nEnter destination station - \n"
             << endl;
        cin >> station2;
        cout << "\nEnter date of journey - \n"
             << endl;
        cin >> date;

        srand(time(0));
        pnr = "252512" + to_string(rand());
        seat = rand() % 50;

        for (int k = 0; k < number; k++)
        {
            st.push_back(seat + k);
        }
        structure(passenger_name, Age, G, train_number, date, station1, station2, pnr, Name, age, gender, st, price);

        file = pnr + ".txt";
        ofstream out;
        out.open(file, ios::app);
        out << "PNR NO. - " << pnr << endl;
        out << "Passenger Name - " << Name[0] << " " << Name[1] << " " << Name[2] << " " << Name[3] << endl;
        out << "Train No. - " << train_number << endl;
        out << "Boarding - " << station1 << endl;
        out << "Destination - " << station1 << endl;
        out << "Date of Journey - " << date << endl;
        out << "Coach NO. - D1" << endl;
        out << "Seat NO. - ";

        for (auto itr : st)
        {
            out << itr << " ";
        }
        out << "\n\n"
            << endl;
        out.close();
    }

    void checkstatus()
    {
        FILE *fle;
        string pnr, file;
        string str1, str2;
        cout << "Enter PNR number - " << endl;
        cin >> pnr;
        file = pnr + ".txt";
        ifstream in;
        in.open(file);

        if (in)
        {
            while (!in.eof())
            {
                getline(in, str1);
                cout << str1 << endl;
            }
        }
        else
        {
            cout << "File does not Exist" << endl;
        }

        in.close();
    }

    void cancel_ticket()
    {
        char pnr[20];

        int status;
        string secret;
        string str1, str2;
        cout << "Enter File name - " << endl;
        cin >> pnr;
        cout << "Enter your secret code - " << endl;
        cin >> secret;
        ifstream ch;
        ch.open("secure.txt");
        while (!ch.eof())
        {
            ch >> str1;
            if (str1 == secret)
            {
                status = remove(pnr);
                cout << "Ticket Cancelled" << endl;
                ch.close();
                exit(0);
            }
        }
        cout << "Invalid Code" << endl;
        ch.close();
    }
};

int main()
{

    vector<pair<string, int>> v1;
    v1.push_back(make_pair("12853", 50));
    v1.push_back(make_pair("12854", 100));
    v1.push_back(make_pair("12001", 100));
    v1.push_back(make_pair("12002", 100));
    v1.push_back(make_pair("12062", 100));
    v1.push_back(make_pair("12061", 100));

    RMS obj;
    int choice;
    bool cfm, cfm2;
    system("Color 70");
    cout << "\t\t|^^^^^^^^^^^^^^^^^^^WELCOME TO RAILWAY MANAGEMENT SYSTEM^^^^^^^^^^^^^^^^^^^|\n"
         << endl;
    cout << "\t1) Check Trains info" << endl;
    cout << "\t2) Create ID & Password" << endl;
    cout << "\t3) Check Seat Availability" << endl;
    cout << "\t4) Book Ticket" << endl;
    cout << "\t5) Check Ticket Status" << endl;
    cout << "\t6) Ticket Cancellation" << endl;

    cout << "\t\nPlease Enter your choice - ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\t\t*--------- HERE IS THE DETAILS ---------*\n"
             << endl;
        obj.checkInfo();
        break;

    case 2:
        obj.createID();
        break;

    case 3:
        obj.seatAvailable(v1);
        break;

    case 4:
        cfm = obj.check();

        if (cfm == true)
        {
            cout << "ID & Password verified" << endl;
            obj.bookTicket(v1);
        }
        else
        {
            cout << "Invalid ID & password!!" << endl;
        }
        break;

    case 5:
        obj.checkstatus();
        break;

    case 6:
        cfm2 = obj.check();

        if (cfm2 == true)
        {
            cout << "ID & Password verified" << endl;
        }
        else
        {
            cout << "Invalid ID & password!!" << endl;
            exit(0);
        }

        obj.cancel_ticket();

        break;

    default:
        break;
    }

    return 0;
}