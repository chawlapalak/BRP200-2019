/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms5
email : pchawla5@myseneca.ca
07 April 2019*/

#include <cstring>
#include <string>
#include <iostream>
#include "AmaApp.h"
#include "Sort.h"
#include "Utilities.h"
using namespace std;
namespace ama{
        void AmaApp::pause() const{
			cin.clear();
			cout << "Press Enter to continue..."<<endl;
			cin.ignore(256, '\n');
			
        }

		void AmaApp::flush() const {
			cin.clear();
			cin.ignore(256, '\n');
		}
        
        AmaApp::AmaApp(const char filename[256]){
            strcpy(m_filename, filename);
            m_noOfProducts = 0;
            m_products[0]= nullptr;
            loadProductRecords();
        }
        
        AmaApp::~AmaApp(){
           for (int i = 0; i < m_noOfProducts; i++)
               { m_products[i] = nullptr;}
           m_products[0] = nullptr;
        }
        
        int AmaApp::menu() const{
            int selection;
            cout << "Disaster Aid Supply Management Program" << endl;
            cout << "--------------------------------------"<<endl;
            cout << "1- List products" << endl;
            cout << "2- Search product" << endl;
            cout << "3- Add non-perishable product" << endl;
            cout << "4- Add perishable product" << endl;
            cout << "5- Add to product quantity" << endl;
            cout << "6- Delete product" << endl;
            cout << "7- Sort products" << endl;
            cout << "0- Exit program" << endl;
            cout << "> ";
			cin.clear();
			cin >> selection;
			cin.ignore(1000, '\n');
            if (selection>=0 && selection <=7){
                return selection;
            }
            else {
                return -1;
            }
        }
        
        void AmaApp::loadProductRecords(){
            fstream dataFile;
            int i = 0;
            char tag = 'w';
            for (int i = 0; i < m_noOfProducts; i++)
               { m_products[i] = nullptr;}
            dataFile.open(m_filename, ios::in);
            if (dataFile.is_open()) {
                while (dataFile.good()) {
					tag = '\0';
					dataFile >> tag;
                    dataFile.ignore();
                    iProduct* tempProduct = createInstance(tag);
                    if(tempProduct){
                        m_products[i] = tempProduct;
                        m_products[i]->read(dataFile, false);
                        i++;
                    }
			}
		}
		else {
			dataFile.clear();
			dataFile.close();
			dataFile.open(m_filename, ios::out);
			dataFile.close();
		}
            m_noOfProducts = i;
            dataFile.close();
    }

        
        void AmaApp::saveProductRecords() const{
            fstream dataFile;
            dataFile.open(m_filename, ios::out);
            for (int i = 0; i < m_noOfProducts; i++) {
                m_products[i]->write(dataFile, write_condensed);
				dataFile << endl;
            }
            
            dataFile.clear();
            dataFile.close();
        }
        
        void AmaApp::listProducts() const{
            double totalcost = 0;
            cout << "------------------------------------------------------------------------------------------------" << endl;
            cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl;
            cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

            for (int i = 0; i < m_noOfProducts; i++){               
                cout << "|"<<setw(4) << right << setfill(' ')<<(i + 1) << " |";

                m_products[i]->write(cout, write_table);
                totalcost += m_products[i]->total_cost();
                cout << endl;

            }
            cout << "------------------------------------------------------------------------------------------------" << endl;
            cout <<"|"<<setw(83)<<right<< "Total cost of support ($): | " << setprecision(2) <<setw(10)<< totalcost <<" |" <<endl;
            cout << "------------------------------------------------------------------------------------------------" << endl<<endl;
        }
        
        void AmaApp::deleteProductRecord(iProduct* product){
            fstream dataFile;
            dataFile.open(m_filename, ios::out);
            for(int i=0; i<m_noOfProducts; i++){
                if(m_products[i] != product){
                    m_products[i]->write(dataFile, write_condensed);
					dataFile << endl;
                }
            }
			cout << endl;
			cout << "Deleted!" << endl;
        }
        
        void AmaApp::sort(){
            sict::sort(m_products, m_noOfProducts);
        }
        
        iProduct* AmaApp::find(const char* sku){
            for (int i = 0; i < m_noOfProducts; i++){
                if (*m_products[i] == sku) 
                    return m_products[i];
            }
            return nullptr;
        }
        
        void AmaApp::addQty(iProduct* product){
            int qty;
            cout << endl << "Please enter the number of purchased items: ";
            cin >> qty;
            if (cin.fail()) {
                cout << "Invalid quantity value!" << endl<<endl;
				cin.clear();
            }
            else {
					if (qty <= (product->qtyNeeded() - product->qtyAvailable())){
						*product += qty;
						cout <<endl;
						cout << "Updated!" << endl << endl;
					}
					else {
						int qtNeeded = (product->qtyNeeded() - product->qtyAvailable());
						*product += qtNeeded;
						int extra = qty - qtNeeded;
						cout << "Too many items; only " <<qtNeeded<< " is needed. Please return the extra " << extra << " items." <<endl<<endl;
						cout << "Updated!" << endl << endl;
					}
					saveProductRecords();
				}
		}
        
        
        void AmaApp::addProduct(char tag){
            iProduct* tempProduct = createInstance(tag);
            if(tempProduct){
                cin >> *tempProduct;
                if (cin.fail()) {
                    
                    cout<<endl;
                    tempProduct->write(cout, write_human);
					cout << endl;
                    cout<<endl;
           			cin.clear();
                }
                else{
                    m_products[m_noOfProducts++] = tempProduct;
					cout << endl;
					cout << "Success!";
					cout << endl;
					cout << endl;
					cin.clear();
                }
            }
        }
        
    int AmaApp::run(){

		int option = menu();
		char sku[max_length_sku];
		iProduct* product;
		loadProductRecords();
        
		if (option == 1){
			listProducts();
			pause();
			run();
		}

		else if (option == 2){
			cout << "Please enter the product SKU: ";
			cin >> sku;
			cout << endl;
			cin.ignore(256, '\n');
			cin.clear();
			product = find(sku);

			if (product){
				product->write(cout, write_human);
				cout << endl;
				pause();
                run();
			}
			else{
				cout << "No such product!"<<endl;
				pause();
				run();
			}
		}

		else if (option == 3){
            addProduct('N');
			saveProductRecords();
			flush();
			run();
		}

		else if (option == 4){
            addProduct('P');
			saveProductRecords();
			flush();
			run();
			
		}
		else if (option == 5){
			cout << "Please enter the product SKU: ";
            cin >> sku;
			cout << endl;
			cin.ignore(256, '\n');
			product = find(sku);
			if (product){
				product->write(cout, write_human)<<endl;
                addQty(product);
                flush();
                run();
			}
			else{
				cout << "No such product!" << endl;
				cout << endl;
				run();
			}
		}
        else if (option == 6){
			cout << "Please enter the product SKU: ";
            cin >> sku;
			product = find(sku);
			if (product){
                deleteProductRecord(product);
                flush();
                run();
			}
			else{
				cout << endl<<"No such product!";
				cout << endl;
				flush();
				run();
			}
		}
        else if (option == 7){
			sort();
            saveProductRecords();
			cout << "Sorted!" << endl;
			cout << endl;
			run();

		}
        else if (option == 0){
			cout << "Goodbye!" << endl;
		}

		else{
			cout << "~~~Invalid selection, try again!~~~"<<endl;
			pause();
			run();
		}
		return 0;
	}
}


