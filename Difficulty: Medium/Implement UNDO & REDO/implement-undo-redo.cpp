class Solution {
  public:
    string str;
    stack<char> st;
    void append(char x) {
        // append x into document
        str.push_back(x);
    }

    void undo() {
        // undo last change
        st.push(str.back());
        str.pop_back();
    }

    void redo() {
        // redo changes
        str.push_back(st.top());
        st.pop();
    }

    string read() {
        // read the document
        return str;
    }
};