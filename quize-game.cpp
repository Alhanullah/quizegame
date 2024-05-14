#include <bits\stdc++.h>
#include <fstream>
#include <windows.h>
#include <sstream>

using namespace std;

const string USER_DATA_FILE_PATH = "game_file.txt";
const string Highest_score_data = "Highest.txt";

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
    int answer[5] = {1600, 779, 69, 120, 121};
    string ques[5] = {
        "Q1) 40x40=___?", "Q2) 999-33-87-100=___?", "Q3) What is 22+47?",
        "Q4) To stay in a hotel costs $40 per night. You stay for three nights and check out on the fourth morning. How much will you pay?", "Q5) 120+240+400-240-400+1=___?"};

    cout << "\n**************** Welcome To Level Easy ****************" << endl;
    cout << ":::::: Instructions ::::::" << endl;
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
    int ans[5], skipCount = 0, ansCount = 0, correctAns = 0;
    int answer[5] = {10, 2, 20, -989, 750};
    string ques[5] = {
        "Q1) What is 10% of 100?", "Q2) If a train leaves a station at 10 p.m., travels at 30 miles per hour and covers 120 miles, what would the time(in a.m.) be?", "Q3) What is 180/9?",
        "Q4) Subtract 999 from 10. What do you have?", "Q5) If I have a liter bottle of cola and I drink 250 ml's, how much is left?"};

    cout << "\n**************** Welcome To Level Medium ****************" << endl;
    cout << ":::::: Instructions ::::::" << endl;
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
        cout << "       Congratulations! You have completed this level.\n"
             << endl;
        cout << "Total no. of questions asked = 5." << endl;
        cout << "You have answered " << correctAns << " correctly!" << endl;
        cout << "You have given " << (5 - correctAns - skipCount) << " wrong answers." << endl;
        cout << "You have skipped " << skipCount << " questions." << endl;
    }
    else
    {
        cout << "       You Failed! Try again!!!\n"
             << endl;
        cout << "Total no. of questions asked = 5." << endl;
        cout << "You have answered " << correctAns << " correctly!" << endl;
        cout << "You have given " << (5 - correctAns - skipCount) << " wrong answers." << endl;
        cout << "You have skipped " << skipCount << " questions." << endl;
        goto tryagain;
    }
}

void hardMath()
{
    int skipCount = 0, ansCount = 0, correctAns = 0;
    double ans[5], answer[5] = {24, 2000, 2, 464.01, 5};
    string ques[5] = {
        "Q1) How many right angles does a cube have?", "Q2) 3,000-800+400-1200+600=___?", "Q3) If a skipping rope is 2 meters long, how many 100-cm pieces could I cut it into?",
        "Q4) Add the following, please: 90+33+0.01+100+241=___?", "Q5) A man must take a pill every half an hour. He starts at 10 a.m. How many pills will he have taken by 12:01 p.m.?"};

    cout << "\n**************** Welcome To Level Hard ****************" << endl;
    cout << ":::::: Instructions ::::::" << endl;
    cout << "Enter your answers after the questions asked\nYou may skip questions by entering 0." << endl;

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
        cout << "       Congratulations! You have completed this level.\n"
             << endl;
        cout << "Total no. of questions asked = 5." << endl;
        cout << "You have answered " << correctAns << " correctly!" << endl;
        cout << "You have given " << (5 - correctAns - skipCount) << " wrong answers." << endl;
        cout << "You have skipped " << skipCount << " questions." << endl;
    }
    else
    {
        cout << "       You Failed! Try again!!!\n"
             << endl;
        cout << "Total no. of questions asked = 5." << endl;
        cout << "You have answered " << correctAns << " correctly!" << endl;
        cout << "You have given " << (5 - correctAns - skipCount) << " wrong answers." << endl;
        cout << "You have skipped " << skipCount << " questions.\n"
             << endl;
        goto tryagain;
    }
}

void registration(Login &log) // Pass by reference
{
    system("cls");

    string name, pass;
    cout << "\t\tEnter User name: ";
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
        cout << "\t\tUser Registered Successfully" << endl;
    }
    outfile.close();
    Sleep(3000);
}

void login()
{
    system("cls");

    string name, pass;
    cout << "\t\tEnter User Name: ";
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
                while (!exit)
                {
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
                        exit = true;
                    }
                    system("cls");
                }
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
        cout << "Choose your level of playing the game!!" << endl;
        cout << "\t1)Easy \n\t 2)Medium \n 3)Hard \n\t 4)Main menu" << endl;
        cin >> level;
        if (level == 1)
        {
            cout << "---------------------- Easy Level Quiz ----------------------" << endl; 
            easyMath();
        }
        else if (level == 2)
        {
            cout << "---------------------- Medium Level Quiz ----------------------" << endl;
            mediumMath();
        }
        else if (level == 3)
        {
            cout << "---------------------- Hard Level Quiz ----------------------" << endl;
            hardMath();
        }
        else if (level == 4)
        {
            system("cls");
            exit = true;
            Sleep(2000);
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

        cout << "\nLocal Date and Time: " << dt << endl
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

        Sleep(3000);
    }

    return 0;
}
