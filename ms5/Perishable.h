/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms5
email : pchawla5@myseneca.ca
07 April 2019*/

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H
#include "Date.h"
#include "Product.h"
namespace ama
{

    class Perishable: public Product
    {
        private:
            Date expiry;
        
        public:
            Perishable();
            std::istream& read(std::istream& in, bool interractive);
            std::ostream& write(std::ostream& out, int writeMode) const;
            ~Perishable();

    };

}

#endif // PERISHABLE_H
