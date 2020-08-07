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

// //////////////////// custom struct Product
struct Product{
    int id;
    double price;

    Product(const Product& p): id(p.id), price(p.price){}
    Product(){id=0;price=0;}
    Product(int i) : id(i), price(0) {}
    Product(int i, double p): id(i),price(p){}


    bool operator == (const Product& p) const {
        if (this->id==p.id ) //and price==p->price
            return true;
        else
            return false;
    }

    bool operator < (const Product* p)  {return id < p->id;}
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

    std::cout<<"Vector:\n";
    std::vector<Product> vector = {{1,21},{2,30},{3,15}};
    vector.push_back({4,70});
    vector.erase(vector.begin());

    for (auto it = vector.begin(); it!=vector.end(); ++it) {
        std::cout<<"Product: id = "<<it->id<<" price = "<<it->price<<std::endl;
    }

    std::array<Product,10> array; // Array Requires a default constructor

    std::cout<<"\n";

    std::cout<<"F_List:\n";
    std::forward_list<Product> f_list;
    f_list.push_front({}); // default constructor id =0 price =0
    f_list.push_front({1, 457});
    for (auto it = f_list.begin(); it!=f_list.end(); ++it) {
        std::cout<<"Product: id = "<<it->id<<" price = "<<it->price<<std::endl;
    }

    std::cout<<"\n";

    std::cout<<"Set:\n";    // Requires operator <
    std::set<Product> set{{4,454},{2,282},{7,737}};
    set.insert(Product(3,332));
    // set.insert({3,332}); Don't work !

    for (auto it = set.begin(); it!=set.end(); ++it) {
        std::cout<<"Product: id = "<<it->id<<" price = "<<it->price<<std::endl;
    }

    std::cout<<"\n";

    std::cout<<"Deque:\n";    // Requires operator <
    std::deque<Product> deque{{4,454},{2,282},{7,737}};
    set.insert(Product(3,332));
    for (auto it = deque.begin(); it!=deque.end(); ++it) {
        std::cout<<"Product: id = "<<it->id<<" price = "<<it->price<<std::endl;
    }

    std::cout<<"\n";

    std::cout<<"MultiMap:\n";
    std::multimap<Product,std::string> m_map{{1,"Table"},{4,"Chair"},{1,"Mouse"}};
    m_map.insert({2,"Display"});
    for (auto it = m_map.begin(); it!=m_map.end(); ++it) {
        std::cout<<"Product: id = "<<it->first.id<<" name = "<<it->second<<std::endl;
    }

    std::cout<<"\n";

    std::cout<<"Unordered_MultiSet:\n";
    std::unordered_multiset<Product> un_m_set;
    un_m_set.insert(Product(1,187));
    un_m_set.insert(Product(6,687));
    un_m_set.insert(Product(2,287));

    for (auto it = un_m_set.begin(); it!=un_m_set.end(); ++it) {
        std::cout<<"Product: id = "<<it->id<<" Price = "<<it->price<<std::endl;
    }

    std::cout<<"\n";

    std::cout<<"Unordered_Map:\n";
    std::unordered_map<Product,std::string> un_map{{Product(1,200),"Display"},{Product(3,90),"Table"},{Product(0,3),"Notebook"}};
    un_map.insert(std::make_pair(Product(2,1),"Pen"));
    for (auto it = un_map.begin(); it!=un_map.end() ; ++it) {
        std::cout<<"Product: id = "<<it->first.id<<" name = "<<it->second<<"-> price = "<<it->first.price<<std::endl;
    }
    return 0;
}
