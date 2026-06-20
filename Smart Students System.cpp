#include<iostream>
#include<vector>
#include<limits>
#include<string>
#include<iomanip>

using namespace std;

enum Grade {FAIL, PASS, GOOD, EXCELLENT};

struct Student {
	string Name;
	int Age;
	double GPA;
	int ID;
	Grade grade;
};

// Integers Functions
int Read_Int() {
	int num;
	while (true) {
		cin >> num;

		if (cin.fail()) {
			cout << "Invalid input, Enter A Number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			return num;
		}
	}
}

// Double Functions
double Read_Double() {
	double num;

	while (true) {
		cin >> num;

		if (cin.fail()) {
			cout << "Invalid Input, Enter A Number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			return num;
		}
	}
}


// Add Student Function
void Add_Student(vector<Student>& s) {
	
	// Defint Element In Vector
	Student S;
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// Student Ditails Prompt & Inputs
	cout << "Enter Student First & Second Name => ";
	getline(cin, S.Name);
	cout << "Enter Student Age => ";
	S.Age = Read_Int();
	cout << "Enter Student ID => ";
	S.ID = Read_Int();
	cout << "Enter Student GPA => ";
	S.GPA = Read_Double();

	// Grade Statements
	if (S.GPA >= 3.5) {
		S.grade = EXCELLENT;
	}
	else if (S.GPA >= 2.5 && S.GPA < 3.5) {
		S.grade = GOOD;
	}
	else if (S.GPA < 2.5 && S.GPA >= 2) {
		S.grade = PASS;
	}
	else if (S.GPA < 2) {
		S.grade = FAIL;
	}

	// Add A New Student To The Vector
	s.push_back(S);
}

// Grade Func
string Grade_String(Grade Grade) {
	switch (Grade) {
	case FAIL: return "FAIL";
	case PASS: return "PASS";
	case GOOD: return "GOOD";
	case EXCELLENT: return "EXCELLENT";
	default: return "Unknown";
	}
}

// Show Student Function
void Show_All_Student(const vector<Student>& s) {
	// Loop To Show Student Details
	for (int i = 0; i < s.size(); i++) {
		cout << "Student ( " << (i + 1) << " ) : \n";
		cout << "Student Name => " << s[i].Name << endl;
		cout << "Student ID => " << s[i].ID << endl;
		cout << "Student Age => " << s[i].Age << endl;
		cout << "Student GPA => " << s[i].GPA << endl;
		cout << "Student Grade => " << Grade_String(s[i].grade) << endl;
		cout << "====================\n";
	}
}

// Search Student Function
void Search_Student(const vector<Student>& s) {
	int Search_Way;
	int S_id;
	string S_name;
	cout << "Choose Search Way : \n";
	cout << "(1) ID : (2) Name => ";
	Search_Way = Read_Int();
	// Choose Search Way	
	switch (Search_Way) {
	case 1: {
		bool found = false;
		// Search With ID
		cout << "Enter Student ID => ";
		S_id = Read_Int();
		for (int i = 0; i < s.size(); i++) {
			if (S_id == s[i].ID) {
				found = true;

				cout << "Student Name => " << s[i].Name << endl;
				cout << "Student Age => " << s[i].Age << endl;
				cout << "Student GPA => " << s[i].GPA << endl;
				cout << "Student ID => " << s[i].ID << endl;
			}
		}

		if (!found) {
			cout << "\nStudent Was Not Found\n";
		}

		break;
	}
	case 2: {
		bool found = false;
		// Search With Name
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Student First & Second Name => ";
		getline(cin, S_name);
		for (int i = 0; i < s.size(); i++) {
			if (S_name == s[i].Name) {
				found = true;

				cout << "Student Name => " << s[i].Name << endl;
				cout << "Student Age => " << s[i].Age << endl;
				cout << "Student GPA => " << s[i].GPA << endl;
				cout << "Student ID => " << s[i].ID << endl;
			}
		}

		if (!found) {
			cout << "\nStudent Was Not Found\n";
		}

		break;
	}
	}
}

// Delete Student Function
void Delete_Student(vector<Student>& s) {
	int S_id;
	string S_name;
	int Search_Way;
	int Delete_Sureness;
	cout << "(1)ID : (2)Name => ";
	Search_Way = Read_Int();
	// Delete & Search Way
	switch (Search_Way) {
	// If ID
	case 1: {
		bool found = false;
		cout << "Enter Student ID => ";
		S_id = Read_Int();
		for (int i = 0; i < s.size(); i++) {
			if (S_id == s[i].ID) {
				found = true;
				cout << "Student Number => " << (i + 1) << "\n";
				cout << "Student Name => " << s[i].Name << "\n";
				cout << "Are You Sure You Want To Delete This Student ? (1)Y / (2)N => ";
				Delete_Sureness = Read_Int();
				switch (Delete_Sureness) {
				// If Yes
				case 1: {
					s.erase(s.begin() + i);
					cout << "\nStudent Deleted Successfully\n";
					break;
				}
				// If No
				case 2: {
					cout << "\nOk\n";
					break;
				}
				}
					
			}
			
		}

		if (!found) {
			cout << "\nStudent Was Not Found\n";
		}

		break;

	}
	// If Name
	case 2: {
		bool found = false;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Student Name => ";
		getline(cin, S_name);
		for (int i = 0; i < s.size(); i++) {
			if (S_name == s[i].Name) {
				found = true;
				cout << "Student Number => " << (i + 1) << "\n";
				cout << "Student ID => " << s[i].ID << "\n";
				cout << "Are You Sure You Want To Delete This Student ? (1)Y / (2)N => ";
				Delete_Sureness = Read_Int();
				switch (Delete_Sureness) {
				// If Yes
				case 1: {
					s.erase(s.begin() + i);
					cout << "\nStudent Deleted Successfully\n";
					break;
				}
				// If No
				case 2: {
					cout << "\nOk\n";
					break;
				}
				}
			}
			
		}

		if (!found) {
			cout << "\nStudent Was Not Found\n";
		}

		break;
	}
	}
}

// Update Student Function
void Update_Student(vector<Student>& s) {
	// Define Variables
	int S_id;
	string S_name;
	int Choose;

	int Update_Choose;
	// Search Way
	cout << "Search With (1)Name / (2)ID => ";
	Choose = Read_Int();
	switch (Choose) {
	case 1: {
		bool found = false;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Student Name => ";
		getline(cin, S_name);
		for (int i = 0; i < s.size(); i++) {
			if (S_name == s[i].Name) {
				found = true;
				cout << "Student Name => " << s[i].Name << "\n";
				cout << "Student ID => " << s[i].ID << "\n";
				cout << "Student Age => " << s[i].Age << "\n";
				cout << "Student GPA => " << s[i].GPA << "\n";
				bool ok = true;
				do {
					cout << "\n(1) Name\n";
					cout << "\n(2) ID\n";
					cout << "\n(3) Age\n";
					cout << "\n(4) GPA\n";
					cout << "\n(5) No Edit\n";
					cout << "What You Want To Update ? => ";
					Update_Choose = Read_Int();
					switch (Update_Choose) {
					case 1: {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\nEnter Student New Name => ";
						getline(cin, s[i].Name);
						break;
					}
					case 2: {
						cout << "\nEnter Student New ID => ";
						s[i].ID = Read_Int();
						break;
					}
					case 3: {
						cout << "\nEnter Student New Age => ";
						s[i].Age = Read_Int();
						break;
					}
					case 4: {
						cout << "\nEnter Student New GPA => ";
						s[i].GPA = Read_Double();
						if (s[i].GPA >= 3.5) {
							s[i].grade = EXCELLENT;
						}
						else if (s[i].GPA >= 2.5 && s[i].GPA < 3.5) {
							s[i].grade = GOOD;
						}
						else if (s[i].GPA < 2.5 && s[i].GPA >= 2) {
							s[i].grade = PASS;
						}
						else if (s[i].GPA < 2) {
							s[i].grade = FAIL;
						}
						break;
					}
					case 5: {
						ok = false;
						cout << "\nOK\n";
					}
						  break;
					}
				} while (ok);

			}
		}

		if (!found) {
			cout << "\nStudent Was Not Found\n";
		}

		break;
	}
	case 2: {
		bool found = false;
		cout << "Enter Student ID => ";
		S_id = Read_Int();
		for (int i = 0; i < s.size(); i++) {
			if (S_id == s[i].ID) {
				found = true;

				cout << "Student Name => " << s[i].Name << "\n";
				cout << "Student ID => " << s[i].ID << "\n";
				cout << "Student Age => " << s[i].Age << "\n";
				cout << "Student GPA => " << s[i].GPA << "\n";
				bool ok = true;
				do {
					cout << "\n(1) Name\n";
					cout << "\n(2) ID\n";
					cout << "\n(3) Age\n";
					cout << "\n(4) GPA\n";
					cout << "\n(5) No Edit\n";
					cout << "What You Want To Update ? => ";
					Update_Choose = Read_Int();
					switch (Update_Choose) {
					case 1: {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\nEnter Student New Name => ";
						getline(cin, s[i].Name);
						break;
					}
					case 2: {
						cout << "\nEnter Student New ID => ";
						s[i].ID = Read_Int();
						break;
					}
					case 3: {
						cout << "\nEnter Student New Age => ";
						s[i].Age = Read_Int();
						break;
					}
					case 4: {
						cout << "\nEnter Student New GPA => ";
						s[i].GPA = Read_Double();
						break;
					}
					case 5: {
						ok = false;
						cout << "\nOK\n";
						break;
					}
					}
				} while (ok);
			}

		}

		if (!found) {
			cout << "\nStudent Was Not Found\n";
		}

		break;
	}
	}
}

// Statics Function
void Static_Student(vector<Student>& s) {
	// Define Variables
	double max_gpa = 0 , min_gpa = 4;
	int number_of_successed{ 0 }, number_of_faild{ 0 };
	// Max GPA
	for (int i = 0; i < s.size(); i++) {
		if (s[i].GPA > max_gpa) {
			max_gpa = s[i].GPA;
		}
	}

	// Min GPA
	for (int i = 0; i < s.size(); i++) {
		if (s[i].GPA < min_gpa) {
			min_gpa = s[i].GPA;
		}
	}

	// Number Of Successed & Faild Students
	for (int i = 0; i < s.size(); i++) {
		// Successed
		if (s[i].GPA >= 2) {
			number_of_successed++;
		}
		
		// Faild
		if (s[i].GPA < 2) {
			number_of_faild++;
		}
	}
	cout << "Highest GPA => " << max_gpa << "\n";
	cout << "Lowest GPA => " << min_gpa << "\n";
	cout << "Number Of Successed Students => " << number_of_successed << "\n";
	cout << "Number Of Faild Students => " << number_of_faild << "\n";
}

// Exit System Function
bool Exit(bool& e) {
	return e = false;
}

int main()
{
	// Define Variables In Main Function
	vector<Student> Student_Vector;
	bool state = true;
	int choose = 0;
	
	cout << setprecision(3);
	
	// System Welcome Message
	cout << "    ====== Student System ======\n\n\n";

	do {
		// Menu Prompt
		cout << "\nMenu : \n\n";
		cout << "(1) Add Student\n";
		cout << "(2) Show All Student\n";
		cout << "(3) Search Student (Name / ID)\n";
		cout << "(4) Delete Student\n";
		cout << "(5) Update Student\n";
		cout << "(6) Statics\n";
		cout << "(7) Exit\n\n";
		// Choose Input & Prompt
		cout << "Choose Number Of Operation => ";
		choose = Read_Int();
		cout << "\n\n";
		switch (choose) {
		case 1: Add_Student(Student_Vector);
			break;
		case 2: Show_All_Student(Student_Vector);
			break;
		case 3 : Search_Student(Student_Vector);
			break;
		case 4: Delete_Student(Student_Vector);
			break;
		case 5: Update_Student(Student_Vector);
			break;
		case 6: Static_Student(Student_Vector);
			break;
		case 7: Exit(state);
			break;
		default: cout << "Invalid Choice\n";
		}

	} while (state);


	return 0;
}