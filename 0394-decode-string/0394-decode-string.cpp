class Solution {
public:
    string decodeString(string s) {
        stack<int> numberStack;
        stack<string> stringStack;
        int k = 0;
        string currentString = ""; 
        
        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                numberStack.push(k);
                k = 0;
                stringStack.push(currentString);
                currentString = "";
            } 
            else if (ch == ']') {
                string temp = currentString;
                currentString = stringStack.top();
                stringStack.pop();
                
                int count = numberStack.top();
                numberStack.pop();
                
                for (int j = 0; j < count; j++) {
                    currentString += temp;
                }
            } 
            else {
                currentString += ch;
            }
        }
        
        return currentString;
    }
};
