#include "Student.h"
#include <iomanip>
namespace Faculty
{
    Student::Student()
    {

    }
    Student::Student(const Student &st)
    {
        first_name = st.first_name;
        last_name = st.last_name;
        email = st.email;
        id = st.id;
        password = st.password;
    }
    Student::Student(string a, string b, string c, string d,string e)
    :first_name{a},last_name{b},email{c},id{d},password{e}
    {

    }

    void Student::show_registered_courses()
    {
        // handle if he hasn't reigster in any course yet
		if (registered_courses.size() == 0)
        {
			cout << "you havn't register in any Course yet.\n\n\n\n";
			Menu();
			return;
		}
		cout << "Your Registered Courses:\n";
		for (auto all_courses : registered_courses)
			cout << "Course " << all_courses->course_name << " - Code " << all_courses->course_code << " - Doc " << all_courses->course_doctor << '\n';
		cout << "\n\n\n\n";
		return;
    }
    void Student::Menu()
    {
        cout <<setw(20)<< "welcome "<<first_name<<" "<<last_name<<endl;
        cout << "Please choose one of the following option:" << '\n';
		int selection;
		cout << "\t1 - Register in a course" << '\n';
		cout << "\t2 - List My courses" << '\n';
		cout << "\t3 - view course" << '\n';
		cout << "\t4 - log out" << '\n';
		cout << "Enter your choice: ";
		cin >> selection;
		cout << "\n\n\n";
		if (selection == 1){
			Register_new_course();
			Menu();
			return;
		}
		else if (selection == 2){
			show_registered_courses();
			Menu();
			return;
		}
		else if (selection == 3){
			view_student_course_inf();
			Menu();
			return;
		}
		else if (selection == 4){
			return;
		}
		else{
			cout << "Invalid Option ... Taking you back to your Menu\n\n\n";
		}
		return;

    }
    void Student::Register_new_course()
    {
        cout << "Available Courses to register in:\n";
        for(auto new_course : _courses_manager->courses)
        {
            bool taken =false;
            for(auto cur_course : registered_courses)
            {
                if(new_course == cur_course)
                {
                    taken =true;
                    break;
                }

            }
            // he hasn't registered in this course before
            if(!taken)
            {
                cout << "Course name: " << new_course->course_name << "   Code: " << new_course->course_code << "   Taught by Dr: " << new_course->course_doctor << '\n';

            }
        }
        string choose_course;
		cout << "\n\nplease Enter the course code you want to register on: ";
		cin >> choose_course;
		for(auto new_course : _courses_manager->courses)
        {
            if(new_course->course_code == choose_course)
            {
                cout << "You have successfully registered in course " << new_course->course_doctor << " with doc: "<< new_course->course_doctor << '\n';
                // add the course to the student registered courses
                shared_ptr<Course> n_course(new Course(new_course->course_name,new_course->course_code,new_course->course_doctor));
                registered_courses.push_back(n_course);
                // add the student to the course registered student
                shared_ptr<Student>n_student(new Student(first_name,last_name,email,id,password));

                // successfully registered in a new course
                new_course->registered_students.push_back(n_student);
                cout << "\n\n\n";
				// successfully registered in a new course
				return;
            }
        }
        // unsuccessful registeration
		cout << "Invalid Course Code.. taking you back to your menu\n\n\n";
		Menu();
		return;
    }
    void Student::unregister_from_course(string _course_code)
    {
        for(auto old_course : _courses_manager->courses)
        {
            if(_course_code == old_course->course_code )
            {
                int cur = 0;
                // remove the student from the registered students in the course
                for(auto stud:old_course->registered_students)
                {
                    if(stud->id == id)
                    {
                        old_course->registered_students.erase(old_course->registered_students.begin()+cur);
                        break;
                    }
                    cur++;
                }

                // remove the student assignments ( if he has any )
                for (auto ass : old_course->course_assignments)
                {
                    int cur = 0;
                    for(auto _ass : ass->assignment_submissions)
                    {
                        if(_ass->owner == id)
                        {
                            ass->assignment_submissions.erase(ass->assignment_submissions.begin()+cur);
                            break;
                        }
                        cur++;
                    }
                }
                // remove the course from the student courses list
                for (auto _course : registered_courses)
                {
                    int cur = 0;
                    if (_course->course_code == _course_code)
                    {
                        registered_courses.erase(registered_courses.begin() + cur);
                        break;
                    }
                    cur++;
                }
            }
            cout << "You have successuflly unregistered from course code: " << _course_code << '\n';
            return;
        }
    }
    void Student::view_student_course_inf()
    {
        if(registered_courses.size() == 0)
        {
            cout << "you havn't register in any Course yet.\n\n\n\n";
			Menu();
			return;
        }
    }





}

