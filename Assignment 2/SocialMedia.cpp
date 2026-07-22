#include<iostream>
using namespace std;
void platforms(string clientName,string businessName);
void postDesign(string clientName,string businessName, int managementFee);

void adBudget(string clientName,string businessName,int managementFee,int postDesignCharges );

void campaignDays(string clientName,string businessName,int managementFee,int postDesignCharges,int handlingFee,int adBudgetAmount);

void globalSaleTax(string clientName,string businessName,int managementFee,int postDesignCharges,int handlingFee,int adBudgetAmount,int daysRunning,int additionalFee);

void discountOnBusiness(string clientName,string businessName, int managementFee,int postDesignCharges ,int handlingFee,int adBudgetAmount,int daysRunning,int additionalFee,double gst);

void calculationAll(string clientName,string businessName,int managementFee,int postDesignCharges,int handlingFee,int adBudgetAmount,int daysRunning,int additionalFee,double gst,double discountAmount);

void clientDetails( string clientName,string businessName,int managementFee,int postDesignCharges,int handlingFee,int adBudgetAmount,int daysRunning,int additionalFee,double gst,double discountAmount ,int roughTotalFinal);




int main()
{
    cout<<"\t\t\t----Welcome to Digital Marketing Agency----"<<endl;
    cout<<"\t\t\t\t\tDESIGNED BY YOU, FOR YOU ! "<<endl<<endl;

    string clientName;
    cout<<"\t\tEnter Client Name : ";
    getline(cin,clientName);
    
    string businessName;
    cout<<"\t\tEnter Business Name : ";
    getline(cin,businessName);
    cout<<endl;
   
    platforms(clientName,businessName);
    

    return 0;
}

void platforms(string clientName,string businessName)
{
    cout<<"\t\tLIST OF AVAILABLE PLATFORMS"<<endl;
    cout<<"\t\t1. INSTAGRAM "<<endl;
    cout<<"\t\t2. FACEBOOK "<<endl;
    cout<<"\t\t3. LINKEDIN "<<endl<<endl;
    int managementFeeArray[3]={15000,12000,20000};
    
    int option;
    cout<<"\t\tChoose : ";
    cin>>option;
    int managementFee=0;
    
    if(option==1)
    {
       managementFee= managementFeeArray[0];
       cout<<"\t\tManagement fee : "<<managementFee<<endl<<endl;
        
    }
    else if(option==2)
    {
        managementFee= managementFeeArray[1];
       cout<<"\t\tManagement fee : "<<managementFee<<endl<<endl;
        
    }
    else if(option==3)
    {
       managementFee= managementFeeArray[2];
       cout<<"\t\tManagement fee : "<<managementFee<<endl<<endl; 
        
    }
    else
    {
        cout<<"\t\tINVALID CHOICE "<<endl<<endl;
        platforms( clientName, businessName);
    }
    postDesign(  clientName, businessName,managementFee);
}
void postDesign(string clientName,string businessName,int managementFee)
{
     
    cout<<"\t\tLIST OF AVAILABLE POST DESIGNS "<<endl;
    cout<<"\t\t1. STATIC POST "<<endl;
    cout<<"\t\t2. REEL / VIDEO POST"<<endl;
    cout<<"\t\t3. CAROUSAL POST "<<endl<<endl;
    int postDesignArray[3]={1000,2500,1800};
    
    int staticPost;
    cout<<"\t\tEnter the number of static posts : ";
    cin>>staticPost;
    
    int reelPost;
    cout<<"\t\tEnter the number of reel posts : ";
    cin>>reelPost;
    
    int carousalPost;
    cout<<"\t\tEnter the number of carousal posts : ";
    cin>>carousalPost;
    cout<<endl;
    
    int postDesignCharges=((staticPost*postDesignArray[0])+(reelPost*postDesignArray[1])+(carousalPost*postDesignArray[2]));
    cout<<"\t\tPost Design Charges : "<<postDesignCharges<<endl<<endl;
    
    adBudget( clientName, businessName,managementFee,postDesignCharges );
    
}
void adBudget(string clientName,string businessName,int managementFee,int postDesignCharges )
{
    int handlingFee=0;
    
    int adBudgetAmount;
    cout<<"\t\tENTER YOUR AD BUDGET : ";
    cin>>adBudgetAmount;
    cout<<endl;
    
    if(adBudgetAmount<=50000)
    {
        handlingFee=adBudgetAmount*0.05;
        cout<<"\t\tHANDLING FEE : 5% "<<endl<<endl;
    }
    else if(adBudgetAmount>50000&&adBudgetAmount<=100000)
    {
        handlingFee=adBudgetAmount*0.08;
        cout<<"\t\tHANDLING FEE : 8% "<<endl<<endl;
    }
    else if(adBudgetAmount>100000)
    {
        handlingFee=adBudgetAmount*0.1;
        cout<<"\t\tHANDLING FEE : 10% "<<endl<<endl;
    }
    
    campaignDays( clientName, businessName,managementFee,postDesignCharges,handlingFee,adBudgetAmount);
}
void campaignDays(string clientName,string businessName,int managementFee,int postDesignCharges,int handlingFee,int adBudgetAmount)
{
    int additionalFee=0;
    
    int daysRunning;
    cout<<"\t\tENTER THE NUMBER OF DAYS THE CAMPAIGN WOULD RUN : ";
    cin>>daysRunning;
    
    if(daysRunning>30)
    {
        additionalFee=(daysRunning-30)*500;
        cout<<"\t\tADDITIONAL FEE : "<<additionalFee<<endl<<endl;
        
    }
    else 
    {
        cout<<"\t\tNO ADDITIONAL FEE CHARGED ! "<<endl<<endl;
    }
    
    globalSaleTax( clientName, businessName,managementFee,postDesignCharges,handlingFee,adBudgetAmount,daysRunning,additionalFee);
}
void globalSaleTax(string clientName,string businessName,int managementFee,int postDesignCharges,int handlingFee,int adBudgetAmount,int daysRunning,int additionalFee)
{
    double gst=0.16;
    
    discountOnBusiness( clientName, businessName,managementFee,postDesignCharges,handlingFee,adBudgetAmount,daysRunning,additionalFee,gst);
    
}
void discountOnBusiness(string clientName,string businessName, int managementFee,int postDesignCharges ,int handlingFee,int adBudgetAmount,int daysRunning,int additionalFee,double gst)
{
    double discountAmount=0;
    cout<<"\t\tLIST OF AVAILABLE BUSINESS TYPES "<<endl;
    cout<<"\t\t1. SAMLL BUSINESS "<<endl;
    cout<<"\t\t2. MEDIUM BUSINESS "<<endl;
    cout<<"\t\t3. CORPORATE BUSINESS "<<endl<<endl;
    
    string business[3]={"SAMLL BUSINESS","MEDIUM BUSINESS","CORPORATE BUSINESS"};
    
    int option;
    cout<<"\t\tChoose : ";
    cin>>option;
    cout<<endl;
    if(option==1)
    {
        discountAmount=0.05;
        cout<<"\t\tDISCOUNT AMOUNT : 5%"<<endl<<endl;
        string businessType=business[0];
    }
    else if(option==2)
    {
        discountAmount=0.08;
        cout<<"\t\tDISCOUNT AMOUNT : 8%"<<endl<<endl;
        string businessType=business[1];
    }
    else if(option==3)
    {
        discountAmount=0.1;
        cout<<"\t\tDISCOUNT AMOUNT : 10%"<<endl<<endl;
        string businessType=business[2];
    }
    
    calculationAll( clientName, businessName,managementFee,postDesignCharges,handlingFee,adBudgetAmount,daysRunning,additionalFee,gst,discountAmount);
}
void calculationAll(string clientName,string businessName,int managementFee,int postDesignCharges,int handlingFee,int adBudgetAmount,int daysRunning,int additionalFee,double gst,double discountAmount)
{
    int roughTotal=(managementFee+postDesignCharges+handlingFee+additionalFee+adBudgetAmount);
    int roughTotalAgain=roughTotal+(roughTotal*gst);
    int roughTotalFinal=roughTotalAgain-(roughTotalAgain*discountAmount);
    cout<<"\t\tTOTAL COST : "<<roughTotalFinal<<endl<<endl;
    
    clientDetails( clientName, businessName,managementFee,postDesignCharges,handlingFee, adBudgetAmount,daysRunning,additionalFee,gst,discountAmount ,roughTotalFinal);
    
}
void clientDetails( string clientName,string businessName,int managementFee,int postDesignCharges,int handlingFee,int adBudgetAmount,int daysRunning,int additionalFee,double gst,double discountAmount ,int roughTotalFinal)
{
    cout<<"\t\t\t=======Details======="<<endl<<endl;
    cout<<"\t\tClient Name : "<<clientName<<endl;
    cout<<"\t\tBusiness Name : "<<businessName<<endl;
    cout<<"\t\tDays Running : "<<daysRunning<<endl;
    cout<<"\t\tPlatform Management Fee : "<<managementFee<<endl;
    cout<<"\t\tPost charges : "<<postDesignCharges<<endl;
    cout<<"\t\tAd Budget : "<<adBudgetAmount<<endl;
    cout<<"\t\tAds Handling Fee : "<<handlingFee<<endl;
    cout<<"\t\tAdditional Fee: "<<additionalFee<<endl;
    cout<<"\t\tGST : 16% "<<endl;
    cout<<"\t\tDiscount : "<<discountAmount<<endl;
    cout<<"\t\t Final Bill : "<<roughTotalFinal<<endl;
    
}
