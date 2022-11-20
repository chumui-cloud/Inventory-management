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
	void soldProduct();
	void inputProduct();
	void displayProduct();
};

void Product::inputProduct()
{
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

	cout << ProductName << setw(15) << Quantity << setw(15) << Price << endl;

}

int main()
{
	vector<Product> products;

	do
	{
		system("cls");
		cout << "-----Menu-----" << endl;
		cout << "Enter your choice!" << endl;
		cout << "1: Add items to your inventory" << endl;
		cout << "2: Display items of your inventory" << endl;
		cout << "3: Exit " << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		
		{
			system("cls");
			string ans;
			while (true)
			{
				Product newProduct;
				newProduct.inputProduct();
				products.push_back(newProduct);
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
			cout << "Product-Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
			for (int j = 0; j < products.size(); j++)
			{
				products[j].displayProduct();
			}
			system("pause");
			break;
		}
		case 3:
			exit(1);
		default:
			cout << "Invalid input" << endl;
		}
		} while (1);
	}
