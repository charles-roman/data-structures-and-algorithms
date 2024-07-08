// EXCEPTION HANDLING:

    try { 
        // code to try running

        if (/*condition*/) {                                // fail condition checks
            throw 0;						                // throws error of type int
        } else if (/*condition*/) {                                         
            throw std::runtime_error("text to display");    // throws runtime error with text 
        } else if (/*condition*/) {
            throw;                                          // throws error and stops program
        }
    } 

    catch (int int_error_variable) { 
        // code to run if error of type int 
    } 

    catch (std::exception exception_variable) {	// catches exceptions of type std::exception and saves them to error object under exception_variable 
        // code to run if error of type exception
        std::cout << exception_variable.what();	// prints what the exception was 
    } 

    catch (...) {					            // ellipses catches any and all exceptions (catch all)
        // code to run if error of any type 
    }

