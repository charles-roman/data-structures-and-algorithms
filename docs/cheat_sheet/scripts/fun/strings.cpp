// STRINGS

/* An array of chars */

    char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};	// create str as initialized arr (must be initialized)
						                            // \0 is null terminating char (i.e. end of arr)

    char str[] = "hello";	// create str as string literal (easier to type)
                            // null terminating char is implicit
    
    const char *ptr {"hello"};  // const char ptr can be initialzed with str literal
                                // ptr points to address of first char
                                // printing ptr will print str literal directly

    str[idx];			    // access value (same as arrays)
    str[idx] = new_value;	// modify value (same as arrays)

// Character Manipulation:
    // C (#include <ctype.h>)
    isalnum(char)/isalpha(char)...etc;
    islower(char)/isupper(char);
    tolower(char)/toupper(char);

    // C++ (#include <cctype>) https://en.cppreference.com/w/cpp/header/cctype
    std::isalnum(char)/std::isalpha(char)...etc;
    std::islower(char)/isupper(char);
    std::tolower(char)/toupper(char);

// String Manipulation:
	// C (#include <string.h>)
	strlen(str);	    // gives length of string (excluding null terminator)
	strcat(dst, src);	// concatenate (dst assumes new value of combined str)
	strcpy(dst, src);	// copy string (dst assume value of src) *dst len must be >= src len

    // C++ (#include <cstring>) https://en.cppreference.com/w/cpp/header/cstring
    std::strlen(str);	    
	std::strcat(dst, src);	
	std::strcpy(dst, src);

>-----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------

// String Type (#include <string>)
    std::string my_string;                      // create empty string
    std::string my_string {"Hello"};            // create initalized string
    std::string my_string1 {my_string2};        // initalize string with another string
    std::string my_string1 {my_string2, n};     // initalize string with part of another string (n = num of chars)
    std::string my_string1 {my_string2, i, n};  // initalize string with part of another string (i = starting index)
    std::string my_string {n, char};            // initalize string with n copies of a certain char

------------------------------------------------------EXCLUSIVE_TO_C++---------------------------------------------------------<
