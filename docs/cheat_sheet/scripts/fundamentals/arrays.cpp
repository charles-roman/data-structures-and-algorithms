// ARRAYS:

    /* 
    Arrays are static, contiguous blocks of memory. Can contain any data type but must be
    consistent. Must be careful not to access elements outside indices of an array, other 
    data is being stored there.

    Access/Modify -> O(1)
    Insert/Delete -> N/A
    */

    type my_array[size];	                    // create uninitialized array
    type my_array[] = {val1, val2, val3, ...};	// create initialized array
    
    my_array[idx];			    // access value
    my_array[idx] = new_value;	// modify value

    type my_matrix[row_size][column_size];	                            // create uninitialized matrix
    type my_matrix[][column_size] = {{val1, val2}, {val1, val2}, ...};  // create initialized matrix
    
    my_matrix[row_idx][col_idx];			    // access value
    my_matrix[row_idx][col_idx] = new_value;	// modify value

    sizeof(my_array)/sizeof(my_array[0]);       // returns len of array
    sizeof(my_matrix)/sizeof(my_matrix[0]);	    // returns len of rows
    sizeof(matrix[0])/sizeof(my_matrix[0][0]);  // returns len of cols

>-----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------
    std::size(my_array);        // returns len of array
    std::size(my_matrix);       // returns len of rows
    std::size(my_matrix[0]);    // returns len of cols
-----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------<