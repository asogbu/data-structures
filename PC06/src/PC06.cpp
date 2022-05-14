// Initial template provided by Dr. Morrison
/**********************************
 * Name: Andres Santiago Orozco Gorjon
 * Email: aorozcog@nd.edu
 * File Name: PC06.cpp
 * Date Created: 03/17/2022
 * File Contents: main() for PC06
 **********************************/
#include "../include/lru_cache.h"

int main( ){
	
	/*************************************
	 * Here, you will call the constructor for the Doubly Linked List 
	 * and create the unordered_map with the int, dll_node* key value pair
	 ************************************/
	
	COUT << "State the size of the cache: ";
	long unsigned int cache_size;
	CIN >> cache_size;
	dllist cache_list(cache_size, 0);
	UNOR_MAP<int, dllist_node*> cache_map;

	char continue_read = 'y';
	
	int num_accesses = 0;
	
	while( continue_read == 'y' ){
	    
	    // Increment the number of accesses
	    ++num_accesses;
	    
	    char user_choice = get_user_choice( );
		int insert_data;
	   
		switch( user_choice ) {
				
			case 'p':
				
				/*************************************
				 * Here, you will get the input data value from the user 
				 * and then call the put function
				 ************************************/				
				COUT << "Integer data input: ";
				CIN >> insert_data;
				put_value(cache_list, cache_map, insert_data, num_accesses);
				break;
				
			case 'g':
			
				/*************************************
				 * Here, you will get the input data value from the user 
				 * and then call the get function
				 ************************************/	
				COUT << "Integer data input: ";
				CIN >> insert_data;
				get_value(cache_list, cache_map, insert_data, num_accesses);
				break;
				
			default:
				COUT << "Value must be between 1 and 3" << ENDL;
			
		}
		
		/*************************************
		 * Here, you will call print_list on your doubly linked list 
		 ************************************/			
		cache_list.print_list();
	    
	    COUT << "Do you wish to continue? (y/n): ";
	    CIN >> continue_read;
	    
	}
	
	/*************************************
	 * Note: Since you will be calling the constructor for dllist 
	 * without making it a pointer, the destructor will 
	 * automatically be called, so you do not need to call it!
	 ************************************/
	
	return EXIT_SUCCESS;
}
