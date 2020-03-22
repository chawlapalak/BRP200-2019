
/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms4
27 March 2019*/

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include<iostream>
#include "ErrorState.h"
#include "iProduct.h"
namespace ama
{
	class Product: public iProduct
	{
	private:
		char type;
		char prSKU[max_length_sku + 1];
		char prUnit[max_length_unit + 1];
		char* prName;
		int quantityOnHand;
		int quantityNeeded;
		double prodPriceBeforeTax;
		bool taxStatus;
		ErrorState es;
		double cost_with_tax() const;
		void setName(const char *name);
        void setSafeEmpty();
	protected:
		void message(const char* pText);
		bool isClear() const;
	public:
		Product(const char pType = 'N');
		Product(const char* sku, const char* name, const char * unit, double priceBeforeTax = 0.0, int qtyNeeded = 0, int qtyOnHand = 0, bool taxable = true);
		Product(const Product& other);
		~Product();
		Product& operator=(const Product & other);
		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator> (const char* sku) const;
		bool operator> (const iProduct&) const; 
		int qtyAvailable() const;
		int qtyNeeded() const;
		double total_cost() const;
		bool isEmpty() const; 
        const char* name() const; 
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;
	};
}
#endif
