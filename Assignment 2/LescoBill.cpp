#include <iostream>
using namespace std;


//USER REGISTRATION

void userRegistration(string &name , string &customerId , int &customerType,int &noOfMeter){
	cout << "Please Enter Your Full Name : "  ;
	getline(cin,name);
	
	cout << "Please Enter Your Customer Id  (it also contain alphabets) : "  ;
	cin>>customerId;
	
	cout << "Select Your Customer Type" << endl;
	cout << "For Household  (Press 1)"  << endl;
	cout << "For Commercial   (Press 2)"  << endl;
	cin>>customerType;
	
	cout << "Select Your Number of meters already installed " << endl;
	cout << "Meter Installed First Time (Press 1)"  << endl;
	cout << "Meter Alrady Installed     (Press 2)"  << endl;
	cin>>noOfMeter;
	
}


//CUSTOMER DETAIL

void customerDetail(string &name , string &customerId , int &customerType,int &noOfMeter){
	cout << "========== CUSTOMERS DETAILS ==========" << endl;
	cout << "Customer Name:" << name << endl;
	cout << "Customer ID: " << customerId << endl;
	if(customerType == 1){
	cout << "Customer Type: Household" << endl;
	}else{
	cout << "Customer Type: Commercial" << endl;
	}
	if(noOfMeter == 1){
	cout << "Number of Meters: Meter Installed First Time" << endl;
	}else{
	cout << "Number of Meters: Meter Alrady Installed" << endl;
	}

}

//CALCULATE ELECTRICITY BILL

float calculateBill(int consumedUnits,int units[],float ratePerUnit[],int customerType){
cout << "Please Enter Your Consumed Units : ";
cin >> consumedUnits;


int previousUnit = 0;
int fixedCharges = 0;
int meterRent = 250;
int tvFee = 35;

float electricityDuty;
float rates;
float total;
float gst;
float incomeTax;
float grandTotal;

for(int i=0; i<=6;i++){
	if (consumedUnits <= units[i] && consumedUnits > previousUnit){
		rates = consumedUnits * ratePerUnit[i] ;
		
		if(consumedUnits > 300 && consumedUnits<=400){
			fixedCharges=200; 
		}else if (consumedUnits > 400 && consumedUnits<=500){
			fixedCharges=400; 
		}else if (consumedUnits > 500 && consumedUnits<=600){
			fixedCharges=600; 
		}else if (consumedUnits > 600 && consumedUnits<=700){
			fixedCharges=800; 
		}else if (consumedUnits > 700){
			fixedCharges=1000; 
		}else{
			fixedCharges=0; 
		}	
		
		electricityDuty = (rates * 1.5) / 100 ;
		
		cout << "FIXED CHARGES" << fixedCharges << endl;
		cout << "ELECTRICITY CHARGES" << electricityDuty << endl;
		
		total = rates + electricityDuty + fixedCharges + tvFee + meterRent ;
		gst = (total * 15) / 100 ;
		
		if (customerType == 1){
		incomeTax = (total * 10) / 100 ;
		} else{
		incomeTax = (total * 15) / 100 ;
		}
		
		grandTotal = total + gst + incomeTax ;

			
		break;
	}else if(consumedUnits > 700){
		rates = consumedUnits * 49.10 ;
		fixedCharges=1000; 
		electricityDuty = (rates * 1.5) / 100 ;
		
		total = rates + electricityDuty + fixedCharges + tvFee + meterRent ;
		gst = (total * 15) / 100 ;
		
		if (customerType == 1){
		incomeTax = (total * 10) / 100 ;
		} else{
		incomeTax = (total * 15) / 100 ;
		}
		
		grandTotal = total + gst + incomeTax ;
	}
	else{
		previousUnit=units[i];
	}
}
return grandTotal;
}

//NEW CONNECTION



void newConnectionCharges(int customerType, int noOfMeter) {

    float meterCost        = 15000;
    float meterCableCost   = 8000;
    float securityCost     = 5000;
    float additionalCharges = 0;
    
 
    if (customerType == 1) {                    
        if (noOfMeter == 1) {                    
            additionalCharges = 2500;
        } else {                                 
            additionalCharges = 5000;
        }
    } else {                                      
        if (noOfMeter == 1) {                   
            additionalCharges = 35000;
        } else {                            
            additionalCharges = 70000;
        }
    }
 
    float newConnectionCost = 250000.0f;
 
    // -- Ask whether the customer wants a proper new connection --
    int connectionChoice;
    cout << "Do you want a new proper connection?" << endl;
    cout << "Yes (Press 1)" << endl;
    cout << "No  (Press 2)" << endl;
    cin  >> connectionChoice;
 
    // -- Display itemised breakdown --
    cout << "\n----------- Charges Breakdown -----------" << endl;
    cout << "Meter Cost            : Rs. " << meterCost       << endl;
    cout << "Meter Cable Cost      : Rs. " << meterCableCost  << endl;
    cout << "Security Cost         : Rs. " << securityCost    << endl;
 
    if (customerType == 1) {
        cout << "Additional Charges    : Rs. " << additionalCharges
             << (noOfMeter == 1 ? " (Household - 1st Meter)" : " (Household - 2nd Meter)") << endl;
    } else {
        cout << "Additional Charges    : Rs. " << additionalCharges
             << (noOfMeter == 1 ? " (Commercial - 1st Meter)" : " (Commercial - 2nd Meter)") << endl;
    }
 
    float totalCost = meterCost + meterCableCost + securityCost + additionalCharges;
 
    if (connectionChoice == 1) {
        cout << "New Connection Cost   : Rs. " << newConnectionCost << endl;
        totalCost += newConnectionCost;
    }
 
    cout << "-----------------------------------------" << endl;
    cout << "TOTAL CONNECTION COST : Rs. " << totalCost << endl;
    cout << "=========================================" << endl;
}




int main(){
	string name,customerId; 
	int customerType,noOfMeter,selectedMenu,consumedUnits;
	int units[7]={100,200,300,400,500,600,700};
	float ratePerUnit[7]={12.21,14.53,31.51,38.41,41.62,43.04,44.18};
	

    userRegistration(name,customerId, customerType,noOfMeter);
	
    string mainMenu[4] = {"1.Calculate Monthly Electricity Bill ","2.Apply for New Electricity Connection ","3.View Customer Details ","4.Exit Program "};


	cout << "Select the Menu" << endl ;	
	for(int i=0;i<=3; i++){
		cout << mainMenu[i] << endl;
	}  
    cin >> selectedMenu ;





    
    if (selectedMenu == 3){
    	customerDetail(name,customerId, customerType,noOfMeter);
	}else if (selectedMenu == 4){
		cout << "Program is Close" ;
		return 0;
	}else if(selectedMenu == 1){
	  cout << calculateBill(consumedUnits,units,ratePerUnit,customerType);
	}else if(selectedMenu ==2){
	 newConnectionCharges(customerType, noOfMeter);

	}
	
	
	
	
	



	return 0;
}
