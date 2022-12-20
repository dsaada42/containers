#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft{

    // template < class InputIterator >
    // bool equal( InputIterator it1, InputIterator it1end, InputIterator it2, InputIterator it2end){
    //     if ((it2end - it2) != (it1end - it1))
    //         return (false);
    //     while (it1 < it1end){
    //         // //si it2 arrive a la fin avant it1
    //         // if (it2 == it2end)
    //         //     return (false);
    //         //si *it1 != *it2
    //         if (*it1 != *it2)
    //             return (false);
    //         it1++;
    //         it2++;
    //     }
    //     // //si it1 arrive a la fin avant it2
    //     // if (it2 != it2end)
    //     //     return (false);
    //     return (true);
    // }

    template < class Input1, class Input2>
    bool equal(Input1 it1, Input1 it1end, Input2 it2, Input2 it2end){
        while (it1 != it1end){
            if (it1 != it2)
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