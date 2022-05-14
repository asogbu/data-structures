// Initial template provided by Dr. Morrison
/**********************************
 * Name: Andres Santiago Orozco Gorjon
 * Email: aorozcog@nd.edu
 * File Name: lru_cache.cpp
 * Date Created: 03/17/2022
 * File Contents: This file contains the function definitions for Programming Challenge 06
 ***********************************/

#include "../include/lru_cache.h"

char get_user_choice( ){
	
	COUT << "Enter your choice: " << ENDL;
	COUT << "p: Put value onto cache" << ENDL;
	COUT << "g: Get value from cache" << ENDL;
	COUT << "Enter your choice: ";
	
	char user_choice;
	
	CIN >> user_choice;
	
	return user_choice;
	
}


SIZE_T initialize_cache( ){
	
	COUT << "State the size of the cache: ";
	
	int capacity;
	
	CIN >> capacity;
	
	return capacity;
}


void put_value( dllist& cache_list, UNOR_MAP< int, dllist_node* >& cache_map, 
    int insert_data, int num_accesses ){

	/*********************************
	 * You will follow the steps for putting an element into a DLList and unordered map
	 * from the Programming Challenge 06 description
	 *********************************/
	if (cache_map.find(insert_data) == cache_map.end()) {
		COUT << "The element is now in the cache" << ENDL;
		if (cache_list.at_capacity()) cache_list.pop_back();
		dllist_node* inserted_element = cache_list.push_front(insert_data, num_accesses);
		cache_map.insert({insert_data, inserted_element});
	} else {
		COUT << "Cache Hit: The element is already in the cache" << ENDL;
		get_value(cache_list, cache_map, insert_data, num_accesses);
	}	
}


void get_value( dllist& cache_list, UNOR_MAP< int, dllist_node* >& cache_map, 
    const int insert_data, int num_accesses ){
		
	/*********************************
	 * You will follow the steps for putting an element into a DLList and unordered map
	 * from the Programming Challenge 06 description
	 *********************************/
	if (cache_map.find(insert_data) != cache_map.end()) {
		COUT << "Cache Hit: The value is in the cache" << ENDL;
		dllist_node* retrieved_element = cache_map[insert_data];
		cache_list.promote_node_to_front(retrieved_element, num_accesses);
	} else {
		COUT << "Cache miss: The value is not in the cache" << ENDL;
	}
}
