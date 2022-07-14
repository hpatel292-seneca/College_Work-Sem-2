/*
*****************************************************************************
                          Workshop - #7
Full Name  : Harshil patel
Student ID#: 148847213
Email      : hpatel292@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#include "MemberParliament.h"
#define MAXNAMECHAR 50
namespace sdds
{
    class Minister :
        public MemberParliament
    {
        char m_name[MAXNAMECHAR]{};
        double m_begin_year{};
    public:
        Minister(const char* iid, int age, double year, const char* name, const char* district);
        void changePM(const char* pm);
        void assumeOffice(double year);
        std::ostream& write(std::ostream& os)const;
        std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& left, const Minister& right);
    std::istream& operator>>(std::istream& left, Minister& right);
}
#endif // !SDDS_MINISTER_H