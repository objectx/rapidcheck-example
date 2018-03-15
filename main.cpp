#include <rapidcheck.h>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iomanip>

namespace {
    void show_vec (std::ostream &o, const std::vector<int16_t> &vec) {
        size_t col = 0 ;
        o << "# size = " << vec.size () << '\n' ;
        for (auto const &v : vec) {
            o << ' ' << std::setw (8) << v ;
            col++ ;
            if (8 <= col) {
                o << '\n' ;
                col = 0 ;
            }
        }
        if (0 < col) {
            o << '\n' ;
        }
        o << std::endl ;
    }
}

int main () {
    rc::check ( "Double reversal should yield the original value"
              , [](const std::vector<int16_t> &l0) {
        auto l1 = l0 ;
        show_vec (std::cout, l0) ;
        std::reverse (begin (l1), end (l1)) ;
        std::reverse (begin (l1), end (l1)) ;
        RC_ASSERT (l1 == l0) ;
    }) ;
//    rc::check ( "Generate values"
//              , [] () {
//        auto const l0 = *rc::gen::arbitrary<std::vector<int16_t>> ();
//        auto l1 = l0 ;
//        show_vec (std::cout, l0) ;
//        std::reverse (begin (l1), end (l1)) ;
//        std::reverse (begin (l1), end (l1)) ;
//        RC_ASSERT (l1 == l0) ;
//    }) ;
    return 0;
}
