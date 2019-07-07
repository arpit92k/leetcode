class WordDictionary {
    struct Node
    {
        Node *nodes['z' - 'a' + 1];
        bool isEnd;
        Node()
        {
            for(int i = 0; i < 'z' - 'a' + 1; ++i)
            {
                nodes[i] = nullptr;
            }
            isEnd = false;
        }
        ~Node()
        {
            for(int i = 0; i < 'z' - 'a' + 1; ++i)
            {
                if(nodes[i])
                {
                    delete nodes[i];
                }
            }
        }
    };
    Node *root;
    void addtoDict(Node *node, string word, int index, int length)
    {
        if(index < length)
        {
            if(node->nodes[word[index] - 'a'] == nullptr)
            {
                node->nodes[word[index] - 'a'] = new Node();
            }
            addtoDict(node->nodes[word[index] - 'a'], word, index + 1, length);
        }
        else
        {
            node->isEnd = true;
        }
    }
    
    bool searchInDict(Node *node, string word, int index, int length)
    {
        bool result = false;
        if(index < length)
        {
            char c = word[index];
            if(c == '.')
            {
                int i = 0;
                while(i <= 'z' - 'a')
                {
                    if(node->nodes[i] != nullptr)
                    {
                        result = searchInDict(node->nodes[i], word, index + 1, length);
                    }
                    if(result)
                    {
                        break;
                    }
                    ++i;
                }
            }
            else if(node->nodes[c - 'a'] != nullptr)
            {
                result = searchInDict(node->nodes[c - 'a'], word, index + 1, length);
            }
        }
        else
        {
            result = node->isEnd;
        }
        return result;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addtoDict(root, word, 0, word.length());
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchInDict(root, word, 0, word.length());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
