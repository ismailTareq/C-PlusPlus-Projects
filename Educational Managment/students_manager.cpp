#include "students_manager.h"

namespace Faculty{

	students_manager::students_manager()
	{

	}
	extern shared_ptr<students_manager> _students_manager(new students_manager());

	void students_manager::add_NewStudent(Student a)
	{
		shared_ptr<Student> ne(new Student(a));
		students.push_back(ne);
		return;
	}

}
