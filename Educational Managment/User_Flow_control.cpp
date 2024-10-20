#include "User_Flow_control.h"



namespace Faculty
{

    extern shared_ptr<SystemFlow> system(new SystemFlow());

    void SystemFlow::main_Menu()
    {
        cout << "Please choose one of the following option:" << '\n';
		int selection;
		cout << "\t1 - Login" << '\n';
		cout << "\t2 - Sign up" << '\n';
		cout << "\t3 - Shutdown system" << '\n';
		cout << "Enter your choice: " ;
		cin >> selection;
		if (selection == 1){
			Sign_in();
		}
		else if (selection == 2){
			Sign_up();
		}
		else if (selection == 3){
			return;
		}
		else{
			cout << "Invalid Option ... Taking you back to your Menu\n\n\n";
			main_Menu();
		}
		return;
    }
    void SystemFlow::Sign_in()
    {
        cout << "Please enter your id and password\n";
        string _id,_password;
		cout << "Enter your id: ";
		cin >> _id;
		cout << "Enter your Password: ";
		cin >> _password;
		cout << "\n\n\n\n";
		// check user name and password in students
		bool logged_in = false;
		for(auto stud : _students_manager->students)
        {
            if((stud->id == _id )&&(stud->password == _password))
            {
                stud->Menu();
                logged_in = true;
            }
        }
        // check user name and password in doctors
        if(logged_in == false)
        {
            for(auto doc : _doctors_manager->doctors)
            {
                if((doc->id == _id )&&(doc->password == _password))
                {
                    doc->Menu();
                    logged_in = true;
                }
            }
        }
        if(logged_in == false)
        {
            cout << "Incorrect id/Password, Please try again\n\n\n\n";
        }
        system->main_Menu();
        return;
    }
    void SystemFlow::Sign_up()
    {
        string first_name, last_name, email, id, password;
        int selection;
		cout << "please Enter your first name: ";
		cin >> first_name;
		cout << "please Enter your last name: ";
		cin >> last_name;
		cout << "please Enter your email: ";
		cin >> email;
		cout << "please Enter your id: ";
		cin >> id;
		cout << "please Enter your password: ";
		cin >> password;
		cout << "Are you :\n";
		cout << "\t1 - A student\n";
		cout << "\t2 - A doctor\n";
		cout << "Enter your choice: ";
		cin >> selection;

		if(selection == 1)
        {
            for(auto stud:_students_manager->students)
            {
                if(stud->id == id)
                {
                    cout << "This id is already taken, go ahead and sign up again with different id\n\n\n";
					Sign_up();
					return;
                }
            }
        _students_manager->add_NewStudent(Student(first_name,last_name,email,id,password));
        }
        else if(selection == 2)
        {
            for(auto doc: _doctors_manager->doctors)
            {
                if(doc->id == id)
                {
                    cout << "This id is already taken, go ahead and sign up again with different id\n\n\n";
					Sign_up();
					return;
                }
            }
        _doctors_manager->add_NewDoctor(Doctor(first_name,last_name,email,id,password));
        }
        cout << "You have successfully registered, please  log in now.\n\n\n\n\n";
		main_Menu();
		return;
    }

    void SystemFlow::load_doctors_courses_assignments()
    {
        ifstream file("doctor.txt");
        if(file.fail())
            return;
        string _first_name, _last_name, _email, _id, _pass, _course;
		int numberOfCourses;

		while(file >> _first_name >> _last_name >> _email >> _id >> _pass >> numberOfCourses)
        {
            shared_ptr<Doctor> new_doctor(new Doctor(_first_name,_last_name,_email,_id,_pass));
            while(numberOfCourses--)
            {
                shared_ptr<Course> cor(new Course());
                file >> cor->course_name >> cor->course_code;
				cor->course_doctor = _first_name + " " + _last_name;

				int numberOfAssignments;
				file >> numberOfAssignments;
				while(numberOfAssignments--)
                {
                    shared_ptr<assignment_manager> new_assignment(new assignment_manager());
                    new_assignment->assignment_inf ="";
                    string _inf;
                    while(file >> _inf)
                    {
                        if(_inf[0] == '#')
                            break;
                        new_assignment->assignment_inf +=" " + _inf;
                    }

                    file >> new_assignment->max_grade;
                    cor->course_assignments.push_back(new_assignment);
                }
                _courses_manager->courses.push_back(cor);
                new_doctor->created_courses.push_back(cor);
            }
            _doctors_manager->doctors.push_back(new_doctor);
        }
        file.close();
        return;
    }
    void SystemFlow::load_students()
    {
        ifstream file("student.txt");
        if(file.fail())
            return;
        string _first_name, _last_name, _email, _id, _pass, _course;
		int numberOfCourses, _assignment_number, assignment_grade;
		string _course_name, _assignment_solution;
		bool _assignment_solution_done;

		while(file >> _first_name >> _last_name >> _email >> _id >> _pass >> numberOfCourses)
        {
            shared_ptr<Student> new_student(new Student(_first_name,_last_name,_email,_id,_pass));
            while(numberOfCourses--)
            {
                file >> _course_name >> _assignment_solution_done;
                for(auto cor : _courses_manager->courses)
                {
                    if(cor->course_name == _course_name)
                    {
                        if(_assignment_solution_done == 1)
                        {
                            file >> _assignment_number >> _assignment_solution >> assignment_grade;
                            shared_ptr<Assignment> new_assignment(new Assignment());
                            new_assignment->grade = assignment_grade;
							new_assignment->owner = new_student->id;
							new_assignment->solution = _assignment_solution;

							int assignments_counter = 1;

                            for(auto _course_assignments_number:cor->course_assignments)
                            {
                                if(assignments_counter == _assignment_number)
                                    _course_assignments_number->assignment_submissions.push_back(new_assignment);

                            }

                        }
                        new_student->registered_courses.push_back(cor);

                        cor->registered_students.push_back(new_student);
                        break;
                    }
                }


            }
            _students_manager->students.push_back(new_student);
        }
        file.close();
        return;
    }

    void SystemFlow::save_doctors_courses_assignments()
    {
        ofstream file("doctor.txt");
        if(file.fail())
            return;
        for(auto doc : _doctors_manager->doctors)
        {
            file << doc->first_name << " " << doc->last_name << " " << doc->email << " "
				<< doc->id << " " << doc->password << '\n';
			file << doc->created_courses.size() << '\n';

			for(auto cor:doc->created_courses)
            {
                file << cor->course_name << " " << cor->course_code << " ";
                if(cor->course_assignments.size() > 0)
                {
                    file << cor->course_assignments.size() << " ";
                    for(auto cor_ass : cor->course_assignments)
                    {
                        file << cor_ass->assignment_inf << " # " << cor_ass->max_grade << " ";
                    }
                    file << "\n";
                }
                else
                {
                    file << 0 << '\n';
                }
            }
            file << "\n";
        }
        file.close();
    }
    void SystemFlow::save_students()
    {
        ofstream file("student.txt");
        if(file.fail())
            return;
        for(auto stud : _students_manager->students)
        {
            file <<stud->first_name << " " << stud->last_name << " " << stud->email << " "
				<< stud->id << " " << stud->password << '\n';
            file << stud->registered_courses.size()<<endl;
        }
        file.close();
    }

    void SystemFlow::show_students_data()
    {
        cout << "students in the system\n";
        for(auto stud : _students_manager->students)
            cout << stud->id << " " << stud->password << endl;
    }
    void SystemFlow::show_doctors_data()
    {
        cout << "doctors in the system\n";
		for (auto doc : _doctors_manager->doctors)
			cout << doc->id << " " << doc->password << endl;
    }
}
