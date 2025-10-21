/*

STL ALGORITHMS

ENHANCED ITERATOR FUNCTIONS

* on algorithms

c++ on_algorithms.cpp
./a.out > on_algorithms.txt
rm ./a.out

*/

#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    // Set up

    // Source deques for demonstrating algorithms with inserters
    std::cout << "source containers: " << std::endl;

    std::deque<int> source_deque = {10, 20, 30, 40, 50};
    std::deque<int> source_deque_2 = {10, 20, 30, 60, 70, 80};

    std::cout << std::endl;

    std::cout << "source_deque: ";
    std::for_each(source_deque.begin(), source_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << "source_deque_2: ";
    std::for_each(source_deque_2.begin(), source_deque_2.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;

    std::deque<int> target_deque;
    std::back_insert_iterator<std::deque<int>> back_ins_itr = std::back_inserter(target_deque);

    // |---------------------------------------------------------|
    std::cout << std::endl;
    std::cout << "--- Modifying ---" << std::endl;
    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // transform form one
    std::cout << "transform form one" << std::endl;
    std::cout << std::endl;

    // kind_insert_iterator std::transform(source_start_itr, source_end_itr, inserter, unary_callback)
    back_ins_itr = std::transform(
        source_deque.begin(), 
        source_deque.end(), 
        back_ins_itr, 
        [](const int& i)-> int { return i * 2; }
    );
    std::cout << "back_ins_itr = std::transform(source_deque.begin(), source_deque.end(), back_ins_itr, [](const int& i)-> int { return i * 2; });" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // transform form two
    std::cout << "transform form two" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::transform(source_start_itr, source_end_itr, source2_start_itr, inserter, binary_callback)
    back_ins_itr = std::transform(
        source_deque.begin(), 
        source_deque.end(), 
        source_deque_2.begin(), 
        back_ins_itr, 
        [](const int& i, const int& j)-> int { return i * j; }
    );
    std::cout << "back_ins_itr = std::transform(source_deque.begin(), source_deque.end(), source_deque_2.begin(), back_ins_itr, [](const int& i, const int& j)-> int { return i * j; });" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // copy
    std::cout << "copy" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::copy(source_start_itr, source_end_itr, inserter)
    back_ins_itr = std::copy(
        source_deque.begin(), 
        source_deque.end(), 
        back_ins_itr
    );
    std::cout << "back_ins_itr = std::copy(source_deque.begin(), source_deque.end(), back_ins_itr);" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // copy_if
    std::cout << "copy_if" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::copy_if(source_start_itr, source_end_itr, inserter, unary_predicate)
    back_ins_itr = std::copy_if(
        source_deque.begin(), 
        source_deque.end(), 
        back_ins_itr,
        [](const int& i)-> bool { return i > 20; }
    );
    std::cout << "back_ins_itr = std::copy_if(source_deque.begin(), source_deque.end(), back_ins_itr, [](const int& i)-> bool { return i > 20; });" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // remove_copy
    std::cout << "remove_copy" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::remove_copy(source_start_itr, source_end_itr, inserter, 20)
    back_ins_itr = std::remove_copy(
        source_deque.begin(), 
        source_deque.end(), 
        back_ins_itr,
        20
    );
    std::cout << "back_ins_itr = std::remove_copy(source_deque.begin(), source_deque.end(), back_ins_itr, 20);" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // remove_copy_if
    std::cout << "remove_copy_if" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::remove_copy_if(source_start_itr, source_end_itr, inserter, unary_predicate)
    back_ins_itr = std::remove_copy_if(
        source_deque.begin(), 
        source_deque.end(), 
        back_ins_itr,
        [](const int& i)-> bool { return i > 20; }
    );
    std::cout << "back_ins_itr = std::remove_copy_if(source_deque.begin(), source_deque.end(), back_ins_itr, [](const int& i)-> bool { return i > 20; });" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // move
    std::cout << "move" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::move(source_start_itr, source_end_itr, inserter)
    back_ins_itr = std::move(
        source_deque.begin(), 
        source_deque.end(), 
        back_ins_itr
    );
    std::cout << "back_ins_itr = std::move(source_deque.begin(), source_deque.end(), back_ins_itr);" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << "source ints will stay valid after moving because of ints move constructor isnt destructive" << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // generate_n
    std::cout << "generate_n" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::generate_n(inserter, n, nullary_callback)
    back_ins_itr = std::generate_n(
        back_ins_itr,
        10,
        []()-> int { return 5; }
    );
    std::cout << "back_ins_itr = std::generate_n(back_ins_itr, 10, []()-> int { return 5; });" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    std::cout << std::endl;
    std::cout << "--- Sorting ---" << std::endl;
    std::cout << std::endl;
    // |---------------------------------------------------------|

    std::cout << "source_deque: ";
    std::for_each(source_deque.begin(), source_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << "source_deque_2: ";
    std::for_each(source_deque_2.begin(), source_deque_2.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;

    std::front_insert_iterator<std::deque<int>> front_ins_itr = std::front_inserter(target_deque);;

    // |---------------------------------------------------------|
    // merge
    std::cout << "merge" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    front_ins_itr = std::front_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::merge(source1_start_itr, source1_end_itr, source2_start_itr, source2_end_itr, inserter)
    front_ins_itr = std::merge(
        source_deque.begin(),
        source_deque.end(),
        source_deque_2.begin(),
        source_deque_2.end(),
        front_ins_itr
    );
    std::cout << "front_ins_itr = std::merge(source_deque.begin(), source_deque.end(), source_deque_2.begin(), source_deque_2.end(), front_ins_itr);" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    std::cout << std::endl;
    std::cout << "--- Set ---" << std::endl;
    std::cout << std::endl;
    // |---------------------------------------------------------|

    std::cout << "source_deque: ";
    std::for_each(source_deque.begin(), source_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << "source_deque_2: ";
    std::for_each(source_deque_2.begin(), source_deque_2.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;

    // |---------------------------------------------------------|
    // set_union
    std::cout << "set_union" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::set_union(source1_start_itr, source1_end_itr, source2_start_itr, source2_end_itr, inserter)
    back_ins_itr = std::set_union(
        source_deque.begin(),
        source_deque.end(),
        source_deque_2.begin(),
        source_deque_2.end(),
        back_ins_itr
    );
    std::cout << "back_ins_itr = std::set_union(source_deque.begin(), source_deque.end(), source_deque_2.begin(), source_deque_2.end(), back_ins_itr);" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // set_intersection
    std::cout << "set_intersection" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::set_intersection(source1_start_itr, source1_end_itr, source2_start_itr, source2_end_itr, inserter)
    back_ins_itr = std::set_intersection(
        source_deque.begin(),
        source_deque.end(),
        source_deque_2.begin(),
        source_deque_2.end(),
        back_ins_itr
    );
    std::cout << "back_ins_itr = std::set_intersection(source_deque.begin(), source_deque.end(), source_deque_2.begin(), source_deque_2.end(), back_ins_itr);" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // set_difference
    std::cout << "set_difference" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::set_difference(source1_start_itr, source1_end_itr, source2_start_itr, source2_end_itr, inserter)
    back_ins_itr = std::set_difference(
        source_deque.begin(),
        source_deque.end(),
        source_deque_2.begin(),
        source_deque_2.end(),
        back_ins_itr
    );
    std::cout << "back_ins_itr = std::set_difference(source_deque.begin(), source_deque.end(), source_deque_2.begin(), source_deque_2.end(), back_ins_itr);" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|

    // |---------------------------------------------------------|
    // set_symmetric_difference
    std::cout << "set_symmetric_difference" << std::endl;
    std::cout << std::endl;

    std::cout << "cleared target_deque" << std::endl; target_deque.clear();
    back_ins_itr = std::back_inserter(target_deque); // Needs revalidated

    // kind_insert_iterator std::set_symmetric_difference(source1_start_itr, source1_end_itr, source2_start_itr, source2_end_itr, inserter)
    back_ins_itr = std::set_symmetric_difference(
        source_deque.begin(),
        source_deque.end(),
        source_deque_2.begin(),
        source_deque_2.end(),
        back_ins_itr
    );
    std::cout << "back_ins_itr = std::set_symmetric_difference(source_deque.begin(), source_deque.end(), source_deque_2.begin(), source_deque_2.end(), back_ins_itr);" << std::endl;

    std::cout << "target_deque: ";
    std::for_each(target_deque.begin(), target_deque.end(), [](const int& i)-> void { std::cout << i << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
    // |---------------------------------------------------------|
}