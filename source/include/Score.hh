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
// Score.hh
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Score_h
#define Score_h 1

#include <iostream>
#include <vector>
#include <fstream>

class Score_Edeps
{
    private:
        Score_Edeps()= default;

        ~Score_Edeps() = default;

        static Score_Edeps *instance;
    
    public:


        static Score_Edeps *GetInstance(){

            return instance;
        }

        static void CreateInstance();
        static void DeleteInstance();
        static void AddScoreData(int x,int y, int z, double data);
        static void CoutData();

        static std::vector<std::vector<std::vector<double>>> scores;

        int a;
        
        
        /*
        void GetScorerPointer();

        void AddScoreData(int x,int y,int z,double data);

        void CoutData();

        void MakeInstance(); // not made 

        */


};
#endif