#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {

    template < class Input1, class Input2 >
    bool lexicographical_compare(Input1 it1, Input1 it1end, Input2 it2, Input2 it2end){
        while (it1 < it1end)
        {
            //si size range 2 > size range 1
            if (it2 == it2end)
                return (false);
            if (*it1 < *it2)
                return (true);
            it1++;
            it2++;
        }
        //si les deux sont a la fin egales on return false
        if (it2 == it2end)
            return (false);
        //si la range1 est un prefixe de la range2 on return true 
        else
            return (true);
    }
}

#endif