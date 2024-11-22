void intCheck(){
    if(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
        cout<<">>> Please Enter valid input <<<"
        continue;
    }
}