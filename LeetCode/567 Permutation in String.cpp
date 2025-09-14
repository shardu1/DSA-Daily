
class Solution {
private:
    bool checkEqual(int count1[26], int count2[26]){
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]){
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        
        //character count array for s1 string 'aab' | a=2,b=1
        int count1[26]={0};
        for(int i=0 ; i<s1.length();i++){
            int index = s1[i] - 'a';  //index of every char in s1   
            count1[index]++;
        }

        int i = 0;
        int window_size=s1.length();
        int count2[26]={0}; //count array for s2 sub string of s1 length

        while(i<window_size && i<s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if(checkEqual(count1 , count2)){
            return 1;
        }

        while(i<s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;

            //removing the old character
            int index_of_old_char= s2[i-window_size] - 'a';
            count2[index_of_old_char]--;
            i++;


            if(checkEqual(count1 , count2)){
                return 1;
            }
        }
        return 0;
    }
};
