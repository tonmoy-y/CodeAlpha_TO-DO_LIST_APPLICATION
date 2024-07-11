#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

vector<string> tasks;
vector<string> complete;
int in = -1;
int c = -1;

void write_task();
void task();
void fromFile();
void toFile();
void history();
void screenClear();
void markCom();
void completed();

// ###################### insert from file ##########################
void fromFile()
{
    ifstream inputFile("task.txt");
    ifstream inputFil("completed.txt");

    string line;
    string com;

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            tasks.push_back(line);
            ++in;
        }
        while (getline(inputFil, com))
        {
            complete.push_back(com);
            ++c;
        }
        inputFile.close();
        inputFil.close();
    }
    else
    {
        cerr << "Unable to load the task" << endl;
    }
}

// ########################insert to file #############################
void toFile()
{
    ofstream outputFile("task.txt");
    ofstream outputFil("completed.txt");

    if (outputFile.is_open())
    {
        for (const string &line : tasks)
        {
            outputFile << line << '\n';
        }
        for (const string &lin : complete)
        {
            outputFil << lin << '\n';
        }
        outputFile.close();
        outputFil.close();
    }
    else
    {
        cerr << "Unable to save change" << endl;
    }
}

// ################ Clearing the screen #######################
void screenClear()
{
    cout << "\n\nPress any key go to main menu....." << endl;
    getch();
    system("cls");
}

// ################### Deletilng completed task #######################
void history()
{
    cout << "Do you want to delete all completed task? (yes/no)\n";
    string s;
    cin >> s;
    for (char &c : s)
    {
        c = tolower(c);
    }
    if (s == "yes" or s == "y" or s == "ye")
    {
        complete.clear();
        complete.shrink_to_fit();
        c = -1;
        cout << "\nSuccessfully deleted all completed task";
    }
}

// ####################### completed task ############################
void completed()
{
    cout << "Here is your completed tasks: ";

    if (c < 0)
        cout << "Empty\n";
    else
        for (int i = 0; i <= c; i++)
        {
            cout << "\n\t\t"
                 << i + 1 << ". " << complete[i];
        }
}

// ####################### mark task as completed ##########################
void markCom()
{
    int num;
    do
    {
        task();
        cout << "\nEnter the task number you want to mark as completed: ";

        cin >> num;
        if (num - 1 > in)
            cout << "Invalid choice. Enter number that showing in terminal....\n\nTry again......\n\n";
    } while (num - 1 > in);

    complete.push_back(tasks[num - 1]);
    tasks.erase(tasks.begin() + num - 1);
    c++;
    --in;
    cout << "\n\n"
         << num << " number task completed successfully";
}

// ########################## Add task ########################
void addTask()
{
    cout << "Enter the task you want to add: \n\t\t";
    cin.ignore();
    write_task();
}

// ############################ write task #########################
void write_task()
{

    string st;
    getline(cin, st);
    in++;
    // tasks[in] = st;/
    tasks.push_back(st);

    cout << "\n\nTask added successfully";
}

// ################################## Show Tasks ############################
void task()
{
    cout << "Your current tasks are: ";
    if (in < 0)
        cout << "Empty\n";
    else
        for (int i = 0; i <= in; i++)
        {
            cout << "\n\t\t" << i + 1 << ". " << tasks[i];
        }
}

/*#######################  Main Menu    ##############################*/
int main_menu()
{
    cout << "----------- To Do List -----------\n";
    cout << "\n";
    cout << "\t\t1. View tasks\n";
    cout << "\t\t2. Add task\n";
    cout << "\t\t3. Mark task as completed\n";
    cout << "\t\t4. Show completed task\n";
    cout << "\t\t5. Delete completed tasks\n";
    cout << "\t\t6. Exit\n";
    cout << "\nEnter your choice (1-6) : ";
    int num;
    cin >> num;
    return num;
}

int main()
{
    fromFile();
    for (;;)
    {
        int a = main_menu();
        system("cls");
        switch (a)
        {
        case 1:
            task();
            screenClear();
            break;
        case 2:
            addTask();
            screenClear();
            break;
        case 3:
            markCom();
            screenClear();
            break;
        case 4:
            completed();
            screenClear();
            break;
        case 5:
            history();
            screenClear();
            break;
        case 6:
            toFile();
            exit(1);
        default:
            cout << "Enter a valid number\n";
        }
    }

    return 0;
}