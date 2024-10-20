#ifndef USERS_FLOW_CONTROLLER_H_
#define USERS_FLOW_CONTROLLER_H_

#include<iostream>
#include<string>
#include "students_manager.h"
#include "doctors_manager.h"
#include "assignment_manager.h"
#include "courses_manager.h"
#include <vector>
#include <fstream>

using namespace std;

namespace Faculty
{
    class Student;
    class Course;
    class assignment_manager;
    class SystemFlow
    {
    public:

        SystemFlow(){}
        void main_Menu();
		void Sign_in();
		void Sign_up();

		void load_doctors_courses_assignments();
		void load_students();

		void save_doctors_courses_assignments();
		void save_students();

		void show_students_data();
		void show_doctors_data();
    };
    extern shared_ptr<SystemFlow> system;
}






#endif // USERS_FLOW_CONTROLLER_H_
