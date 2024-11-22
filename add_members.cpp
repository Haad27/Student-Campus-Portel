#include <iostream>
#include <string>

using namespace std;

// declerations
char choice;
bool repeat;
bool isintvalid;
long long int rolenumber;
int i = 0, totalStudents = 0;

string studentname[10000];
int rollno[10000] = {};
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

void intCheck(){
    if(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<">>> Please Enter valid input <<<"<<endl;
        isintvalid=false;
        repeat=true;
    }
    else{isintvalid=true;}
}



void add_members()
{
    // do loop to make sure the the project never ends so data remains stored
    do
    {   
        cout << "\nEnter Roll Number (1-10000): ";
        cin >> rolenumber;
        intCheck(); //to check if integer or not
        if(isintvalid==false){
            continue;
        }
        if(rolenumber>=1 && rolenumber<10000){

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
                    cout << "Enter Password 4 digit: ";
                    cin >> studentpassword[rolenumber];
                    intCheck(); //to check if integer or not
                    if(isintvalid==false){
                        continue;
                    }

                    rollno[rolenumber] = rolenumber;

                    // getting data 
                    cout << "\nEnter details for student " << rolenumber << ":\n";
                    cout << "Enter Name: ";

                    cin.ignore();  // remove garbage value
                    // storing data in arrays
                    getline(cin, studentname[rolenumber]);

                    cout << "Enter Registration Number: ";
                    cin >> regNO[rolenumber];
                    
                    cout << "Enter Father Name: ";
                    cin.ignore(); // remove garbage value
                    getline(cin, father[rolenumber]);

                    cout << "Enter Phone Number: ";
                    cin >> studentphone[rolenumber];

                    do{
                    cout << "Enter Physics GPA: ";
                    cin >> phy_gpa[rolenumber];
                    intCheck(); //to check if integer or not
                    if(isintvalid==false){
                        continue;
                    }

                    cout << "Enter Chemistry GPA: ";
                    cin >> chem_gpa[rolenumber];
                    intCheck(); //to check if integer or not
                    if(isintvalid==false){
                        continue;
                    }

                    cout << "Enter Biology GPA: ";
                    cin >> bio_gpa[rolenumber];
                    intCheck(); //to check if integer or not
                    if(isintvalid==false){
                        continue;
                    }

                    cout << "Enter Mathematics GPA: ";
                    cin >> math_gpa[rolenumber];
                    intCheck(); //to check if integer or not
                    if(isintvalid==false){
                        continue;
                    }

                    cout << "Enter English GPA: ";
                    cin >> eng_gpa[rolenumber];
                    intCheck(); //to check if integer or not
                    if(isintvalid==false){
                        continue;
                    }

                    repeat=false;
                    }while(repeat!=false);


                
                
                // displaying the end results
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

                i++;
                totalStudents++;
                }

            cout << "\nPress 'Y' to add another student or 'Press any key' to return to main menu: ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                repeat=true;
            }
            else{repeat=false;}
        }
        else{
            cout<<"Role number out of range.Please enter again"<<endl;
            repeat=true;
        }

    } while (repeat==true);
    cout << "Thank you \n";
}

int main()
{
    // calling the function
    add_members();

    return 0;
}
