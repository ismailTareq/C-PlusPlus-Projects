#ifndef COURSE_MANAGER_H_
#define COURSE_MANAGER_H_

#include <iostream>
#include<vector>
#include<memory>
#include "Course.h"
using namespace std;



namespace Faculty
{
	class Course;

	class courses_manager
	{
	public:
		courses_manager();
		vector<shared_ptr<Course>> courses;
	};
	extern shared_ptr<courses_manager> _courses_manager;
}


#endif
