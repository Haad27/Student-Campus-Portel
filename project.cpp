#include<iostream>
using namespace std;

// ====   FUNCTIONS  ======
void main_menu();
void student_login();  // FUNCTION FOR LOGG IN
void student_menu(int rollno);     //FUNCTION FOR PRINTING STUDENT WHOOLE PROFIIE



// =====  VARIABLES ========
int rollno[10000]={0,1,2,3};
string studentname[10000]={"","Asad khan","Saad Khan"};         //THIS DATA WILL BE ALREADY STORED
string fathername[10000]={"","Abdul Wahid","Amjad Ali"};
string studentphone[10000]={"","0348475592","03458877645"};
int studentpassword[10000]={0,4774,4748};
float semestergpa[10000]={0,3.5,3.3};
// COURSES GPA
float phy_gpa[10000]={0,3.5,3.3};
float bio_gpa[10000]={0,3.5,3.3};
float chem_gpa[10000]={0,3.5,3.3};
float math_gpa[10000]={0,3.5,3.3};
float eng_gpa[10000]={0,3.5,3.3};



int main(){
   
    main_menu(); //THIS WILL START THE PROGRAM
    


    
    return 0;
}

void main_menu(){
    string option;  // WILL TAKE THIS STRINNG TO HANDLE ALPHABETS
    bool repeat;
    do{
        repeat=true;
        cout<<"\n======  WELCOME TO THE CAMPUS PORTAL  ======\n\n";
        cout<<"1. Run as Admin.\n2. Run as student.\n\nChoose option(1 or 2)";
        cin>>option;
        if(option=="1"){
                // ADD FUNCTION TO ADMIN MENU
        }else if(option=="2"){
            student_login();
        }else{
            repeat=false;
            cout<<"\n>>>>>>Please enter valid input<<<<<<<"<<endl;
        }
    }while(repeat==false);
}

void student_login(){
    //LONG  LONG INT BECAUSE IF SOMEONE ENTERS VERY LONNG NUMBER THE PROGRAM WONT CRASH
    long long int temp_rollno;  // WILL TEMPORARILY STORE ROLL NUMBER
    long long int temp_password;  // EWILL STORE PASSWORD TEMOPRARILY
    bool repeat;
    do{
        repeat=true;
        cout<<"\n=====  LOGIN FIRST  =====\n\nEnter your roll number(1-10000): "<<endl;
        cin>>temp_rollno;
        if(cin.fail()){  //CIN.FAIL() MEANS THAT IF WRONG INPUT IS ENTER THE CONDITION WILLBE TRUE
            cin.clear(); // IT WILL CLEAR THE INPUT SO PROGRAM WONT CRASH
            cin.ignore(100,'\n'); // IT WILL  IGNORE ALL CHARACTER ENTERD TO NOT DISTURB FURTHER INPUTS
            cout<<"\n>>>>>Please enter a valid input<<<<<<"<<endl;
            repeat=false;   //CONDITION FOR DO WHILE LOOP IS SET TO TRUE SO PROG WILL RUN AGAINN
            continue; // SKIP THIS  ITERATION
        }else{
            if(temp_rollno>0 && temp_rollno<=10000){    // ROLL NO SHOULD BE LESS THAN 10000 TO  AVOID MESSING WITH ARRAYS
                cout<<"Enter 4 digit password"<<endl;
                cin>>temp_password;
                //  INPUT VALIDATION AGAIN
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout<<"\n>>>>>Please enter a valid input<<<<<<"<<endl;
                    repeat=false;
                    continue;
                }else{
                    if((temp_rollno==rollno[temp_rollno]) && (temp_password==studentpassword[temp_rollno])){
                        student_menu(temp_rollno);  // WILL PRINT STUDENT DETAILS IF ROLL NO AND PASSWORD MATCH
                    }
                    else{
                        cout<<"\n>>>>>This rollno or password doesnot exist. Enter again<<<<<<"<<endl;
                        repeat=false;
                    }
                }
            }
            else{
                repeat=false;
                cout<<"\n>>>>>>This rollno is out of range. Enter again(1 -  10000)<<<<<<"<<endl;

            }
        }
    }while(repeat==false);

}

void student_menu(int rollno){
    bool repeat=true;
    do{
        cout<<"\n\n===== STUDENT PROFILE =====\n"<<endl;
        cout<<"NAME : "<<studentname[rollno]<<endl;
        cout<<"FATHER NAME : "<<fathername[rollno]<<endl;
        cout<<"CONTACT NUMBER : "<<studentphone[rollno]<<endl;
        cout<<"LOGIN PASSWORD : "<<studentpassword[rollno]<<endl;
        cout<<"\n=== COURSES ==="<<endl;
        cout<<"1. PHYSICS -  GPA: "<<phy_gpa[rollno]<<endl;
        cout<<"2. CHEMISTRY -  GPA: "<<chem_gpa[rollno]<<endl;
        cout<<"3. MATH -  GPA: "<<math_gpa[rollno]<<endl;
        cout<<"4. BIOLOGY -  GPA: "<<bio_gpa[rollno]<<endl;
        cout<<"5. ENGLISH -  GPA: "<<eng_gpa[rollno]<<endl;
        cout<<"\nYEARLY -  GPA: "<<semestergpa[rollno]<<endl;
        cout<<endl<<endl;
        string condition;
        // A MENU FURTHER
        cout<<"1. Back to start.\n2. End program."<<endl;
        cin>>condition;
        if(condition=="1"){
            main_menu();
        }else if(condition=="2"){
            break;
        }else{
            cout<<">>>Enter valid input<<<"<<endl;
            repeat=false;
        }
    }while(repeat==false);
       
}



