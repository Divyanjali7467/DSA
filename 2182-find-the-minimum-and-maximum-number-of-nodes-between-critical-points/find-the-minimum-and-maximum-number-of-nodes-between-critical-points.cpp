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
        
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        
        int pos = 1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr != nullptr && curr->next != nullptr) {
            
            ListNode* next = curr->next;
            
            // Check if current node is a critical point
            bool isCritical = 
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);
            
            if (isCritical) {
                
                if (first == -1) {
                    // First critical point
                    first = pos;
                } 
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);
                }
                
                last = pos;
            }
            
            prev = curr;
            curr = next;
            pos++;
        }
        
        // Fewer than 2 critical points
        if (first == -1 || first == last) {
            return {-1, -1};
        }
        
        int maxDist = last - first;
        
        return {minDist, maxDist};
    }
};