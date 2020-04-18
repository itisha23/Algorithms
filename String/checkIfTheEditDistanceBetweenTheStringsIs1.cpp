

bool isEditDistance1(string s1, string s2) {

    int m = s1.size();
    int n = s2.size();

    if(abs(m-n) > 1)
        return 0;

    i=0; j=0;

    while(i<m && j<n) {

        if(s1[i] == s2[j]) {
            i++; j++;
        }

        else {
            count++;
            if(m == n)
            {
                i++; j++; //replace is the only option we can perform
            } else if(m > n) {
                i++;
            } else {
                j++;
            }
        }
    }

    return count <= 1;
}