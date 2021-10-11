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

#include <string>
#include <vector>

class ScoreEdeps {

public:
  ~ScoreEdeps() = default;

  ScoreEdeps(const ScoreEdeps&) = delete;
  ScoreEdeps& operator=(const ScoreEdeps&) = delete;

  static ScoreEdeps* GetInstance();

  void SetDimensions(int nx, int ny, int nz);

  void InitializeDose();
  void AddDose(int ix, int iy ,int iz, double val);
  void StacDose(int num, double val);

  void Print() const;
  void SaveToFile(const std::string& filename) const;


private:
  ScoreEdeps();

  int nx_;
  int ny_;
  int nz_;

  std::vector<double> dose_list_;


};

// ===========================================================================

inline void ScoreEdeps::SetDimensions(int nx, int ny, int nz)
{
  nx_ = nx;
  ny_ = ny;
  nz_ = nz;
}

#endif
