// LINKED LISTS:

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

            struct node* tail = NULL;
            tail = node;

            // C++ (example)
            Node* head = nullptr;       // head pointer (represents list)
                
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

            Node* tail = nullptr;       // tail pointer (allows quick reference to last element)
            tail = node;

    // Doubly Linked List

    // Circular Linked List