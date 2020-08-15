#include <iostream>
#include <string>

#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>

#include <set>
#include <map>

#include <unordered_set>
#include <unordered_map>


void startInVector(); // Vector
void startInArray();
void startInList(); // List
void startInF_list(); // Forward List
void startInDeque(); // Deque
void startInSet(); // Set
void startInMultiMap(); // MultiMap
void startInUnordered_MultiSet(); // Unordered_MultiSet
void startInUnordered_Map(); //Unordered_Map


// //////////////////// custom struct Product
struct Product{
    int id;
    double price;

    Product(const Product& p): id(p.id), price(p.price){}
    // Product(const Product&& p): id(p.id), price(p.price){}
    Product(int i=0, double p=0): id(i),price(p){}


    bool operator == (const Product& p) const {
        if (this->id==p.id ) //and price==p->price
            return true;
        else
            return false;
    }

    bool operator < (const Product* p) const  {return id < p->id;}
};

// Functor
namespace std {
    template <>
    struct hash<Product>{
       size_t operator()(const Product &p) const
        {
            return hash<int>()(p.id);
        }
    };
}

// less<CLASS>
namespace std {
    template <>
    struct less<Product>{
        bool operator()(const Product &p1,const Product &p2) const
        {
            return p1.id < p2.id;
        }
    };
}


int main() {

     startInVector();
     startInArray();
     startInList();
     startInF_list();
     startInDeque();
     startInSet();
     startInMultiMap();
     startInUnordered_MultiSet();
     startInUnordered_Map();

    return 0;
}


void startInVector(){

    std::cout<<"Vector:\n";
    std::vector<Product> vector = {{1,21},{2,30},{3,15}};
    vector.emplace_back(4,70);
    vector.erase(vector.begin());

    for (const auto& it : vector) {
        std::cout<<"Product: id = "<<it.id<<" price = "<<it.price<<std::endl;
    }

    std::cout<<"\n";

}



void startInArray(){

    std::cout<<"Array:\n";
    std::array<Product,10> array; // Array Requires a default constructor
    for (auto i = 0; i!=5; ++i) {
       array[i]={i,(double )i*2};
    }
    for (auto i = 0; i!=5; ++i) {
        std::cout<<"Product: id = "<<array[i].id<<" price = "<<array[i].price<<std::endl;
    }
    std::cout<<"\n";

}



void startInList() {
    std::cout<<"List:\n";
    std::list<Product> list;
    list.push_front({}); // default constructor id =0 price =0
    list.push_front({1, 457});
    for (const auto & it : list) {
        std::cout<<"Product: id = "<<it.id<<" price = "<<it.price<<std::endl;
    }

    std::cout<<"\n";
}


void startInF_list(){
    std::cout<<"F_List:\n";
    std::forward_list<Product> f_list;
    f_list.push_front({}); // default constructor id =0 price =0
    f_list.push_front({1, 457});
    for (const auto & it : f_list) {
        std::cout<<"Product: id = "<<it.id<<" price = "<<it.price<<std::endl;
    }

    std::cout<<"\n";
}


void startInDeque(){
    std::cout<<"Deque:\n";
    std::deque<Product> deque{{4,454},{2,282},{7,737}};

    deque.insert(deque.end(),2, Product(10,25));
    deque.emplace(deque.end(),Product(3, 332));
    for (const auto & it : deque) {
        std::cout<<"Product: id = "<<it.id<<" price = "<<it.price<<std::endl;
    }
    std::cout<<"\n";
}


void startInSet(){
    std::cout<<"Set:\n";    // Requires operator <
    std::set<Product> set{{4,454},{2,282},{7,737}};
    set.emplace(Product(3,332));
    set.insert(Product(2,282));

    for (const auto & it : set) {
        std::cout<<"Product: id = "<<it.id<<" price = "<<it.price<<std::endl;
    }

    std::cout<<"\n";
}


void startInMultiMap(){
    std::cout<<"MultiMap:\n";
    std::multimap<Product,std::string> m_map{{1,"Table"},{4,"Chair"},{1,"Mouse"}};
    m_map.emplace(Product(2),"Display"); // Clearly !
    m_map.insert({2,"Display"});
    for (const auto & it : m_map) {
        std::cout<<"Product: id = "<<it.first.id<<" name = "<<it.second<<std::endl;
    }

    std::cout<<"\n";
}


void startInUnordered_MultiSet(){
    std::cout<<"Unordered_MultiSet:\n";
    std::unordered_multiset<Product> un_m_set;
    un_m_set.emplace(Product(1,187));
    un_m_set.insert(Product(6,687));
    un_m_set.emplace(Product(2,287));

    for (const auto & it : un_m_set) {
        std::cout<<"Product: id = "<<it.id<<" Price = "<<it.price<<std::endl;
    }

    std::cout<<"\n";
}


void startInUnordered_Map(){
    std::cout<<"Unordered_Map:\n";
    std::unordered_map<Product,std::string> un_map{{Product(1,200),"Display"},{Product(3,90),"Table"}};
    un_map.insert(std::make_pair(Product(2,1),"Pen"));
    un_map.emplace(std::make_pair(Product(0,3),"Notebook"));

    for (const auto & it : un_map) {
        std::cout<<"Product: id = "<<it.first.id<<" name = "<<it.second<<"-> price = "<<it.first.price<<std::endl;
    }

    std::cout<<"\n";
}