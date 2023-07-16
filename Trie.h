#include "TrieNode.h"
#include <string>
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode *(word[0]);
            root->children[index] = child;
        }

        // Recursive Call
        insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    // SEARCH

    bool searchResult(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            return searchResult(child, word.substr(1));
        }
        else
        {
            return false;
        }
    }

    bool search(string word)
    {
        // Write your code here
        if (word.size() == 0)
            return false;

        return searchResult(root, word);
    }

    //   DELETE

    void deleteWord(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }

        // Recursive Call
        deleteWord(child, word.substr(1));

        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                /* code */
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    // For user
    void deleteWord(string word)
    {
        deleteWord(root, word);
    }
};
