#include <iostream>
#include <list>
#include <set>
using namespace std;
class Sale{
public:
    string town;
    string product;
    double price;
    double quantity;

    Sale(){

    }
    Sale(string town,string product,double price,double quantity){
        this->town = town;
        this->product = product;
        this->price = price;
        this->quantity = quantity;
    }


};
int main(){
    int listSize;
    cin >> listSize;
    list<Sale> sales;
    set<string> towns;
    for(int i = 0;i < listSize;i++){
        Sale currentSale;
        cin >> currentSale.town >> currentSale.product >> currentSale.price >> currentSale.quantity;
        sales.push_back(currentSale);
        towns.insert(currentSale.town);
    }
    cout <<endl;
    for(auto i = towns.begin();i != towns.end();i++){
        string town = *i;
        double total = 0;
        for(auto j = sales.begin();j != sales.end();j++){
            if((*j).town == town){
                total += (*j).price * (*j).quantity;
            }

        }
        cout << *i << " -> " <<total<<endl;
    }

    return 0;
}
