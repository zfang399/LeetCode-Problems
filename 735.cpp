class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool collide = true;
        while(collide){
            collide = false;
            for(int i = 0; i < asteroids.size()-1; i++){
                if(asteroids[i] > 0 && asteroids[i+1] < 0){
                    collide = true;
                    if(abs(asteroids[i]) > abs(asteroids[i+1])){
                        asteroids.erase(asteroids.begin()+i+1);
                    }else if(abs(asteroids[i]) < abs(asteroids[i+1])){
                        asteroids.erase(asteroids.begin()+i);
                    }else{
                        asteroids.erase(asteroids.begin()+i);
                        asteroids.erase(asteroids.begin()+i);
                        if(asteroids.size()==0) return asteroids;
                    }
                }
            }
        }
        return asteroids;
    }
};
