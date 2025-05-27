// FUNCTORS:

/* Object or Struct that can be called like a function by overloading function call operator ‘( )’ */ 

class MyClass { 
    public: 
        type operator( )(args) {		// defining a functor 
            // function body 
        } 
}; 

MyClass myObject;	// instantiate object 

myclass(args);		// calling a functor