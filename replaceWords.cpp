// 648. Replace Words
// Leetcode: Medium 07-06-2024

// OPTIMISED APPROACH USING TRIE
    struct trieNode { 
        trieNode *children[26]; 
        bool isEndOfWord; 
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        
        for (int i = 0; i < 26; i++) {
			newNode->children[i] = NULL;
		}
        
        return newNode;
    }

            
    trieNode* root;

    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                crawler->children[index] = getNode();
            
            crawler = crawler->children[index]; 
        }
        
        crawler->isEndOfWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    string search(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                return word; 
            crawler = crawler->children[index];
            if(crawler->isEndOfWord) {
                return word.substr(0, i+1);
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        stringstream ss(sentence);
        string word;
        string result;
        root = getNode();
        for (string word : dictionary) {
            insert(word);
        }

        while(getline(ss, word, ' ')) {
            result += search(word) + " ";
        }

        result.pop_back();
        return result;
    }

// BRUTE FORCE APPROACH 
string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s;
        string ans="";
        for(string it:dictionary)
        {
            s.insert(it);
        }
        int i=0;
        while(i<sentence.length())
        {
            int j=i;
            bool flag=0;
            while(j<sentence.length() && sentence[j]!=' ')
            {
                string temp=sentence.substr(i,j-i+1);
                if(s.find(temp)!=s.end() && !flag)
                {
                    flag=true;  
                    if(ans.size()!=0)
                    {
                        ans+=" ";
                    }
                    ans+=temp;                
                }
                j++;
            }
            if(!flag)
            {
                if(ans.size()!=0)
                { 
                    ans+=" ";
                }
                ans+=sentence.substr(i,j-i);
            }
            i=j+1;            
        }
        return ans;
    }
