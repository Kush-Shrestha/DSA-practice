/* pseudo code to insert in the beginning 
   Step 1: create new node 
   Step 2: IF (NEW_NODE == NULL) THEN
             DISPLAY "Memory Overflow"
             EXIT
         ENDIF
    Step 3: Read num    // Get the value to be inserted
    Step 4: SET NEW_NODE.data ← num
         SET NEW_NODE.next ← HEAD   // Link new node to the previous first 
    Step 5: Set Head <- new node // Update HEAD to point to the new node

    Step 6:  DISPLAY "Node inserted at beginning successfully"

Thats all Now the actual code 
*/