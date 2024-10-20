#ifndef DOCTOR_MANAGER_H_
#define DOCTOR_MANAGER_H_

#include<vector>
#include<memory>
#include "Doctor.h"

using std::vector;
using std::string;
using std::shared_ptr;

namespace Faculty
{
    class Doctor;

    class doctors_manager
    {
    public:
        doctors_manager();

        void add_NewDoctor(Doctor d);

        vector<shared_ptr<Doctor>> doctors;
    };
    extern shared_ptr<doctors_manager> _doctors_manager;
}










#endif // DOCTOR_MANAGER_H_
