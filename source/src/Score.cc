//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Source.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Score_Edeps::Score_Edeps(){

    pointer = new *Score_Edeps();

}

Score_Edeps::~Score_Edeps(){

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

void AddScoreData(x,y,z,data){

    Score_edep.at(x).at(y).at(z) = data;
    
}