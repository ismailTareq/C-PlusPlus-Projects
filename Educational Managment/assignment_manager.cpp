#include "assignment_manager.h"


namespace Faculty
{
    assignment_manager::assignment_manager()
    {

    }
    assignment_manager::assignment_manager(string a,int b)
    :assignment_inf{a},max_grade{b}
    {

    }
    void assignment_manager::view_assignment()
    {
        cout << "Please choose one of the following option:" << '\n';
		int selection;
		cout << "\t1 - Show Info" << '\n';
		cout << "\t2 - Show grades Report" << '\n';
		cout << "\t3 - List Solutions" << '\n';
		cout << "\t4 - View Solution" << '\n';
		cout << "\t5 -  Back" << '\n';
		cout << "Enter your choice: " ;
		cin >> selection;
		/*// ignore invalid input such as char instead of int
		while(cin.fail())
        {
            cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Choice, Please try again\n";
			cout << "Enter your choice: ";
			cin >> option;
        }*/
        if(selection == 1)
        {
            cout << assignment_inf << "\n\n\n";
        }
        else if(selection == 2)
        {
            grades_report();
        }
        else if(selection == 3)
        {
            list_students_solutions();
        }
        else if(selection == 4)
        {
            view_student_solution();
        }
        else if(selection == 5)
        {
            return;
        }
        else
        {
			cout << "Invalid Option ... Taking you back to your Menu\n\n\n";
		}
		view_assignment();

    }
    void assignment_manager::grades_report()
    {
        cout << "Student Grades:\n";
        for(auto ass:assignment_submissions)
        {
            cout << "Student id: " << ass->owner << " Grade: " << ass->grade << "\n";
        }
        cout << "\n\n\n\n";
    }
    void assignment_manager::list_students_solutions()
    {
        cout << "Student Grades:\n";
        for(auto ass:assignment_submissions)
        {
            cout << "Student id: " << ass->owner << " Solution: " << ass->solution << "\n";
        }
        cout << "\n\n\n\n";
    }
    void assignment_manager::view_student_solution()
    {
        list_students_solutions();
        string id;
        cout << "Please enter student id: ";
        cin >> id;
        for(auto ass:assignment_submissions)
        {
            if(ass->owner == id)
            {
                int selection;
				cout << "Please choose ine of the following options:\n";
				cout << "\t1 - Set-grade\n";
				cout << "\t2 - back";
				cout << "Enter your choice: " << '\n';
				cin >> selection;

				if(selection == 1)
                {
                    cout <<"Please enter student grade: ";
                    cin >> ass->grade;
                }
                else if(selection == 2)
                {
                    return;
                }
                else
                {
                    cout << "Invalid Option, Please try again \n\n\n\n";
					view_student_solution();
                }

            }

        }
        cout << "Invalid id, Please try again \n\n\n\n";
		view_student_solution();
    }
}













