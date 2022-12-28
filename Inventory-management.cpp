#include<iostream>
#include <vector>
#include<iomanip>

using namespace std;

class Product
{
private:
	string ProductName;
	int Quantity;
	float Price;


public:
	int Id;
	int getQuantity();
	float getPrice();
	int getProductId();
	string getProductName();
	void soldProduct();
	void inputProduct(int id);
	void displayProduct();
	void updateQuantity(int q);
	bool hasName(string n);
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

void Product::soldProduct()
{
	int sellQuantity;
	cout << "How much quantity do you want to sell?" << endl;
	cin >> sellQuantity;
	if (sellQuantity <= Quantity)
	{
		Quantity = Quantity - sellQuantity;
	}
	else
	{
		cout << "You don't have that much quantity" << endl;
	}

}

void Product::updateQuantity(int q)
{
	Quantity = Quantity + q;
}

int main()
{
	vector<Product> products;
	int id = 0;
	do
	{
		system("cls");
		cout << "-----Menu-----" << endl;
		cout << "Enter your choice!" << endl;
		cout << "1: Add items to your inventory" << endl;
		cout << "2: Display items of your inventory" << endl;
		cout << "3: Sell product" << endl;
		cout << "4: Exit " << endl;
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
			cout << "ID  " << setw(10) << "Product-Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
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
			cout << "ID  " << setw(10) << "Product-Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
			for (int i = 0; i < products.size(); i++)
			{
				if (name == products[i].getProductName())
				{
					products[i].displayProduct();
				}
			}
			cout << endl << "Enter the Id of the product" << endl;
			int I;
			cin >> I;
			for (int i = 0; i < products.size(); i++)
			{
				if (name == products[i].getProductName() && I==products[i].getProductId())
				{
					products[i].soldProduct();
					cout << endl;
					cout << "After selling the product" << endl;
					cout << endl;
					cout << "ID  " << setw(10) << "Product-Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
					products[i].displayProduct();

					break;
				}
				check++;

			}
			if (check == products.size())
			{
				cout << "Sorry product doesn't exist!" << endl;
			}
			system("pause");
			break;
		}
		case 4:
			exit(1);
		default:
			cout << "Invalid input" << endl;
		}
	} while (1);
}
