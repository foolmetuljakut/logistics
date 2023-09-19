#ifndef ratemodel_item_hpp
#define ratemodel_item_hpp

namespace ratemodel {

    class item {
        unsigned id;
    public:
        item(const unsigned& id) : id{id} {}

        friend bool operator<(const item& lhs, const item& rhs);
    };

    bool operator<(const item& lhs, const item& rhs);

};

#endif//ratemodel_item_hpp