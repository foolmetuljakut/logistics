#ifndef ratemodel_item_hpp
#define ratemodel_item_hpp

namespace RateModel {

    class Item {
        unsigned id;
    public:
        Item(const unsigned& id) : id{id} {}
        unsigned Id() const;

        friend bool operator<(const Item& lhs, const Item& rhs);
    };

    bool operator<(const Item& lhs, const Item& rhs);

};

#endif//ratemodel_item_hpp