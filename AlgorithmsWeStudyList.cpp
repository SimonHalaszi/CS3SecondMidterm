/*
Short List:
    Utility Algorithms
        xy_type = std::min(x, y)
        xy_type = std::max(x, y)
        pair<xy_type, xy_type> = std::minmax(x, y)
        void std::swap(x, y)

    Non-Modifying Search Algorithms
        itr = std::find_if(start_itr, end_itr, unary_predicate) 
        itr = std::find_if_not(start_itr, end_itr, unary_predicate)
        itr = std::min_element(start_itr, end_itr)
        itr = std::max_element(start_itr, end_itr)
        pair<itr, itr> = std::minmax_element(start_itr, end_itr)
        itr = std::adjacent_find(start_itr, end_itr)
        itr = std::find_first_of(start_itr, end_itr, candidates_start_itr, candidates_end_itr)
        itr = std::search(start_itr, end_itr, find_start_itr, find_end_itr)
        itr = std::search_n(start_itr, end_itr, n, value)
        bool = std::binary_search(start_itr, end_itr, value)
        itr = std::lower_bound(start_itr, end_itr, value)
        itr = std::upper_bound(start_itr, end_itr, value)
        pair<itr, itr> = std::equal_range(start_itr, end_itr, value)
        
    Non-Modifying Quantifier Algorithms
        bool = std::all_of(start_itr, end_itr, unary_predicate)
        bool = std::any_of(start_itr, end_itr, unary_predicate)
        bool = std::none_of(start_itr, end_itr, unary_predicate)

    Non-Modifying Comparison Algorithms 
        bool = std::equal(start_itr, end_itr, start_itr_two, end_itr_two)
        pair<itr, itr> = std::mismatch(start_itr, end_itr, start_itr_two, end_itr_two)
        bool = std::lexicographical_compare(start_itr, end_itr, start_itr_two, end_itr_two)

    Non-Modifying Operational Algorithms 
        void std::for_each(start_itr, end_itr, unary_callback)

    Non-Modifying Numerical Processing Algorithms 
        int = std::count(start_itr, end_itr, value)
        int = std::count_if(start_itr, end_itr, unary_predicate)
        initial_value_type = std::accumulate(start_itr, end_itr, initial_value) // form one
        initial_value_type = std::accumulate(start_itr, end_itr, initial_value, binary_callback) // form two

    Modifying: Remove (and Erase)
        itr = std::remove(start_itr, end_itr, element_value)
        itr = std::remove_if(start_itr, end_itr, unary_predicate)

    Modifying Algorithms
        itr_in_target = std::transform(source_start_itr, source_end_itr, target_start_itr, unary_callback) // form one
        itr_in_target = std::transform(source_start_itr, source_end_itr, second_source_start_itr, target_start_itr, binary_callback) // form two
        itr_in_target = std::copy(source_start_itr, source_end_itr, target_start_itr)
        itr_in_target = std::copy_if(source_start_itr, source_end_itr, target_start_itr, unary_predicate)
        itr_in_target = std::remove_copy(source_start_itr, source_end_itr, target_start_itr, source_element_value)
        itr_in_target = std::remove_copy_if(source_start_itr, source_end_itr, target_start_itr, unary_predicate)
        itr_in_target = std::move(source_start_itr, source_end_itr, target_start_itr)

    Modifying Algorithms that Operate on a Single Range
        void std::replace(start_itr, end_itr, value_to_replace, replace_with_value)
        void std::replace_if(start_itr, end_itr, unary_predicate, replace_with_value)
        void std::reverse(start_itr, end_itr)
        itr = std::unique(start_itr, end_itr)
        void std::generate(start_itr, end_itr, nullary_callback)
        void std::generate_n(start_itr, n, nullary_callback)

    Sorting
        void std::sort(start_itr, end_itr)
        itr_in_target = std::merge(source_start_itr, source_end_itr, source2_start_itr, source2_end_itr, targert_start_itr)
        itr = std::unique(start_itr, end_itr)
        bool = std::binary_search(start_itr, end_itr, value)
        void std::random_shuffle(start_itr, end_itr)

    Set
        bool = std::includes(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr)
        itr_in_target = std::set_union(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr)
        itr_in_target = std::set_intersection(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr)
        itr_in_target = std::set_difference(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr)
        itr_in_target = std::set_symmetric_difference(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr)

*/