#include <iostream>
#include <vector>


using namespace std;


class Product
{
    private:
        int coffe;
        int milk;
        int chocolate;
    public:
        Product(int a,int b,int c)
        {
            coffe=a;
            milk=b;
        	chocolate=c;
        }
        bool order_coffe(){
			if(coffe>0){
        		coffe--;
        		return 1;
			}else{
				if(coffe==0)
					cout<<"Not enough coffe"<<endl;
				return 0;
			}
		}
		bool order_coffe_milk(){
        	if(coffe>0 && milk>0)
        	{
        		coffe--;
        		milk--;
        		return 1;
			}else{
				if(coffe==0)
					cout<<"Not enough coffe"<<endl;
				if(milk==0)
					cout<<"Not enough milk"<<endl;
				return 0;
			}
		}
		bool order_chocolate(){
        	if(chocolate>0)
        	{
        		chocolate--;
        		return 1;
			}else{
				if(chocolate==0)
					cout<<"Not enough chocolate"<<endl;
				return 0;
			}
		}
		bool order_chocolate_milk(){
        	if(chocolate>0 && milk>0)
        	{
        		chocolate--;
        		milk--;
        		return 1;
			}else{
				if(chocolate==0)
					cout<<"Not enough chocolate"<<endl;
				if(milk==0)
					cout<<"Not enough milk"<<endl;
				return 0;
			}
		}
		bool reset(){
			coffe=10;
            milk=20;
            chocolate=10;
            return 0;
		}
		

};


int menu()
{
	
    int choice;
    cout<<"1. Coffe 1.5€"<<endl;
    cout<<"2. Coffe with milk 1.8€"<<endl;
    cout<<"3. Chocolate 2.1€"<<endl;
    cout<<"4. Chocolate with milk 2.4€"<<endl;
    cout<<"5. Refill"<<endl;
    cout<<"-1. Exit"<<endl;
    cout<<"What will you have?\n";
    cin>>choice;
    cout<<endl;
    return choice;

}    


int main()
{
	
    Product inventory(10,20,10);
    float coins[7]={0.1,0.2,0.5,1,2,5,10}; 
    float price[4]={1.5,1.8,2.1,2.4};
    vector <int> recipt;
    int selection;
    bool check;
    
    while(true)
   	{
            selection=menu();
            switch(selection)
        {
            case 1:
				    check=inventory.order_coffe();
                break;
            case 2:
				    check=inventory.order_coffe_milk();
                break;
            case 3:
				    check=inventory.order_chocolate();
                break;
            case 4:
				    check=inventory.order_chocolate_milk();
                break;
            case 5:
				    check=inventory.reset();
				    recipt.push_back(selection);
                break;
        }
        if(selection== -1)
			break;
		if(check==1)
		{
		    
			float temp=0;
			float temp2=0;
			float temp3=0;
			while(temp<price[selection-1])
			{
			    temp3=temp-price[selection-1];
				cout<<"insufisient amount ";
				cout<<"remaining amount:"<< temp3 <<endl;
				do{
					cin>>temp2;
					if(temp2!=coins[0] && temp2!=coins[1] && temp2!=coins[2] && temp2!=coins[3] && temp2!=coins[4] && temp2!=coins[5] && temp2!=coins[6] && temp2!=-1)
						cout<<"wrong curensy"<<endl;
				    }while(temp2!=coins[0] && temp2!=coins[1] && temp2!=coins[2] && temp2!=coins[3] && temp2!=coins[4] && temp2!=coins[5] && temp2!=coins[6] && temp2!=-1);
				if(temp2==-1)
					break;
				temp+=temp2;
			}
			
			if(temp2!=-1)
			{
				temp-=price[selection-1];
				    int i=temp/10;
				cout<<"10:  "<<i<<endl;
				    temp-=i*10;
				    i=temp/5;
				cout<<"5:   "<<i<<endl;
				    temp-=i*5;
				    i=temp/2;
				cout<<"2:   "<<i<<endl;
				    temp-=i*2;
				    i=temp/1;
				cout<<"1:   "<<i<<endl;
				    temp-=i*1;
				    i=temp/0.5;
				cout<<"0.5: "<<i<<endl;
				    temp-=i*0.5;
				    i=temp/0.2;
				cout<<"0.2: "<<i<<endl;
				    temp-=i*0.2;
				    i=temp/0.1;
				cout<<"0.1: "<<i<<endl;
				    temp-=i*0.1;
				    i=temp/0.1;
				recipt.push_back(selection);
			}
		}
    }
    
	for (int i = 0; i < recipt.size(); i++) {
        cout << recipt.at(i) <<endl;
            switch(recipt.at(i))
            {
            case 1:
				cout<<"1. Coffe 1.5€"<<endl;
                break;
            case 2:
				cout<<"2. Coffe with milk 1.8€"<<endl;
                break;
            case 3:
				cout<<"3. Chocolate 2.1€"<<endl;
                break;
            case 4:
				cout<<"4. Chocolate with milk 2.4€"<<endl;
                break;
            case 5:
				cout<<"5. Refill"<<endl;
                break;
		    }
	}
}
