#include <iostream>
#include <string>
#include <sstream>
using namespace std;



//the class of WordTree
class WordTree
{
    //define a struct for tree node
private:
    typedef struct wordnode
    {
        //the word in current node
        string word;
        //the number of current word
        int num;
        //the pointer to the right and left child
        wordnode* left;
        wordnode* right;
        //the constructor, a word is passed in
        wordnode(string word_)
        {
            word=word_;
            num=1;
            left=nullptr;
            right=nullptr;
        }
    }WordNode;

    //the root of current binary tree
private:
    WordNode* root;

public:
    //default constructor
    WordTree()
    {
        //just set the root to be nullptr
        root=nullptr;
    }

    //destructor
    ~WordTree()
    {
        //release all the nodes of current tree
        releaseTree(root);
        root=nullptr;
    }

    //add one word to the tree
    void Add(string word)
    {
        //the, The, THE, and tHe are all "the", so change word into lower case
        for(int i=0;i<word.length();i++)
        {
            if(word[i]>='A' && word[i]<='Z')
                word[i]=(word[i]-'A')+'a';
        }
        //best-selling counts as two words: best and selling
        //and 2/7 is considered as 27, then 27 should not be considers as a word
        //so remove characters except letters and then split the word,
        //and check whether the string is a word
        for(int i=0;i<word.length();i++)
        {
            if(word[i]<'a' || word[i]>'z') word[i]=' ';
        }
        //remove start and end spaces
        if(word.length()>0) word.erase(0,word.find_first_not_of(" "));
        if(word.length()>0) word.erase(word.find_last_not_of(" ") + 1);
        //split the string into words by space
        while(word.length()>0)
        {
            int i=word.find_first_of(" ");
            //end of the word
            if(i==-1)
            {
                root=addWord(root, word);
                break;
            }
                //get the substring of the word
            else
            {
                string wordSub=word.substr(0, i);
                root=addWord(root, wordSub);
                word.erase(0,i);
                //continue remove all spaces at start and end
                if(word.length()>0) word.erase(0,word.find_first_not_of(" "));
                if(word.length()>0) word.erase(word.find_last_not_of(" ") + 1);
            }
        }
    }

    //get the number of words
    int NumWords()
    {
        //call recursive method
        return getWordTotalNum(root);
    }

    //Stream output operator<<()
    friend ostream & operator<<( ostream & os,const WordTree & c);

private:
    //the helper functions

    //release all the tree by post-order traversal
    void releaseTree(WordNode* node)
    {
        //terminate if current node is nullptr
        if(node==nullptr) return;
        //release left children
        releaseTree(node->left);
        //release right children
        releaseTree(node->right);
        //release current node
        delete node;
    }

    //add one word to the tree
    //it's a recursion
    WordNode* addWord(WordNode* node, string word)
    {
        //if current node is nullptr, insert to this place
        if(node==nullptr) return new WordNode(word);
            //equal to current node, add current number
        else if(node->word==word)
        {
            node->num++;
            return node;
        }
            //less than current node, try left child
        else if(node->word>word)
        {
            node->left=addWord(node->left, word);
            return node;
        }
            //to right child
        else
        {
            node->right=addWord(node->right, word);
            return node;
        }
    }

    //a recursive method for get the total number of words
    //it's a post-order traversal
    int getWordTotalNum(WordNode* node)
    {
        if(node==nullptr) return 0;
        //get the total number of left child
        int n1=getWordTotalNum(node->left);
        //get the total number of right child
        int n2=getWordTotalNum(node->right);
        //get the total number of current
        int n3=node->num;
        return n1+n2+n3;
    }

    //a recursive method to get all words in alphabet order
    //it's in-order traversal
    void print(ostream & os, WordNode* node) const
    {
        if(node==nullptr) return;
        //the left children
        print(os, node->left);
        //current node
        os<<node->word<<"("<<node->num<<")"<<"\n";
        //the right children
        print(os, node->right);
    }
};

ostream & operator<<( ostream & os,const WordTree & c)
{
    c.print(os, c.root);
    return os;
}

int main()
{
    cout<<"234"<<endl;
    WordTree tree;
    //add words to it
    cout<<"Input some words, press 0 to end the input."<<endl;
    string s;
    while(1)
    {
        cin>>s;
        if(s=="0") break;
        tree.Add(s);
    }
    //output
    cout<<tree;
    //output the number of words
    cout<<"Word num: "<<tree.NumWords()<<endl;

    return 0;
}