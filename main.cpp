#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
using namespace std;

void ReadTextFile()
{
    system("cls");

    ifstream f("ideas.txt");

    if (!f.is_open())
    {
        cerr << "Error opening up ideas.txt ..." << std::endl;
    }

    string s;
    int counter = 0;

    while (getline(f, s))
    {
        counter++;
        std::cout << "[" << counter << "] " << s << std::endl;
    }

    f.close();
}

void AddIdem()
{
    string projectIdea;

    system("cls");
    cout << "Please enter a project idea: ";

    getline(cin, projectIdea); // have to use a dummy line
    getline(cin, projectIdea); // it keeps reading an old value i hate cin

    ofstream outfile;

    outfile.open("ideas.txt", ios_base::app);
    outfile << projectIdea << endl;

    cout << "" << std::endl;
    cout << "Successfully appended to the ideas file!" << std::endl;
    cout << "" << std::endl;
    cout << "Press enter to return to the menu..." << std::endl;
}

void RemoveItem()
{
    int RemoveLine;
    string line;
    
    system("cls");
    cout << "Please enter a project idea number you wish to delete: ";

    cin >> RemoveLine;
    cout << RemoveLine << endl;

    ifstream file;
    file.open("ideas.txt");
    ofstream temp;
    temp.open("temp.txt");

    int line_number = 0;

    while ( getline(file, line) )
    {
        line_number++;

        if (line_number != RemoveLine)
        {
            temp << line << endl;
        }
    }

    temp.close();
    file.close();

    remove("ideas.txt");
    rename("temp.txt", "ideas.txt");


    this_thread::sleep_for(750ms);
    cout.flush();

    cout << "" << std::endl;
    cout << "Successfully removed the idea!" << std::endl;
    cout << "" << std::endl;
    cout << "Press enter to return to the menu..." << std::endl;
}

void HandleInterface()
{
    int input;

    cout << "Welcome to my first C++ based project, a code idea organizer. This project was developed entirely by th_remain, all credit to me. I've learned so much through just this tiny project, and hope to continue advancing my programming skills." << std::endl
         << std::endl;

    cout << "[1] View Project List" << std::endl;
    cout << "[2] Add To Project List" << std::endl;
    cout << "[3] Remove From Project List" << std::endl;
    cout << "[4] Close Project List" << std::endl
         << std::endl;

    cin >> input;
    cout << "" << std::endl;

    switch (input)
    {
    case 1:
        ReadTextFile();

        cout << "" << std::endl;
        cout << "Press enter to continune..." << std::endl;

        getch();
        system("cls");
        HandleInterface();
    case 2:

        AddIdem();

        getch();
        system("cls");
        HandleInterface();
    case 3:
        RemoveItem();

        getch();
        system("cls");
        HandleInterface();
    case 4:
        exit(0);
    }
}

int main()
{
    HandleInterface();

    return 0;
}
