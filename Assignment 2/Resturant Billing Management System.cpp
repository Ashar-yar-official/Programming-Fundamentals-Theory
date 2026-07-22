#include <iostream>
using namespace std;

void displayMenu(string foodItem[], int price[]);
int placeOrder(string foodItem[], int price[]);
void customerDetails(string name, string contact, string orderType, int person);
void finalBillDisplay(int totalBill, string orderType, string name, string contact, int person);

int main()
{
 string customerName;
    cout <<"Enter customer name:";
    cin >> customerName;
    string contactNumber;
    cout <<"Enter contact number:";
    cin >> contactNumber;
    int person;
    cout <<"Enter number of persons:";
    cin >> person;
    string orderType;
    int choice;
    cout<<"Enter your choice for order type: 1. Dine in 2. Take away:";
    cin >> choice;
    if (choice == 1)
        orderType = "Dine in";
    else
        orderType = "Take away";

    string foodItem[8] = {
        "Chicken Burger",
         "Zinger Burger", 
         "Pizza Small", 
         "Pizza Large",
        "Chicken Biryani",
         "BBQ Platter",
          "Fries",
           "Cold Drink"};

    int price[8] = {
        450, 
        550, 
        900, 
        1800, 
        350,
        1200,
        250,
        120 };

    displayMenu(foodItem, price);

    int totalBill = placeOrder(foodItem, price);

    finalBillDisplay(totalBill, orderType, customerName, contactNumber, person);

    return 0;
}

void displayMenu(string foodItem[], int price[])
{
    cout << "......Food Menu";
    for (int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". " << foodItem[i] << " - " << price[i] << endl;
    }
}

int placeOrder(string foodItem[], int price[])
{
    int choice, quantity;
    int totalBill = 0;
    char more = 'y';

    while (more == 'y' || more == 'Y')
    {
        cout << "\nEnter item number (1-8): ";
        cin >> choice;

        if (choice < 1 || choice > 8)
        {
            cout << "Invalid item!\n";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Current Total Bill = " << totalBill << endl;

        totalBill += price[choice - 1] * quantity;

        cout << "More items? (y/n): ";
        cin >> more;
    }

    return totalBill;
}

void finalBillDisplay(int totalBill, string orderType, string name, string contact, int person)
{
    double serviceCharges, gst;
    double discount = 0;
    double finalBill;
  if(orderType == "Dine in") 
   { 
    serviceCharges = totalBill * 0.10; 
       }
   else 
   { 
    serviceCharges = totalBill * 0.05;
      }
   gst = totalBill * 0.16;

    if (totalBill >= 3000 && totalBill <= 5000)
        {
            discount = totalBill * 0.05;
        }
    else if (totalBill <= 10000)
        {
            discount = totalBill * 0.10;
        }
    else
        {
            discount = totalBill * 0.15;
        }

    finalBill = totalBill + serviceCharges + gst - discount;

    customerDetails(name, contact, orderType, person);

    cout << "......FINAL BILL .......";
    cout << "Food Bill: " << totalBill << endl;
    cout << "Service: " << serviceCharges << endl;
    cout << "GST: " << gst << endl;
    cout << "Discount: " << discount << endl;
    cout << "Final: " << finalBill << endl;
}

void customerDetails(string name, string contact, string orderType, int person)
{
    cout << "......CUSTOMER DETAILS.......";
    cout << "Name: " << name << endl;
    cout << "Contact: " << contact << endl;
    cout << "Order Type: " << orderType << endl;
    cout << "persons: " << person << endl;
}
