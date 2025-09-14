class Solution {
public:
    string removeDuplicates(string s) {
        string stack;
        
        for (char c : s) {
            if (!stack.empty() && c == stack.back()) {
                stack.pop_back();
            } 
            else {
                stack.push_back(c);
            }
        }
        
        return stack;
        
    }
};
