/*
This Shopping cart Backend project is created by
- Lakshay Kumar

Github - https://github.com/Lakshaykumarr28

*/

#include<iostream>
#include<vector>
#include"datamodel.h"
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(3, "mango", 16),
    Product(2, "guava", 36),
    Product(5, "banana", 56),
    Product(4, "strawberry", 29),
    Product(6, "pineapple", 20),
};

Product* chooseProduct(){
    //display the list of products
    string Productlist;
    cout<<"Available products: "<<endl;

    for(auto product: allProducts){
        Productlist.append(product.getdisplayName() );
    }

    cout<<Productlist<<endl;

    cout<<"_____________"<<endl;

    string choice;
    cin>>choice;

    for(int i=0; i<allProducts.size(); i++){
        if(allProducts[i].getshortname() == choice){
            return &allProducts[i];
        }
    }
    cout<<"product not found!"<<endl;
    return NULL;

}

bool checkout(Cart &cart){
    if(cart.isempty()){
        return false;
    }

    int total = cart.getTotal();
    cout<<"Pay in cash, Enter your given cash amount: ";

    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change: "<<paid - total <<endl;
        cout<<"Thank you for shopping!";
        return true;
    }

    else{
        cout<<"Not Enough Cash";
        return false;
    }

}

int main(){
    
    char action;
    Cart cart;

    while(true){
        cout<<"select an action: (a) add item, (v) view cart, (c) checkout"<<endl;
        cin>>action;

        if(action=='a'){
            //add to cart
            //view all products + choose product + add to cart
            Product* product = chooseProduct();
            if(product!=NULL){
                cout<<"Added to the cart "<<product->getdisplayName()<<endl;
                cart.addProduct(*product);
            }
        }

        else if(action=='v'){
            //view the cart
            cout<<"___________"<<endl;
            cout<<cart.viewCart();
            cout<<"___________"<<endl;

        }

        else {
            //checkout
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }

    return 0;
}