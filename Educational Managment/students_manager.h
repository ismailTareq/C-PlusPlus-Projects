#ifndef STUDENT_MANAGER_H_
#define STUDENT_MANAGER_H_

#include<vector>
#include<memory>
#include "Student.h"
using std::vector;
using std::string;
using std::shared_ptr;

namespace Faculty
{
    class Student;

    class students_manager
    {
    public:
        students_manager();

        void add_NewStudent(Student a);

        vector<shared_ptr<Student>> students;
    };
    extern shared_ptr<students_manager> _students_manager;
}







#endif // STUDENT_MANAGER_H_
