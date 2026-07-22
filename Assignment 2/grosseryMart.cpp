#include<iostream>
using namespace std;
void groceryItems(string userName,string userId);
void addItems(string userName,string userId,int itemPriceArray[],int allItemPrice);
void Discount1(string userName,string userId,int allItemPrice);
void billCalculation(string userName,string userId,int allItemPrice,double memberDiscount,string memberType);
void Discount2(string  userName,string  userId,int allItemPrice,double memberDiscount,string memberType,double roughFinal,double discount,double bankService);
void loyalityPoints(string  userName,string  userId,int allItemPrice,double memberDiscount,string memberType,double roughFinal,double discount,double bankService, int totalFinal,string paymentMethod );
void detailsDisplay(string  userName,string  userId,double memberDiscount,string memberType,double roughFinal,double discount,double bankService, int totalFinal,string paymentMethod,int loyalityPoint,int grossFinal);


int main()
{
	cout<<"\t\t\t========WELCOME TO ASHAR GROCERY STORE======== "<<endl;
	cout<<"\t\t\t\t-----BUILDING BAD MEMORIES-----"<<endl<<endl;
	
	string userName;
	cout<<"\t\t\tENTER YOUR USERNAME : ";
	getline(cin,userName);
	
	string userId;
	cout<<"\t\t\tENTER YOUR CUSTOMER ID : ";
	getline(cin,userId);
	cout<<endl;
	
	groceryItems(userName, userId);
	
	return 0;
}
void groceryItems(string userName,string userId)
{
	cout<<"\t\t\tLIST OF GROCERY ITEMS  "<<endl;
	cout<<"\t\t\t1. RICE 1 KG -------------350"<<endl;
	cout<<"\t\t\t2. SUGAR 1 KG ------------180 "<<endl;
	cout<<"\t\t\t3. COOKING OIL 1 LITRE ---580 "<<endl;
	cout<<"\t\t\t4.MILK PACK --------------220"<<endl;
	cout<<"\t\t\t5. TEA PACK --------------450"<<endl;
	cout<<"\t\t\t6. FLOUR 5 KG ------------950"<<endl;
	cout<<"\t\t\t7. EGGS DOZEN ------------320"<<endl;
	cout<<"\t\t\t8. DETERGENT -------------600"<<endl;
	cout<<"\t\t\t9. EXIT CART "<<endl<<endl;
	
	int itemPriceArray[8]={350,180,580,220,450,950,320,600};
	int allItemPrice=0;
	
	addItems(userName, userId, itemPriceArray,allItemPrice );
}
void addItems(string userName,string userId,int itemPriceArray[],int allItemPrice)
{
	int itemPrice=0;
    double tax=0;
    
	int choice;
	cout<<"\t\t\tSELECT THE ITEM BY NUMBER : ";
	cin>>choice;
	
	if(choice>=1&&choice<=8)
	{
		if(choice>=1&&choice<=7)
		{
			cout<<"\t\t\tFOOD ITEM "<<endl;
			tax=0.05;
			itemPrice= itemPriceArray[choice-1] - (tax*itemPriceArray[choice-1]);
	    	allItemPrice+=itemPrice;
			
		}
		else if(choice==8)
		{
			cout<<"\t\t\tNON FOOD ITEM "<<endl;
			tax=0.1;
			itemPrice= itemPriceArray[choice-1] - (tax*itemPriceArray[choice-1]);
	    	allItemPrice+=itemPrice;
		}
		else 
		{
			cout<<"\t\t\tINVALID CHOICE !"<<endl<<endl;
			addItems(userName, userId, itemPriceArray,allItemPrice );
		}

		cout<<"\t\t\tBILL : "<<allItemPrice<<"PKR."<<endl<<endl;	
		addItems(userName, userId, itemPriceArray,allItemPrice );	
	}
	else if(choice==9)
	{
		Discount1(userName, userId,allItemPrice);
	}
	else
	{
		cout<<"\t\t\tINVALID CHOICE !"<<endl<<endl;
		addItems(userName, userId, itemPriceArray,allItemPrice );
	}
}
void Discount1(string userName,string userId,int allItemPrice)
{
	cout<<"\t\t\tCUSTOMER TYPE "<<endl;
	cout<<"\t\t\t1. REGULAR CUSTOMER "<<endl;
	cout<<"\t\t\t2. MEMBER CUSTOMER "<<endl;
	
	double memberDiscount=0;
	string memberType= "NOT SPECIFIED ";
	
	int option;
	cout<<"\t\t\tSELECT : ";
	cin>>option;
	
	if(option==1)
	{
		memberDiscount=0;
		memberType=" REGULAR CUSTOMER ";
		
	}
	else if(option==2)
	{
		memberDiscount=0.07;
		memberType=" MEMBER CUSTOMER ";
		
	}
	
	billCalculation(userName, userId,allItemPrice,memberDiscount, memberType);
	
	
	
}
void billCalculation(string userName,string userId,int allItemPrice,double memberDiscount,string memberType)
{
	double roughBill=allItemPrice - (allItemPrice*memberDiscount);
	
	double discount=0;
	double bankService=0;
	
	if(roughBill<5000)
	{
		discount=0;
		cout<<"\t\t\tDiscount : "<<discount*100<<endl<<endl;
	}
	else if(roughBill>=5000&&roughBill<=10000)
	{
		discount=0.05;
		cout<<"\t\t\tDiscount : "<<discount*100<<endl<<endl;
		
	}
	else if(roughBill>10000)
	{
		discount=0.1;
		cout<<"\t\t\tDiscount : "<<discount*100<<endl<<endl;
		
	}
	
	double roughFinal=roughBill - (roughBill*discount);
	
	Discount2( userName, userId,allItemPrice,memberDiscount, memberType,roughFinal,discount ,bankService);
	
}
void Discount2(string  userName,string  userId,int allItemPrice,double memberDiscount,string memberType,double roughFinal,double discount ,double bankService)
{
	cout<<"\t\t\tPAYMENT METHOD  "<<endl;
	cout<<"\t\t\t1. CASH  "<<endl;
	cout<<"\t\t\t2. CARD  "<<endl;
    
	string paymentMethod="NOT SPECIFIED ";
    
	int option;
	cout<<"\t\t\tSELECT : ";
	cin>>option;
	
	if(option==1)
	{
		bankService=0;
		cout<<"\t\t\tCASH ON DELIVERY "<<endl<<endl;
		paymentMethod="CASH ";
	}
	else if (option==2)
	{
		bankService=0.02;
		cout<<"\t\t\tPAYMENT BY CARD "<<endl<<endl;
		paymentMethod="CARD ";
	}
	else {
		cout<<"\t\t\tINVALID CHOICE !"<<endl<<endl;
		Discount2(userName, userId,allItemPrice,memberDiscount, memberType,roughFinal, discount, bankService);
	}
	
	int totalFinal=roughFinal + (roughFinal*bankService);
	
	loyalityPoints(userName, userId,allItemPrice,memberDiscount, memberType,roughFinal, discount, bankService,totalFinal,paymentMethod);
	
}
void loyalityPoints(string  userName,string  userId,int allItemPrice,double memberDiscount,string memberType,double roughFinal, double discount,double bankService, int totalFinal,string paymentMethod )
{
	int loyalityPointNew=totalFinal/100;
	cout<<"\t\t\tTHIS PURCHASE LOYALITY POINTS : "<<loyalityPointNew<<endl<<endl;
	
	int loyalityPointExisting;
	cout<<"\t\t\tENTER YOUR PREVIOUS LOYALITY POINTS : ";
	cin>>loyalityPointExisting;
	
	int loyalityPoint=loyalityPointNew + loyalityPointExisting;
	cout<<"\t\t\tYOUR LOYALITY POINTS ARE : "<<loyalityPoint<<" POINTS."<<endl;
	
	cout<<"\t\t\t1 LOYALITY POINT = 1 PKR DISCOUNT "<<endl<<endl;
	cout<<"\t\t\tDO YOU WISH TO REDEEM YOUR POINTS ? "<<endl;
	cout<<"\t\t\t1. YES "<<endl;
	cout<<"\t\t\t2. NO "<<endl<<endl;
	
	int grossFinal=0;
	
	int option;
	cout<<"\t\t\tSELECT : ";
	cin>>option;
	cout<<endl;
	
	if(option==1)
	{
	    grossFinal=totalFinal - loyalityPoint;
		
	}
	else if(option==2)
	{
		grossFinal=totalFinal;
		
	}
	else
	{
		cout<<"\t\t\tINVALID CHOICE !"<<endl<<endl;
		loyalityPoints(userName, userId,allItemPrice,memberDiscount, memberType,roughFinal, discount, bankService,totalFinal,paymentMethod);
	}
	
	
	
		
	detailsDisplay(userName, userId,memberDiscount, memberType,roughFinal, discount, bankService,totalFinal,paymentMethod,loyalityPoint, grossFinal);
}

void detailsDisplay(string  userName,string  userId,double memberDiscount,string memberType,double roughFinal,double discount,double bankService, int totalFinal,string paymentMethod,int loyalityPoint,int grossFinal )
{
	cout<<"\t\t\t\t\t\t---CUSTOMER DETAILS---"<<endl<<endl;
	cout<<"\t\t\tCUSTOMER DETAILS "<<endl;
	cout<<"\t\t\tCUSTOMER NAME : "<<userName<<endl;
	cout<<"\t\t\tCUSTOMER TYPE : "<<memberType<<endl;
	cout<<"\t\t\tPAYMENT METHOD :  "<<paymentMethod <<endl;
	cout<<"\t\t\tGROSS BILL : "<< roughFinal<<endl;
	cout<<"\t\t\tMEMBERSHIP DISCOUNT : "<< memberDiscount*100<<endl;
	cout<<"\t\t\tBILL DISCOUNT  "<<  discount*100<<endl;
	cout<<"\t\t\tCARD CHARGES :  "<<bankService*100 <<endl;
	cout<<"\t\t\tLOYALITY POINTS : "<<	loyalityPoint<<endl<<endl;
	cout<<"\t\t\tTOTAL PAYABLE AMOUNT : "<<grossFinal<<endl<<endl;
	cout<<"\t\t\t-------THANKS FOR SHOPPING------ "<<endl;
	
			
}


