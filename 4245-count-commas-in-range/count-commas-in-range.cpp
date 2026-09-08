class Solution {
public:
    int countCommas(int n) {
        int number=n;
        int digcount=0;
        int comma=0;
        while (number>0){
            int remainder= number%10;
            digcount++;
            number=number/10;
        }

        if(digcount>3){
            for (int i=1000;i<=n;i++){
                comma++;
            }
        }
        return comma;
    }
};