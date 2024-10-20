#ifndef ASSIGNMENT_SOLUTION_H_
#define ASSIGNMENT_SOLUTION_H_

#include <string>
#include <vector>
#include <memory>
using std::vector;
using std::string;
using std::shared_ptr;


namespace Faculty
{
    struct Student;
    struct Assignment;

    struct AssignmentSolution
    {
        int grade;
        bool is_graded;
        string answer;
        string Assistant_Comments;
        shared_ptr<Assignment> assignment;
        shared_ptr<Student> student;
    };
}








#endif // ASSIGNMENT_SOLUTION_H_
