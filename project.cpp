#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


//===========================================================================
// =============================  FUNCTIONS  ================================
//===========================================================================
void main_menu();   // a  main menu or start of prog
void student_login();  // FUNCTION FOR LOGG IN
void student_menu(int rollno);     //FUNCTION FOR PRINTING STUDENT WHOLE PROFIIE
int calculateGPA(int x);    //  calculated gpa
void intCheck();    //handles an integer input
void stringcheck(string &value);    //handles a string input
void phonecheck(string &value); //handles a string input
void add_members(); //  used to add new members
void admin_menu();  // a menu for adminintrative feartures
void view_student();    // a function to view detail of specific students
void view_all();    // a func to view a list of all students
void remove_student();  //to remove a student
void changedetails_1(); // used to change details of students
void changedetails_2(); // used to change details of students



//===========================================================================
// ============================= VARIABLES ==================================
//===========================================================================
char choice;  // for carrying various choices
bool repeat;  // a flag  for repitiion
bool isintvalid;    // flag if integr is valid or not
bool isphonevalid;   // flag if phone no is valid or not
bool isstringvalid;   // flag if string entered is valid or not
long long int rolenumber;  // carries user entered rolenumber
// ARRAYS FOR STORING STUDENT INFORMATION
int rollno[10000]={0,1,2};  // to store roll numbers
string studentname[10000]={"","Muhammad Saad","Saad Sani"}; // stores names of stundents
string father[10000]={"","saad's Father","Saad's Father"};  // stores students' fathsers names
string studentphone[10000]={"","03451234567","03451234567"}; // stores contact numbers
int studentpassword[10000]={0,4774,4774}; // stores pin for students
// ARRAYS TO STORE COURSES GPA
float cgpa[10000]={0,3.1,3.3}; // semester gpa
float phy_gpa[10000]={0,3.2,3.5};
float bio_gpa[10000]={0,3.0,3.6};
float chem_gpa[10000]={0,4.0,3.0};
float math_gpa[10000]={0,3.5,3.1};
float eng_gpa[10000]={0,3.5,3.3};





int main(){
   
    main_menu(); //THIS WILL START THE PROGRAM
    


    
    return 0;
}






//================================================================================================================================
//========================================= MAIN MENU FUNNCTION===================================================================
//================================================================================================================================
void main_menu(){
    string option;  // Variable to store the user's input as a string, allowing handling of alphabets or invalid input.
    bool repeat;  // Flag to determine whether the menu should repeat due to invalid input.

    do {
        repeat = false;  // Reset the repeat flag at the start of each loop iteration.

        // Display the main menu options.
        cout << "\n======  WELCOME TO THE CAMPUS PORTAL  ======\n\n";
        cout << "1. Run as Admin.\n2. Run as Student.\n3. End Program.\n\nChoose option: ";
        cin >> option;  // Take the user's input.

        // Check the user's input and execute the corresponding functionality.
        if (option == "1") {
            admin_menu();  // Navigate to the admin menu.
        } else if (option == "2") {
            student_login();  // Navigate to the student login.
        } else if (option == "3") {
            exit(0);  // Exit the program.
        } else {
            // Handle invalid input.
            repeat = true;  // Set the flag to repeat the menu.
            cout << "\n>>>>>> Please enter a valid input <<<<<<<" << endl;
        }
    } while (repeat == true);  // Repeat the menu if the input is invalid.
}







//================================================================================================================================
//========================================= STUDENT LOGIN FUNNCTION===============================================================
//================================================================================================================================
void student_login(){
    //LONG  LONG INT BECAUSE IF SOMEONE ENTERS VERY LONNG NUMBER THE PROGRAM WONT CRASH
    long long int temp_rollno;  // WILL TEMPORARILY STORE ROLL NUMBER
    long long int temp_password;  // EWILL STORE PASSWORD TEMOPRARILY
    bool repeat;
    do{
        repeat=false;
        cout<<"\n=====  LOGIN FIRST  =====\n\nEnter your roll number(1-10000): "<<endl;
        cin>>temp_rollno;
        if(cin.fail()){  //CIN.FAIL() MEANS THAT IF WRONG INPUT IS ENTER THE CONDITION WILLBE TRUE
            cin.clear(); // IT WILL CLEAR THE INPUT SO PROGRAM WONT CRASH
            cin.ignore(100,'\n'); // IT WILL  IGNORE ALL CHARACTER ENTERD TO NOT DISTURB FURTHER INPUTS
            cout<<"\n>>>>>Please enter a valid input<<<<<<"<<endl;
            repeat=true;   //CONDITION FOR DO WHILE LOOP IS SET TO TRUE SO PROG WILL RUN AGAINN
            continue; // SKIP THIS  ITERATION
        }else{
            if(temp_rollno>0 && temp_rollno<=10000){    // ROLL NO SHOULD BE LESS THAN 10000 TO  AVOID MESSING WITH ARRAYS
                cout<<"Enter 4 digit pin"<<endl;
                cin>>temp_password;
                //  INPUT VALIDATION AGAIN
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout<<"\n>>>>>Please enter a valid input<<<<<<"<<endl;
                    repeat=true;
                    continue;
                }else{
                    if((temp_rollno==rollno[temp_rollno]) && (temp_password==studentpassword[temp_rollno])){
                        student_menu(temp_rollno);  // WILL PRINT STUDENT DETAILS IF ROLL NO AND PASSWORD MATCH
                    }
                    else{
                        cout<<"\n>>>>>This rollno or pin doesnot exist. Enter again<<<<<<"<<endl;
                        string try_again;
                        cout<<"Press 1 to go Back to start || Press any key to try again."<<endl;
                        cin>>try_again;
                        if(try_again=="1"){
                            main_menu();
                        }

                        repeat=true;
                    }
                }
            }
            else{
                repeat=true;
                cout<<"\n>>>>>>This rollno is out of range. Enter again(1 -  10000)<<<<<<"<<endl;

            }
        }
    }while(repeat==true);

}






//================================================================================================================================
//========================================= STUDENT MENU FUNNCTION================================================================
//================================================================================================================================
void student_menu(int rollno){
    bool repeat=true;   // flag for repetiiton
    do{
        cout<<"\n\n================== STUDENT PROFILE ===================\n"<<endl;
        cout<<"NAME : "<<studentname[rollno]<<endl;
        cout<<"FATHER NAME : "<<father[rollno]<<endl;
        cout<<"CONTACT NUMBER : "<<studentphone[rollno]<<endl;
        cout<<"LOGIN PIN : "<<studentpassword[rollno]<<endl;
        cout<<"\n=== COURSES ==="<<endl;
        cout<<"1. PHYSICS -  GPA: "<<phy_gpa[rollno]<<endl;
        cout<<"2. CHEMISTRY -  GPA: "<<chem_gpa[rollno]<<endl;
        cout<<"3. MATH -  GPA: "<<math_gpa[rollno]<<endl;
        cout<<"4. BIOLOGY -  GPA: "<<bio_gpa[rollno]<<endl;
        cout<<"5. ENGLISH -  GPA: "<<eng_gpa[rollno]<<endl;
        cout<<"\nSEMESTER -  GPA: "<<cgpa[rollno]<<endl;
        cout<<"============================================"<<endl<<endl;
        string condition;
        // A MENU FURTHER
        cout<<"1. Back to start.\n2. End program."<<endl;
        cin>>condition;
        if(condition=="1"){
            main_menu();    // navigate to mainmenu
        }else if(condition=="2"){
            exit(0); // end program
        }else{
            // input handling
            cout<<">>>Enter valid input<<<"<<endl;
            repeat=false;
        }
    }while(repeat==false);
       
}






//================================================================================================================================
//========================================= ADMIN MENU FUNNCTION==================================================================
//================================================================================================================================

void admin_menu()
{
    while (true)
    {
        int select;
        cout << "\n=======================================\n";
        cout << "      STUDENT MANAGEMENT SYSTEM       \n";
        cout << "=======================================\n";
        
        cout << "1. Add Student\n";
        cout << "2. Search a student\n";
        cout << "3. View All Students\n";
        cout << "4. Remove Student\n";
        cout << "5. Change Details\n";
        cout << "6. Back To start\n";
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
            view_student();
            break;

        case 3:
            view_all();
            break;

        case 4:
            cout << "\n=======================================\n";
            cout << "        REMOVE STUDENT SECTION        \n";
            cout << "=======================================\n";
            remove_student();
            break;

        case 5:
            changedetails_1();
            break;

        

        case 6:
            cout << "\n=======================================\n";
            cout << "              GOODBYE!                \n";
            cout << "=======================================\n";
            cout << "Thank you for using the Student\n";
            cout << "Management System!\n";
            cout << "---------------------------------------\n";
            main_menu();
            break;

        default:
            cout << "\n=======================================\n";
            cout << "          ERROR MESSAGE               \n";
            cout << "=======================================\n";
            cout << "Invalid input!\n";
            cout << "Please enter a number between 1 and 6.\n";
            cout << "---------------------------------------\n";
            break;
        }
    }
}






//================================================================================================================================
//========================================= ACCESSORIES FUNNCTION=================================================================
//================================================================================================================================

// ================  CALCULATION OF GPA =======================
int calculateGPA(int x)
{

    float total_gpa = phy_gpa[rolenumber] * 3 +
                      chem_gpa[rolenumber] * 3 +
                      bio_gpa[rolenumber] * 3 +
                      math_gpa[rolenumber] * 3 +
                      eng_gpa[rolenumber] * 3;

    return cgpa[x] = total_gpa / 15; // Total credit hours (5 subjects × 3 credits)
}

// ================  CHECKING OF INTGER INPUT =======================
void intCheck()
{
    // if not integer
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

// ================  CHECKING OF STRING INPUT =======================
void stringcheck(string &value)
{
    // check if it is a string

    isstringvalid = true;
    // Check if string is empty
    if (value.empty())
    {
        isstringvalid = false;
    }
    // Check each character
    for (char x : value)
    {
        if (isdigit(x)==true)
        {
            isstringvalid = false;
        }
        
    }
    if (isstringvalid == false)
    {
        cout << "Enter a string without numbers" << endl;
    }
}

// ================  CHECKING OF STRING PHONE NUMBER INPUT =======================
void phonecheck(string &value)
{
    // check if it is only numbers in string
    isphonevalid = true;
    // Check if string is empty
    if (value.empty())
    {
        isphonevalid = false;
    }
    // Check each character
    for (char x : value)
    {
        if (isdigit(x)==false)
        {
            isphonevalid = false;
        }
        
    }
    if (isphonevalid == false)
    {
        cout << "Enter numbers only" << endl;
    }
}






//================================================================================================================================
//========================================= ADD MEMBER FUNNCTION==================================================================
//================================================================================================================================
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
                     << "Father Name: " << father[rolenumber] << "\n"
                     << "Phone Number: " << studentphone[rolenumber] << "\n"
                     << "Pin: " << studentpassword[rolenumber] << "\n"
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
                {   // getting password
                    cout << "Enter 4 digit PIN: ";
                    cin >> studentpassword[rolenumber];
                    intCheck();
                    if (isintvalid == false)
                    {
                        repeat = true;
                        continue;
                    }   // ccheck if its 4 digit or not
                    else if (studentpassword[rolenumber] <= 999 || studentpassword[rolenumber] > 9999)
                    {
                        repeat = true;
                        continue;
                    }

                    repeat = false;
                } while (repeat != false);

                rollno[rolenumber] = rolenumber;  // assign roll  no in rollno array

                // getting data
                do
                {
                    cout << "\nEnter details for student " << rolenumber << ":\n";

                    do
                    {   // getting name
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
                    } while (repeat == true);

                    // getting father name
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
                    } while (repeat == true);

                    do
                    {   // getting phone number
                        cout << "Enter Phone Number: ";
                        cin >> studentphone[rolenumber];
                        phonecheck(studentphone[rolenumber]);// check if there is an alphabet
                        if (studentphone[rolenumber].size() != 11)//check if 11 digit or not
                        {
                            cout << "Phone number must be 11 digits" << endl;
                            repeat = true;
                            continue;
                        }
                        else if (isphonevalid == false)
                        {
                            repeat = true;
                            continue;
                        }

                        repeat = false;
                    } while (repeat == true);

                    // entering courses gpa one by one
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
                        else if (phy_gpa[rolenumber] < 0 || phy_gpa[rolenumber] > 4)
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
                        else if (chem_gpa[rolenumber] < 0 || chem_gpa[rolenumber] > 4)
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
                        else if (bio_gpa[rolenumber] < 0 || bio_gpa[rolenumber] > 4)
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
                        else if (math_gpa[rolenumber] < 0 || math_gpa[rolenumber] > 4)
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
                        else if (eng_gpa[rolenumber] < 0 || eng_gpa[rolenumber] > 4)
                        {
                            repeat = true;
                            continue;
                        }
                        repeat = false;
                    } while (repeat != false);

                    repeat = false;
                } while (repeat != false);
                calculateGPA(rolenumber);   // calculating semester gpa and assigning to role number
                // displaying results of newly added student...
                cout << "\nStudent Details Added:\n";
                cout << "Name: " << studentname[rolenumber] << "\n"
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
        else    //if role number  is greter than 10,000
        {
            cout << "Role number out of range. Please enter again" << endl;
            repeat = true;
        }
    } while (repeat == true);
}






//================================================================================================================================
//========================================= VIEW STUDENT FUNNCTION================================================================
//================================================================================================================================
void view_student(){
    do{
        repeat=false;   //flag to deal with input validations
        cout<<"Enter the students roll no(1 - 10,000): "<<endl;// enter roll no to view his details
        cin>>rolenumber;
        intCheck(); // check if integer entered or nt
        if(isintvalid==false){
            repeat=true;
            continue;
        }
        else if(rolenumber<=0 || rolenumber>10000){
            repeat=true;
            continue;
        }
        else{   //chek if student exists with thhis rollno or not
            if(rolenumber==rollno[rolenumber]){
                repeat=false;
            }else{
                cout<<"This rolenumber doesnot exists, Sorry. Try another."<<endl;
                repeat=true;
                continue;
            }
        }
    }while(repeat==true);
    // if student exists print details
    cout<<"\n\n================== STUDENT PROFILE ===================\n"<<endl;
    cout<<"NAME : "<<studentname[rolenumber]<<endl;
    cout<<"FATHER NAME : "<<father[rolenumber]<<endl;
    cout<<"CONTACT NUMBER : "<<studentphone[rolenumber]<<endl;
    cout<<"LOGIN PIN : "<<studentpassword[rolenumber]<<endl;
    cout<<"\n=== COURSES ==="<<endl;
    cout<<"1. PHYSICS -  GPA: "<<phy_gpa[rolenumber]<<endl;
    cout<<"2. CHEMISTRY -  GPA: "<<chem_gpa[rolenumber]<<endl;
    cout<<"3. MATH -  GPA: "<<math_gpa[rolenumber]<<endl;
    cout<<"4. BIOLOGY -  GPA: "<<bio_gpa[rolenumber]<<endl;
    cout<<"5. ENGLISH -  GPA: "<<eng_gpa[rolenumber]<<endl;
    cout<<"\nSEMESTER -  GPA: "<<cgpa[rolenumber]<<endl;
    cout<<"============================================"<<endl<<endl;
    do{ // further menu to navigate 
        repeat=false;
        string condition;
        // A MENU FURTHER
        cout<<"1. Back to Menu.\n2. See another Student"<<endl;
        cin>>condition;
        if(condition=="1"){
            admin_menu();
        }else if(condition=="2"){
            view_student();
        }else{
            cout<<">>>Enter valid input<<<"<<endl;
            repeat=true;
        }
    }while(repeat==true);
       
}






//================================================================================================================================
//========================================= VIEW ALL STUDENTS FUNNCTION===========================================================
//================================================================================================================================
void view_all()
{
    bool  are_there_any_students=false; //flag to deal if there is not student
    cout << "\n=======================================\n";
    cout << "         ALL STUDENT RECORDS          \n\n";

    for (int i = 0; i < 9999; i++)
    {
        if (rollno[i] != 0)
        {
            cout<<"Roll Number: "<<rollno[i]<<" | Name: "<<studentname[i]<<endl;
            are_there_any_students=true;    //students found so flag becomes true 
        }
    }
    // if flag false then no student exists
    if(are_there_any_students==false){
        cout << "\n---------------------------------------\n";
        cout << "          NO RECORDS FOUND            \n";
        cout << "---------------------------------------\n";
        return;
    }else{
        cout << "\n\n          END OF RECORDS              \n";
        cout << "=======================================\n";
    }
}






//================================================================================================================================
//========================================= REMOVE STUDENT FUNNCTION==============================================================
//================================================================================================================================

void remove_student()
{
    long long int remove;   // will store roll no  to be removed
    string confirm; //flag for confirmation

    do
    {
        
        cout << "\nEnter Registration Number to remove: ";
        cin >> remove;
        //check if roll noo out of range
        if(remove<0 || remove>9999){
            cout<<"Roll no out of range, Please Try again;";
            repeat=true;
            continue;
        }
        intCheck(); // check if integer
        if (isintvalid == false)
        {
            repeat = true;
            continue;
        }
        // chek if student exist or not
        else if (rollno[remove] == 0)
        {
            cout << ">>> Student with this Roll number does not exist! <<<" << endl;
            repeat = true;
            continue;
        }

        // Confirmation before deletion
        do
        {       // ask for confirmation
            cout<<"Roll no: "<<rollno[remove]<<" | Name: "<<studentname[remove]<<endl;  //print hhis name and roll no
            cout << "Are you sure you want to remove this student? (Y/N): ";
            cin >> confirm;

            if (confirm=="y" || confirm=="Y"){
                rollno[remove] = {};//empties his roll no to  zero
                cout << "\nStudent successfully removed from the system!\n";
                cout << "---------------------------------------\n";
            }else if(confirm=="n" || confirm=="N"){
                cout << "\n>>> Deletion cancelled <<<\n";
            }                
            else{   //repeat if incorrect input
                cout << ">>> Please enter a single character (Y/N) <<<" << endl;
                repeat = true;
                continue;
            }
            repeat = false;

        } while (repeat);

       
        repeat = false;

    } while (repeat);
}






//================================================================================================================================
//========================================= CHANGE DETAILS FUNNCTION==============================================================
//================================================================================================================================
void changedetails_1()
{
  
    do
    {
        cout << "\n=======================================\n";
        cout << "         MODIFY STUDENT RECORD         \n";
        cout << "=======================================\n";
        cout << "\nEnter Roll Number to change details: ";
        cin >> rolenumber;  // roll no to edit details
        
        intCheck(); // chek if int
        if (isintvalid == false)
        {
            cout << ">>> Please enter a valid Roll number <<<" << endl;
            repeat = true;
            continue;
        }
        // check if in range
        else if (rolenumber < 1 || rolenumber > 9999)
        {
            cout << ">>> Please enter valid Roll number(1-10000) <<<" << endl;
            repeat = true;
            continue;
        }
        // check if this student exists
        else if (rollno[rolenumber] == 0)
        {
            cout << "\nStudent not found!\n";
            cout << "Please enroll first from the main menu.\n";
            cout << "---------------------------------------\n";
            // option for going back to admin menu
            cout<<"Enter 1 to go to menu. Or press any key to try again: ";
            string opt;
            cin>>opt;
            if(opt=="1"){
                admin_menu();
            }
            repeat = true;
            continue;
        }
        
        repeat = false;
        
    } while (repeat);

    cin.ignore();
    changedetails_2();  // nowcall the second function for changing details
}

void changedetails_2()
{   // flag for showing menu  unless false
    bool keep_cahnging=true;
    while(keep_cahnging==true){
        // New variables to get new input and then store them in arrays
        string new_name, new_father_name, new_phone;
        int new_rollno, new_password;
        float newGPA;
        float new_cgpa;
        int choice;

        // Display Menu for changing details details
        cout << "\n=======================================\n";
        do {
            //first show the students name and roll no and then menu
            cout<<"Roll no: "<<rollno[rolenumber]<<" | Name: "<<studentname[rolenumber]<<endl;
            cout << "1 : Name\n"
                << "2 : Physics GPA\n"
                << "3 : Chemistry GPA\n"
                << "4 : Biology GPA\n"
                << "5 : Mathematics GPA\n"
                << "6 : English GPA\n"
                << "7 : Father Name\n"
                << "8 : Phone Number\n"
                << "9:  Pin\n"
                << "10: Back to menu\n"
                << "---------------------------------------\n"
                << "Enter your choice (1-10): ";
            cin >> choice;
            intCheck(); // input validations
            if (isintvalid == false)
            {
                repeat = true;
                continue;
            }
            
            if (choice < 1 || choice > 10)
            {   // if incorrect choice show menu again
                cout << ">>> Please enter a number between 1 and 10 <<<" << endl;
                repeat = true;
                continue;
            }
            repeat = false;
        } while (repeat);

        cout << "\n---------------------------------------\n";
        cout << "Enter New Information:\n";
        cout << "---------------------------------------\n";

        switch (choice)
        {
        case 1: // for changing name
            do {
                cout << "Enter the new name: ";
                cin.ignore();
                getline(cin, new_name);
                stringcheck(new_name);
                if (!isstringvalid)
                {
                    repeat = true;
                    continue;
                }
                studentname[rolenumber] = new_name;
                repeat = false;
            } while (repeat);
            break;

        // cases for changing gpa of any subject
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            do {
                cout << "Enter the new GPA (0.0 - 4.0): ";
                cin >> newGPA;
                intCheck(); // input validations
                if (isintvalid == false)
                {
                    repeat = true;
                    continue;
                }
                else if (newGPA < 0.0 || newGPA > 4.0)
                {
                    cout << ">>> Please enter a GPA between 0.0 and 4.0 <<<" << endl;
                    repeat = true;
                    continue;
                }
                // now depending upon previous choice change only that GPA
                switch(choice) {
                    case 3: phy_gpa[rolenumber] = newGPA; break;
                    case 4: chem_gpa[rolenumber] = newGPA; break;
                    case 5: bio_gpa[rolenumber] = newGPA; break;
                    case 6: math_gpa[rolenumber] = newGPA; break;
                    case 7: eng_gpa[rolenumber] = newGPA; break;
                }
                repeat = false;
            } while (repeat);
            break;

        case 7: //father name change
            do {
                cout << "Enter the new father name: ";
                cin.ignore();
                getline(cin, new_father_name);
                stringcheck(new_father_name);
                if (!isstringvalid)
                {
                    repeat = true;
                    continue;
                }
                father[rolenumber] = new_father_name;
                repeat = false;
            } while (repeat);
            break;
        // changing phone number
        case 8:
            do {
                cout << "Enter the new phone number: ";
                cin >> new_phone;
                // input validations
                phonecheck(new_phone);
                if (!isstringvalid)
                {
                    repeat = true;
                    continue;
                }
                if (new_phone.length() != 11)
                {
                    cout << ">>> Please enter a valid 11-digit phone number <<<" << endl;
                    repeat = true;
                    continue;
                }
                studentphone[rolenumber] = new_phone;
                repeat = false;
            } while (repeat);
            break;
        // Changing pin
        case 9:
            do {
                cout << "Enter the new PIN (4 digits): ";
                cin >> new_password;
                // input validations
                intCheck();
                if (isintvalid == false)
                {
                    repeat = true;
                    continue;
                }// to ensure its 4 digit
                if (new_password < 1000 || new_password > 9999)
                {
                    cout << ">>> Please enter a 4-digit PIN <<<" << endl;
                    repeat = true;
                    continue;
                }
                studentpassword[rolenumber] = new_password;
                repeat = false;
            } while (repeat);
            break;
        // this will turn the flag for while loop into false and while loop will break
        case 10:
            keep_cahnging=false;
        }
        cout<<"<== Details Changed ==>"<<endl;
        // this Calculate new CGPA if any subject gpa has been changed and will assign it to rolenumber in parameter
        calculateGPA(rolenumber);

    }
    // Display updated details
    cout << "\n=======================================\n";
    cout << "        UPDATED STUDENT DETAILS       \n";

    cout << "---------------------------------------\n";
    cout << "Name            : " << studentname[rolenumber] << "\n"
         << "---------------------------------------\n"
         << "Academic Records:\n"
         << "---------------------------------------\n"
         << "Physics GPA    : " << phy_gpa[rolenumber] << "\n"
         << "Chemistry GPA  : " << chem_gpa[rolenumber] << "\n"
         << "Biology GPA    : " << bio_gpa[rolenumber] << "\n"
         << "Mathematics GPA: " << math_gpa[rolenumber] << "\n"
         << "English GPA    : " << eng_gpa[rolenumber] << "\n"
         << "New CGPA       : " << cgpa[rolenumber] << "\n\n"
         << "---------------------------------------\n"
         << "Contact Information:\n"
         << "---------------------------------------\n"
         << "Father Name    : " << father[rolenumber] << "\n"
         << "Phone Number   : " << studentphone[rolenumber] << "\n"
         << "PIN       : " << studentpassword[rolenumber] << "\n"
         << "---------------------------------------\n";

    
}


