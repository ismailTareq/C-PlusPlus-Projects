#ifndef DOCTOR_H_
#define DOCTOR_H_
#include <iostream>
#include<vector>
#include<memory>
#include "Course.h"
#include "assignment_manager.h"
#include "courses_manager.h"
#include "doctors_manager.h"

using namespace std;

namespace Faculty
{
    class Course;

    class Doctor
    {
    public:
        Doctor(const Doctor &doc);
		Doctor(string a, string b, string c,string d,string e);
		string first_name, last_name, email,id,password;

		vector<shared_ptr<Course>> created_courses;

        void show_my_courses();
		void Menu();
		void create_course();
		void select_course();
    };


}











#endif // DOCTOR_H_
