#include <iostream>
#include <string>

using namespace std;

// declerations
char choice;
long long int rolenumber;
int i = 0, totalStudents = 0;

string studentname[2000];
int rollno[9999] = {};
float semestergpa[9999];
string regNO[9999];

string father[9999];
long int studentphone[9999];
int studentpassword[9999];

// courses
float phy_gpa[9999];
float bio_gpa[9999];
float chem_gpa[9999];
float math_gpa[9999];
float eng_gpa[9999];

float cgpa[9999];

void add_members()
{
    // do loop to make sure the the project never ends so data remains stored
    do
    {
        cout << "\nEnter 4-digit Roll Number: ";
        cin >> rolenumber;
       

            // check if the student already exists in database or not
            if (rollno[rolenumber] == rolenumber)
            {
                cout << "\nStudent Details:\n";
                cout << "Name: " << studentname[rolenumber] << "\n"
                     << "Registration Number: " << regNO[rolenumber] << "\n"
                     << "Physics GPA: " << phy_gpa[rolenumber] << "\n"
                     << "Chemistry GPA: " << chem_gpa[rolenumber] << "\n"
                     << "Biology GPA: " << bio_gpa[rolenumber] << "\n"
                     << "Mathematics GPA: " << math_gpa[rolenumber] << "\n"
                     << "English GPA: " << eng_gpa[rolenumber] << "\n"
                     << "Semister GPA: " << cgpa[rolenumber] << "\n"
                     << "Father Name: " << father[rolenumber] << "\n"
                     << "Phone Number: " << studentphone[rolenumber] << "\n"
                     << "Password: " << studentpassword[rolenumber] << "\n";
            }
            // if student not found
            else
            {
                // getting data 
                cout << "\nEnter details for student " << rolenumber << ":\n";
                cout << "Enter Name: ";
                cin.ignore();  // remove garbage value


                // storing data in arrays
                getline(cin, studentname[rolenumber]);

                cout << "Enter Registration Number: ";
                cin >> regNO[rolenumber];

                cout << "Enter Physics GPA: ";
                cin >> phy_gpa[rolenumber];

                cout << "Enter Chemistry GPA: ";
                cin >> chem_gpa[rolenumber];

                cout << "Enter Biology GPA: ";
                cin >> bio_gpa[rolenumber];

                cout << "Enter Mathematics GPA: ";
                cin >> math_gpa[rolenumber];

                cout << "Enter English GPA: ";
                cin >> eng_gpa[rolenumber];

                cout << "Enter Father Name: ";
                cin.ignore(); // remove garbage value
                getline(cin, father[rolenumber]);

                cout << "Enter Phone Number: ";
                cin >> studentphone[rolenumber];

                cout << "Enter Password 4 digit: ";
                cin >> studentpassword[rolenumber];
            
            
            // displaying the end results
            cout << "\nStudent Details Added:\n";
            cout << "Name: " << studentname[rolenumber] << "\n"
                 << "Registration Number: " << regNO[rolenumber] << "\n"
                 << "Physics GPA: " << phy_gpa[rolenumber] << "\n"
                 << "Chemistry GPA: " << chem_gpa[rolenumber] << "\n"
                 << "Biology GPA: " << bio_gpa[rolenumber] << "\n"
                 << "Mathematics GPA: " << math_gpa[rolenumber] << "\n"
                 << "English GPA: " << eng_gpa[rolenumber] << "\n"
                 << "SGPA: " << cgpa[rolenumber] << "\n"
                 << "Semister GPA: " << cgpa[rolenumber] << "\n"
                 << "Father Name: " << father[rolenumber] << "\n"
                 << "Phone Number: " << studentphone[rolenumber] << "\n"
                 << "Password: " << studentpassword[rolenumber] << "\n";

            i++;
            totalStudents++;
            }

        cout << "\nPress 'Y' to add another student or 'N' to return to main menu: ";
        cin >> choice;
        rollno[rolenumber] = rolenumber;

    } while (choice == 'y' || choice == 'Y');
    cout << "Thank you \n";
}

int main()
{
    // calling the function
    add_members();

    return 0;
}
