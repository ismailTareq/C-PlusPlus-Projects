#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <vector>
#include <memory>
#include "Course.h"
#include "courses_manager.h"
#include "assignment.h"
#include "Assignment_Solution.h"

using namespace std;

namespace Faculty
{
    class Course;

    class Student
	{
	public:
		Student();
		Student(const Student &st);
		Student(string a, string b, string c, string d,string e);
		string first_name, last_name, email, id,password;
		vector<shared_ptr<Course>> registered_courses;
		void show_registered_courses();
		void Menu();
		void Register_new_course();
		void unregister_from_course(string _course_code);
		void view_student_course_inf();
	};
}











#endif // STUDENT_H_
