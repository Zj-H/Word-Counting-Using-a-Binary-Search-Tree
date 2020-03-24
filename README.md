# Word-Counting-Using-a-Binary-Search-Tree
Word Counting Using a Binary Search Tree
Word Counting Using a Binary Search Tree
In this assignment, you are to write a program that analyzes a selection of text, counting the number of times each word appears in the text. Your word counts must ignore capitalization, so the, The, THE, and tHe all increase the count for the word "the" by one. For purposes of this assignment, a word is any consecutive string of letters and the apostrophe character, so don't counts as a single word, and best-selling counts as two words: best and selling. Notice that a blank space will not necessarily occur between two words. Numbers such as 27 and 2/3 will not be counted as words.

You must store the words and their counts in a single binary search tree. Each word occurring in the text can only be stored once in the tree. Call the structure for the nodes of the tree WordNode, and call the pointers in this structure left and right. Use C++ strings to store words in the tree. Call the class implementing the binary search tree WordTree. It must contain (at least) the following public functions:

Destructor and default constructor.
Add(): adds the given word to the tree if it is not already in the tree OR increments the appropriate counter if it is already there. It returns nothing.
NumWords(): returns the number of words currently stored in the tree.
Stream output operator<<(): prints the words of the tree in alphabetical order, and next to each word, prints the number of times each word occurs in the text. Should output one (word, count) pair per line.
Implementation Details
Each of the destructor, output operator, and public member functions Add() and NumWords() must each be implemented using a recursive private member function. Three of these operations (all but Add()) must visit every node in the tree. One of these must use preorder traversal, one must use inorder traversal, and one must use postorder traversal. You must decide which method to use for each function; document the type of traversal used in the method comments.

The structure WordNode should be defined as nested within WordTree (i.e., as WordTree::WordNode); it should have a convenience constructor that uses an initialization list.

The WordTree class may have only one member variable, root, and it must be private (but you should already know that part). It contains the address of the root node of the tree.

Because this program is fairly straightforward, I will be especially strict with grading for coding style, including use of const, file naming, indentation, etc.

Your main program should be in a file called CountWords.cpp. It should read from cin and write to cout. Before it uses the tree's stream output operator to output the individual word counts, it should output the total number of words (from NumWords()). I strongly suggest that you read in the data character by character using get. You can of course use any text files to test your program; if you want to use interesting ones, Project Gutenberg (Links to an external site.) has many.

