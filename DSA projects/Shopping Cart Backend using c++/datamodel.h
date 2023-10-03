/*
This Shopping cart Backend project is created by
- Lakshay Kumar

Github - https://github.com/Lakshaykumarr28

*/



#include<string>
#include<unordered_map>
using namespace std;

//produc t, Item and class
class Item;
class Cart;

class Product{
    int id;
    string name;
    int price;

public:
    Product(){

    }

    Product(int u_id, string name, int price){
        id = u_id;
        this->name = name;
        this->price = price;
    }

    string getdisplayName(){
        return name + " : Rs- " + to_string(price) + "\n";
    }

    string getshortname(){
        return name.substr(0,1);
    }

    friend class Item;
    friend class Cart;
};

class Item{
    Product product;
    int quantity;

public:
    Item(){

    }
    //constructor using init list
    Item(Product p, int q): product(p), quantity(q){}

    int getitemPrice(){
        return quantity* product.price;
    }

    string getIteminfo(){
        return to_string(quantity) + " x " + product.name + ": Rs. " + to_string(quantity*product.price)+"\n";
    }

    friend class Cart;
};

class Cart{

    unordered_map<int, Item> items;

public:
    void addProduct(Product product){
        if(items.count(product.id)==0){
            Item newItem(product, 1);
            items[product.id] = newItem;
        }
        else{
            items[product.id].quantity += 1;
        }
    }

    int getTotal(){
        int total = 0;
        for(auto itemPair: items){
            auto item = itemPair.second;
            total += item.getitemPrice();
        }
        return total;
    }

    string viewCart(){
        if(items.empty()){
            return "Cart is empty";
        }

        string itemizedlist;
        int cart_total = getTotal();

        for(auto itemPair: items){
            auto item = itemPair.second;
            itemizedlist.append(item.getIteminfo());
        }

        return itemizedlist + "\nTotal Amount: Rs. " + to_string(cart_total) + '\n';
    }

    bool isempty(){
        return items.empty();
    }


};