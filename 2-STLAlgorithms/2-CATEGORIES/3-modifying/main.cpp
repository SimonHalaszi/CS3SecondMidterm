/*

STL ALGORITHMS

CATEGORIES

* modifying
    - remove-erase idiom
    - source and target range

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <deque> // for a container
#include <algorithm> // for most algorithms
#include <numeric> // for accumulate

int main() {
    std::deque<int> d;

    // ----------------------------------------------------------------------- //
    std::cout << "Modifying Algorithms" << std::endl;
    // ----------------------------------------------------------------------- //

    // ----------------------------------------------------------------------- //
    // transform for one
    std::cout << std::endl << "transform form one" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::deque<int> d_target;
    d_target.resize(6);

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   
    
    std::deque<int>::iterator transform_form_one_itr;

    // transform form one
    // iterator std::transform(source_start_itr, source_end_itr, target_start_itr, unary_callback) {...}
    transform_form_one_itr = std::transform(
        d.begin(), 
        d.end(), 
        d_target.begin(),
        [](const int& i)-> int { return i + 5; }
    );

    std::cout << "std::transform(d.begin(), d.end(), d_target.begin(), [](const int& i)-> int { return i + 5; })" << std::endl;
    std::cout << "*transform_form_one_itr: " << *transform_form_one_itr << std::endl;
    std::cout << "std::distance(d_target.begin(), transform_form_one_itr): " << std::distance(d_target.begin(), transform_form_one_itr) << std::endl;

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // ----------------------------------------------------------------------- //
    // transform for two
    std::cout << std::endl << "transform form two" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 
    
    std::deque<int> d2 = {10, 20, 30, 30, 40, 50};

    std::cout << "d2: ";
    std::for_each(d2.begin(), d2.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::deque<int>::iterator transform_form_two_itr;

    // transform form two
    // iterator std::transform(source_start_itr, source_end_itr, source2_start_itr, target_start_itr, binary_callback) {...}
    transform_form_two_itr = std::transform(
        d.begin(), 
        d.end(), 
        d2.begin(),
        d_target.begin(),
        [](const int& i, const int& j)-> int { return i + j; }
    );

    std::cout << "std::transform(d.begin(), d.end(), d2.begin(), d_target.begin(), [](const int& i, const int& j)-> int { return i + j; })" << std::endl;
    std::cout << "*transform_form_two_itr: " << *transform_form_two_itr << std::endl;
    std::cout << "std::distance(d_target.begin(), transform_form_two_itr): " << std::distance(d_target.begin(), transform_form_two_itr) << std::endl;

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // ----------------------------------------------------------------------- //
    // copy
    std::cout << std::endl << "copy" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::deque<int>::iterator copy_itr;

    // copy
    // iterator std::copy(source_start_itr, source_end_itr, target_start_itr) {...}
    copy_itr = std::copy(
        d.begin(), 
        d.end(), 
        d_target.begin()
    );

    std::cout << "std::copy(d.begin(), d.end(), d_target.begin())" << std::endl;
    if(copy_itr == d_target.end()) {
        std::cout << "copy_itr is at d_target.end()" << std::endl;
    }
    std::cout << "std::distance(d_target.begin(), copy_itr): " << std::distance(d_target.begin(), copy_itr) << std::endl;

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // ----------------------------------------------------------------------- //
    // copy_if
    std::cout << std::endl << "copy_if" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::deque<int>::iterator copy_if_itr;

    // copy_if
    // iterator std::copy_if(source_start_itr, source_end_itr, target_start_itr, unary_predicate) {...}
    copy_if_itr = std::copy_if(
        d.begin(), 
        d.end(), 
        d_target.begin(),
        [](const int& i)-> bool { return i == 20; }
    );

    std::cout << "std::copy_if(d.begin(), d.end(), d_target.begin(), [](const int& i)-> bool { return i == 20; })" << std::endl;
    std::cout << "*copy_if_itr: " << *copy_if_itr << std::endl;
    std::cout << "std::distance(d_target.begin(), copy_if_itr): " << std::distance(d_target.begin(), copy_if_itr) << std::endl;

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // ----------------------------------------------------------------------- //
    // remove_copy
    std::cout << std::endl << "remove_copy" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::deque<int>::iterator remove_copy_itr;

    // remove_copy
    // iterator std::copy_if(source_start_itr, source_end_itr, target_start_itr, value_to_remove) {...}
    remove_copy_itr = std::remove_copy(
        d.begin(), 
        d.end(), 
        d_target.begin(),
        20
    );

    std::cout << "std::remove_copy(d.begin(), d.end(), d_target.begin(), 20)" << std::endl;
    std::cout << "*remove_copy_itr: " << *remove_copy_itr << std::endl;
    std::cout << "std::distance(d_target.begin(), remove_copy_itr): " << std::distance(d_target.begin(), remove_copy_itr) << std::endl;

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // ----------------------------------------------------------------------- //
    // remove_copy_if
    std::cout << std::endl << "remove_copy_if" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::deque<int>::iterator remove_copy_if_itr;

    // remove_copy_if
    // iterator std::remove_copy_if(source_start_itr, source_end_itr, target_start_itr, unary_predicate) {...}
    remove_copy_if_itr = std::remove_copy_if(
        d.begin(), 
        d.end(), 
        d_target.begin(),
        [](const int& i)-> bool { return i == 20; }
    );

    std::cout << "std::remove_copy_if(d.begin(), d.end(), d_target.begin(), [](const int& i)-> bool { return i == 20; })" << std::endl;
    std::cout << "*remove_copy_if_itr: " << *remove_copy_if_itr << std::endl;
    std::cout << "std::distance(d_target.begin(), remove_copy_if_itr): " << std::distance(d_target.begin(), remove_copy_if_itr) << std::endl;

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // ----------------------------------------------------------------------- //
    // move
    std::cout << std::endl << "move" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::deque<int>::iterator move_itr;

    // move
    // void std::move(source_start_itr, source_end_itr, target_start_itr) {...}
    move_itr = std::move(
        d.begin(), 
        d.end(), 
        d_target.begin()
    );

    std::cout << "std::move(d.begin(), d.end(), d_target.begin(), [](const int& i)-> bool { return i == 20; })" << std::endl;
    if(move_itr == d_target.end()) {
        std::cout << "move_itr is at d_target.end()" << std::endl;
    }
    std::cout << "std::distance(d_target.begin(), move_itr): " << std::distance(d_target.begin(), move_itr) << std::endl;

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "Did use move constructor but ints move constructor doesnt really do anything moving wise just copys" << std::endl;

    // ----------------------------------------------------------------------- //
    std::cout << std::endl << "Modifying Algorithms that Operate on a Single Range" << std::endl;
    // ----------------------------------------------------------------------- //

    // ----------------------------------------------------------------------- //
    // replace
    std::cout << std::endl << "replace" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // replace
    // void std::replace(source_start_itr, source_end_itr, value_to_replace, replace_with_value) {...}
    std::replace(
        d.begin(), 
        d.end(), 
        20,
        200
    );

    std::cout << "std::replace(d.begin(), d.end(), 20, 200)" << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // ----------------------------------------------------------------------- //
    // replace_if
    std::cout << std::endl << "replace_if" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // replace_if
    // void std::replace_if(source_start_itr, source_end_itr, unary_predicate, replace_with_value) {...}
    std::replace_if(
        d.begin(), 
        d.end(), 
        [](const int& i)-> bool { return i == 20; },
        200
    );

    std::cout << "std::replace_if(d.begin(), d.end(), [](const int& i)-> bool { return i == 20; }, 200)" << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   

    // ----------------------------------------------------------------------- //
    // reverse
    std::cout << std::endl << "reverse" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // reverse
    // void std::reverse(source_start_itr, source_end_itr) {...}
    std::reverse(
        d.begin(), 
        d.end() 
    );

    std::cout << "std::reverse(d.begin(), d.end())" << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   

    // ----------------------------------------------------------------------- //
    // generate
    std::cout << std::endl << "generate" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // generate
    // void std::generate(source_start_itr, source_end_itr, nullary_callback) {...}
    std::generate(
        d.begin(), 
        d.end(), 
        []()-> int { return 250; }
    );

    std::cout << "std::generate(d.begin(), d.end(), []()-> int { return 250; })" << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;  
    
    // ----------------------------------------------------------------------- //
    // generate_n
    std::cout << std::endl << "generate_n" << std::endl << std::endl;

    d = {10, 20, 30, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // generate_n
    // void std::generate_n(source_start_itr, source_end_itr, n, nullary_callback) {...}
    std::generate_n(
        d.begin(), 
        2,
        []()-> int { return 250; }
    );

    std::cout << "std::generate_n(d.begin(), 2, []()-> int { return 250; })" << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

}