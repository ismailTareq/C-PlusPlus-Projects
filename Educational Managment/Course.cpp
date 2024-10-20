#include "Course.h"

namespace Faculty
{
    Course::Course()
    {

    }
    Course::Course(string a, string b, string c)
    :course_name{a},course_code{b},course_doctor{c}
    {

    }

    void Course::show_registered_students()
    {
        cout << "Registered Students ID: ";
        for(auto stud:registered_students)
            cout<<stud->id;
        cout << "\n\n\n\n";
		return;
    }
    void Course::view_student_course_inf(string cur_student_id)
    {
        cout << "course " << course_name << " - code " << course_code << " - doc " << course_doctor << '\n';
		cout << "course has " << course_assignments.size() << " assignments\n";

		int assignment_number = 0;
		for(auto ass:course_assignments)
        {
            bool student_done_this_assignment = 0;
            for(auto stud:ass->assignment_submissions)
            {
                if(stud->owner == cur_student_id)
                {
                    cout << "Assignment " << ++assignment_number << " Submitted" << " - ";
                    if (stud->grade == -1)
						cout << "NA";
                    else
                        cout << stud->grade;
                    cout << " / " << ass->max_grade << "\n\n";
					student_done_this_assignment = true;
                }
            }
            // he havn't submit this assignment yet ( he might want to submit it now )
            if(student_done_this_assignment == false)
            {
                cout << "Do you want to submit this assignment now ?\n";
				cout << "\t1 - submit assignment now\n";
				cout << "\t2 - don't submit now\n";
				int selection;
				cout << "Enter your choice: ";
				cin >> selection;
				if(selection == 1)
                {
                    shared_ptr<Assignment> new_assignment(new Assignment());
                    cout << "Please Enter your Solution (one word): ";
					cin >> new_assignment->solution;
					new_assignment->grade = -1;
                    new_assignment->owner = cur_student_id;
                    ass->assignment_submissions.push_back(new_assignment);
                    cout << "MAX_GRADE :" << ass->max_grade << "\n";
					cout << "You've submitted you assignment successfully \n\n\n\n";
                }
            }
        }

    cout << "\n\n\n\n";
		return;
    }
    void Course::view_doctor_course_inf()
    {
        cout << "Please choose one of the following option:" << '\n';
		int selection;
		cout << "\t1 - List assignment" << '\n';
		cout << "\t2 - add assignment" << '\n';
		cout << "\t3 - View assignment" << '\n';
		cout << "\t4 -  Back" << '\n';
		cout << "Enter your choice: " ;
		cin >> selection;

		if (selection == 1){
			list_course_assignment();
		}
		else if (selection == 2){
			add_assignment();
		}
		else if (selection == 3){
			select_assignment();
		}
		else if (selection == 4){
			return;
		}
		view_doctor_course_inf();
		//return;
    }
    void Course::list_course_assignment()
    {
        cout << "This Couse Has " << course_assignments.size() << " assignments\n";
		int assignmentNumber = 0;
		for (auto assignment : course_assignments)
			cout << "Assignment " << ++assignmentNumber << ":" << assignment->assignment_inf <<
			", Grade:" << assignment->max_grade << '\n';
		cout << "\n\n\n";
    }
    void Course::add_assignment()
    {
        shared_ptr<assignment_manager> new_assignment(new assignment_manager());
		new_assignment->assignment_inf = "";
		cout << "Please enter some inf about the assignment ( end it with # in a sepearte word ):";
		string inf;
		while (cin >> inf){
			if (inf[0] == '#')
				break;
			new_assignment->assignment_inf += " " + inf;
		}
		cout << "Please enter max grade of the assignment :";
		cin >> new_assignment->max_grade;
		cout << "\n\n\n\n";
		course_assignments.push_back(new_assignment);
    }
    void Course::select_assignment()
    {
        int numberOfassignment = 0;
		for (auto ass : course_assignments)
        {
            cout << "Assignment number " << ++numberOfassignment << '\n';
			cout << "Enter one of the following option: \n";
			cout << "\t1 - view this assignment\n";
			cout << "\t2 - Continue\n";
			cout << "Enter your choice: ";
			int selection;
			cin >> selection;

			cout << "\n\n";
			if (selection == 1)
				ass->view_assignment();
			cout << "\n\n";
        }
    }
























}

