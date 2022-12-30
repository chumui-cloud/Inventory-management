#include<iostream>
#include <vector>
#include<iomanip>
#include<string.h>
using namespace std;

int checkQuantity=0;

class Product
{
private:
	string ProductName;
	int Quantity;
	float Price;
	int sellQuantity;
	float priceTotal;

public:
	int Id;
	int getQuantity();
	float getPrice();
	int getProductId();
	string getProductName();
	float getTotalSoldPrice();
	void sellProduct();
	void inputProduct(int id);
	void displayProduct();
	void updateQuantity(int q);
	void displayStatistics();

};

string Product::getProductName()
{
	return ProductName;
}
float Product::getPrice()
{
	return Price;
}
int Product::getQuantity()
{
	return Quantity;
}
int Product::getProductId()
{
	return Id;
}
float Product::getTotalSoldPrice()
{
	return priceTotal;
}

void Product::inputProduct(int id)
{
	Id = id;
	cout << "Enter Product Name: ";
	cin >> ProductName;
	cout << endl;

	cout << "Enter Product Quantity: ";
	cin >> Quantity;
	cout << endl;

	cout << "Enter Product Price(per unit): ";
	cin >> Price;
	cout << endl;
	system("cls");
}

void Product::displayProduct()
{

	cout << Id << setw(10) << ProductName << setw(15) << Quantity << setw(15) << Price << endl;

}

void Product::sellProduct()
{
	cout << "How much quantity do you want to sell?" << endl;
	cin >> sellQuantity;
	if (sellQuantity <= Quantity)
	{
		Quantity = Quantity - sellQuantity;
		checkQuantity = 0;
	}
	else
	{
		cout << "You don't have that much quantity" << endl;
		checkQuantity = 1;
	}

}

void Product::updateQuantity(int q)
{
	Quantity = Quantity + q;
}

void Product::displayStatistics()
{
	if (sellQuantity <= Quantity)
	{
		priceTotal = sellQuantity * Price;
		cout << Id << setw(10) << ProductName << setw(15) << sellQuantity << setw(15) << Price << setw(20) << priceTotal << endl;
	}

}

int main()
{
	vector<Product> products;
	vector<Product> soldProducts;
	int id = 0;
	do
	{
		system("cls");
		cout << "-----Menu-----" << endl;
		cout << "Enter your choice!" << endl;
		cout << "1: Add items to your inventory" << endl;
		cout << "2: Display items of your inventory" << endl;
		cout << "3: Sell product" << endl;
		cout << "4: Display sold products " << endl;
		cout << "5: Exit " << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:

		{
			system("cls");
			string ans;
			int i;
			while (true)
			{
				Product newProduct;
				newProduct.inputProduct(++id);
				for ( i = 0; i < products.size(); i++)
				{
					if (newProduct.getProductName() == products[i].getProductName() && newProduct.getPrice() == products[i].getPrice())
					{
						products[i].updateQuantity(newProduct.getQuantity());
						break;
					}

				}
				if (i == products.size())
				{
					products.push_back(newProduct);
				}
				cout << "Do you want to add more?(If yes type y/Y else type any key.)" << endl;
				cin >> ans;
				if (ans != "y" && ans != "Y")
				{
					break;
				}
			}
			break;
		}
		case 2:
		{
			system("cls");
			cout << "ID  " << setw(10) << "Product-Name" << setw(10) << "Quantity" << setw(10) << "  Price(per unit in Tk)" << endl;
			for (int j = 0; j < products.size(); j++)
			{
				products[j].displayProduct();
			}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			int check = 0;
			cout << "Which product do you want to sell?" << endl;
			string name;
			cin >> name;
			system("cls");
			cout << "ID  " << setw(10) << "Product-Name" << setw(10) << "Quantity" << setw(10) << "  Price(per unit in Tk)" << endl;
			for (int i = 0; i < products.size(); i++)
			{
				string s = products[i].getProductName();
				
				if (strstr(s.c_str(), name.c_str()))
				{
					products[i].displayProduct();
				}
				else
					check++;
			}
			if (check == products.size())
			{
				system("cls");
				cout << "Sorry product doesn't exist" << endl;
			}
			else
			{
				cout << endl << "Enter the Id of the product" << endl;
				int I,i;
				cin >> I;
				system("cls");
				for (i = 0; i < products.size(); i++)
				{
					string s = products[i].getProductName();
					if ((strstr(s.c_str(), name.c_str()) && I == products[i].getProductId()))
					{
						products[i].sellProduct();
						soldProducts.push_back(products[i]);
						if (checkQuantity == 1)
							break;
						else
						{
							cout << endl;
							cout << "After selling the product" << endl;
							cout << endl;
							cout << "ID  " << setw(10) << "Product-Name" << setw(10) << "Quantity" << setw(15) << "  Price(per unit in Tk)" << endl;
							products[i].displayProduct();

							break;
						}
					}
				}
				if (i == products.size())
				{
					system("cls");
					cout << "Sorry product doesn't exist" << endl;
				}
			}
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			float tot = 0;
			cout << "The sold products are given below" << endl << endl;
			cout << "ID  " << setw(10) << " Product-Name" << setw(10) << " Quantity" << setw(10) << "   Price(per unit in Tk)"<< setw(15) << "   Price(total unit in Tk)" << endl;
			for (int i = 0; i < soldProducts.size(); i++)
			{
				soldProducts[i].displayStatistics();
				tot = tot + soldProducts[i].getTotalSoldPrice();
			}

			cout << endl << endl << "Total Price of All sold items is: " << tot<< "Tk" << endl;;
			system("pause");
			break;
		}
		case 5:
			exit(1);
		default:
			cout << "Invalid input" << endl;
		}
	} while (1);
}
