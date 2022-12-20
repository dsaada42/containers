#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft{

    template < class Input1, class Input2>
    bool equal(Input1 it1, Input1 it1end, Input2 it2, Input2 it2end){
        while (it1 != it1end){
            if (!(*it1 == *it2))
                return(false);
            it1++;
            it2++;
        }
        if (it2 != it2end)
            return (false);
        return (true);
    }
}
#endif