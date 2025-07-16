class Solution {
public:
    bool isValid(string word) {
        int countvowel=0;
        int consonant=0;
        if(word.length() >= 3)
        {
            for(int i=0;i < word.length() ; i++)
            {
                if(isalpha(word[i]) || isdigit(word[i]))
                {
                    if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
   word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'){
                    countvowel++;
                }
                    else if(isalpha(word[i]))
                    {
                        consonant++;
                    }
                    else{
                        continue;
                    }
                
                }
                else
                {
                    return false;
                }
            }
            if(countvowel >=1 &&  consonant >= 1)
            {
                return true;
            }
        }
        return false;
    }
};