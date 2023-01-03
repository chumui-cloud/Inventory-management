#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

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
	bool sellProduct();
	void inputProduct(int id);
	void displayProduct();
	void updateQuantity(int q);
	void displayStatistics();
	void editInventory();
};

inline string Product::getProductName()
{
	return ProductName;
}
inline float Product::getPrice()
{
	return Price;
}
inline int Product::getQuantity()
{
	return Quantity;
}
inline int Product::getProductId()
{
	return Id;
}
inline float Product::getTotalSoldPrice()
{
	return priceTotal;
}

inline void Product::inputProduct(int id)
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

inline void Product::displayProduct()
{

	cout << Id << setw(10) << ProductName << setw(15) << Quantity << setw(15) << Price << endl;

}

inline bool Product::sellProduct()
{
	cout << "How much quantity do you want to sell?" << endl;
	cin >> sellQuantity;
	if (sellQuantity <= Quantity)
	{
		Quantity = Quantity - sellQuantity;
		return true;

	}
	cout << "Sorry. You do not have enough product";
	return false;
}

inline void Product::updateQuantity(int q)
{
	Quantity = Quantity + q;
}

inline void Product::displayStatistics()
{
	if (sellQuantity <= Quantity)
	{
		priceTotal = sellQuantity * Price;
		cout << Id << setw(10) << ProductName << setw(15) << sellQuantity << setw(15) << Price << setw(20) << priceTotal << endl;
	}

}


inline void Product::editInventory()
{
	do
	{
		system("cls");
		cout << "Select an option for editing the product information" << endl;
		cout << "1: For editing product name" << endl;
		cout << "2: For editing product quantity" << endl;
		cout << "3: For editing product price" << endl;
		cout << "4: Exit" << endl;
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
		{
			system("cls");
			cout << "Enter the new name for the product" << endl;
			string newName;
			cin >> newName;
			ProductName = newName;
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Enter the new quantity for the product" << endl;
			int q;
			cin >> q;
			Quantity = q;
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Enter the new price for the product" << endl;
			int p;
			cin >> p;
			Price = p;
			break;
		}
		case 4:
			return;
		default:
			cout << "Invalid input" << endl;
			system("pause");
		}
	} while (1);

}

