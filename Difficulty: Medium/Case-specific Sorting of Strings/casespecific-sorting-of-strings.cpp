class Solution {
  public:
    string caseSort(string& s) {
               
             string check=s;    
              sort(s.begin(),s.end());
              
             int i=0;
             int n =s.size();
             for(int j=0;j<n;j++){
                   
                      if (check[j]>='A' && check[j]<='Z'){
                           check[j]=s[i];
                           i++;
                      }
                   
             }
             for(int j=0;j<n;j++){
                   
                      if (check[j]>='a' && check[j]<='z'){
                           check[j]=s[i];
                           i++;
                      }
                   
             }
             
             
             return check;
    }
};
 