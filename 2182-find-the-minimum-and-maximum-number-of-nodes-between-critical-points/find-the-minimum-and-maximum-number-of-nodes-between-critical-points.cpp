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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return {-1, -1};
        }

        int first_idx=-1; 
        int last_idx=-1;
        int min_dist=INT_MAX; 
        
        ListNode* prev=head;
        ListNode* curr=head->next;
        int idx=1;
        
        while(curr->next!=nullptr){
            ListNode* next_node=curr->next;
            if((curr->val > prev->val && curr->val > next_node->val) || 
                (curr->val < prev->val && curr->val < next_node->val)){
                if(first_idx==-1){
                    first_idx=idx;
                    last_idx=idx;
                }else{
                    min_dist=min(min_dist, idx - last_idx);
                    last_idx=idx; 
                }
            }
            prev=curr;
            curr=next_node;
            idx++;
        }
        if(min_dist==INT_MAX){
            return {-1, -1};
        }
        return {min_dist, last_idx - first_idx};
    }
};