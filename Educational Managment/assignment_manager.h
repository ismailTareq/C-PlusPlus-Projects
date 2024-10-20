#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include "assignment.h"

using namespace std;


namespace Faculty
{
    class Assignment;
    class assignment_manager
    {
    public:
        assignment_manager();
		assignment_manager(string a,int b);

		string assignment_inf;
		int max_grade;
        void view_assignment();
		void grades_report();
		void list_students_solutions();
		void view_student_solution();

		vector<shared_ptr<Assignment>> assignment_submissions;
    };
}

