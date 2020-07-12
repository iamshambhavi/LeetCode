class Solution {
public:
    string reformatDate(string date) {
        string arr[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int n=date.size();
        string d=date.substr(n-4)+"-";
        string m=date.substr(n-8,3);
        for(int i=0;i<12;i++){
            if(arr[i]==m){
                if(i+1<10){
                    d+="0";
                    d+=to_string(i+1)+"-";
                }
                else{
                    d+=to_string(i+1)+"-";
                }
                break;
            }
        }
        string p;
        for(int i=0;i<n;i++){
            if(date[i]>='0'&&date[i]<='9'){
                p+=date[i];
            }
            else{
                break;
            }
        }
        if(p.size()==1){
            d+="0"+p;
        }
        else{
            d+=p;
        }
        return d;
    }
};
