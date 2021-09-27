//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Score.hh
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class Score_Edeps
{

    public:
        ~Score_Edeps(){

            std::ofstream outdata("data.csv");

            for (i=0; i < 61; i++ ){

                for (j=0; j < 61; j++ ){
                
                    for (k=0; k < 150; k++ ){

                        outdata << Score_edep.at(i).at(j).at(k);
                    
                    }
                }
            }

            outdata.close();
        
        }

        void GetScorerPointer(){

            return pointer;
        
        }

        void AddScoreData(i,j,k,data){

            Score_edep.at(i).at(j).at(k) = data;

        }

    private:

        Score_Edep(){
    
            static pointer = new *ScoreEdep();
    
        }
    
        static pointer
        static Score_Edep*;
        
        static std::vector<std::vector<std::vector<double>>> Score_edep;

};