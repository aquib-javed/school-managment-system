#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class Student
{
private:
	string firstName;
	string lastName;
	int Class;
	int rollNo;
	string registrationDate;
	string Gender;
	string contactNo;
	string fatherName;
	string fatherProfession;
	string parentContact;
	string feeSubmitted;
	string bloodGroup;
	string Address;
public:
	void enterData();
	void edit_StudentData(string);
	void diaplay_student();
	void feeStatus();
	void log_in_admin();
	void log_in_student();
	virtual void display();
};
///////// yahan kuch esa tha jo k hamaray lea khatarnaak tha
//Second Class
class Teacher
{
public:
	string FirstName;
	string LastName;
	string Email;
	string JoiningDate;
	string Password;
	string ConfirmPassword;
	string CNIC;
	string gender;
	string Qualification;
	string ContactNo;
	string DOB;
	string address;
	string Salary;
	void enter_TeacherData();
	bool chkpass(string pass, string conpass);
	void edit_TeacherData(string);
	void diaplay_teacher();
	virtual void display();
};

//Third Class
class Course
{
private:
	string CourseName;
	string CourseCode;
	string SelectClass; //(Pre - nursery to matric)
	string ParentCourse; //(selected from general courses)
public:
	void enter_CourseData();
	virtual void display();
};

class marks
{
public:
	string English;
	string OOP;
	string DLD;
	string PS;
	marks()		//Default Constructor 
	{			//Initializing with zero
		English = "";
		OOP = "";
		DLD = "";
		PS = "";
	}
	void updateMarks();
	void showMarks();
	virtual void display();
};

void Student::display()				//This is a virtual void display function
{
	cout << "   |  Hello Student  |" << endl;
}
void Teacher::display()				//This is a virtual void display function
{
	cout << "   |  Hello Teacher  |" << endl;
}
void Course::display()				//This is a virtual void display function
{
	cout << "   | Welcome to update Courses |" << endl;
}
void marks::display()				//This is a virtual void display function
{
	cout << "   |   Welcome to update Marks |" << endl;
}

void Student::log_in_admin()		//This function is for login Admin Id
{
	ifstream admin_file("admin-password.txt");	//It will check in the file

	string user;
	string line;
	string pass;

	bool user1 = 0;
	bool password1 = 0;
	int count = 0;

	cout << "                     Enter User name : ";		cin >> user;
	cout << "                     Enter Password  : ";		cin >> pass;
	while (admin_file)
	{
		getline(admin_file, line);
		if ((line == user) || (line == pass))
		{
			if (line == user)
			{
				user1 = 1;
			}
			else if (line == pass)
			{
				password1 = 1;
			}

		}


		count++;
		if (count == 2)
		{
			count = 0;
			if ((user1 == 1) && (password1 == 1))
			{

				cout << "user /password match \n";
				admin_file.close();
			}
			else if ((user1 == 1) && (password1 == 0))
			{

				cout << "   Password Unmatch ! " << endl;
				cout << "     Enter Again !" << endl;

			}
			else if ((user1 == 0) && (password1 == 1))
			{

				cout << "   Password Unmatch ! " << endl;
				cout << "     Enter Again !" << endl;

			}

		}
	}

}
void Student::log_in_student()
{
	ifstream admin_file("student_login.txt");
	string user, pass; //////ya many wasay he variable likhay han ap en ko adjust kar layna class ma ya jahan marzi
	string line; ///////ya var file ma caparison karnay k lea ha
	bool user1 = 0, password1 = 0;
	int count = 0;
	///////// eder wellcome wagarah jo b cout karvana ha karva layna
	cout << "    Enter User name : ";		cin >> user;
	cout << "    Enter Password  : ";		cin >> pass;
	while (admin_file)
	{
		getline(admin_file, line);
		if ((line == user) || (line == pass))
		{
			if (line == user)
			{
				user1 = 1;
			}
			else if (line == pass)
			{
				password1 = 1;
			}

		}

		count++;
		if (count == 2)
		{
			count = 0;
			if ((user1 == 1) && (password1 == 1))
			{
				cout << "user /password match \n";
				admin_file.close();
			}
			else if ((user1 == 1) && (password1 == 0))
			{
				cout << "   Password Unmatch ! " << endl;
				cout << "     Enter Again !" << endl;
			}
			else if ((user1 == 0) && (password1 == 1))
			{
				cout << "   Password Unmatch ! " << endl;
				cout << "     Enter Again !" << endl;
			}
		}
	}
}
///////////ya funtion sirf file likhnay k lea ha 
/*void make_pass_file()
{
	ofstream admin_pass("admin-password.txt", ios::app);
	string user, pass;
	int opp;
	if (admin_pass.is_open())
	{
		cout << "enter user name\n";
		cin >> user;
		cout << "enter user  password\n";
		cin >> pass;
		admin_pass << user << endl << pass << endl;
		cout << "if you want to again enter pss/user press 1 to exit press 0\n";
		cin >> opp;
		if (opp == 0)
		{
			admin_pass.close();

		}
	}
}*/
int main()
{

	string cnic; ///////ya manay naya variable declare kea ha edit teacher chalanay k lea cnic pass karta ha

	///// ya sab pahlay he declare thy bas uper lay aya  hon
	Student w;
	Teacher x;
	Course y;
	marks z;
	string roll;
	cout << endl << "            Welcome to School Manamgment System" << endl << endl;

	char op;
	do
	{
		cout << "                 ------------------------" << endl;
		cout << "                 | Choose One Option    |" << endl;
		cout << "                 ------------------------" << endl;
		cout << "                 |     1. Admin         |" << endl;
		cout << "                 |     2. Student       |" << endl;
		cout << "                 |     3. Teacher       |" << endl;
		cout << "                 ------------------------" << endl;
		cout << "                 |   Enter : ";		cin >> op;
		cout << "                 ------------------------" << endl << endl;
		system("cls");
	} while (op != '1' && op != '2' && op != '3');


	//make_pass_file();	//For setting up the username


	cout << endl;
	cout << "                      -----------------------" << endl;
	cout << "                      |         LOG IN      |" << endl;
	cout << "                      -----------------------" << endl;
	w.log_in_admin();		//For logging in

	system("cls");
	switch (op)
	{
	case ('1'):

		cout << endl;
		cout << " | Hello Admin | " << endl;

		cout << " Enter Information of the Student" << endl;

		w.enterData();

		cout << " Enter Information of the Teacher" << endl;

		x.enter_TeacherData();

		cout << " Enter Information of the Course" << endl;

		y.enter_CourseData();

		cout << "Assign Course to the Teachers" << endl;
		//Still have to be done



		char option;
		do
		{
			cout << "         ---------------------------------------" << endl;
			cout << "         |          Choose One Option           |" << endl;
			cout << "         ---------------------------------------" << endl;
			cout << "         |  1. Edit Student Details             |" << endl;
			cout << "         |  2. Edit Teacher Details             |" << endl;
			cout << "         |  3. View All Students                |" << endl;
			cout << "         |  4. View All Teachers                |" << endl;
			cout << "         |  5. Update Student Marks             |" << endl;
			cout << "         |  6. View Student Marks               |" << endl;
			cout << "         |  7. View Fee Status                  |" << endl;
			cout << "         |  8. Exit                             |" << endl;
			cout << "         ---------------------------------------" << endl;
			cout << "         |   Enter : ";		cin >> option;
			cout << "         ---------------------------------------" << endl << endl;
		} while (option != '1' && option != '2' && option != '3' && option != '4' && option != '5'
			&& option != '6' && option != '7' && option != '8' && option != '9' && option != '10');


		do
		{
			switch (option)
			{
			case ('1'):
				cout << "Enter Roll Number of the stuent";
				cin >> roll;

				w.edit_StudentData(roll);

				cout << "Edited Successfully !" << endl;
				break;

			case ('2'):

				cout << "Enter CNIC Number of the teacher\n";
				cin >> cnic;
				x.edit_TeacherData(cnic);

				cout << "Edited Successfully !" << endl;
				break;

			case ('3'):
				//this is funtion to display all the students in  the file
				w.diaplay_student();
				break;
			case ('4'):
				//this is funtion to display all the students in  the file
				x.diaplay_teacher();
				break;

			case ('5'):
				//this is function to update the student marks
				z.updateMarks();
				break;

			case ('6'):
				//this is function to display the student  marks
				z.showMarks();
				break;

			case ('7'):
				//this is function to display the student fee status
				w.feeStatus();

			case ('8'):
				cout << endl << " Thank you !" << endl;
				exit(0);
				break;
			}
		} while (exit);

		break;

	case ('2'):

		cout << "   -----------------------" << endl;
		cout << "   |         LOG IN      |" << endl;
		cout << "   -----------------------" << endl;

		char opp;
		string rr;
		w.log_in_student();
		do
		{
			cout << "-----------------------" << endl;
			cout << "| Choose One Option    |" << endl;
			cout << "-----------------------" << endl;
			cout << "|  1. View Marks       | " << endl;
			cout << "|  2. View Fee Status  |" << endl;
			cout << "|  3. Exit             |" << endl;
			cout << "-----------------------" << endl;
			cout << "|   Enter : ";		cin >> opp;
			cout << "-----------------------" << endl << endl;
		} while (opp != '1' && opp != '2' && opp != '3');

		do
		{
			switch (opp)
			{
			case ('1'):
				cout << "Enter your roll no : ";	cin >> rr;
				//This will show student marks
				break;

			case ('2'):
				cout << "Enter your roll no : ";	cin >> rr;
				//This will show student fee
				break;

			case ('3'):
				cout << "Thank You !" << endl;
				exit(0);
				break;
			}
		} while (exit);
		break;


	}
	system("pause");
	return 0;
}

void Student::enterData()
{

	ofstream stfile("student_data.txt", ios::app);
	int op;
	while (1)
	{
		cout << " Enter First Name  : ";		cin >> firstName;
		cout << " Enter Last Name   : ";		cin >> lastName;
		cout << " Enter Class       : ";		cin >> Class;
		cout << " Enter Roll Num    : " << Class << "-"; 	cin >> rollNo;
		cout << " Enter Regis Date  : ";		cin >> registrationDate;
		cout << " Enter Gender(M/F) : ";		cin >> Gender;
		cout << " Enter Contact Num : ";		cin >> contactNo;
		//while (sizeof(contactNo) != 11)
		//{
			//cin >> contactNo;
		//}
		cout << " Enter Father Name : ";		cin >> fatherName;
		cout << " Father Profession : ";		cin >> fatherProfession;
		cout << " Father Contact No.: ";		cin >> contactNo;
		cout << " Fee Submitted     : ";		cin >> feeSubmitted;
		cout << " Enter Blood Group : ";		cin >> bloodGroup;
		cout << " Enter Address     : ";		cin >> Address;
		cout << endl;

		/*
		////////////////following is code to input in file
		*/
		if (stfile.is_open())		//Checking for if the file is open or not
		{
			stfile << "\n					student # " << rollNo << endl << endl;
			stfile << " First-Name        : ";		 stfile << firstName << endl;
			stfile << " Last-Name         : ";		 stfile << lastName << endl;
			stfile << " Class             : ";		 stfile << Class << endl;
			stfile << " Roll#             : "; 	     stfile << rollNo << endl;
			stfile << " Regis-Date        : ";		 stfile << registrationDate << endl;
			stfile << " Gender(M/F)       : ";		 stfile << Gender << endl;
			stfile << " Contact NO        : ";		 stfile << contactNo << endl;
			stfile << " Father-Name       : ";		 stfile << fatherName << endl;
			stfile << " Father Profession : ";		 stfile << fatherProfession << endl;
			stfile << " Father Contact No.: ";		 stfile << contactNo << endl;
			stfile << " Fee Submitted     : ";		 stfile << feeSubmitted << endl;
			stfile << " Blood Group       : ";		 stfile << bloodGroup << endl;
			stfile << " Enter Address     : ";		 stfile << Address << endl;
		}
		else
		{
			cout << "Unable to open file";
		}

		cout << " Enter More Students ? " << endl;
		cout << " Yes=1 ; No=0 : ";				cin >> op;

		if (op == 0)
		{
			break;
		}
	}
}

//Input function of Teacher
void Teacher::enter_TeacherData()
{
	ofstream stfile("teacher_data.txt", ios::app);

	int op;
	while (1)
	{
		cout << " Enter First Name   : ";		cin >> FirstName;
		cout << " Enter Last Name    : ";		cin >> LastName;
		cout << " Enter Email        : ";		cin >> Email;
		cout << " Enter Joining Date : ";		cin >> JoiningDate;
		cout << " Enter Password     : ";		cin >> Password;
		cout << " Enter Confirm Pass : ";		cin >> ConfirmPassword;
		while (chkpass(Password, ConfirmPassword) != true)
		{
			chkpass(Password, ConfirmPassword);
		}
		cout << " Enter Teacher CNIC  : ";		cin >> CNIC;
		cout << " Enter Teacher Gender: ";		cin >> gender;
		cout << " Enter Qualification : ";		cin >> Qualification;
		cout << " Enter Contact Num   : ";		cin >> ContactNo;
		cout << " Enter Date of Birth : ";		cin >> DOB;
		cout << " Enter Address       : ";		cin >> address;
		cout << " Enter Teacher Salary: Rs/-";		cin >> Salary;
		cout << endl;

		if (stfile.is_open())		//Checking for if the file is open or not
		{
			stfile << "\n					Teacher # " << CNIC << endl << endl;
			stfile << " First-Name   : ";		 stfile << FirstName << endl;
			stfile << " Last-Name    : ";		 stfile << LastName << endl;
			stfile << " Email        : ";		 stfile << Email << endl;
			stfile << " Joining-Date : "; 	     stfile << JoiningDate << endl;
			stfile << " Password     : ";		 stfile << Password << endl;
			stfile << " CNIC         : ";		 stfile << CNIC << endl;
			stfile << " Gender       : ";		 stfile << gender << endl;
			stfile << " Qualification: ";		 stfile << Qualification << endl;
			stfile << " Contact-No   : ";		 stfile << ContactNo << endl;
			stfile << " Date OF Birth: ";		 stfile << DOB << endl;
			stfile << " Address      : ";		 stfile << address << endl;
			stfile << " Salary       : ";		 stfile << Salary << endl;
		}
		else
		{
			cout << "Unable to open file";
		}

		cout << " Enter More Teacher ? " << endl;
		cout << " Yes=1 ; No=0 : ";				cin >> op;

		if (op == 0)
		{
			break;
		}
	}
}
//Function for checking password
bool Teacher::chkpass(string pass, string conpass)
{
	if (Password.compare(ConfirmPassword) == 0)
	{
		return true;
	}
	else
	{
		cout << endl;
		cout << "Incorrect Password !";
		cout << "Enter Pass Again : ";		cin >> ConfirmPassword;
	}
}

void Course::enter_CourseData()
{
	cout << " Enter Course Name : ";		cin >> CourseName;
	cout << " Enter Cousre Code : ";		cin >> CourseCode;
	cout << " Enter Class       : ";		cin >> SelectClass;
	cout << " Parent Course     : ";		cin >> ParentCourse;

	ofstream stfile("course_data.txt", ios::app);

	int op;
	while (1)
	{
		if (stfile.is_open())		//Checking for if the file is open or not
		{
			stfile << "\n					Course # " << CourseCode << endl << endl;
			stfile << " Course-Name  : ";		 stfile << CourseName << endl;
			stfile << " Course-Code  : ";		 stfile << CourseCode << endl;
			stfile << " Class        : ";		 stfile << SelectClass << endl;
			stfile << " Parent-Code  : "; 	     stfile << ParentCourse << endl;
		}
		else
		{
			cout << "Unable to open file";
		}

		cout << " Enter More Course ? " << endl;
		cout << " Yes=1 ; No=0 : ";				cin >> op;

		if (op == 0)
		{
			break;
		}
	}
}

void Student::edit_StudentData(string roll)
{
	bool z = 0;
	int count = 0;
	string var[7];
	var[5] = roll;
	string sort = "\t\t\t\t\tstudent # " + var[5];

	///////////declaring files
	ifstream oldfile("student_data.txt");   ////////it will open file to read data
	ofstream newfile("new_student_file.txt", ios::app);   /////it will make new file 
	while (oldfile)
	{
		getline(oldfile, var[6]);  //////// this will read lines from old file
		if (newfile.is_open())		////condition to check either file is open or not
		{
			if (var[6] == sort)
			{
				z = 1;
			}
			if (z)
			{
				if (count != 15)
				{
					if (count == 2 || count == 3 || count == 8 || count == 12 || count == 14)
					{
						if (count == 2)
						{
							cout << " Enter First-Name   : ";		cin >> var[0];
							newfile << " First-Name  : ";		 newfile << var[0] << endl;
						}
						else if (count == 3)
						{
							cout << " Enter Last-Name    : ";		cin >> var[1];
							newfile << " Last-Name   : ";		 newfile << var[1] << endl;
						}
						else if (count == 8)
						{
							cout << " Enter Contact No.  : ";		cin >> var[2];
							newfile << " Contact NO : ";		 newfile << var[2] << endl;
						}
						else if (count == 12)
						{
							cout << " Enter Fee Submitted: ";		cin >> var[3];
							newfile << " Fee Submitted     : ";		 newfile << var[3] << endl;
						}
						else if (count == 14)
						{
							cout << " Enter Address     : ";		cin >> var[4];
							newfile << " Enter Address     : ";		 newfile << var[4] << endl;
						}
						count++;
					}
					else
					{
						count++;
						newfile << var[6] << endl;
					}

				}
				else if (count == 15)
				{
					count++;
					newfile << var[6] << endl;
				}
			}
			else
			{
				newfile << var[6] << endl;
			}
		}
		else
		{
			cout << "Unable to open file" << endl;
		}
	}
	/* file remove karnay k lea or name change karnay k lea pahlay file close karna zaroori ha*/
	oldfile.close();
	newfile.close();
	remove("student_data.txt");     /////purani file deleat kar day ga
	rename("new_student_file.txt", "student_data.txt");   ////name change karay ga file ka
}

void Teacher::edit_TeacherData(string cnic)
{
	//Qualification
	//Contact No
	//Address
	//Salary
	string var[6];
	bool z = 0;
	int count = 0;
	var[4] = cnic;
	string sort = "\t\t\t\t\tTeacher # " + var[4];

	///////////declaring files
	ifstream oldfile("teacher_data.txt");   ////////it will open file to read data
	ofstream newfile("new_teacher_data.txt", ios::app);   /////it will make new file 
	while (oldfile)
	{
		getline(oldfile, var[5]);  //////// this will read lines from old file
		if (newfile.is_open())		////condition to check either file is open or not
		{
			if (var[5] == sort)
			{
				z = 1;
			}
			if (z)
			{
				if (count != 15)
				{
					if (count == 9 || count == 10 || count == 12 || count == 13)
					{
						if (count == 9)
						{
							cout << " Enter new Qualification   : ";		cin >> var[0];
							newfile << " Qualification: ";		 newfile << var[0] << endl;
						}
						else if (count == 10)
						{
							cout << " Enter new Contact-No    : ";		cin >> var[1];
							newfile << " Contact-No   : ";		 newfile << var[1] << endl;
						}
						else if (count == 12)
						{
							cout << " Enter new Address: ";		cin >> var[2];
							newfile << " nee Address  : ";		 newfile << var[2] << endl;
						}
						else if (count == 13)
						{
							cout << " Enter Salary     : ";		cin >> var[3];
							newfile << " Salary       : ";		 newfile << var[3] << endl;
						}
						count++;
					}
					else
					{
						count++;
						newfile << var[5] << endl;
					}
				}
				else if (count == 15) ///this case will execute only when count will be 15 
				{
					count++;
					newfile << var[5] << endl;
				}
			}
			else
			{
				newfile << var[5] << endl;
			}
		}
		else
		{
			cout << "Unable to open file" << endl;
		}
	}
	/* file remove karnay k lea or name change karnay k lea pahlay file close karna zaroori ha*/
	oldfile.close();
	newfile.close();
	remove("teacher_data.txt");     /////purani file deleat kar day ga
	rename("new_teacher_data.txt", "teacher_data.txt");   ////name change karay ga file ka




}
//////////this is funtion to display all student 
void Student::diaplay_student()
{
	ifstream stfile("student_data.txt");
	string line;
	while (stfile)
	{
		getline(stfile, line);
		cout << line << endl;
	}
	stfile.close();
}
//////////this is funtion to display all teachers 
void Teacher::diaplay_teacher()
{
	ifstream stfile("teacher_data.txt");
	string line;
	while (stfile)
	{
		getline(stfile, line);
		cout << line << endl;
	}
	stfile.close();
}

void marks::updateMarks()
{
	int opp;
	//string classs;
	//cout << "Enter Class : ";	cin >> classs;
	cout << "do u want to enter number of full class press 1 if indiviual student prss0\n";
	cin >> opp;
	switch (opp)
	{
	case 1:
	{
		string cla;
		cout << "enter class do u want to enter number\n";
		cin >> cla;
		string var[16];
		string line;
		string sort = " Enter Class       : " + cla;
		int i = 0;
		ifstream student_file("student_data.txt");
		ofstream marks_file("marks_file.txt", ios::app);
		while (student_file)
		{
			getline(student_file, line);

			var[i] = line;
			if (line == sort)
			{
				int a, b;
				cout << "enter the marks of assignment 1: ";
				cin >> a;
				cout << "enter the marks of assignment 2 : ";
				cin >> b;
				for (int j = 0; j < 6; j++)
				{
					marks_file << var[j] << endl;
				}
				marks_file << " assignment 1 :" << a << "/50" << endl;
				marks_file << " assignment 2 :" << b << "/50" << endl;
				marks_file << " total marks " << a + b << "/100 " << endl;
				//i = 0;
			}
			i++;
			if (i == 16)
			{
				i = 0;
			}

		}

	}
	}




	//Now it will search the student by class and update the marks

	//Ab aysa hoga k wo jis nam ka bacha hoga us nam ko ek new file may store krana hai 
	//Or user sy new marks poochny hain out of 100
	//or usko store kra dyna new file may !
	//Uski class uska roll uska nam or sary marks
}

void marks::showMarks()
{
	string claaas;
	cout << "Enter Class : ";	cin >> claaas;
	//Now it will display all the students marks of the specific class

}

void Student::feeStatus()
{
	string roll; //////////ya var roll no. enter karnay k lea ha baaaad ma bay shak es funtion ko parameter ma roll no.  day dayna
	cout << "ENTER THE ROLL NUMBERF OF STUDENT\n";
	cin >> roll;
	string sort = "\t\t\t\t\tstudent # " + roll;
	string line;
	bool z = 0;
	int count = 0;
	//This will display all the students :
	// 1. Full Name 
	// 2. Roll
	// 3. Fee Status
	ifstream file("student_data.txt");
	while (file)
	{
		getline(file, line);
		if (line == sort)
		{
			z = 1;
			cout << sort << endl;
		}
		if (z)
		{
			if (count != 15)
			{
				if (count == 2 || count == 3 || count == 12)
				{
					if (count == 2)
					{
						cout << line << endl;
					}
					else if (count == 3)
					{
						cout << line << endl;
					}
					else if (count == 12)
					{
						cout << line << endl;
					}

				}

				count++;
			}
		}

	}
}