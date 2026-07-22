#include <iostream>
using namespace std;

// Global variables
string username, email, city, customertype;
int cartTotal = 0;

// products rate and name//
string products[8] = {"T-Shirt","Shoes","Jeans","Watch","Handbag","Headphones","Mobile Cover","Perfume"};
int prices[8] = {1200,3500,5000,2500,4200,3000,700,2800};

void registerUser() {
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your city: ";
    cin >> city;

    int type;
    cout << "Enter customer type (1.New 2.Returning): ";
    cin >> type;
    customertype = (type == 1) ? "New Customer" : "Returning Customer";
}

// Display Products ky liye//
void displayProducts() {
    cout << "Product No\tProduct\t\tPrice\n";
    for(int i=0; i<8; i++) {
        cout << (i+1) << "\t" << products[i] << "\tRs. " << prices[i] << endl;
    }
}

// Add to Cart
void addToCart(int productNo) {
    cartTotal += prices[productNo-1];
    cout << products[productNo-1] << " added to cart.\n";
}

// Calculate Product Total
int calculateProductTotal() {
    return cartTotal;
}

// GST
double calculateGST(int productTotal) {
    return productTotal * 0.17;
}

// Delivery Charges
int calculateDeliveryCharges(string city) {
    if(city == "Lahore" || city == "Karachi" || city == "Islamabad")
        return 250;
    else
        return 500;
}

// Customer Discount
double calculateCustomerDiscount(int productTotal) {
    if(customertype == "New Customer")
        return productTotal * 0.05;
    else
        return productTotal * 0.10;
}

// Order Value Discount
double calculateOrderValueDiscount(int productTotal) {
    if(productTotal >= 5000 && productTotal < 10000)
        return productTotal * 0.05;
    else if(productTotal > 10000)
        return productTotal * 0.12;
    return 0;
}

// Payment Charges
double calculatePaymentCharges(int productTotal, int method) {
    if(method == 2) // Card
        return productTotal * 0.025;
    return 0;
}

// Display Bill
void displayCheckoutBill(int productTotal, double gst, int deliveryCharges, double customerDisc, double orderDisc, double paymentCharges) {
    double finalAmount = productTotal + gst + deliveryCharges + paymentCharges - customerDisc - orderDisc;

    cout << "\n========== ONLINE SHOPPING BILL ==========\n";
    
    cout << "User Name: " << username << endl;
    cout << "City: " << city << endl;
    cout << "Customer Type: " << customertype << endl;
    cout << "\nProduct Total: Rs. " << productTotal;
    cout << "\nGST: Rs. " << gst;
    cout << "\nDelivery Charges: Rs. " << deliveryCharges;
    cout << "\nCustomer Discount: Rs. " << customerDisc;
    cout << "\nOrder Discount: Rs. " << orderDisc;
    cout << "\nPayment Charges: Rs. " << paymentCharges;
    
    
    cout << "\n------------------------------------------";
    cout << "\nFinal Payable Amount: Rs. " << finalAmount;
    cout << "\nThank You for Shopping :)";
    cout << "\n==========================================\n";
}

// main part// 
int main() {
    registerUser();
    int choice;

    do {
        cout << "\nMain Menu:\n";
        cout << "1. View Products\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. Calculate Checkout Bill\n";
        cout << "4. View User Details\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            displayProducts();
        }
        else if(choice == 2) {
            int pNo;
            cout << "Enter Product No: ";
            cin >> pNo;
            addToCart(pNo);
        }
        else if(choice == 3) {
            int productTotal = calculateProductTotal();
            double gst = calculateGST(productTotal);
            int delivery = calculateDeliveryCharges(city);
            double custDisc = calculateCustomerDiscount(productTotal);
            double orderDisc = calculateOrderValueDiscount(productTotal);
            cout << "Select Payment Method (1.Cash, 2.Card): ";
            int method;
            cin >> method;
            double payCharges = calculatePaymentCharges(productTotal, method);
            displayCheckoutBill(productTotal, gst, delivery, custDisc, orderDisc, payCharges);
        }
        else if(choice == 4) {
            cout << "Username: " << username << endl;
            cout << "Email: " << email << endl;
            cout << "City: " << city << endl;
            cout << "Customer Type: " << customertype << endl;
        }
        else if(choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice, try again.\n";
        }

    } while(choice != 5);

    return 0;
}
