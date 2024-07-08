// LISTS:

// Singly Linked List

    // Defining a Node
        // C (example)
        struct node {
            type data;          // data to store in node
            struct node* next;  // ptr to next node
        };

        // C++ (example)
        class Node {
            public:
            type data;
            Node* next;
        };

    // Initializing Nodes
        // C (example)
        struct node* head = NULL;
        struct node* node = (struct node*)malloc(sizeof(struct node));  // Check for NULL!

        node->data = value;
        node->next = NULL;
        head = node;

        node = (struct node*)malloc(sizeof(struct node));   // If NULL, free memory and rtn
        node->data = value;
        node->next = NULL;
        head->next = node;

        node = (struct node*)malloc(sizeof(struct node));   // If NULL, free memory and rtn
        node->data = value;
        node->next = NULL;
        head->next->next = node;

        // C++ (example)
        Node* head = nullptr;
            
        Node* node = new Node();    // allocating memory for node
        node->data = value;
        node->next = nullptr;
        head = node;                // head points to first node

        node = new Node();          // creating additional node
        node->data = value;
        node->next = nullptr;       
        head->next = node;          // prev node points to next node

        node = new Node();
        node->data = value;
        node->next = nullptr;       // last node points nowhere
        head->next->next = node;

    // Implementing a Tail Pointer
    

    >-----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------
    // Forward List Container (#include <forward_list>)

    /* Main advantage of using a forward list compared to a standard
    list is the savings that could be achieved in memory.*/

        // Declaring a Forward List
        forward_list<type> flist;

        // Forward List Operations
            // Member Functions
            flist.assign();
            flist1 = flist2;    // = operator copies list to another

            // Element Access
            flist.front();

            // Iterators    (Bidirectional Iterators only!)
            flist.begin();
            flist.end();

            // Capacity
            flist.empty();
            flist.max_size();

            // Modifiers
            flist.push_front();
            flist.emplace_front();
            flist.pop_front();
            flist.insert_after();
            flist.emplace_after();
            flist.erase_after();
            flist.clear();
            flist.swap();

            // Operations
            flist.merge();
            flist.remove();
            flist.remove_if();
            flist.splice_after();
            flist.reverse();
            flist.sort();
            flist.unique();
        
    -----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------<

// Doubly Linked List

    //
        //

        //

    //
        //

        //
    >-----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------
    // List Container (#include <list>)

    -----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------<

// Circular Linked List
