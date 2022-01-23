#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class Student
{
	private:
		int roll;
		char name[30];
		int logic;
		int dsa;
		int oops;
		int math;
		float per;
		char grade;
		int total;
	public:
		void getdata();
		void showdata();
		void calculate();
		int rollnum();
		int returnTotal();
		void tabular();
		int returnOOPS();
		int returnDSA();
		int returnMath();
		int returnLogic();
};
int Student :: rollnum()
{
	return roll;
}
int Student :: returnOOPS()
{
	return oops;
}
int Student :: returnDSA()
{
	return dsa;
}
int Student :: returnMath()
{
	return math;
}
int Student :: returnLogic()
{
	return logic;
}
int Student :: returnTotal()
{
	return total;
}
void Student :: getdata()
{
	cout<<"\nEnter roll number:";
	cin>>roll;
	cout<<"\nEnter name of student:";
	cin>>name;
	cout<<"\nEnter marks of Digital Logic:";
	cin>>logic;
	cout<<"\nEnter marks of Data Structure:";
	cin>>dsa;
	cout<<"\nEnter marks of Math:";
	cin>>math;
	cout<<"\nEnter marks of OOPS:";
	cin>>oops;
	calculate();
}
void Student :: tabular()
{
	cout<<roll<<setw(8)<<" "<<name<<setw(12)<<logic<<setw(12)<<dsa<<setw(7)<<math<<setw(8)
		<<oops<<setw(6)<<grade<<setw(12)<<per<<setw(12)<<total<<endl;
}

void Student :: showdata()
{
	cout<<"\nRoll number:"<<roll;
	cout<<"\nName of student:"<<name;
	cout<<"\nMarks of Digital Logic:"<<logic;
	cout<<"\nMarks of Data Structure:"<<dsa;
	cout<<"\nMarks of Math:"<<math;
	cout<<"\nMarks of OOPS:"<<oops;
	cout<<"\nGrade:"<<grade;
	cout<<"\nTotal marks:"<<total;
	cout<<"\nPercentage:"<<per;
	cout<<endl;
}
void Student :: calculate()
{
	total=logic+dsa+math+oops;
	per=total/4.0;
	if(per>70)
	{
		grade='A';
	}
	else if (per>60)
	{
		grade='B';
	}
	else if (per>50)
	{
		grade='C';
	}
	else if (per>40)
	{
		grade='D';
	}
	else if (per>30)
	{
		grade='E';
	}
	else
	{
		grade='F';
	}
}
void create_student()
{
	system("clear");
	char opt;
	Student s;
	ofstream outfile;
	outfile.open("student.dat", ios::app);
	s.getdata();
	outfile.write((char*) &s,sizeof(s));
	outfile.close();
	cout<<"\nPress y for adding more data and n for not adding the data\n";
	cin>>opt;
	if(opt=='y' || opt=='Y')

	{
		create_student();
	}
	else
	{
		cout<<"\nExisting from creating student record\n";
	}

}
void subject_mean()
{
	int ctr=0;
	int oops_mean=0,dsa_mean=0,math_mean=0,logic_mean=0;
	system("clear");
	Student s;
	ifstream infile;
	infile.open("student.dat");
	if(!infile)
	{
		cout<<"File could not be open !!!";
	}
	else
	{
		while(infile.read((char*) &s,sizeof(s)))
		{
			ctr++;
			oops_mean=oops_mean+s.returnOOPS();
			math_mean=math_mean+s.returnMath();
			dsa_mean=dsa_mean+s.returnDSA();
			logic_mean=logic_mean+s.returnLogic();
		}
		oops_mean/=ctr;
		math_mean/=ctr;
		dsa_mean/=ctr;
		logic_mean/=ctr;
		cout<<"\nOOPS mean:"<<oops_mean;
		cout<<"\nMath mean:"<<math_mean;
		cout<<"\nDSA mean:"<<dsa_mean;
		cout<<"\nDigital Logic mean:"<<logic_mean;
	}
}
void class_result()
{
	system("clear");
	Student s;
	ifstream inFile;
	inFile.open("student.dat");
	if(!inFile)
	{
		cout<<"File could not be open!!!";
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"===========================================================================================\n";
	cout<<"R.No       Name        Digital Logic   DSA   Math   OOPS    Grade   Percentage   Total"<<endl;
	cout<<"===========================================================================================\n";
	while(inFile.read((char*) (&s), sizeof(s)))
	{
		
		s.tabular();		
	}
	cout<<"=============================================================================================\n";
	inFile.close();
}
void display()
{
	system("clear");
	Student s;
	ifstream infile;
	infile.open("student.dat");
	if(!infile)
	{
		cout<<"File does not exist\n";
	}
	else
	{
		cout<<"All student record.....\n";
		while(infile.read((char*) &s,sizeof(s)))
		{
			getchar();
			s.showdata();
		}
		infile.close();
	}
}
void class_mean()
{
	system("clear");
	float mean=0.0;
	int ctr=0;
	float Tmean=0.0;
	ifstream infile; 
	Student s;
	infile.open("student.dat");
	if(!infile)
	{
		cout<<"File can't link\n";
	}
	else
	{
		while(infile.read((char*) &s,sizeof(s)))
		{
			mean=mean+(s.returnTotal()/4.0);
			ctr++;
		}
		Tmean=(float)mean/ctr;
		cout<<"\nClass mean is:"<<Tmean;
	}
}
/*
void modify_student(int n)
{
	int ctr=0,pos;
	system("clear");
	fstream fs;
	Student s;
	fs.open("student.dat",ios::in | ios::out | ios::binary);
	while(fs.read((char*) &s,sizeof(s)))
	{
		pos=fs.tellg();
		if(n=s.rollnum())
		{
			ctr++;
			s.getdata();
			fs.seekp(pos);
			fs.write((char*) &s,sizeof(s));
			cout<<"New updated data:";
			s.showdata();
			break;
		}
	}	
	if(ctr==0)
	{
		cout<<"\nData not found\n";
	}
}
*/
void delete_student(int n)
{
	system("clear");
	Student s;
	ifstream infile;
	infile.open("student.dat");
	if(!infile)
	{
		cout<<"\nFile can't link";
	}
	else
	{
		ofstream outfile;
		outfile.open("new.dat",ios::out);
		infile.seekg(0,ios::beg);
		while(infile.read((char*) &s,sizeof(s)))
		{
			if(s.rollnum() != n)
			{
				outfile.write((char*) &s,sizeof(s));
			}
		}
		infile.close();
		outfile.close();
		remove("student.dat");
		rename("new.dat","student.dat");
		cout<<"\nRecord deleted";
	}
}
void search_disp(int n)
{
	system("clear");
	Student s;
	ifstream infile;
	infile.open("student.dat");
	if(!infile)
	{
		cout<<"File does not exist\n";
	}
	else
	{
		int ctr=0;
		while(infile.read((char*) &s,sizeof(s)))
		{
			if(s.rollnum() == n)
			{
				cout<<"\nRecord founded...";
				cout<<"\n...Press any key to see the record...\n";
				getchar();
				s.showdata();
				ctr++;
				infile.close();
				break;
			}
		}
		if(ctr==0)
		{
			cout<<"\n\nRecord not found\n";
		}
	}
}
int main()
{
	int opt,num;
	do
	{
		cout<<"\n0.To exit\n";
		cout<<"1.To create a record\n";
		cout<<"2.To delete a record\n";
		cout<<"3.To read all records from file\n";
		cout<<"4.To Search a record\n";
		cout<<"5.Class mean\n";	
		cout<<"6.Display all students record in tabular form\n";
		cout<<"7.Modify Record\n";
		cout<<"8.All Subject Mean\n";
		cout<<"\nEnter your option:";
		cin>>opt;
		switch(opt)
		{
			case 0:
				cout<<"\nLeaving thank you!!";
				break;
			case 1:
				create_student();
				break;
			case 2:
				cout<<"Enter roll number:";
				cin>>num;
				delete_student(num);
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"Enter roll number:";
				cin>>num;
				search_disp(num);
				break;
			case 5:
				class_mean();
				break;
			case 6:
				class_result();
				break;
			case 7:
				cout<<"Enter roll number:";
				cin>>num;
			 	modify_student(num);
			 	break;
			 case 8:
			 	subject_mean();
			 	break;
			default:
				cout<<"Invalid choice";
		}	
	}while(opt!=0);
}