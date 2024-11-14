#include<iostream>
using namespace std;

// ====   FUNCTIONS  ======
void main_menu();
void student_login();
void student_menu(int rollno);



// =====  VARIABLES ========
int rollno[10000]={0,1,2,3};
string studentname[10000]={"","Asad khan","Saad Khan"};
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
   
    main_menu();
    


    
    return 0;
}

void main_menu(){
    int option;
    cout<<"\n\n======  WELCOME TO THE CAMPUS PORTAL  ======\n\n";
    cout<<"1. Run as Admin.\n2. Run as student.\n\nChoose option(1 or 2)";
    cin>>option;
    if(option==1){
            // ADD FUNCTION TO YOUR MAIN MENU
    }else{
        student_login();
    }
}

void student_login(){
    int temp_rollno;
    int temp_password;
    bool repeat;
    do{
    repeat=true;
    cout<<"\n\n=====  LOGIN FIRST  =====\n\nEnter your roll number: "<<endl;
    cin>>temp_rollno;
    cout<<"Enter 4 digit password"<<endl;
    cin>>temp_password;

    if((temp_rollno==rollno[temp_rollno]) && (temp_password==studentpassword[temp_rollno])){
        student_menu(temp_rollno);
    }
    else{
        cout<<"\nThis rollno or password doesnot exist. Enter again."<<endl;
        repeat=false;
    }
    }while(repeat==false);

}

void student_menu(int rollno){
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
    
    

       
}



