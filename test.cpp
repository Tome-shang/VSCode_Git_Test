#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class person{
    public:
    virtual void Add(){};
    virtual void Save(){};
    virtual void Load(){};
    virtual void Show(){};
    virtual void Exit(){};
    virtual void Delete(){};
    virtual void Find(){};
    virtual void Sort(){};
    void setNumber(string number){
        this->number=number;
    }
    string getNumber(){
        return this->number;
    }
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return this->name;
    }
    void setAge(int age){
        this->age=age;
    }
    int getAge(){
        return this->age;
    }
    void setCollege(string college){
        this->college=college;
    }
    string getCollege(){
        return this->college;
    }
    char getSex(){
        return this->sex;
    }
    void setSex(char sex){
        this->sex=sex;
    }
    private:
        string number;
        string name; 
        int age;
        string college;
        char sex;
};
class student:public person{
    private:
        float math;
        float english;
        float chinese;
    public:
        student(string number="oo",string name="oo",int age=0,string college="oo",char sex='o',float math=0,float english=0,float chinese=0){
        setNumber(number);
        setName(name);
        setAge(age);
        setCollege(college);
        setSex(sex);
        setMath(math);
        setEnglish(english);
        setChinese(chinese);
    };
    friend istream& operator >> (istream&, student&);
    friend ostream& operator << (ostream&, student&);
    void Add();
    void Save();
    void Load();
    void Show();
    void Exit();
    void Delete();
    void Sort();
    void Find();
    void setMath(float math){
        this->math=math;
    }
    float getMath(){
        return this->math=math;
    }
    void setEnglish(float english){
        this->english=english;
    }
    float getEnglish(){
        return this->english=english;
    }
    void setChinese(float chinese){
        this->chinese=chinese;
    }
    float getChinese(){
        return this->chinese=chinese;
    }
};
vector<student> vi;
istream& operator >> (istream& in, student& pt)
{
    string number;
    string name; 
    int age;
    string college;
    char sex;
    float math;
    float english;
    float chinese;
    cout<<"please input number"<<endl;
    in>>number;
    pt.setNumber(number);
    cout<<"please input name"<<endl;
    in>>name;
    pt.setName(name);
    cout<<"please input age"<<endl;
    in>>age;
    pt.setAge(age);
    cout<<"please input college"<<endl;
    in>>college;
    pt.setCollege(college);
    cout<<"please input sex"<<endl;
    in>>sex;
    pt.setSex(sex);
    cout<<"please input math"<<endl;
    in>>math;
    pt.setMath(math);
    cout<<"please input english"<<endl;
    in>>english;
    pt.setEnglish(english);
    cout<<"please input chinese"<<endl;
    in>>chinese;
    pt.setChinese(chinese);
    return in;
}
ostream& operator << (ostream& out, student& pt)
{
   out<<"Number="<<pt.getNumber()<<" "
    <<"Name="<<pt.getName()<<" "
    <<"age="<<pt.getAge()<<" "
    <<"college="<<pt.getCollege()<<" "
    <<"Sex="<<pt.getSex()<<" "
    <<"math="<<pt.getMath()<<" "
    <<"english="<<pt.getEnglish()<<" "
    <<"chinese="<<pt.getChinese()<<endl;
   return out;
}
void student::Exit(){
    exit(0);
}
void student::Show(){
    for(int i=0;i<vi.size();i++){
        cout<<vi[i];
    }
}
void student::Add(){
    cout<<"Is add?(y/n):";
    char temp;
    cin>>temp;
    if(temp=='n'||temp=='N'){
        return;
    }
    do{ student stu;
        cin>>stu;
        vi.push_back(stu);
        cout<<"Is continue add?(y/n):";
        cin>>temp;
    }while(temp=='y'||temp=='Y');
    cout<<"Added Successfully!"<<endl;
}
void student::Save(){
    ofstream outfile;
    outfile.open("hello.txt");
    for(int i=0;i<vi.size();i++)
    {
        outfile<<vi[i].getNumber()<<" "
        <<vi[i].getName()<<" "
        <<vi[i].getAge()<<" "
        <<vi[i].getCollege()<<" "
        <<vi[i].getSex()<<" "
        <<vi[i].getMath()<<" "
        <<vi[i].getEnglish()<<" "
        <<vi[i].getChinese()<<" ";
    }
    outfile.close();
    cout<<"Saved Successfully!"<<endl;
}
void student::Delete(){
    cout<<"Please enter the number or name that needs to be deleted:";
    string num;
    cin>>num;
    vector<student>::iterator itor;
    for (itor = vi.begin(); itor != vi.end(); itor++)
    {
        if (num.compare(itor->getNumber())==0||num.compare(itor->getName())==0)
        {
            itor = vi.erase(itor);
            break;
        }
    }
    if(itor == vi.end()){
			cout<<"No find it!!"<<endl;
		}
    cout<<"Successful implementation!"<<endl;
}
template <class Type>
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;    
}
void student::Load(){
    vi.clear();
    ifstream infile("hello.txt");
    while(!infile.eof()){
    string number[8];
    for(int i=0;i<8;i++){
        infile>>number[i];
    }
    if(infile.fail()){break;}
    student stu(number[0],number[1],stringToNum<int>(number[2]),number[3],stringToNum<char>(number[4]),stringToNum<float>(number[5]),stringToNum<float>(number[6]),stringToNum<float>(number[7]));
    vi.push_back(stu);
    }
    infile.close();
    cout<<"Loaded Successfully!"<<endl;
}
bool GreatSort (student a,student b) { return (a.getNumber()>b.getNumber()); };
void student::Sort(){
    sort(vi.begin(),vi.end(),GreatSort);
}
void student::Find(){
    cout<<"Please enter the number or name that needs to be found:";
    string num;
    cin>>num;
    vector<student>::iterator itor;
    for (itor = vi.begin(); itor != vi.end(); itor++)
    {
        if (num.compare(itor->getNumber())==0||num.compare(itor->getName())==0)
        {
            cout<<found it!!"<<endl;
            break;
        }
    }
    if(itor == vi.end()){
			cout<<"No find it!!"<<endl;
		}
    cout<<"Successful implementation!"<<endl;
}
class teacher:public person{
    private:
        string position;
		string major;
		int seniority;
    public:
        teacher(string number="oo",string name="oo",int age=0,string college="oo",char sex='o',string position="oo",string major="oo",int seniority=0){
        setNumber(number);
        setName(name);
        setAge(age);
        setCollege(college);
        setSex(sex);
        setPosition(position);
        setMajor(major);
        setSeniority(seniority);
    };
    friend istream& operator >> (istream&, teacher&);
    friend ostream& operator << (ostream&, teacher&);
    void Add();
    void Save();
    void Load();
    void Show();
    void Exit();
    void Delete();
    void Sort();
    void setPosition(string position){
        this->position=position;
    }
    string getPosition(){
        return this->position=position;
    }
    void setMajor(string major){
        this->major=major;
    }
    string getMajor(){
        return this->major=major;
    }
    void setSeniority(int seniority){
        this->seniority=seniority;
    }
    int getSeniority(){
        return this->seniority=seniority;
    }
};
vector<teacher> vo;
istream& operator >> (istream& in, teacher& pt)
{
    string number;
    string name; 
    int age;
    string college;
    char sex;
	string position;
	string major;
	int seniority;
    cout<<"please input number"<<endl;
    in>>number;
    pt.setNumber(number);
    cout<<"please input name"<<endl;
    in>>name;
    pt.setName(name);
    cout<<"please input age"<<endl;
    in>>age;
    pt.setAge(age);
    cout<<"please input college"<<endl;
    in>>college;
    pt.setCollege(college);
    cout<<"please input sex"<<endl;
    in>>sex;
    pt.setSex(sex);
    cout<<"please input position"<<endl;
    in>>position;
    pt.setPosition(position);
    cout<<"please input major"<<endl;
    in>>major;
    pt.setMajor(major);
    cout<<"please input seniority"<<endl;
    in>>seniority;
    pt.setSeniority(seniority);
    return in;
}
ostream& operator << (ostream& out, teacher& pt)
{
   out<<"Number="<<pt.getNumber()<<" "
    <<"Name="<<pt.getName()<<" "
    <<"age="<<pt.getAge()<<" "
    <<"college="<<pt.getCollege()<<" "
    <<"Sex="<<pt.getSex()<<" "
    <<"position="<<pt.getPosition()<<" "
    <<"major="<<pt.getMajor()<<" "
    <<"seniority="<<pt.getSeniority()<<endl;
   return out;
}
void teacher::Exit(){
    exit(0);
}
void teacher::Show(){
    for(int i=0;i<vo.size();i++){
        cout<<vo[i];
    }
}
void teacher::Add(){
    cout<<"Is add?(y/n):";
    char temp;
    cin>>temp;
    if(temp=='n'||temp=='N'){
        return;
    }
    do{ teacher stu;
        cin>>stu;
        vo.push_back(stu);
        cout<<"Is continue add?(y/n):";
        cin>>temp;
    }while(temp=='y'||temp=='Y');
    cout<<"Successful implementation!"<<endl;
}
void teacher::Save(){
    ofstream outfile;
    outfile.open("teacher.txt");
    for(int i=0;i<vo.size();i++)
    {
        outfile<<vo[i].getNumber()<<" "
        <<vo[i].getName()<<" "
        <<vo[i].getAge()<<" "
        <<vo[i].getCollege()<<" "
        <<vo[i].getSex()<<" "
        <<vo[i].getPosition()<<" "
        <<vo[i].getMajor()<<" "
        <<vo[i].getSeniority()<<" ";
    }
    outfile.close();
    cout<<"Successful implementation!"<<endl;
}
void teacher::Delete(){
    cout<<"Please enter the number that needs to be deleted:";
    string num;
    cin>>num;
    vector<teacher>::iterator itor;
    for (itor = vo.begin(); itor != vo.end(); itor++)
    {
        if (num.compare(itor->getNumber())==0||num.compare(itor->getName())==0)
        {
            itor = vo.erase(itor);
            break;
        }
    }
    if(itor == vo.end()){
			cout<<"No find it!!"<<endl;
		}
    cout<<"Successful implementation!"<<endl;
}
void teacher::Load(){
    vo.clear();
    ifstream infile("teacher.txt");
    while(!infile.eof()){
    string number[8];
    for(int i=0;i<8;i++){
        infile>>number[i];
    }
    if(infile.fail()){break;}
    teacher tea(number[0],number[1],stringToNum<int>(number[2]),number[3],stringToNum<char>(number[4]),number[5],number[6],stringToNum<int>(number[7]));
    vo.push_back(tea);
    }
    infile.close();	
}
bool GreatSort1 (teacher a,teacher b)
 { return (a.getNumber()>b.getNumber()); };
void teacher::Sort(){
    sort(vo.begin(),vo.end(),GreatSort1);
}
int main(){
    person *per;
    teacher tea;
    student stu;
    while(1){
        system("cls");
        cout<<"*************************"<<endl;
        cout<<"1.student       2.teacher"<<endl;
        cout<<"0.Exit                   "<<endl;
        cout<<"*************************"<<endl;
        cout<<"please choose (0-2):";
        int temp1=0;
        cin>>temp1;
        if(temp1==1){
            per=&stu;
            while(1){
                cout<<"*****student management system*****"<<endl;
                cout<<"1.Add                        2.Save"<<endl;
                cout<<"3.Load                       4.Show"<<endl;
                cout<<"5.Delete                     6.Sort"<<endl;
                cout<<"7.Return main menu           0.Exit"<<endl;
                cout<<"***********************************"<<endl;
                cout<<"please choose (0-7):";
                int temp3=0;
                cin>>temp3;
                if(temp3==7){
                    cout<<"hello!"<<endl;
                    break;
                }
                else{
                    switch(temp3){
                    case 0:per->Exit();   break;
                    case 1:per->Add();    break;
                    case 2:per->Save();   break;
                    case 3:per->Load();   break;
                    case 4:per->Show();   break;
                    case 5:per->Delete(); break;
                    case 6:cout<<"before sorting"<<endl;
                    per->Show();per->Sort(); 
                    cout<<"after sorting"<<endl;  
                    per->Show();break;
                    default:cout<<"Input error!!!"<<endl;break;
                }
                }
                getchar();
                cout<<"prees any key to continue!!";
                getchar();
                system("cls");
            }
        }
        if(temp1==2){
              per=&tea;
            while(1){
                cout<<"*****teacher management system*****"<<endl;
                cout<<"1.Add                        2.Save"<<endl;
                cout<<"3.Load                       4.Show"<<endl;
                cout<<"5.Delete                     6.Sort"<<endl;
                cout<<"7.Return main menu           0.Exit"<<endl;
                cout<<"***********************************"<<endl;
                cout<<"please choose (0-7):";
                cout<<"please choose (0-7):";
                int temp2=0;
                cin>>temp2;
                if(temp2==7){
                    break;
                }
                else{
                    switch(temp2){
                    case 0:per->Exit();   break;
                    case 1:per->Add();    break;
                    case 2:per->Save();   break;
                    case 3:per->Load();   break;
                    case 4:per->Show();   break;
                    case 5:per->Delete(); break;
                    case 6:cout<<"before sorting"<<endl;
                    per->Show();per->Sort(); 
                    cout<<"after sorting"<<endl;  
                    per->Show();break;
                    default:cout<<"Input error!!!"<<endl;break;
                }
                }
                getchar();
                cout<<"prees any key to continue!! ";
                getchar();
                system("cls");
            }
        }
        if(temp1==0){
            cout<<"break"<<endl;
            exit(0);
        }
    }
    return 0;
    system("pause");
}