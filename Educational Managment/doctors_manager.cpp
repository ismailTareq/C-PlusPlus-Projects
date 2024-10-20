#include "doctors_manager.h"

namespace Faculty
{
    doctors_manager::doctors_manager()
    {

    }
    extern shared_ptr<doctors_manager> _doctors_manager(new doctors_manager());

    void doctors_manager::add_NewDoctor(Doctor d)
    {
        shared_ptr<Doctor>new_doc(new Doctor(d));
        doctors.push_back(new_doc);
        return;
    }
}
