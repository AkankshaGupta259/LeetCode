class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int nl=0,nr=0,nu=0;
        int dist=0;
        for (auto& s : moves){
            if (s=='L'){
                nl++;
            }
            else if (s=='R'){
                nr++;
            }
            else {
                nu++;
            }
        }

        dist=abs(nl-nr) + nu;
        return dist;

    }
};