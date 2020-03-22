/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms5
email : pchawla5@myseneca.ca
07 April 2019*/

#include <cstring>
#include <iomanip>
#include "Perishable.h"
#include "Date.h"
using namespace std;
namespace ama {
    

    Perishable::Perishable() : Product('P')
	{
        
	}
    
    Perishable::~Perishable()
	{
        
	}
    
    std::istream & ama::Perishable::read(std::istream & in, bool interractive)
	{
        Date temp;
        Product::read(in, interractive);
        if (isClear()){
            if (!interractive) {
                expiry.read(in);
				in.ignore();
            }else{
                cout << "    Expiry date (YYYY/MM/DD): ";
                temp.read(in);
                if(!temp.isGood()){
                   in.setstate(std::ios::failbit);
                   if(temp.status() == error_year){
                       message("Invalid Year in Date Entry");
                   }
                   else if(temp.status() == error_mon){
                       message("Invalid Month in Date Entry");
                   }
                   else if(temp.status() == error_day){
                       message("Invalid Day in Date Entry");
                   }
                   else{
                       message("Invalid Date Entry");
                   }
                }
                else
				{
                    expiry = temp;
                }
            }
        }
        return in;
    }
    
    std::ostream & ama::Perishable::write(std::ostream & out, int writeMode) const
	{
        Product::write(out, writeMode);
		if (isClear() && !isEmpty())
		{
			if (writeMode == 0) {
					out << ',' ;
                    expiry.write(out);
                }
				else if (writeMode == 1) {
					out << " " <<right<<expiry <<" |";
					
				}
				else {
                    out << setw(max_length_label) << right << "Expiry Date: ";
                    expiry.write(out);
					out << endl;
				}
		}
		return out;

    }
}



