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
#ifndef SCORE_EDEPS_H_
#define SCORE_EDEPS_H_

#include <fstream>
#include <string>
#include <vector>

class ScoreEdeps {

public:
  ~ScoreEdeps() = default;

  ScoreEdeps(const ScoreEdeps&) = delete;
  ScoreEdeps& operator=(const ScoreEdeps&) = delete;

  static ScoreEdeps* GetInstance();

  void SetDimention(char m, int n);
  void SetDimensions(int nx, int ny, int nz);

  void CountEvent();
  int GetEventTimes() const;

  void InitializeDose();
  void AddDose(int ix, int iy ,int iz, double val);

  void Print() const;// can print a event only
  void SaveToFile(const std::string& filename) const;

  void AddPoint(double point_x, double point_y);
  void SavePoint(const std::string& filename) const;

  void AddCos(double val);
  void SaveCos(const std::string& filename) const;

private:
  ScoreEdeps();

  int nx_;
  int ny_;
  int nz_;

  int event_counter_;

  std::vector<double> dose_list_;
  std::vector<double> points_list_x_;
  std::vector<double> points_list_y_;
  std::vector<double> rand_cos_list_;

};

// ===========================================================================
inline void ScoreEdeps::SetDimention(char m, int n)
{
  //set dimension m n
}
//-----------------------------------------------------------------------------
inline void ScoreEdeps::SetDimensions(int nx, int ny, int nz)
{
  nx_ = nx;
  ny_ = ny;
  nz_ = nz;
}

//-----------------------------------------------------------------------------
inline void ScoreEdeps::CountEvent()
{
  event_counter_ = event_counter_ + 1;
}

//-----------------------------------------------------------------------------
inline int ScoreEdeps::GetEventTimes() const
{
  return event_counter_ ;
}

//----------------------------------------------------------------------------
inline void ScoreEdeps::AddCos(double val)
{
  rand_cos_list_.push_back(val);
}

//----------------------------------------------------------------------------
inline void ScoreEdeps::SaveCos(const std::string& filename) const
{
 std::ofstream file_pt(filename, std::ios::out);

 for (int i = 0; i < rand_cos_list_.size(); i++) {

   file_pt << rand_cos_list_[i] << std::endl;

 }

 file_pt.close();
}

#endif
