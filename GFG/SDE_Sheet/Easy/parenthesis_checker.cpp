class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        bool ans = true;
        stack<char> st;
        for (char c : x)
        {
            if ((c == '{') || (c == '(') || (c == '['))
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    ans = false;
                    break;
                }
                else
                {
                    char o = st.top();
                    st.pop();
                    if (((c == '}') && (o == '{')) ||
                        ((c == ')') && (o == '(')) ||
                        ((c == ']') && (o == '[')))
                    {
                        continue;
                    }
                    else
                    {
                        ans = false;
                        break;
                    }
                }
            }
        }
        ans = ans && st.empty();
        return ans;
    }
};
