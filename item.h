#ifndef ITEM_H
#define ITEM_H


class Item
{
    public:
        Item(std::string name = "rock", double price = 0.01, std::string stadiumName = "", int quantity = 0);
        void setName(std::string newName);
        void setPrice(double newPrice);
        void setStadiumName(std::string newStadiumName);
        void setQuantity(int newQuantity);
        std::string getName() const;
        double getPrice() const;
        std::string getStadiumName() const;
        int getQuantity() const;

        bool operator<(const Item& other);
        bool operator>(const Item& other);
        bool operator<=(const Item& other);
        bool operator>=(const Item& other);
        bool operator==(const Item& other);
        bool operator!=(const Item& other);
    private:
        std::string name;
        double price;
        std::string stadiumName;
        int quantity;
};

#endif // ITEM_H
