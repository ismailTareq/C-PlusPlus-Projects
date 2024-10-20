#ifndef COURSE_H_
#define COURSE_H_

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "Student.h"
#include "assignment.h"
#include "assignment_manager.h"

using namespace std;


namespace Faculty
{
    class Student;
    class assignment_manager;

    class Course
    {
    public:
        Course();
		Course(string a, string b, string c);

		string course_name;
		string course_code;
		string course_doctor;

		void show_registered_students();
		void view_student_course_inf(string cur_student_id);
		void view_doctor_course_inf();
		void list_course_assignment();
		void add_assignment();
		void select_assignment();

		vector<shared_ptr<assignment_manager>> course_assignments;
		vector<shared_ptr<Student>> registered_students;
    };
}


#endif // COURSE_H_
