#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include "course.hpp"
#ifdef __WIN32__
#include <windows.h>
#endif

using namespace std;

ostream &operator<<(ostream &os,const Course &c)
{
    return os<<"Pass:"<<c.code<<" Title:"<<c.title<<" Semester:"<<c.semester<<" Dm:"<<c.credits;
}


class Student{
	public:
		int am;
		string name;
		string lname;
		int ex;
		int dm;
		void refresh(int a,string b,string c,int d,int e){
			am=a;
			name=b;
			lname=c;
			ex=d;
			dm=e;
		}
};

vector <Student> studentscroll;
Course::Course(string c,int s,string t,int cr):code(c),semester(s),title(t),credits(cr) {}

int menu(){
	cout<<"1.Register account of student"<<endl;
	cout<<"2.Refresh info of student"<<endl;
	cout<<"3.Delete student of account"<<endl;
	cout<<"4.Course registeration"<<endl;
	cout<<"5.Display statements per student(GUI)"<<endl;
	cout<<"0.Exit"<<endl;
	int input;
	cin>>input;
	return input;
}



std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}



std::ifstream& GotoLine(std::ifstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}



Student analyze(int num){
	Student a;
	string temp;
	int spacea=-1;
	int spaceb=-1;
	int spacec=-1;
	int spaced=-1;
	int am;
	string name="";
	string lname="";
	int ex;
	int dm;
	ifstream r("student_info.txt");
		GotoLine(r, num);
			getline(r,temp);
			for (int i=0;i<temp.size();i++){
				if(spacea == -1){
					if(temp[i] == '_')
						spacea=i;
				}
				else if(spaceb == -1){
					if(temp[i] == '_')
						spaceb=i;
				}
				else if(spacec == -1){
					if(temp[i] == '_')
						spacec=i;
				}
				else if(spaced == -1){
					if(temp[i] == '_')
						spaced=i;
				}			
			}
			int times=1000;
			for(int i=0;i<spacea;i++){
				int num1 = (int)temp[i];
				am+=(num1-48)*(times);
				times=times/10;
			}
			for(int i=spacea+1;i<spaceb;i++){
				name+=temp[i];
			}
			for(int i=spaceb+1;i<spacec;i++){
				lname+=temp[i];
			}
			if((spaced-spacec)==3)
				times=10;
			else
				times=1;
			ex=0;
			for(int i=spacec+1;i<spaced;i++){
				ex+=((int)temp[i]-48)*times;
				times=1;
			}
			if((spaced-spacec)==0)
				ex=ex/10;
			if((temp.size()-spaced)==4)
				times=100;
			else if((temp.size()-spaced)==3)
				times=10;
			else
				times=1;
			dm=0;
			for(int i=spaced+1;i<temp.size();i++){
				dm+=((int)temp[i]-48)*times;
				times=times/10;
			}
			if((spaced-temp.size())==2)
				dm=ex/10;
	r.close();
	a.refresh(am,name,lname,ex,dm);
	return a;
}



void studentCourse(vector <Student>& addstudent,int a){
	Student Course;
	if (a=!0){
		int am;
		string fname;
		string lname;
		int ex;
		int dm;
		cout<<"Add AM"<<endl;
		cin>>am;
		cout<<"Add First Name"<<endl;
		cin>>fname;
		cout<<"Add Last Name"<<endl;
		cin>>lname;
		cout<<"Add the cemester of your studies"<<endl;
		cin>>ex;
		cout<<"Add the number studies"<<endl;
		cin>>dm;
		Course.refresh(am,fname,lname,ex,dm);
		studentscroll.push_back(Course);
		//add new student to file
		ofstream foutput; 
		ifstream finput;
		finput.open ("Coursepaths.txt");
		foutput.open ("Coursepaths.txt",ios::app); 
		if(finput.is_open())
			foutput << am <<"_"<< fname <<"_"<< lname <<"_"<< ex <<"_"<< dm << endl;
		finput.close();
		foutput.close();
		//add new student num to file
		Student temps;
		string student_num;
		ifstream count("Coursepaths.txt");
		getline(count,student_num);
		int num = stoi(student_num);
		count.close();
		num++;
		fstream file("Coursepaths.txt");
		GotoLine(file, 1);
		string line2=to_string(num);
		file<<line2;
		file.close();
	}
}

void fill_info(){
	Student temps;
	string student_num;
	ifstream count("student_info.txt");
	getline(count,student_num);
	int num = stoi(student_num);
	count.close();
	for(int i=2;i<num+2;i++)
	{
		temps=analyze(i);
		studentscroll.push_back(temps);
	}
}



void studentplusplus(vector <Student>& addstudent,int a){
	Student temps;
	if (a==0){
		fill_info();
	}
	else{
		int am;
		string fname;
		string lname;
		int ex;
		int dm;
		cout<<"Add AM"<<endl;
		cin>>am;
		cout<<"Add First Name"<<endl;
		cin>>fname;
		cout<<"Add Last Name"<<endl;
		cin>>lname;
		cout<<"Add the cemester of your studies"<<endl;
		cin>>ex;
		cout<<"Add the number studies"<<endl;
		cin>>dm;
		temps.refresh(am,fname,lname,ex,dm);
		studentscroll.push_back(temps);
		//add new student to file
		ofstream foutput; 
		ifstream finput;
		finput.open ("student_info.txt");
		foutput.open ("student_info.txt",ios::app); 
		if(finput.is_open())
			foutput << am <<"_"<< fname <<"_"<< lname <<"_"<< ex <<"_"<< dm << endl;
		finput.close();
		foutput.close();
		//add new student num to file
		Student temps;
		string student_num;
		ifstream count("student_info.txt");
		getline(count,student_num);
		int num = stoi(student_num);
		count.close();
		num++;
		fstream file("student_info.txt");
		GotoLine(file, 1);
		string line2=to_string(num);
		file<<line2;
		file.close();
	}
}



int main(){
	studentplusplus(studentscroll,0);
	while(1){
		int input;
		input=menu();
		if (input==1)
			studentplusplus(studentscroll,1);
		else if (input==2)
		{
			cout<< "====================================="<<endl;
			for(int i=0;i<studentscroll.size();i++)
			{
				cout << "= " << studentscroll[i].am <<" "<<studentscroll[i].name <<" "<<studentscroll[i].lname <<" "<<studentscroll[i].ex <<" "<<studentscroll[i].dm <<endl;
			}
			cout<< "=====================================\nWho do you want to change?\nAM: "<<endl;
			cin>>input;
			int i=0;
			int am;
			string name="";
			string lname="";
			int ex;
			int dm;
			while(i < studentscroll.size()){
				if(studentscroll[i].am==input){
					cout<<"New AM: ";
					cin>>am;
					cout<<"New Name: ";
					cin>>name;
					cout<<"New Last Name: ";
					cin>>lname;
					cout<<"New Ex: ";
					cin>>ex;
					cout<<"New DM: ";
					cin>>dm;
					string strReplace=to_string(studentscroll[i].am)+'_'+studentscroll[i].name +'_'+studentscroll[i].lname +'_'+to_string(studentscroll[i].ex)+'_'+to_string(studentscroll[i].dm);
					string strNew=to_string(am)+"_"+name+"_"+lname+"_"+to_string(ex)+"_"+to_string(dm);
				    ifstream filein("student_info.txt"); //File to read from
				    ofstream fileout("temp.txt"); //Temporary file
				    if(!filein || !fileout)
				    {
				        cout << "Error opening files!" << endl;
				        return 1;
				    }
				    string strTemp;
				    while(filein >> strTemp)
				    {
				        if(strTemp == strReplace){
				            strTemp = strNew;
				        }
				        strTemp += "\n";
				        fileout << strTemp;
				    }
				    filein.close();
					fileout.close();
					string line;
				    ifstream in_file {"temp.txt"};
				    ofstream out_file {"student_info.txt"};
				        while(getline(in_file,line)){
				            out_file << line << endl;
				        }
				    in_file.close();
				    out_file.close();
					break;
				}
				i++;
			}
		}
		else if (input==3)
		{
			string student_num;
			ifstream count("student_info.txt");
			getline(count,student_num);
			int num = stoi(student_num);
			count.close();
			cout<< "====================================="<<endl;
			for(int i=0;i<studentscroll.size();i++)
			{
				cout << "= " <<studentscroll[i].am <<" "<<studentscroll[i].name <<" "<<studentscroll[i].lname <<" "<<studentscroll[i].ex <<" "<<studentscroll[i].dm <<endl;
			}
			cout<< "=====================================\nWho do you want to delete?\nAM: "<<endl;
			cin>>input;
			int i=0;
			int flag=0;
			while(i < studentscroll.size()&& flag==0){
				if(studentscroll[i].am==input){
					Student del=analyze(i+2);
					string line;
				    ifstream in_file {"student_info.txt"};
				    ofstream out_file {"temp.txt"};
						int j=-1;
						while(getline(in_file,line)){
							if(j== -1)
								out_file<<num-1<<endl;
							else if (j!=i)
								out_file << line << endl;
							j++;
				        }
				    in_file.close();
				    out_file.close();
				    ifstream in_file2 {"temp.txt"};
				    ofstream out_file2 {"student_info.txt"};
				        while(getline(in_file2,line)){
				            out_file2 << line << endl;
				        }
				    in_file2.close();
				    out_file2.close();
					flag=1;
				}
				i++;
			}
			if (flag==1)
				studentscroll.erase(studentscroll.begin()+i);	
		}
		else if (input==4)
		{	
			string student_num;
			ifstream count("student_info.txt");
			getline(count,student_num);
			int num = stoi(student_num);
			count.close();
			cout<< "====================================="<<endl;
			for(int i=0;i<studentscroll.size();i++)
			{
				cout << "= " << studentscroll[i].am <<" "<<studentscroll[i].name <<" "<<studentscroll[i].lname <<" "<<studentscroll[i].ex <<" "<<studentscroll[i].dm <<endl;
			}
			cout<< "=====================================\n\nAM: "<<endl;
			cin>>input;
			int i=0;
			int flag=0;
			
			while(i < studentscroll.size() && flag==0){
				if(studentscroll[i].am==input){
					flag=1;
				}
				i++;
			}
			if(flag==0){
				cout<<"Student not found"<<endl<<endl<<endl;
			}
			else{
				#ifdef __WIN32__
	        	SetConsoleOutputCP(65001);
	    		#endif
	    		string filename="dit_uoi_courses.txt";
	   			fstream fs(filename,ios::in);
	    		string line,word;
	   			vector <string> data;
	    		vector <Course> courses;
	    		auto start=true;
	    		while(getline(fs,line))
	    		{
		        	if(start)
		        	{
			            start=false;
			            
			            
			            continue;
		        	}
		        	data.clear();
		        	stringstream ss(line);
		        	while(getline(ss,word,','))
		        	{
			            data.push_back(word);
			        }
		        	if(data.size()!=4) continue;
		        	courses.push_back(Course(data[0],stoi(data[1]),data[2],stoi(data[3])));
		    	}
		    	fs.close();
		    	int k=0;
		    	for(auto &course:courses)
		    	{
					if(courses[k].semester==studentscroll[i-1].ex)
						cout<<course<<endl;	
					k++;
		    	}
		    	cout<<"Select courses"<<endl;
		    	cout<<"Example:PASS:501,301,506"<<endl;
		    	string lessons;
				cin>> lessons;
				ofstream foutput; 
				ifstream finput;
				finput.open ("student_courses.txt");
				foutput.open ("student_courses.txt",ios::app);
				if(finput.is_open())
					foutput << studentscroll[i-1].am<<" "<<lessons<< endl;
				finput.close();
				foutput.close();	
	    	}
		}
		else if (input==5)
		{
			cout<< "====================================="<<endl;
			for(int i=0;i<studentscroll.size();i++)
			{
				cout << studentscroll[i].am <<" "<<studentscroll[i].name <<" "<<studentscroll[i].lname <<" "<<studentscroll[i].ex <<" "<<studentscroll[i].dm <<endl;
			}
			cout<< "====================================="<<endl;

		}
		else
			return 5;
	}
	return 0;
}
