#include "Doctor.h"
#include <iomanip>1

namespace Faculty
{
    Doctor::Doctor(string a, string b, string c,string d,string e)
    :first_name(a), last_name(b), email(c),id(d),password(e)
    {

    }
	Doctor::Doctor(const Doctor &a)
	{
		first_name = a.first_name;
		last_name = a.last_name;
		email = a.email;
		id = a.id;
		password = a.password;
	}

	void  Doctor::show_my_courses()
	{
	    cout << "Courses you are teaching:\n";
	    for(auto show_course : created_courses)
        {
            cout << "Course " << show_course->course_name << " - Code " << show_course->course_code << " - Doc " << show_course->course_doctor << '\n';
        }
        cout << "\n\n";
	}
    void  Doctor::Menu()
    {
        cout <<setw(20)<< "welcome "<<first_name<<" "<<last_name<<endl;
        cout << "Please choose one of the following option:" << '\n';
		int selection;
		cout << "\t1 - Create Course" << '\n';
		cout << "\t2 - List My courses" << '\n';
		cout << "\t3 - view course" << '\n';
		cout << "\t4 - log out" << '\n';
		cout << "Enter your choice: " ;
		cin >> selection;
		if (selection == 1){
			create_course();
			Menu();
		}
		else if (selection == 2){
			show_my_courses();
			Menu();
		}
		else if (selection == 3){
			show_my_courses();
			select_course();
			Menu();

		}
		else if (selection == 4){
			return;
		}
		else{
			// invalid option don't handle char instead of int ... this crush ... To-Do
			cout << "Invalid Option ... Taking you back to your Menu\n\n\n";
			Menu();

		}
		return;
    }
    void  Doctor::create_course()
    {
        // make the new course
		shared_ptr<Course> new_course(new Course());

		cout << "Please enter the Course name: ";
		cin >> new_course->course_name;

		cout << "Please enter the Course Code: ";
		cin >> new_course->course_code;

		new_course->course_doctor = first_name + " " + last_name;

		// add the course the the available courses list
		_courses_manager->courses.push_back(new_course);
		created_courses.push_back(new_course);
		cout << "Course has been successfully created\n\n\n";
		return;
    }
    void  Doctor::select_course()
    {
        string _code;
		cout << "Please Enter one of your courses code: ";
		cin >> _code;
		for (auto _course:created_courses)
        {
            if (_course->course_code == _code){
				cout << "\n\n\n";
				_course->view_doctor_course_inf();
				return;
			}
        }
		cout << "You have entered invalid code, Please try again\n\n\n\n";
		show_my_courses();
		select_course();
		return;
    }
}


