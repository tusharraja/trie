class WordDictionary
{
public:
    struct trienode
    {
        trienode *child[26];
        bool isendofword;
        trienode()
        {
            this->isendofword = false;
            for (int i = 0; i < 26; i++)
            {
                this->child[i] = NULL;
            }
        }
    };
    trienode *root;
    WordDictionary()
    {
        root = new trienode();
    }

    void addWord(string word)
    {
        trienode *crawler = root;
        for (auto x : word)
        {
            int index = x - 'a';
            if (crawler->child[index] == nullptr)
            {
                crawler->child[index] = new trienode();
            }
            crawler = crawler->child[index];
        }
        crawler->isendofword = true;
    }
    trienode *crawler;

    bool helpsearch(string word, int ind, int n, trienode *crawler)
    {

        if (ind == n)
        {
            if (crawler->isendofword == true)
            {
                return true;
            }
            return false;
        }

        char x = word[ind];
        if (word[ind] != '.')
        {
            int index = x - 'a';
            if (crawler->child[index] == nullptr)
            {
                return false;
            }
            return helpsearch(word, ind + 1, n, crawler->child[index]);
        }
        else
        {
            bool a = false;
            for (int i = 0; i < 26; i++)
            {
                if (crawler->child[i] != nullptr)
                {
                    if (helpsearch(word, ind + 1, n, crawler->child[i]) == true)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
    bool search(string word)
    {
        int n = word.size();
        int ind = 0;
        crawler = root;
        return helpsearch(word, ind, n, crawler);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */