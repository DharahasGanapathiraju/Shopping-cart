#include<iostream>
#include<cstring>
using namespace std;
int n;
class bill
{
	int quantity[50],code_no[50];
	float price[50];
	char item_name[50][50];
	float sum;
	public:
		void create();
		void remove();
		void display();
		void modify();
};
	
void bill::create()
{
	int i;
	cout<<"Enter no of items: ";
	cin>>n;
	if(n<=0)
	{
	cout<<"Invalid input\n";
	create();
    }
	for(i=0;i<n;i++){
		cout<<endl;
		cout<<"Enter item code: ";
		cin>>code_no[i];
		cout<<"Enter item name: ";
		cin>>item_name[i];
		cout<<"Enter quantity: ";
		cin>>quantity[i];
		cout<<"Enter price(per unit): ";
		cin>>price[i];
	}
	cout<<"Items added to your list"<<endl;
}

void bill::display()
{
	if(n==0){
		cout<<"Your cart is empty!! Add items!!"<<endl;
	}
	else{
		int i;
		cout<<"\n////////////////////Your shopping bill////////////////////"<<endl;
		cout<<"\ncode_no\t\titem_name\tquantity\tprice\t\tsubtotal"<<endl;
		for(i=0;i<n;i++){
			cout<<code_no[i];
			cout<<"\t\t"<<item_name[i];
			cout<<"\t\t"<<quantity[i];
			cout<<"\t\t"<<price[i];
			cout<<"\t\t"<<price[i]*quantity[i]<<endl;
		}
		sum=0;
		for(i=0;i<n;i++){
			sum+=price[i]*quantity[i];
		}
		cout<<"Total cost: "<<sum<<endl;
		cout<<"\n////////////////////Thankyou Visit Again////////////////////"<<endl;
	}
}
void bill::modify()
{
	if(n==0){
		cout<<"Your list is empty!!"<<endl;
	}
	else{
		int c,i,f=0;
	cout<<"Enter the item code to be modified: ";
	cin>>c;
	cout<<"Enter new price\n";
	float pr;
	cin>>pr;
	for(i=0;i<n;i++){
		if(code_no[i]==c)
		{
price[i]=pr;
		f++;
		}

	}
	if(f!=0){
		cout<<"Item modified"<<endl;
		
	}
	else
		cout<<"The item you needed to modify is not present in the list"<<endl;
	}
}

void bill::remove()
{
	if(n==0){
		cout<<"Your list is empty!!"<<endl;
	}
	else{
		int c,i,f=0;
	cout<<"Enter the item code to be deleted: ";
	cin>>c;
	for(i=0;i<n;i++){
		if(code_no[i]==c){
			for(i=i;i<n;i++){
				code_no[i]=code_no[i+1];
				strcpy(item_name[i],item_name[i+1]);
				quantity[i]=quantity[i+1];
				price[i]=price[i+1];
				f++;
			}
		}
	}
	if(f!=0){
		cout<<"Item removed"<<endl;
		n--;
	}
	else
		cout<<"The item you needed to delete is not present in the list"<<endl;
	}
}
int main()
{
	bill b;
	int choice,i;
	while(i!=0)
	{
	cout<<"**MENU***\n1.Add Items\n2.Remove Item\n3.Modify price\n4.Display Bill"<<endl;
	cout<<"Enter the choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			b.create();			
			break;
		case 2:
			b.display();
			b.remove();
			break;
		case 3:
			b.modify();
			break;
			case 4:
			b.display();
			break;
		default:
			cout<<"Enter valid choice!!!"<<endl;
	}
	cout<<"Do you want to continue(1-yes, 0-no):\n ";
	cin>>i;
	}
	return 0;
}
