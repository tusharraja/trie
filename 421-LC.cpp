class Solution
{
public:
    struct trienode
    {
        trienode *left;
        trienode *right;
    };

    trienode *root;

    void insertintrie(int num)
    {
        trienode *crawler = root;
        for (int i = 31; i >= 0; i--)
        {
            int dig = (num >> i) & 1;
            if (dig == 1)
            {
                if (crawler->right == nullptr)
                {
                    crawler->right = new trienode();
                }
                crawler = crawler->right;
            }
            else
            {
                if (crawler->left == nullptr)
                {
                    crawler->left = new trienode();
                }
                crawler = crawler->left;
            }
        }
    }

    int ans = 0;

    void traveltrie(int num)
    {

        trienode *crawler = root;
        int n = 0;
        for (int i = 31; i >= 0; i--)
        {

            int dig = (num >> i) & 1;
            if (dig == 1)
            {
                if (crawler->left)
                {
                    crawler = crawler->left;
                    n = n + (pow(2, i));
                    // s+="1";
                }
                else
                {
                    crawler = crawler->right;
                    //  s+="0";
                }
            }

            else
            {
                if (crawler->right)
                {
                    crawler = crawler->right;
                    n = n + (pow(2, i));
                    // s+="1";
                }
                else
                {
                    crawler = crawler->left;
                    // s+="0";
                }
            }
        }

        ans = max(ans, n);
    }

    int findMaximumXOR(vector<int> &nums)
    {
        root = new trienode();
        for (auto x : nums)
        {
            insertintrie(x);
        }

        for (auto x : nums)
        {
            traveltrie(x);
        }

        return ans;
    }
};