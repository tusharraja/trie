class Trie
{
public:
    struct trienode
    {
        trienode *children[26];
        bool isendofword;

        trienode()
        {
            this->isendofword = false;
            for (int i = 0; i < 26; i++)
            {
                this->children[i] = NULL;
            }
        }
    };

    trienode *root;
    Trie()
    {
        root = new trienode();
    }

    void insert(string word)
    {
        trienode *crawler = root;
        for (auto x : word)
        {
            int index = x - 'a';
            if (crawler->children[index] == NULL)
            {
                crawler->children[index] = new trienode();
            }
            crawler = crawler->children[index];
        }
        crawler->isendofword = true;
    }

    bool search(string word)
    {
        trienode *crawler = root;
        for (auto x : word)
        {
            int index = x - 'a';
            if (crawler->children[index] == NULL)
            {
                return false;
            }
            crawler = crawler->children[index];
        }
        if (crawler->isendofword == true)
        {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        trienode *crawler = root;
        for (auto x : prefix)
        {
            int index = x - 'a';
            if (crawler->children[index] == NULL)
            {
                return false;
            }
            crawler = crawler->children[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */