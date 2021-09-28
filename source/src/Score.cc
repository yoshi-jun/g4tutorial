/*==============================================================================
  BSD 2-Clause License
  Copyright (c) 2021 Junichi Yoshida
  All rights reserved.
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
==============================================================================*/

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Source.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include"Score.hh"

Score_Edeps *Score_Edeps::instance = NULL;

void Score_Edeps::CreateInstance()
{

    if(!instance){
        instance = new Score_Edeps;
    }
}

void Score_Edeps::DeleteInstance()
{

    std::ofstream outdata("data.csv");

    for (int i = 0; i < int(Score_Edeps::scores.size()); i++ )
    {

        for (int j = 0; j < int(Score_Edeps::scores.at(0).size()); j++ )
        {
        
            for (int k = 0; k < int(Score_Edeps::scores.at(0).at(0).size()); k++ )
            {

                outdata << Score_Edeps::scores.at(i).at(j).at(k) << "\n";
            
            }
        }
    }

    outdata.close();

    delete instance;

    instance = NULL;
}

void AddScoreData(int x,int y,int z,double data)
{

    Score_Edeps::scores.at(x).at(y).at(z) = data;

}

void CoutData(){

    for (int i = 0; i < int(Score_Edeps::scores.size()); i++ )
    {

        for (int j = 0; j < int(Score_Edeps::scores.at(0).size()); j++ )
        {
        
            for (int k = 0; k < int(Score_Edeps::scores.at(0).at(0).size()); k++ )
            {

                std::cout << Score_Edeps::scores.at(i).at(j).at(k) << "\n" << std::endl;
            
            }
        }
    }


}