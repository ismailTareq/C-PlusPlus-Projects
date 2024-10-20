#include "User_Flow_control.h"

using namespace std;

int main()
{
    Faculty::SystemFlow sys;
    sys.load_doctors_courses_assignments();
    sys.load_students();
    sys.show_doctors_data();
    sys.show_students_data();
    sys.main_Menu();
    sys.save_doctors_courses_assignments();
    sys.save_students();
    return 0;
}
