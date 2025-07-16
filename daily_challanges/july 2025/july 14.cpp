/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pow(int x,int n)
    {
        if(n==0) return 1;
        if(n==1) return x;
        return x* pow(x,n-1);
    }
    int getDecimalValue(ListNode* head) {
        int n=-1;
        vector<int>vec;
        int x=0;
        ListNode* temp=head;
        while(temp != nullptr)
        {
            n++;
            vec.push_back(temp-> val);
            temp=temp->next;
        }
        for(auto it : vec)
        {
            if(it==1)
            {
                x+=pow(2,n);
            }
            n--;
        }
        return x;
    }
};