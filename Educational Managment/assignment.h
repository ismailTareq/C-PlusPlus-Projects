#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_
#include <string>
#include <vector>
#include <memory>
using std::vector;
using std::string;
using std::shared_ptr;


namespace Faculty
{
    class Assignment
    {
    public:
        Assignment(){};
        Assignment(int a,string b, string c);
        int grade;
        string owner;
        string solution;

    };
}









#endif // ASSIGNMENT_H_
