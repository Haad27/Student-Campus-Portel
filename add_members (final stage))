#include <iostream>
#include "scedule.cpp"
#include <string>

using namespace std;

// declerations
char choice;
bool repeat;
bool isintvalid;
bool isphonevalid;
bool isstringvalid;
long long int rolenumber;
int i = 0, totalStudents = 0;

string studentname[10000];
int rollno[10000];
float semestergpa[10000];
string regNO[10000];

string father[10000];
string studentphone[10000];
int studentpassword[10000];

// courses
float phy_gpa[10000];
float bio_gpa[10000];
float chem_gpa[10000];
float math_gpa[10000];
float eng_gpa[10000];
float cgpa[10000];

int calculateGPA(int x)
{

    float total_gpa = phy_gpa[rolenumber] * 3 +
                      chem_gpa[rolenumber] * 3 +
                      bio_gpa[rolenumber] * 3 +
                      math_gpa[rolenumber] * 3 +
                      eng_gpa[rolenumber] * 3;

    return cgpa[x] = total_gpa / 15; // Total credit hours (5 subjects × 3 credits)
}

void intCheck()
{
    // check if it is a intgeer
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << ">>> Please Enter valid input <<<" << endl;
        isintvalid = false;
    }
    else
    {
        isintvalid = true;
    }
}
void stringcheck(string &value)
{
    // check if it is a string

    bool temp;
    isstringvalid = true;
    // Check if string is empty

    if (value.empty())
    {
        isstringvalid = false;
        temp = false;
    }

    // Check each character
    for (char x : value)
    {
        if (isdigit(x))
        {
            isstringvalid = false;
            temp = false;
        }
        else
        {
            temp = true;
            repeat = true;
        }
    }
    if (temp == false)
    {
        cout << "Enter a string without numbers" << endl;
    }
}
void phonecheck(string &value)
{
    // check if it is a string but wiht only letters
    // also used from regno
    bool temp;
    isstringvalid = true;
    // Check if string is empty

    if (value.empty())
    {
        isphonevalid = false;
        temp = false;
    }

    // Check each character
    for (char x : value)
    {
        if (isdigit(x))
        {
            isphonevalid = true;
            temp = true;
        }
        else
        {
            temp = false;
            repeat = false;
        }
    }
    if (temp == false)
    {
        cout << "Enter numbers only" << endl;
    }
}

void isintvalidbool()
{
    if (isintvalid == false)
    {
        repeat = true;
    }
}
void add_members()
{
    // do loop to make sure the the project never ends so data remains stored
    do
    {
        cout << "\nEnter Roll Number (1-10000): ";
        cin >> rolenumber;
        intCheck(); // to check if integer or not
        if (isintvalid == false)
        {
            repeat = true;
            continue;
        }
        if (rolenumber >= 1 && rolenumber < 10000)
        {
            // check if the student already exists in database or not
            if (rollno[rolenumber] == rolenumber)
            {
                cout << "\nStudent Already Exists:\n";
                cout << "Name: " << studentname[rolenumber] << "\n"
                     << "Registration Number: " << regNO[rolenumber] << "\n"
                     << "Father Name: " << father[rolenumber] << "\n"
                     << "Phone Number: " << studentphone[rolenumber] << "\n"
                     << "Password: " << studentpassword[rolenumber] << "\n"
                     << "Physics GPA: " << phy_gpa[rolenumber] << "\n"
                     << "Chemistry GPA: " << chem_gpa[rolenumber] << "\n"
                     << "Biology GPA: " << bio_gpa[rolenumber] << "\n"
                     << "Mathematics GPA: " << math_gpa[rolenumber] << "\n"
                     << "English GPA: " << eng_gpa[rolenumber] << "\n"
                     << "Semester GPA: " << cgpa[rolenumber] << "\n";
            }
            // if student not found
            else
            {
                do
                {
                    cout << "Enter Password 4 digit: ";
                    cin >> studentpassword[rolenumber];
                    intCheck();
                    if (isintvalid == false)
                    {
                        repeat = true;
                        continue;
                    }
                    if (studentpassword[rolenumber] <= 999 || studentpassword[rolenumber] > 9999)
                    {
                        repeat = true;
                        continue;
                    }

                    repeat = false;
                } while (repeat != false);

                rollno[rolenumber] = rolenumber;

                // getting data
                do
                {
                    cout << "\nEnter details for student " << rolenumber << ":\n";

                    do
                    {
                        cout << "Enter Name: ";
                        cin.ignore();
                        getline(cin, studentname[rolenumber]);
                        stringcheck(studentname[rolenumber]);
                        if (isstringvalid == false)
                        {
                            repeat = true;
                            continue;
                        }
                        repeat = false;
                    } while (repeat != false);

                    do
                    {
                        cout << "Enter Registration Number: ";
                        cin >> regNO[rolenumber];
                        phonecheck(regNO[rolenumber]);
                        if (isphonevalid == false)
                        {
                            repeat = true;
                            continue;
                        }
                        repeat = false;
                    } while (repeat != false);

                    do
                    {
                        cout << "Enter Father Name: ";
                        cin.ignore();
                        getline(cin, father[rolenumber]);
                        stringcheck(father[rolenumber]);
                        if (isstringvalid == false)
                        {
                            repeat = true;
                            continue;
                        }
                        repeat = false;
                    } while (repeat != false);

                    do
                    {
                        cout << "Enter Phone Number: ";
                        cin >> studentphone[rolenumber];
                        phonecheck(studentphone[rolenumber]);
                        if (studentphone[rolenumber].size() != 11)
                        {
                            cout << "Phone number must be 11 digits" << endl;
                            repeat = true;
                            continue;
                        }
                        if (isphonevalid == false)
                        {
                            repeat = true;
                            continue;
                        }

                        repeat = false;
                    } while (repeat != false);

                    do
                    {
                        cout << "Enter Physics GPA: ";
                        cin >> phy_gpa[rolenumber];
                        intCheck();
                        if (isintvalid == false)
                        {
                            repeat = true;
                            continue;
                        }
                        if (phy_gpa[rolenumber] < 0 || phy_gpa[rolenumber] > 4)
                        {
                            repeat = true;
                            continue;
                        }
                        repeat = false;
                    } while (repeat != false);

                    do
                    {
                        cout << "Enter Chemistry GPA: ";
                        cin >> chem_gpa[rolenumber];
                        intCheck();
                        if (isintvalid == false)
                        {
                            repeat = true;
                            continue;
                        }
                        if (chem_gpa[rolenumber] < 0 || chem_gpa[rolenumber] > 4)
                        {
                            repeat = true;
                            continue;
                        }
                        repeat = false;
                    } while (repeat != false);

                    do
                    {
                        cout << "Enter Biology GPA: ";
                        cin >> bio_gpa[rolenumber];
                        intCheck();
                        if (isintvalid == false)
                        {
                            repeat = true;
                            continue;
                        }
                        if (bio_gpa[rolenumber] < 0 || bio_gpa[rolenumber] > 4)
                        {
                            repeat = true;
                            continue;
                        }
                        repeat = false;
                    } while (repeat != false);

                    do
                    {
                        cout << "Enter Mathematics GPA: ";
                        cin >> math_gpa[rolenumber];
                        intCheck();
                        if (isintvalid == false)
                        {
                            repeat = true;
                            continue;
                        }
                        if (math_gpa[rolenumber] < 0 || math_gpa[rolenumber] > 4)
                        {
                            repeat = true;
                            continue;
                        }
                        repeat = false;
                    } while (repeat != false);

                    do
                    {
                        cout << "Enter English GPA: ";
                        cin >> eng_gpa[rolenumber];
                        intCheck();
                        if (isintvalid == false)
                        {
                            repeat = true;
                            continue;
                        }
                        if (eng_gpa[rolenumber] < 0 || eng_gpa[rolenumber] > 4)
                        {
                            repeat = true;
                            continue;
                        }
                        repeat = false;
                    } while (repeat != false);

                    repeat = false;
                } while (repeat != false);
                calculateGPA(rolenumber);
                // Your existing code for displaying results...
                cout << "\nStudent Details Added:\n";
                cout << "Name: " << studentname[rolenumber] << "\n"
                     << "Registration Number: " << regNO[rolenumber] << "\n"
                     << "Father Name: " << father[rolenumber] << "\n"
                     << "Phone Number: " << studentphone[rolenumber] << "\n"
                     << "Password: " << studentpassword[rolenumber] << "\n"
                     << "Physics GPA: " << phy_gpa[rolenumber] << "\n"
                     << "Chemistry GPA: " << chem_gpa[rolenumber] << "\n"
                     << "Biology GPA: " << bio_gpa[rolenumber] << "\n"
                     << "Mathematics GPA: " << math_gpa[rolenumber] << "\n"
                     << "English GPA: " << eng_gpa[rolenumber] << "\n"
                     << "Semester GPA: " << cgpa[rolenumber] << "\n";
            }
        }
        else
        {
            cout << "Role number out of range. Please enter again" << endl;
            repeat = true;
        }
    } while (repeat == true);
}

void admin_main()
{
    while (true)
    {
        int select;
        cout << "\n=======================================\n";
        cout << "      STUDENT MANAGEMENT SYSTEM       \n";
        cout << "=======================================\n";
        cout << "\n---------------------------------------\n";
        cout << "               MAIN MENU              \n";
        cout << "---------------------------------------\n";
        cout << "1. Add Student\n";
        cout << "2. View yourself\n";
        cout << "3. View All Students\n";
        cout << "4. Remove Student\n";
        cout << "5. Change Details\n";
        cout << "6. Schedule\n";
        cout << "7. Exit\n";
        cout << "---------------------------------------\n";
        cout << "Enter your choice (1-7): ";
        cin >> select;
        intCheck();

        switch (select)
        {
        case 1:
            cout << "\n=======================================\n";
            cout << "         ADD STUDENT SECTION          \n";
            cout << "=======================================\n";
            add_members();
            break;

        case 2:
            cout << "\n=======================================\n";
            cout << "         VIEW STUDENT SECTION         \n";
            cout << "=======================================\n";
            // will be added soon
            // view_student();
            break;

        case 3:
            cout << "\n=======================================\n";
            cout << "       VIEW ALL STUDENTS SECTION      \n";
            cout << "=======================================\n";
            // will be added soon

            // view_all();
            break;

        case 4:
            cout << "\n=======================================\n";
            cout << "        REMOVE STUDENT SECTION        \n";
            cout << "=======================================\n";
            // will be added soon

            // view_student();
            break;

        case 5:
            cout << "\n=======================================\n";
            cout << "       MODIFY STUDENT SECTION         \n";
            cout << "=======================================\n";
            // will be added soon

            // changedetails();
            break;

        case 6:
            cout << "\n=======================================\n";
            cout << "          SCHEDULE SECTION            \n";
            cout << "=======================================\n";
            // will be added soon

            // main_scedule();
            // admin_main();
            break;

        case 7:
            cout << "\n=======================================\n";
            cout << "              GOODBYE!                \n";
            cout << "=======================================\n";
            cout << "Thank you for using the Student\n";
            cout << "Management System!\n";
            cout << "---------------------------------------\n";
            break;

        default:
            cout << "\n=======================================\n";
            cout << "          ERROR MESSAGE               \n";
            cout << "=======================================\n";
            cout << "Invalid input!\n";
            cout << "Please enter a number between 1 and 7.\n";
            cout << "---------------------------------------\n";
            break;
        }
    }
}

int main()
{
    admin_main();
}
