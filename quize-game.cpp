#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>



using namespace std;

const string USER_DATA_FILE_PATH = "game_file.txt";


class Login
{
private:
    string loginId, password;

public:
    Login() : loginId(" "), password(" ") {}

    void setId(string id)
    {
        loginId = id;
    }

    void setPass(string Pass)
    {
        password = Pass;
    }

    string getId()
    {
        return loginId;
    }

    string getPass()
    {
        return password;
    }
};

// Forward declaration of the game function
void game();

void registration(Login& log) // Pass by reference
{
    system("cls");

    string id, pass;
    cout << "\t\tEnter Login ID: ";
    cin >> id;
    log.setId(id);

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

    string id, pass;
    cout << "\t\tEnter Login Id: ";
    cin >> id;

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
            if (id == userId && pass == userPass)
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
                cout << "\t\tWelcome to the Quiz Game of Group 4" << endl;
                cout << "\t******************************************************\t" << endl;
                int op;
                bool exit = false;
                while (!exit)
                {
                    system("cls");
                    cout << "\t\t1.play game" << endl;
                    cout << "\t\t2.Exit" << endl;
                    cout << "\t\tEnter choice: ";
                    cin >> op; // Capture the user's choice
                    if (op == 1)
                    {
                        game(); // Call the game function
                    }
                    else if (op == 2)
                    {
                        exit = true;
                    }
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
    string questions[] = {"1. What is 2+2 ?",
                          "2. What is 2+3 ?",
                          "3. What is 2+1 ?",
                          "4. What is 2+4 ?",
                          "5. What is 2+5 ?"};

    string options[][4] = {
        {"a. 4 ", "b. 1 ", "c. 0 ", "d. 5 "},
        {"a. 4 ", "b. 1 ", "c. 3 ", "d. 5 "},
        {"a. 3 ", "b. 1 ", "c. 0 ", "d. 5 "},
        {"a. 4 ", "b. 1 ", "c. 6 ", "d. 5 "},
        {"a. 4 ", "b. 7 ", "c. 0 ", "d. 5 "}};

    char answerKey[] = {'a', 'd', 'a', 'c', 'b'};

    int qSize = sizeof(questions) / sizeof(questions[0]);
    char guess; // Corrected variable name
    int score = 0; // Initialize score

    for (int i = 0; i < qSize; i++)
    {
        cout << "**********************************" << endl;
        cout << questions[i] << endl;
        cout << "**********************************" << endl;

        for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][j]); j++)
        {
            cout << options[i][j] << endl;
        }

        cin >> guess;

        if (guess == answerKey[i])
        {
            cout << "Correct" << endl;
            score++;
        }
        else
        {
            cout << "Wrong" << endl;
            cout << "Correct Answer: " << answerKey[i] << endl;
        }
    }

    cout << "**********************************" << endl;
    cout << "*              Result            *" << endl;
    cout << "**********************************" << endl;
    cout << "Correct Answers: " << score << endl;
    cout << "Number of questions: " << qSize << endl;
    cout << "Result: " << (score / (double)qSize) * 100 << " % " << endl;
    Sleep(5000);
}

int main()
{
    Login log;

    bool exit = false;
    while (!exit)
    {
        system("cls");

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
