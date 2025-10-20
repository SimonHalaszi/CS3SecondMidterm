/*

STL ALGORITHMS

CATEGORIES

* non-modifying

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <deque> // for a container
#include <algorithm> // for most algorithms
#include <numeric> // for accumulate

int main() {
    std::deque<int> d = {10, 20, 30, 30, 40, 50};

    // ----------------------------------------------------------------------- //
    std::cout << "Non-Modifying Search Algorithms" << std::endl;
    // ----------------------------------------------------------------------- //

    // ----------------------------------------------------------------------- //
    // find functions, all will get iterator to d[1] (20)
    std::cout << std::endl << "find functions, all will get iterator to d[1] (20)" << std::endl << std::endl;

    // iterators for find functions
    std::deque<int>::iterator find_itr;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // find
    // iterator find(start_itr, end_itr, value) {...}
    find_itr = std::find(
        d.begin(), 
        d.end(), 
        20
    );
    std::cout << "itr = std::find(d.begin(), d.end(), 20);" << std::endl;
    std::cout << "*itr: " << *find_itr << std::endl;

    // find_if
    // iterator find_if(start_itr, end_itr, unary_predicate) {...}
    find_itr = std::find_if(
        d.begin(),
        d.end(),
        [](const int& i)-> bool { return i == 20; }
    );
    std::cout << "itr = std::find_if(d.begin(), d.end(), [](const int& i)-> bool { return i == 20; });" << std::endl;
    std::cout << "*itr: " << *find_itr << std::endl;

    // find_if_not
    // iterator find_if_not(start_itr, end_itr, unary_predicate) {...}
    find_itr = std::find_if_not(
        d.begin(),
        d.end(),
        [](const int& i)-> bool { return i == 10; }
    );
    std::cout << "itr = std::find_if_not(d.begin(), d.end(), [](const int& i)-> bool { return i == 10; });" << std::endl;
    std::cout << "*itr: " << *find_itr << std::endl;

    // ----------------------------------------------------------------------- //
    // min_element, max_element, minmax_element, functions
    std::cout << std::endl << "min_element, max_element, minmax_element, functions" << std::endl << std::endl;

    // iterators for min_element, max_element, minmax_element, functions
    std::deque<int>::iterator min_or_max_itr;
    std::pair<std::deque<int>::iterator, std::deque<int>::iterator> minmax_pair_itrs;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // min_element
    // iterator min_element(start_itr, end_itr) {...}
    min_or_max_itr = std::min_element(
        d.begin(), 
        d.end() 
    );
    std::cout << "min_or_max_itr = std::min_element(d.begin(), d.end());" << std::endl;
    std::cout << "*min_or_max_itr: " << *min_or_max_itr << std::endl;

    // max_element
    // iterator max_element(start_itr, end_itr) {...}
    min_or_max_itr = std::max_element(
        d.begin(), 
        d.end() 
    );
    std::cout << "min_or_max_itr = std::max_element(d.begin(), d.end());" << std::endl;
    std::cout << "*min_or_max_itr: " << *min_or_max_itr << std::endl;  
    
    // minmax_element
    // pair<iterator, iterator> minmax_element(start_itr, end_itr) {...}
    minmax_pair_itrs = std::minmax_element(
        d.begin(), 
        d.end() 
    );
    std::cout << "min_or_max_itr = std::minmax_element(d.begin(), d.end());" << std::endl;
    std::cout << "*minmax_pair_itrs.first: " << *minmax_pair_itrs.first;
    std::cout << " *minmax_pair_itrs.second: " << *minmax_pair_itrs.second << std::endl;

    // ----------------------------------------------------------------------- //
    // adjacent_find
    std::cout << std::endl << "adjacent_find" << std::endl << std::endl;

    std::deque<int>::iterator adjacent_find_itr;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // adjacent_find
    // iterator adjacent_find(start_itr, end_itr) {...}
    adjacent_find_itr = std::adjacent_find(
        d.begin(), 
        d.end() 
    );
    std::cout << "adjacent_find_itr = std::adjacent_find(d.begin(), d.end());" << std::endl;
    std::cout << "*adjacent_find_itr: " << *adjacent_find_itr << std::endl;
    std::cout << "++adjacent_find_itr;" << std::endl; ++adjacent_find_itr;
    std::cout << "*adjacent_find_itr: " << *adjacent_find_itr << std::endl;

    // ----------------------------------------------------------------------- //
    // find_first_of
    std::cout << std::endl << "find_first_of" << std::endl << std::endl;

    std::deque<int>::iterator find_first_of_itr;

    std::deque<int> candidates = {0, 23, 43, 12, 30};
    std::cout << "candidates: ";
    std::for_each(candidates.begin(), candidates.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // find_first_of
    // iterator find_first_of(start_itr, end_itr, candidates_start_itr, candidates_end_itr) {...}
    find_first_of_itr = std::find_first_of(
        d.begin(), 
        d.end(),
        candidates.begin(),
        candidates.end()
    );
    std::cout << "find_first_of_itr = std::find_first_of(d.begin(), d.end(), candidates.begin(), candidates.end());" << std::endl;
    std::cout << "*find_first_of_itr: " << *find_first_of_itr << std::endl;

    // ----------------------------------------------------------------------- //
    // search
    std::cout << std::endl << "search" << std::endl << std::endl;

    std::deque<int>::iterator search_itr;

    std::deque<int> find_me = {30, 40, 50};
    std::cout << "find_me: ";
    std::for_each(find_me.begin(), find_me.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // search
    // iterator search(start_itr, end_itr, find_me_start_itr, find_me_end_itr) {...}
    search_itr = std::search(
        d.begin(), 
        d.end(),
        find_me.begin(),
        find_me.end()
    );
    std::cout << "search_itr = std::search(d.begin(), d.end(), find_me.begin(), find_me.end());" << std::endl;
    std::cout << "*search_itr: " << *search_itr << std::endl;
    std::cout << "std::distance(d.begin(), search_itr): " << std::distance(d.begin(), search_itr) << std::endl;

    // ----------------------------------------------------------------------- //
    // search_n
    std::cout << std::endl << "search_n" << std::endl << std::endl;

    std::deque<int>::iterator search_n_itr;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // search_n
    // iterator search_n(start_itr, end_itr, n, value) {...}
    search_n_itr = std::search_n(
        d.begin(), 
        d.end(),
        2,
        30
    );
    std::cout << "search_n_itr = std::search_n(d.begin(), d.end(), 2, 30);" << std::endl;
    std::cout << "*search_n_itr: " << *search_n_itr << std::endl;
    std::cout << "std::distance(d.begin(), search_n_itr): " << std::distance(d.begin(), search_n_itr) << std::endl;

    // ----------------------------------------------------------------------- //
    // binary_search
    std::cout << std::endl << "binary_search" << std::endl << std::endl;

    bool binary_search_bool;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // binary_search
    // bool binary_search(start_itr, end_itr, value) {...}
    binary_search_bool = std::binary_search(
        d.begin(), 
        d.end(),
        20
    );
    std::cout << "binary_search_bool = std::binary_search(d.begin(), d.end(), 20);" << std::endl;
    std::cout << "binary_search_bool: " << binary_search_bool << std::endl;

    // ----------------------------------------------------------------------- //
    // lower_bound
    std::cout << std::endl << "lower_bound" << std::endl << std::endl;

    std::deque<int>::iterator lower_bound_itr;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // lower_bound
    // iterator lower_bound(start_itr, end_itr, value) {...}
    lower_bound_itr = std::lower_bound(
        d.begin(), 
        d.end(),
        20
    );
    std::cout << "lower_bound_itr = std::lower_bound(d.begin(), d.end(), 20);" << std::endl;
    std::cout << "*lower_bound_itr: " << *lower_bound_itr << std::endl;
    std::cout << "std::distance(d.begin(), lower_bound_itr): " << std::distance(d.begin(), lower_bound_itr) << std::endl;
    
    // ----------------------------------------------------------------------- //
    // upper_bound
    std::cout << std::endl << "upper_bound" << std::endl << std::endl;

    std::deque<int>::iterator upper_bound_itr;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // upper_bound
    // iterator upper_bound(start_itr, end_itr, value) {...}
    upper_bound_itr = std::upper_bound(
        d.begin(), 
        d.end(),
        20
    );
    std::cout << "upper_bound_itr = std::upper_bound(d.begin(), d.end(), 20);" << std::endl;
    std::cout << "*upper_bound_itr: " << *upper_bound_itr << std::endl;
    std::cout << "std::distance(d.begin(), upper_bound_itr): " << std::distance(d.begin(), upper_bound_itr) << std::endl;  
    
    // ----------------------------------------------------------------------- //
    // equal_range
    std::cout << std::endl << "equal_range" << std::endl << std::endl;

    std::pair<std::deque<int>::iterator, std::deque<int>::iterator> equal_range_itrs;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // equal_range
    // pair<iterator, iterator> equal_range(start_itr, end_itr, value) {...}
    equal_range_itrs = std::equal_range(
        d.begin(), 
        d.end(),
        30
    );
    std::cout << "equal_range_itr = std::equal_range(d.begin(), d.end(), 30);" << std::endl;
    std::cout << "*equal_range_itr.first: " << *equal_range_itrs.first << std::endl;
    std::cout << "*equal_range_itr.second: " << *equal_range_itrs.second << std::endl;
    std::cout << "std::distance(d.begin(), equal_range_itr.first): " << std::distance(d.begin(), equal_range_itrs.first) << std::endl;
    std::cout << "std::distance(d.begin(), equal_range_itr.second): " << std::distance(d.begin(), equal_range_itrs.second) << std::endl; 

    // ----------------------------------------------------------------------- //
    std::cout << std::endl << "Non-Modifying Quantifier Algorithms" << std::endl;
    // ----------------------------------------------------------------------- //  

    // ----------------------------------------------------------------------- //
    // all_of
    std::cout << std::endl << "all_of" << std::endl << std::endl;

    bool all_of_bool;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // all_of
    // bool all_of(start_itr, end_itr, unary_predicate) {...}
    all_of_bool = std::all_of(
        d.begin(), 
        d.end(),
        [](const int& i)-> bool { return i == 30; }
    );
    std::cout << "all_of_bool = std::all_of(d.begin(), d.end(), [](const int& i)-> bool { return i == 30; });" << std::endl;
    std::cout << "all_of_bool: " << all_of_bool << std::endl;

    // ----------------------------------------------------------------------- //
    // any_of
    std::cout << std::endl << "any_of" << std::endl << std::endl;

    bool any_of_bool;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // any_of
    // bool any_of(start_itr, end_itr, unary_predicate) {...}
    any_of_bool = std::any_of(
        d.begin(), 
        d.end(),
        [](const int& i)-> bool { return i == 30; }
    );
    std::cout << "any_of_bool = std::any_of(d.begin(), d.end(), [](const int& i)-> bool { return i == 30; });" << std::endl;
    std::cout << "any_of_bool: " << any_of_bool << std::endl;

    // ----------------------------------------------------------------------- //
    // none_of
    std::cout << std::endl << "none_of" << std::endl << std::endl;

    bool none_of_bool;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // none_of
    // bool none_of(start_itr, end_itr, unary_predicate) {...}
    none_of_bool = std::none_of(
        d.begin(), 
        d.end(),
        [](const int& i)-> bool { return i == 30; }
    );
    std::cout << "none_of_bool = std::none_of(d.begin(), d.end(), [](const int& i)-> bool { return i == 30; });" << std::endl;
    std::cout << "none_of_bool: " << none_of_bool << std::endl;
    
    // ----------------------------------------------------------------------- //
    std::cout << std::endl << "Non-Modifying Comparison Algorithms" << std::endl;
    // ----------------------------------------------------------------------- //  

    // ----------------------------------------------------------------------- //
    // equal
    std::cout << std::endl << "equal" << std::endl << std::endl;

    bool equal_bool;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // equal
    // bool equal(start_itr, end_itr, second_start_itr, second_end_itr) {...}
    equal_bool = std::equal(
        d.begin(), 
        d.end(),
        d.begin(), 
        d.end()
    );
    std::cout << "equal_bool = std::equal(d.begin(), d.end(), d.begin(), d.end());" << std::endl;
    std::cout << "equal_bool: " << equal_bool << std::endl;

    // ----------------------------------------------------------------------- //
    // mismatch
    std::cout << std::endl << "mismatch" << std::endl << std::endl;

    std::pair<std::deque<int>::iterator, std::deque<int>::iterator> mismatch_itrs;

    std::deque<int> dmismatched = {10, 20, 30, 40, 50};
    std::cout << "dmismatched: ";
    std::for_each(dmismatched.begin(), dmismatched.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // mismatch
    // pair<iterator, iterator> mismatch(start_itr, end_itr, second_start_itr, second_end_itr) {...}
    mismatch_itrs = std::mismatch(
        d.begin(), 
        d.end(),
        dmismatched.begin(),
        dmismatched.end()
    );
    std::cout << "mismatch_itrs = std::mismatch(d.begin(), d.end(), 30);" << std::endl;
    std::cout << "*mismatch_itrs.first: " << *mismatch_itrs.first << std::endl;
    std::cout << "*mismatch_itrs.second: " << *mismatch_itrs.second << std::endl;
    std::cout << "std::distance(d.begin(), mismatch_itrs.first): " << std::distance(d.begin(), mismatch_itrs.first) << std::endl;
    std::cout << "std::distance(dmismatched.begin(), mismatch_itrs.second): " << std::distance(dmismatched.begin(), mismatch_itrs.second) << std::endl;

    // ----------------------------------------------------------------------- //
    // lexicographical_compare
    std::cout << std::endl << "lexicographical_compare" << std::endl << std::endl;

    bool lexicographical_compare_bool;

    std::deque<int> dlexico = {10, 20, 30, 20};
    std::cout << "dlexico: ";
    std::for_each(dlexico.begin(), dlexico.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // lexicographical_compare
    // bool lexicographical_compare(start_itr, end_itr, second_start_itr, second_end_itr) {...}
    lexicographical_compare_bool = std::lexicographical_compare(
        d.begin(), 
        d.end(),
        dlexico.begin(), 
        dlexico.end()
    );
    std::cout << "lexicographical_compare_bool = std::equal(d.begin(), d.end(), dlexico.begin(), dlexico.end());" << std::endl;
    std::cout << "lexicographical_compare_bool: " << lexicographical_compare_bool << std::endl;

    // ----------------------------------------------------------------------- //
    std::cout << std::endl << "Non-Modifying Numerical Processing Algorithms " << std::endl;
    // ----------------------------------------------------------------------- //  

    // ----------------------------------------------------------------------- //
    // count
    std::cout << std::endl << "count" << std::endl << std::endl;

    int count_int;  
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // count
    // int count(start_itr, end_itr, value) {...}
    count_int = std::count(
        d.begin(), 
        d.end(),
        30
    );
    std::cout << "count_int = std::count(d.begin(), d.end(), value);" << std::endl;
    std::cout << "count_int: " << count_int << std::endl;

    // ----------------------------------------------------------------------- //
    // count
    std::cout << std::endl << "count_if" << std::endl << std::endl;

    int count_if_int;  
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // count_if
    // int count_if(start_itr, end_itr, unary_predicate) {...}
    count_if_int = std::count_if(
        d.begin(), 
        d.end(),
        [](const int& i)-> bool { return i == 30; }
    );
    std::cout << "count_if_int = std::count_if(d.begin(), d.end(), [](const int& i)-> bool { return i == 30; });" << std::endl;
    std::cout << "count_if_int: " << count_if_int << std::endl;

    // ----------------------------------------------------------------------- //
    // accumulate form one
    std::cout << std::endl << "accumulate form one" << std::endl << std::endl;

    int accumulate_form_one_int;  
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // accumulate form one
    // intial_value_type accumulate(start_itr, end_itr, intial_value) {...}
    accumulate_form_one_int = std::accumulate(
        d.begin(), 
        d.end(),
        0
    );
    std::cout << "accumulate_form_one_int = std::accumulate(d.begin(), d.end(), 0);" << std::endl;
    std::cout << "accumulate_form_one_int: " << accumulate_form_one_int << std::endl;

    // ----------------------------------------------------------------------- //
    // accumulate form two
    std::cout << std::endl << "accumulate form two" << std::endl << std::endl;

    int accumulate_form_two_int;  
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // accumulate form two
    // intial_value_type accumulate(start_itr, end_itr, intial_value, intial_value_type_binary_callback) {...}
    accumulate_form_two_int = std::accumulate(
        d.begin(), 
        d.end(),
        1,
        std::multiplies<>()
    );
    std::cout << "accumulate_form_two_int = std::accumulate(d.begin(), d.end(), 1, std::multiplies<>());" << std::endl;
    std::cout << "accumulate_form_two_int: " << accumulate_form_two_int << std::endl;
}