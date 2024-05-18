#include <bits\stdc++.h>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <cstdlib>

using namespace std;

const string USER_DATA_FILE_PATH = "game_file.txt";
const string Highest_score_data = "Highest.txt";

void exitProgram(int status)
{
    cout << "Exiting the Program" << status << endl;
    exit(status);
}

class Login
{
private:
    string loginNmae, password;

public:
    Login() : loginNmae(" "), password(" ") {}

    void setId(string name)
    {
        loginNmae = name;
    }

    void setPass(string Pass)
    {
        password = Pass;
    }

    string getId()
    {
        return loginNmae;
    }

    string getPass()
    {
        return password;
    }
};

// Forward declaration of the game function
void game();

void easyMath()
{
    system("cls");
    int ans[5], skipCount = 0, ansCount = 0, correctAns = 0;
    int answer[5] = {1600, 779, 69, 1010, 121};
    string ques[5] = {
        "Q1) 40x40=___?", "Q2) 999-33-87-100=___?", "Q3) What is 22+47?",
        "Q4) 100*10+(20-10)=___?", "Q5) 120+240+400-240-400+1=___?"};

    cout << "\n**************** Welcome To Math Quize ****************" << endl;
    cout << "\t\t:::::: Instructions ::::::" << endl;
    cout << "Enter your asnwers after the questions asked\nYou may skip questions by entering 0." << endl;

tryagain:
    for (int i = 0; i < 5; i++)
    {
        cout << ques[i] << endl;
        cin >> ans[i];
        if (ans[i] != 0)
        {
            ansCount++;
            if (ans[i] == answer[i])
            {
                correctAns++;
                cout << "Correct Answer!" << endl;
            }
            else
            {
                cout << "Wrong Answer!" << endl;
                cout << "Answer = " << answer[i] << endl;
            }
        }
        else
        {
            skipCount++;
            cout << "Answer = " << answer[i] << endl;
        }
    }
    if (correctAns >= 3)
    {
        system("cls");
        cout << "       Congratulations! You have completed this level.\n"
             << endl;
        cout << "Total no. of questions asked = 5." << endl;
        cout << "You have answered " << correctAns << " correctly!" << endl;
        cout << "You have given " << (5 - correctAns - skipCount) << " wrong answers." << endl;
        cout << "You have skipped " << skipCount << " questions.\n"
             << endl;
    }
    else
    {
        system("cls");
        cout << "       You Failed! Try again!!!\n"
             << endl;
        cout << "Total no. of questions asked = 5." << endl;
        cout << "You have answered " << correctAns << " correctly!" << endl;
        cout << "You have given " << (5 - correctAns - skipCount) << " wrong answers." << endl;
        cout << "You have skipped " << skipCount << " questions.\n"
             << endl;
    }

    system("pause");
}

void mediumMath()
{
    system("cls");
    string ans[5];
    int skipCount = 0, ansCount = 0, correctAns = 0;
    string answer[5] = {"camel", "26", "lion", "dhaka", "7"};
    string ques[5] = {
        "Q1) Which animal is known as the 'Ship of the Desert'?", "Q2) How many letters are there in the English alphabet", "Q3) Which animal is known as the king of the jungle",
        "Q4) What is the capital of Bangladesh?", "Q5) How many continents are there in the world?"};

    cout << "\n**************** Welcome To Genarall Knowledge ****************" << endl;
    cout << "\t\t:::::: Instructions ::::::" << endl;
    cout << "Enter your asnwers after the questions asked, Answere the questions in small latter.\nYou may skip questions by entering 0." << endl;

tryagain:
    for (int i = 0; i < 5; i++)
    {
        cout << ques[i] << endl;
        cin >> ans[i];
        if (ans[i] != "0")
        {
            ansCount++;
            if (ans[i] == answer[i])
            {
                correctAns++;
                cout << "Correct Answer!" << endl;
            }
            else
            {
                cout << "Wrong Answer!" << endl;
                cout << "Answer = " << answer[i] << endl;
            }
        }
        else
        {
            skipCount++;
            cout << "Answer = " << answer[i] << endl;
        }
    }
    if (correctAns >= 3)
    {
        system("cls");
        cout << "       Congratulations! You have completed this level.\n"
             << endl;
        cout << "Total no. of questions asked = 5." << endl;
        cout << "You have answered " << correctAns << " correctly!" << endl;
        cout << "You have given " << (5 - correctAns - skipCount) << " wrong answers." << endl;
        cout << "You have skipped " << skipCount << " questions.\n"
             << endl;
    }
    else
    {
        system("cls");
        cout << "       You Failed! Try again!!!\n"
             << endl;
        cout << "Total no. of questions asked = 5." << endl;
        cout << "You have answered " << correctAns << " correctly!" << endl;
        cout << "You have given " << (5 - correctAns - skipCount) << " wrong answers." << endl;
        cout << "You have skipped " << skipCount << " questions.\n"
             << endl;
    }

    system("pause");
}

void registration(Login &log) // Pass by reference
{
    system("cls");

    string name, pass;
    cout << "\t******************************************************" << endl;
    cout << "\t******************** Registration ********************" << endl;

    cout << "\n\n\t\tEnter User name: ";
    cin >> name;
    log.setId(name);

// using start as goto stateneb
start:
    cout << "\t\tEnter a strong password: ";
    cin >> pass;
    if (pass.length() >= 6)
    {
        log.setPass(pass);
    }
    else
    {
        cout << "\n\t\tEnter Minimum 6 digit password." << endl;
        goto start;
    }
    ofstream outfile(USER_DATA_FILE_PATH, ios::app);
    if (!outfile)
    {
        cout << "\t\tFile can not open!" << endl;
    }
    else
    {
        outfile << log.getId() << " " << log.getPass() << endl;
        cout << "\t\tRegistration is on prosess";
        for (int i = 0; i < 3; i++)
        {
            Sleep(1000);
            cout << ".";
        }
    }
    system("cls");
    outfile.close();
    cout << "\t******************************************************" << endl;
    cout << "\t\tUser Registered Successfully\n\n\n";
    cout << "\t******************************************************" << endl;
    system("pause");
}

void login()
{
    system("cls");

    string name, pass;
    cout << "\t******************************************************" << endl;
    cout << "\t*********************** Log in ***********************" << endl;

    cout << "\n\t\tEnter User Name: ";
    cin >> name;

    cout << "\t\tEnter Password: ";
    cin >> pass;

    ifstream infile(USER_DATA_FILE_PATH);

    if (!infile)
    {
        cout << "\t\tError: File can't open!" << endl;
    }
    else
    {
        string userId, userPass;
        bool found = false;

        while (infile >> userId >> userPass)
        {
            if (name == userId && pass == userPass)
            {
                found = true;
                cout << "\t\tPlease Wait";
                for (int i = 0; i < 3; i++)
                {
                    cout << ".";
                    Sleep(300);
                }
                system("cls");
                cout << "\t******************************************************\t" << endl;
                cout << "\t\t" << userId << "Welcome to the Quiz Game of Group 4" << endl;
                cout << "\t******************************************************\t" << endl;
                // Sleep(3000);
                int op;
                bool exit = false;
                bool shouldexit = true;
                cout << "\t\t1.play game" << endl;
                cout << "\t\t2.Exit" << endl;
                cout << "\t\tEnter choice: ";
                cin >> op; // Capture the user's choice
                if (op == 1)
                {
                    system("cls");
                    game(); // Call the game function
                }
                else if (op == 2)
                {
                    system("cls");
                    Sleep(300);
                    cout << "Please Wait";
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ".";
                        Sleep(300);
                    }
                    return;
                }
                system("cls");
            }
        }
        if (!found)
        {
            cout << "\t\tError: Incorrect login Id or Password" << endl;
        }
    }
    infile.close();
}

void game()
{
    bool exit = false;
    while (!exit)
    {
        int level;
        char ch;

    lvl:
        system("cls");
        cout << "\t\t************************************************************************" << endl;
        cout << "\t\t**********  Choose your level of playing the game!!  *******************" << endl;
        cout << "\t\t************************************************************************" << endl;
        cout << "\n\t1)Easy \n\n\t 2)Medium \n\n\t 3)Main menu\n"
             << endl;
        cin >> level;
        if (level == 1)
        {
            cout << "************************************************************************" << endl;
            cout << "************************ Easy Level Quiz ************************" << endl;
            cout << "************************************************************************" << endl;
            Sleep(400);
            cout << "Please Wait";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                Sleep(400);
            }
            easyMath();
        }
        else if (level == 2)
        {
            cout << "************************************************************************" << endl;
            cout << "************************ Medium Level Quiz ************************" << endl;
            cout << "************************************************************************" << endl;
            Sleep(400);
            cout << "Please Wait";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                Sleep(400);
            }
            mediumMath();
        }
        else if (level == 3)
        {
            system("cls");
            Sleep(400);
            cout << "Returning to Main menu";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                Sleep(400);
            }
            exit = true;
        }
        else
        {
            cout << "You have entered an invalid input. Please choose again!!" << endl;
            goto lvl;
        }

        cout << endl;
    }
}

int main()
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
                                                                 FOREGROUND_GREEN |
                                                                 FOREGROUND_INTENSITY |
                                                                 BACKGROUND_BLUE);

    Login log;

    bool exit = false;
    while (!exit)
    {
        // clear terminal
        system("cls");
        // current date/time based on current system
        time_t now = time(0);

        // convert now to string form
        char *dt = ctime(&now);

        cout << "\t******************************************************" << endl;
        cout << "\t      Local Date and Time: " << dt << endl
             << endl;

        int val;
        cout << "\t******************************************************\t" << endl;
        cout << "\t\tWelcome to Quiz game Made by Group 4\t" << endl;
        cout << "\t******************************************************\t" << endl;
        cout << "\t\t1.Register\t" << endl;
        cout << "\t\t2.Log In\t" << endl;
        cout << "\t\t3.Exit\t" << endl;

        cout << "\t\tEnter Choice: ";
        cin >> val;
        if (val == 1)
        {
            registration(log);
        }
        else if (val == 2)
        {
            login();
        }
        else if (val == 3)
        {
            system("cls");
            exit = true;
            cout << "\t\tGood Bye. Hope you enjoyed it!" << endl;
            Sleep(3000);
        }
    }

    return 0;
}
