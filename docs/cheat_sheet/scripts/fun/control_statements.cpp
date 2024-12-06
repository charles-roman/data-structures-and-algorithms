// CONTROL STATEMENTS:

    // CONDITIONALS:
        if (/*condition*/)      // brackets unrequired for one line statements
            // action;

        if (/*condition1*/) {
            // action 1;
        } else if (/*condition2*/) {
            // action 2;
        } else {
            // action 3;
        }

        switch(/*comparable value*/) {
            case value1:
                // action 1;
                break;		    // need break statement to avoid further actions!!!
            case value2:
                // action 2;
                break;
            default:
                // action 3;
                break;
        }

        /*condition*/ ? /*true_action*/ : /*false_action*/;                     // ternary operator (?)

        int min = my_var1 < my_var2 ? my_var1 : my_var2;	                    // ex: int min stores low value
        my_var1 < my_var2 ? printf(“%d\n”, my_var1) : printf(“%d\n”, my_var2);  // ex: print low value

    // LOOPS:
        while (/*condition*/) {     // while loop
            // actions;
        }

        do {						// do-while loop
            // actions;
        } while (/*condition*/);

        for (/*initialize counter*/, /*condition*/, /*change in counter*/)	// for loop: basic format

        for (size_t i = 0; i < total; ++i) {		                        // for loop: example
            // actions;
            break;		    // leave loop
            continue; 	    // next iter
            goto /*label*/; // jump to label
        }

    >-----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------

        type numbers[] = { ... };
        for (auto num : numbers) {   // range based for loop example (auto deduces type from list)
            // actions;
        }
        
    -----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------<