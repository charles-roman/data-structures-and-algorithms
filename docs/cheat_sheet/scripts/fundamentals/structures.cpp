// STRUCTS:

/* Allow you to collect many different data types into one derived data type */ 

struct myStruct {		// define struct 

    char* str; 
    int x; 
    struct otherStruct; 
    etc...              // variables should be declared, not initialized 

}; 

struct myStruct struct1;	                    // declare struct of type myStruct with name struct1 

struct myStruct struct1[n];	                    // declare struct array of size n 

struct myStruct struct1 = {“hello”, 1, ...};	// initialize (ordered) 

struct myStruct struct1 = {			            // initialize (unordered) 

    .x = 0, 
    .str = “hello”, 
    etc...	               // don’t need to initialize member variables in a struct immediately (can also just do a few) 

};	                       // myStruct is the “type” of structure and struct1 is the initialized structure 

 
struct1.x = 1;					// dot operator
struct1.str = “goodbye”;        // access/modify member variables


struct myStruct* structPointer = &struct1;	// struct pointer 

(*structPointer).x;				            // access/modify member variables through derefenced struct pointer
structPointer->str;				            // alternate syntax 