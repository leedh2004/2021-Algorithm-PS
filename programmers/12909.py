def solution(s):

    st = []
    for c in s:
        if c == "(":
            st.append("(")
        elif c == ")":
            if st == []:
                return False
            else:
                st.pop()
        
    return True if st == [] else False