#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

const string USER_DATA_FILE_PATH = "game_file.txt";
const string HIGHEST_SCORE_FILE_PATH = "Highest.txt";


class Login
{
private:
    string loginName, password;

public:
    Login() : loginName(" "), password(" ") {}

    void setId(const string &name)
    {
        loginName = name;
    }

    void setPass(const string &Pass)
    {
        password = Pass;
    }

    string getId() const
    {
        return loginName;
    }

    string getPass() const
    {
        return password;
    }
};

void shuffleQuestions(vector<tuple<string, vector<string>, char>> &questions)
{
    srand(time(0)); // Seed the random number generator with the current time
    for (size_t i = 0; i < questions.size(); ++i)
    {
        size_t j = i + rand() % (questions.size() - i);
        swap(questions[i], questions[j]);
    }
}


void loginInterface(const string &userId)
{
    system("cls");
    cout << "\t******************************************************\t" << endl;
    cout << "\t\t" << userId << "\t" << "Welcome to the Quiz Game of Group 4" << endl;
    cout << "\t******************************************************\t" << endl;
    cout << "\t\t1. Play game" << endl;
    cout << "\t\t2. Exit" << endl;
}

void game(const string &userName);
int highestScore(int newScore, const string &userName);
void displayHighestScores();
void login();

int level1()
{
    system("cls");
    vector<tuple<string, vector<string>, char>> questions = {
        {"Question: What is the result of 40x40?", {"A) 1600", "B) 800", "C) 400", "D) 200"}, 'A'},
        {"Question: What is the result of 999 - 33 - 87 - 100?", {"A) 759", "B) 789", "C) 769", "D) 779"}, 'B'},
        {"Question: What is the result of 22 + 47?", {"A) 89", "B) 77", "C) 69", "D) 91"}, 'C'},
        {"Question: What is the result of 100 * 10 + (20 - 10)?", {"A) 1010", "B) 1000", "C) 1100", "D) 1200"}, 'A'},
        {"Question: What is the result of 120 + 240 + 400 - 240 - 400 + 1?", {"A) 120", "B) 241", "C) 361", "D) 121"}, 'D'},
        {"Question: 50 times of 8 is equal to", {"A) 80", "B) 400", "C) 800", "D) 4000"}, 'B'},
        {"Question: 20+(90÷2) is equal to:", {"A) 50", "B) 55", "C) 65", "D) 75"}, 'C'},
        {"Question: Find the missing terms in multiple of 3: 3, 6, 9, __, 15", {"A) 27", "B) 9", "C) 12", "D) 26"}, 'C'},
        {"Question: What is the next prime number after 5?", {"A) 6", "B) 7", "C) 8", "D) 9"}, 'B'},
        {"Question: If we minus 712 from 1500, how much do we get?", {"A) 788", "B) 778", "C) 800", "D) 400"}, 'A'}};

    shuffleQuestions(questions); // Shuffle the questions

    int correctAns = 0, wrongAns = 0;

    cout << "\n\t**************** Welcome To Math Quiz ****************" << endl;
    cout << "\t\t:::::: Instructions ::::::" << endl;
    cout << "\n\tEnter your answers after the questions asked\n\tYou may skip questions by entering 0." << endl;

    for (const auto &q : questions)
    {
        string question = get<0>(q);
        vector<string> options = get<1>(q);
        char correctOption = get<2>(q);

        cout << "\n\t" << question << endl;
        for (const auto &option : options)
        {
            cout << "\t" << option << endl;
        }

        char userAnswer;
        cout<<"\t Ans: ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);

        if (userAnswer != '0')
        {
            if (userAnswer == correctOption)
            {
                correctAns++;
                cout << "\tCorrect Answer!" << endl;
            }
            else
            {
                wrongAns++;
                cout << "\tWrong Answer!" << endl;
                cout << "\tCorrect Answer: Option " << correctOption << endl;
            }
        }
        else
        {
            cout << "\tSkipped! Correct Answer: Option " << correctOption << endl;
        }
    }

    system("cls");
    cout << "\tTotal no. of questions asked = " << questions.size() << endl;
    cout << "\tYou have answered " << correctAns << " correctly!" << endl;
    cout << "\tYou have given " << wrongAns << " wrong answers." << endl;
    cout<<"\t\n";system("pause");

    return correctAns;
}

int level2()
{
    system("cls");
    vector<tuple<string, vector<string>, char>> questions = {
        {"Bangladesh shares land borders with only two nations. Which among the following are those two nations?", {"A) India and Bhutan", "B) India and china", "C) India and Myanmar", "D) India and Nepal"}, 'C'},
        {"In which year Bangladesh got independence from Pakistan?", {"A) 1956", "B) 1971", "C) 1970", "D) 1969"}, 'B'},
        {"The Port of Chittagong is the seaport of which one of the following nations?", {"A) India", "B) Iran", "C) Bangladesh", "D) Bhutan"}, 'C'},
        {"Question: What is the capital of France?", {"A) Berlin", "B) Madrid", "C) Paris", "D) Rome"}, 'C'},
        {"Question: Who wrote 'Hamlet'?", {"A) Charles Dickens", "B) J.K. Rowling", "C) William Shakespeare", "D) Mark Twain"}, 'C'},
        {"Question: What is the largest planet in our Solar System?", {"A) Earth", "B) Jupiter", "C) Saturn", "D) Mars"}, 'B'},
        {"Question: Which element has the chemical symbol 'O'?", {"A) Gold", "B) Silver", "C) Oxygen", "D) Hydrogen"}, 'C'},
        {"Question: In which year did the Titanic sink?", {"A) 1912", "B) 1905", "C) 1920", "D) 1898"}, 'A'},
        {"Question: What is the smallest country in the world by land area?", {"A) Monaco", "B) Vatican City", "C) Nauru", "D) San Marino"}, 'B'},
        {"Question: Who painted the Mona Lisa?", {"A) Vincent van Gogh", "B) Pablo Picasso", "C) Leonardo da Vinci", "D) Claude Monet"}, 'C'}};

    shuffleQuestions(questions); // Shuffle the questions

    int correctAns = 0, wrongAns = 0;

    cout << "\n\t**************** Welcome To GK Quiz ****************" << endl;
    cout << "\t\t:::::: Instructions ::::::" << endl;
    cout << "\n\tEnter your answers after the questions asked\n\tYou may skip questions by entering 0." << endl;

    for (const auto &q : questions)
    {
        string question = get<0>(q);
        vector<string> options = get<1>(q);
        char correctOption = get<2>(q);

        cout << "\n\t" << question << endl;
        for (const auto &option : options)
        {
            cout << "\t" << option << endl;
        }

        char userAnswer;
        cout<<"\t Ans: ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);

        if (userAnswer != '0')
        {
            if (userAnswer == correctOption)
            {
                correctAns++;
                cout << "\tCorrect Answer!" << endl;
            }
            else
            {
                wrongAns++;
                cout << "\tWrong Answer!" << endl;
                cout << "\tCorrect Answer: Option " << correctOption << endl;
            }
        }
        else
        {
            cout << "\tSkipped! Correct Answer: Option " << correctOption << endl;
        }
    }

    system("cls");
    cout << "\tTotal no. of questions asked = " << questions.size() << endl;
    cout << "\tYou have answered " << correctAns << " correctly!" << endl;
    cout << "\tYou have given " << wrongAns << " wrong answers." << endl;
    cout<<"\t\n";system("pause");

    return correctAns;
}

int level3()
{
    system("cls");
    vector<tuple<string, vector<string>, char>> questions = {
        {"Question: Who is known as the father of C++?", {"A) Bjarne Stroustrup", "B) James Gosling", "C) Dennis Ritchie", "D) Guido van Rossum"}, 'A'},
        {"Question: Which of the following is the correct syntax to print a message in C++?", {"A) Console.WriteLine('Hello World');", "B) printf('Hello World');", "C) cout << 'Hello World';", "D) print('Hello World');"}, 'C'},
        {"Question: Which of the following is not a C++ keyword?", {"A) private", "B) public", "C) protected", "D) integer"}, 'D'},
        {"Question: What is the output of the following code? \n int main() { int x = 5; cout << x++; return 0; }", {"A) 5", "B) 6", "C) Error", "D) 4"}, 'A'},
        {"Question: Which operator is used to access the members of a class in C++?", {"A) . (dot)", "B) -> (arrow)", "C) :: (scope resolution)", "D) # (hash)"}, 'B'},
        {"Question: Which of the following correctly describes the use of pointers in C++?", {"A) Pointers store the address of other variables", "B) Pointers store the value of other variables", "C) Pointers are used to store large data types", "D) Pointers are used to store boolean values"}, 'A'},
        {"Question: What is the correct syntax for a for loop in C++?", {"A) for (int i = 0; i < 10; i++) {}", "B) for (int i = 0; i < 10) {}", "C) for i in range(0, 10) {}", "D) for (i = 0; i < 10; i++) {}"}, 'A'},
        {"Question: What does the 'new' keyword do in C++?", {"A) It creates a new variable", "B) It allocates memory on the stack", "C) It allocates memory on the heap", "D) It initializes a variable to zero"}, 'C'},
        {"Question: Which of the following is used to define a constant in C++?", {"A) #define", "B) const", "C) final", "D) static"}, 'B'}
        };

    shuffleQuestions(questions); // Shuffle the questions

    int correctAns = 0, wrongAns = 0;

    cout << "\n\t**************** Welcome To C++ Quiz ****************" << endl;
    cout << "\t\t:::::: Instructions ::::::" << endl;
    cout << "\n\tEnter your answers after the questions asked\n\tYou may skip questions by entering 0." << endl;

    for (const auto &q : questions)
    {
        string question = get<0>(q);
        vector<string> options = get<1>(q);
        char correctOption = get<2>(q);

        cout << "\n\t" << question << endl;
        for (const auto &option : options)
        {
            cout << "\t" << option << endl;
        }

        char userAnswer;
        cout<<"\t Ans: ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);

        if (userAnswer != '0')
        {
            if (userAnswer == correctOption)
            {
                correctAns++;
                cout << "\tCorrect Answer!" << endl;
            }
            else
            {
                wrongAns++;
                cout << "\tWrong Answer!" << endl;
                cout << "\tCorrect Answer: Option " << correctOption << endl;
            }
        }
        else
        {
            cout << "\tSkipped! Correct Answer: Option " << correctOption << endl;
        }
    }

    system("cls");
    cout << "\tTotal no. of questions asked = " << questions.size() << endl;
    cout << "\tYou have answered " << correctAns << " correctly!" << endl;
    cout << "\tYou have given " << wrongAns << " wrong answers." << endl;
    cout<<"\t\n";system("pause");

    return correctAns;
}

void registration(Login &log)
{
    system("cls");

    string name, pass;
    cout << "\t******************************************************" << endl;
    cout << "\t******************** Registration ********************" << endl;
    char op ;
    cout<<"\n\tAlready Registared? Press Y to logIn N to Registar"<<endl;
    cin>>op;
    if(op == 'y')
    {
        login();
        return;
    }
    system("cls");

    cout << "\t******************************************************" << endl;
    cout << "\t******************** Registration ********************" << endl;
    cout << "\n\n\t\tEnter User name: ";
    cin >> name;
    log.setId(name);

    while (true)
    {
        cout << "\t\tEnter a strong password: ";
        cin >> pass;
        if (pass.length() >= 6)
        {
            log.setPass(pass);
            break;
        }
        else
        {
            cout << "\n\t\tEnter Minimum 6 digit password." << endl;
        }
    }

    ofstream outfile(USER_DATA_FILE_PATH, ios::app);
    if (!outfile)
    {
        cout << "\t\tFile can not open!" << endl;
    }
    else
    {
        outfile << log.getId() << " " << log.getPass() << endl;
        cout << "\t\tRegistration is in process";
        for (int i = 0; i < 3; i++)
        {
            Sleep(1000);
            cout << ".";
        }
    }

    outfile.close();
    system("cls");
    cout << "\t******************************************************" << endl;
    cout << "\t\tUser Registered Successfully\n\n\n";
    cout << "\t******************************************************" << endl;
    system("pause");
}

void game(const string &userName)
{
    bool exit = false;
    while (!exit)
    {
        int score = 0;

        score += level1();
        if (score >= 5)
        {
            system("cls");
            cout << "\t******************************************************" << endl;
            cout << "\t******* Congratulations You have passed The math quiz ******" << endl;
            system("pause");
            score += level2();
        }
        if (score >= 10)
        {
            system("cls");
            cout << "\t******************************************************" << endl;
            cout << "\t******* Congratulations You have passed GK quiz ******" << endl;
            system("pause");
            score += level3();
        }


        char choice;
        system("cls");
        cout << "\t******************************************************" << endl;
        cout<< "\tHurreh!! You have completed the quize game with a score: "<<score<<endl;
        cout << "\n\t\tDo you want to play again? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);

        if (choice != 'Y')
        {
            exit = true;
        }

        highestScore(score, userName);
    }
}

void login()
{
    bool retry = true;
    while (retry)
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
            return;
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
                    infile.close();
                    loginInterface(userId);
                    
                    int op;
                    while (true)
                    {
                        cout << "\t\tEnter choice: ";
                        cin >> op;
                        if (op == 1)
                        {
                            game(userId);
                            break;
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
                        else
                        {
                            cout << "\t\tInvalid choice. Please try again." << endl;
                        }
                    }
                    system("cls");
                    retry = false;
                    break;
                }
            }
            if (!found)
            {
                cout << "\t\tError: Incorrect login Id or Password" << endl;
                cout << "\t\tDo you want to try again? (y/n): ";
                char choice;
                cin >> choice;
                if (tolower(choice) != 'y')
                {
                    retry = false;
                }
            }
        }
        infile.close();
    }
}


int highestScore(int newScore, const string &userName)
{
    ifstream infile(HIGHEST_SCORE_FILE_PATH);
    ofstream outfile;
    unordered_map<string, int> scoreMap;
    string name;
    int score;
    bool found = false;

    // Read the current highest scores into a map
    if (infile.is_open())
    {
        while (infile >> name >> score)
        {
            scoreMap[name] = score;
        }
        infile.close();
    }

    // Check if the user already has a score
    if (scoreMap.find(userName) != scoreMap.end())
    {
        // Update the score if the new score is higher
        if (newScore > scoreMap[userName])
        {
            scoreMap[userName] = newScore;
            found = true;
        }
    }
    else
    {
        // Add the new user and score
        scoreMap[userName] = newScore;
        found = true;
    }

    // Write the updated scores back to the file only if there are changes
    if (found)
    {
        outfile.open(HIGHEST_SCORE_FILE_PATH);
        if (outfile.is_open())
        {
            for (const auto &entry : scoreMap)
            {
                outfile << entry.first << " " << entry.second << std::endl;
            }
            outfile.close();
        }
        else
        {
            std::cerr << "Error: Cannot open highest score file for writing!" << std::endl;
        }
    }

    return newScore;
}

void displayHighestScores()
{
    system("cls");
    cout << "\t******************************************************" << endl;
    cout << "\t******************* Highest Scores *******************" << endl;

    ifstream infile(HIGHEST_SCORE_FILE_PATH);
    if (!infile)
    {
        cout << "\t\tError: Cannot open highest score file!" << endl;
        return;
    }

    string name;
    int score;
    while (infile >> name >> score)
    {
        cout << "\t\t" << name << ": " << score << endl;
    }
    infile.close();

    cout << "\t******************************************************" << endl;
    system("pause");
}

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
                                                                FOREGROUND_GREEN |
                                                                FOREGROUND_INTENSITY |
                                                                BACKGROUND_RED);

    Login log;
    bool exit = false;

    while (!exit)
    {
        system("cls");

        time_t now = time(0);
        char *dt = ctime(&now);





        cout << "\t******************************************************" << endl;
        cout << "\t      Local Date and Time: " << dt << endl;
        cout << "\t******************************************************" << endl;
        cout << "\t\tWelcome to Quiz game Made by Group 4\t" << endl;
        cout << "\t******************************************************" << endl;
        cout << "\t\t1. Register\t" << endl;
        cout << "\t\t2. Log In\t" << endl;
        cout << "\t\t3. Show Highest Scores\t" << endl;
        cout << "\t\t4. Exit\t" << endl;





        int val;
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
            displayHighestScores();
        }
        else if (val == 4)
        {
            system("cls");
            exit = true;
            cout << "\t\tGood Bye. Hope you enjoyed it!" << endl;
            Sleep(3000);
        }
    }

    return 0;
}
