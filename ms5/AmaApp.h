/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms5
email : pchawla5@myseneca.ca
07 April 2019*/

#ifndef AMAAPP_H
#define AMAAPP_H
#include "iProduct.h"
#include <cstring>
#include <fstream>
#include <iomanip>
namespace ama
{

class AmaApp
{
    private:
        char m_filename[256];
        iProduct* m_products[100];
        int m_noOfProducts;
        //fstream dataFile;
        AmaApp (const AmaApp&) = delete;
        AmaApp& operator= (const AmaApp&) = delete;
		void pause() const;
		void flush() const;
        int menu() const;
        void loadProductRecords();
        void saveProductRecords() const;
        void listProducts() const;
        void deleteProductRecord(iProduct* product);
        void sort();
        iProduct* find(const char* sku);
        void addQty(iProduct* product);
        void addProduct(char tag);
    public:
        AmaApp(const char filename[256]);
        ~AmaApp();
        int run();  
    };

}
#endif
