//leetcode 3304

class Solution {
public:
    char kthCharacter(int k) {
        string st="a";
        while(st.length() <= k)
        {
            string temp="";
            for(char x:st)
            {
                if(x=='z')
                {
                    temp+='a';
                    
                }
                else
                {
                    temp+=x+1;
                }
                
            }
            st+=temp;
        }
        return st[k-1];
    }
};