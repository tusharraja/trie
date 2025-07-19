class Solution
{
public:
    struct trienode
    {
        int cnt;
        trienode *children[26];
        trienode()
        {
            this->cnt = 0;
            for (int i = 0; i < 26; i++)
            {
                this->children[i] = NULL;
            }
        }
    };

    trienode *root;

    void inserttrie(string word)
    {
        int n = word.size();
        trienode *crawler = root;
        for (int i = 0; i < n; i++)
        {
            char ch = word[i];
            int index = ch - 'a';
            if (crawler->children[index] == nullptr)
            {
                crawler->children[index] = new trienode();
            }
            crawler->children[index]->cnt++;
            crawler = crawler->children[index];
        }
    }

    vector<int> sumPrefixScores(vector<string> &words)
    {
        root = new trienode();
        for (auto x : words)
        {
            inserttrie(x);
        }

        vector<int> ansarray;

        for (auto x : words)
        {
            int ans = 0;
            string w = x;
            int n = w.size();
            trienode *crawler = root;
            for (int i = 0; i < n; i++)
            {

                char ch = w[i];
                int index = ch - 'a';
                if (crawler->children[index] == nullptr)
                {

                    break;
                }
                else
                {
                    ans = ans + crawler->children[index]->cnt;
                    crawler = crawler->children[index];
                }
            }
            ansarray.push_back(ans);
        }
        return ansarray;
    }
};